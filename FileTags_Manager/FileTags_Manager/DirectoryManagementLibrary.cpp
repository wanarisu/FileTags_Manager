#include "DirectoryManagementLibrary.h"

/**
* @brief �t�H���_�ȉ��̃t�@�C���ꗗ���擾����֐�
* @param[in]    folderPath  �t�H���_�p�X
* @param[out]   file_names  �t�@�C�����ꗗ
* return        true:����, false:���s
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
