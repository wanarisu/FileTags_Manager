#pragma once

#include<iostream>
#include <msclr/marshal_cppstd.h>
#include<fstream>
#include <string>
#using <system.dll> // Debug::WriteLineのために必要

// "DEBUG"マクロをコメントアウトすれば、ログは出力されません。
#define DEBUG

// __FILE__はファイルパス名のため、下記のマクロでファイル名のみ切り出します。
#define FILE (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

// ログを出力する場合、"LogDebug"関数ではなく"LOG_DEBUG"マクロを呼び出してください。
// 直接LogDebug関数を呼び出した場合、呼び出し元のファイル名、関数名、行番号が付加されません。
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
        // このクラスはインスタンス化させないため、コンストラクタはprivateにします。
    private:
        CLog();
        static void FileExport(std::string str, std::string path);
    public:
        /**
        * @brief デバッグログを出力します。
        *
        * @param [in] file ファイル名
        * @param [in] func 関数名
        * @param [in] line 行番号
        * @param [in] fmt メッセージ
        * @param [in] args メッセージに埋め込む可変長引数
        */
        static void CLog::LogDebug(std::string file, std::string func, int line, std::string fmt);
    };
}