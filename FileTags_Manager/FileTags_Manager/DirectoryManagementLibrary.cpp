#include "DirectoryManagementLibrary.h"

/**
* @brief フォルダ以下のファイル一覧を取得する関数
* @param[in]    folderPath  フォルダパス
* @param[out]   file_names  ファイル名一覧
* return        true:成功, false:失敗
**/
std::vector<std::string> DirectoryManagementLibrary::getFileNames(const char* path)
{
    DIR* dp;
    dp = opendir(path);
    if (dp == NULL) exit(1);
    dirent* entry = readdir(dp);

    std::vector<std::string>* inDirs = new std::vector<std::string>();

    while (entry != NULL) {
        if (entry != NULL) {
            //std::cout << path << entry->d_name << std::endl;
            LOG_DEBUG(entry->d_name);
            inDirs->push_back(entry->d_name);
        }
        entry = readdir(dp);
    }

    return *inDirs;
}
