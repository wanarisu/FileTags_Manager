#include "DirectoryManagementLibrary.h"

/**
* @brief フォルダ以下のファイル一覧を取得する関数
* @param[in]    folderPath  フォルダパス
* @param[out]   file_names  ファイル名一覧
* return        true:成功, false:失敗
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

    /* エラー処理 */
    if (err) {
        LOG_DEBUG(std::to_string(err.value()));
        LOG_DEBUG(err.message());

        //std::cout << err.value() << std::endl;
        //std::cout << err.message() << std::endl;
        return false;
    }
    return true;
}