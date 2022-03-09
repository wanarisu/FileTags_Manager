#include "Logs.h"

using namespace Log;

CLog::CLog()
{
}

void CLog::LogDebug(const char* file, const char* func, int line, std::string fmt, ... array<Object^>^ args)
{
    // ���b�Z�[�W�ɉϒ������𖄂ߍ��݂܂��B
    String^ message = String::Format(gcnew String(fmt.c_str()), args);

    // 0����̂��߃C���N�������g
    ++line;

    // ���O��<�t�@�C����> �֐���(�s�ԍ�) ���b�Z�[�W�̕�����ɂ��܂��B
    String^ log = String::Format("{0} {1}({2}) {3}", gcnew String(file), gcnew String(func), line, message);

    //// ���O���R���\�[���ɏo�͂��܂��B
    //Debug::WriteLine(log);

    CLog::FileExport(msclr::interop::marshal_as<std::string>(log), "C:\\Users\\wanarisu\\Documents\\cpp.log");
}

void CLog::FileExport(std::string str, std::string path) {
    std::ofstream outputfile(path);
    outputfile << str.c_str();
    outputfile.close();
}
