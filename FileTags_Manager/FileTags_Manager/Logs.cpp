#include "Logs.h"

using namespace Log;

CLog::CLog()
{
}

void CLog::LogDebug(const char* file, const char* func, int line, std::string fmt, ... array<Object^>^ args)
{
    // メッセージに可変長引数を埋め込みます。
    String^ message = String::Format(gcnew String(fmt.c_str()), args);

    // 0からのためインクリメント
    ++line;

    // ログを<ファイル名> 関数名(行番号) メッセージの文字列にします。
    String^ log = String::Format("{0} {1}({2}) {3}", gcnew String(file), gcnew String(func), line, message);

    //// ログをコンソールに出力します。
    //Debug::WriteLine(log);

    CLog::FileExport(msclr::interop::marshal_as<std::string>(log), "C:\\Users\\wanarisu\\Documents\\cpp.log");
}

void CLog::FileExport(std::string str, std::string path) {
    std::ofstream outputfile(path);
    outputfile << str.c_str();
    outputfile.close();
}
