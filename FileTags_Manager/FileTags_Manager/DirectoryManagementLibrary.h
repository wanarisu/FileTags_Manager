#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "Logs.h"



ref class DirectoryManagementLibrary
{
    /**
    * @brief �t�H���_�ȉ��̃t�@�C���ꗗ���擾����֐�
    * @param[in]    folderPath  �t�H���_�p�X
    * @param[out]   file_names  �t�@�C�����ꗗ
    * return        true:����, false:���s
    **/
    public:
    static bool getFileNames(std::string folderPath, std::vector<std::string>& file_names);
};

