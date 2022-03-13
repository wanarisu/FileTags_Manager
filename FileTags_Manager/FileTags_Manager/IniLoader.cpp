#include "IniLoader.h"

bool        IniLoader::logExportFlag=false;
std::string IniLoader::logExportPath="";

bool        IniLoader::LogExportFlag() { return logExportFlag;}
std::string IniLoader::LogExportPath() { return logExportPath;}

void IniLoader::IniLoad() {
	std::ifstream reading_file;
	reading_file.open("D:\\VisualC\\config.ini", std::ios::in);
	std::string reading_line_buffer;
	while (std::getline(reading_file, reading_line_buffer)) {
		std::smatch m;
		//if (std::regex_match(reading_line_buffer, m, std::regex("(\\w+) = (\\d+)"))) {
		if (std::regex_match(reading_line_buffer, m, std::regex(R"((\w+) = (.+))"))) {
			InitializationOfSettings(m[1], m[2]);
		}
		//else if (std::regex_match(reading_line_buffer, m, std::regex(R"(^\[(.+)\]$)")))
		//{
		//    LOG_DEBUG(m[0].str());  // => 123=4567
		//    LOG_DEBUG(m[1].str());  // => 123
		//    LOG_DEBUG(m[2].str());  // => 4567
		//}
	}
}

void IniLoader::InitializationOfSettings(std::string propertyName, std::string value)
{
	if (propertyName == "exportFlag") logExportFlag = value == "true" ? true : false;
	else if (propertyName == "exportPath")
	{
		logExportPath = value;
	}
}