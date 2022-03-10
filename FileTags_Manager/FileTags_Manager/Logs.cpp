#include "Logs.h"

using namespace Log;

CLog::CLog()
{
}

void CLog::LogDebug(std::string file, std::string func, int line, std::string message)
{
    //// 0����̂��߃C���N�������g
    //++line;

    std::string log = file + ' ' + func + '('+ std::to_string(line) +") -- " + message;

    // ���O��<�t�@�C����> �֐���(�s�ԍ�) ���b�Z�[�W�̕�����ɂ��܂��B
    //String^ log = String::Format("{0} {1}({2}) {3}", gcnew String(file), gcnew String(func), line, message);

    //// ���O���R���\�[���ɏo�͂��܂��B
    //Debug::WriteLine(log);

    CLog::FileExport(log, "C:\\Users\\wanar\\Documents\\cpp.log");
}

void CLog::FileExport(std::string str, std::string path) {
    //std::ofstream outputfile(path);
    std::fstream file;
    file.open(path, std::ios_base::app | std::ios_base::in);
    file << str.c_str() << std::endl;
    file.close();
}
