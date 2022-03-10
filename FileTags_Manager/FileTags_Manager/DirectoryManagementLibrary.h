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
    * @brief フォルダ以下のファイル一覧を取得する関数
    * @param[in]    folderPath  フォルダパス
    * @param[out]   file_names  ファイル名一覧
    * return        true:成功, false:失敗
    **/
    public:
    static std::vector<std::string> getFileNames(const char* path);
};

