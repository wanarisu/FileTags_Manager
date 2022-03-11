#include "IniLoader.h"
using namespace Log;

void IniLoader::IniLoad(){
    std::ifstream reading_file;
    reading_file.open("D:\\新しいフォルダー\\config.ini", std::ios::in);
    std::string reading_line_buffer;
    while (std::getline(reading_file, reading_line_buffer)) {
        LOG_DEBUG(reading_line_buffer);
    }
}