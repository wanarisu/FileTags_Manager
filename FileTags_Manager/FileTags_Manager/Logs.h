#pragma once

#include<iostream>
#include <msclr/marshal_cppstd.h>
#include<fstream>
#include <string>
#using <system.dll> // Debug::WriteLine�̂��߂ɕK�v

// "DEBUG"�}�N�����R�����g�A�E�g����΁A���O�͏o�͂���܂���B
#define DEBUG

// __FILE__�̓t�@�C���p�X���̂��߁A���L�̃}�N���Ńt�@�C�����̂ݐ؂�o���܂��B
#define FILE (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

// ���O���o�͂���ꍇ�A"LogDebug"�֐��ł͂Ȃ�"LOG_DEBUG"�}�N�����Ăяo���Ă��������B
// ����LogDebug�֐����Ăяo�����ꍇ�A�Ăяo�����̃t�@�C�����A�֐����A�s�ԍ����t������܂���B
#ifdef DEBUG
#define LOG_DEBUG(fmt, ...) CLog::LogDebug(FILE, __FUNCTION__, __LINE__, fmt)
#else
#define LOG_DBUG(fmt, ...)
#endif

namespace Log
{
    using namespace System;
    using namespace System::Diagnostics;

    public ref class CLog
    {
        // ���̃N���X�̓C���X�^���X�������Ȃ����߁A�R���X�g���N�^��private�ɂ��܂��B
    private:
        CLog();
        static void FileExport(std::string str, std::string path);
    public:
        /**
        * @brief �f�o�b�O���O���o�͂��܂��B
        *
        * @param [in] file �t�@�C����
        * @param [in] func �֐���
        * @param [in] line �s�ԍ�
        * @param [in] fmt ���b�Z�[�W
        * @param [in] args ���b�Z�[�W�ɖ��ߍ��މϒ�����
        */
        static void CLog::LogDebug(std::string file, std::string func, int line, std::string fmt);
    };
}