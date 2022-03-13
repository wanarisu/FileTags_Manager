#include "MainForm.h"

using namespace FileTagsManager;

[STAThreadAttribute]
int main()
{
	IniLoader::IniLoad();
	Application::Run(gcnew MainForm());
	return 0;
}