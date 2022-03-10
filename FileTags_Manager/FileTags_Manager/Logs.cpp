#include "Logs.h"

using namespace Log;

CLog::CLog()
{
}

void CLog::LogDebug(std::string file, std::string func, int line, std::string message)
{
    std::string log = file + ' ' + func + '('+ std::to_string(line) +") -- " + message;

    // ファイル書き出し
    CLog::FileExport(log, "C:\\Users\\wanarisu\\Documents\\cpp.log");
}

void CLog::FileExport(std::string str, std::string path) {
    std::fstream file;
    file.open(path, std::ios_base::app | std::ios_base::in);
    file << str.c_str() << std::endl;
    file.close();
}
