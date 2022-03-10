#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include "dirent.h"
#include "Logs.h"

using namespace Log;

ref class DirectoryManagementLibrary
{

    /**
    * @brief �t�H���_�ȉ��̃t�@�C���ꗗ���擾����֐�
    * @param[in]    folderPath  �t�H���_�p�X
    * @param[out]   file_names  �t�@�C�����ꗗ
    * return        true:����, false:���s
    **/
    public:
    static std::vector<std::string> getFileNames(const char* path);
};

