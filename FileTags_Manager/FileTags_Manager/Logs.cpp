#include "Logs.h"
#include "IniLoader.h"
using namespace Log;

CLog::CLog()
{
    
}

void CLog::LogDebug(std::string file, std::string func, int line, std::string message)
{
    if(!IniLoader::LogExportFlag()) return;
    std::string log = getDatetimeStr() + " -- " + file + ' ' + func + '(' + std::to_string(line) + ") -- " + message;

    // ファイル書き出し
    std::string tmp = IniLoader::LogExportPath();
    CLog::FileExport(log, tmp);
}

void CLog::FileExport(std::string str, std::string path) {
    std::fstream file;
    file.open(path, std::ios_base::app | std::ios_base::in);
    file << str.c_str() << std::endl;
    file.close();
}

std::string CLog::getDatetimeStr() {
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
    std::stringstream s;
    s << localTime->tm_year + 1900;
    s << '-';
    // setw(),setfill()で0詰め
    s << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
    s << '-';
    s << std::setw(2) << std::setfill('0') << localTime->tm_mday;
    s << ' ';
    s << std::setw(2) << std::setfill('0') << localTime->tm_hour;
    s << ':';
    s << std::setw(2) << std::setfill('0') << localTime->tm_min;
    s << ':';
    s << std::setw(2) << std::setfill('0') << localTime->tm_sec;
    // std::stringにして値を返す
    return s.str();
}