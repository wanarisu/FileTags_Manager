#include "DirectoryManagementLibrary.h"

/**
* @brief �t�H���_�ȉ��̃t�@�C���ꗗ���擾����֐�
* @param[in]    folderPath  �t�H���_�p�X
* @param[out]   file_names  �t�@�C�����ꗗ
* return        true:����, false:���s
**/
bool DirectoryManagementLibrary::getFileNames(std::string folderPath, std::vector<std::string>& file_names)
{
    using namespace Log;
    using namespace std::filesystem;

    directory_iterator iter(folderPath), end;
    std::error_code err;

    for (; iter != end && !err; iter.increment(err)) {
        const directory_entry entry = *iter;

        file_names.push_back(entry.path().string());
        printf("%s\n", file_names.back().c_str());
    }

    /* �G���[���� */
    if (err) {
        LOG_DEBUG(std::to_string(err.value()));
        LOG_DEBUG(err.message());

        //std::cout << err.value() << std::endl;
        //std::cout << err.message() << std::endl;
        return false;
    }
    return true;
}