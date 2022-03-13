#pragma once
#include <string>
#include <fstream>
#include <regex>

class IniLoader
{
private:
	static bool        logExportFlag;
	static std::string logExportPath;

public:
	static bool        LogExportFlag();
	static std::string LogExportPath();
	static void IniLoad();
	static void InitializationOfSettings(std::string propertyName, std::string value);
};

