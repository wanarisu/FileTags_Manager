#include "SQLite3_Lib.h"

void SQLite3_Lib::SQL_Test()
{
    sqlite3* db = nullptr;
    sqlite3_stmt* stmt = nullptr;

    const char* db_name = "D:\\VisualC\\test.db";

    // If use string type, you should be `db_name.c_str()`
    // stringŒ^‚ðŽg‚¤‚Æ‚«‚Í`db_name.c_str()`‚ðŽg‚Á‚Ä‚­‚¾‚³‚¢
    int ret = sqlite3_open(db_name, &db);
    if (ret != SQLITE_OK)
    {
        printf("%s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    // if type string -> query.c_str()
    const char* query = "select * from test";
    ret = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    if (ret != SQLITE_OK)
    {
        printf("%s", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}