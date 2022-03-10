#include "MainForm.h"

using namespace FileTagsManager;

[STAThreadAttribute]
int main()
{
	Application::Run(gcnew MainForm());
	return 0;
}