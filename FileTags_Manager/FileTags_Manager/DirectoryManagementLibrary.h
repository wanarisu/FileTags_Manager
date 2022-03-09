#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "Logs.h"



ref class DirectoryManagementLibrary
{
    /**
    * @brief フォルダ以下のファイル一覧を取得する関数
    * @param[in]    folderPath  フォルダパス
    * @param[out]   file_names  ファイル名一覧
    * return        true:成功, false:失敗
    **/
    public:
    static bool getFileNames(std::string folderPath, std::vector<std::string>& file_names);
};

