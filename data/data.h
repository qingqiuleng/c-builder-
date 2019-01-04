//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef dataH
#define dataH
#include "sqlite3.h"
#include "TeacherMessage.h"
#include <classes.hpp>
#include <vector>
#include <string>
#include <stdio.h>
#include <windows.h>

typedef struct _teacherMessage //教师信息结构
{
   AnsiString Num;
   AnsiString Name;
   AnsiString Position;
   AnsiString Sex;
   AnsiString Class1;
   AnsiString Class2;
   AnsiString Class3;
   AnsiString Grade;
}teacherMessage;
typedef std::vector<teacherMessage> ST_VECT_MESSAGE;

class dataDBManager
{
    public:
    dataDBManager();
    ~dataDBManager(){};
    void dataDBManagerInt();
    void CreateCountTable();
    void CreateTeacherTable();
    AnsiString MbcsToUtf8(const char *file);
    bool InsertCount(AnsiString& count, AnsiString& password);
    bool isHaveCount(AnsiString& count, AnsiString& password);
    bool InsertTeacher(AnsiString& Num, AnsiString& Name, AnsiString& Position,
        AnsiString& Sex, AnsiString& Class1, AnsiString& Class2, AnsiString& Class3, AnsiString& Grade);
    bool GetTeacher(ST_VECT_MESSAGE* teacherList);
    sqlite3* sl3;
    sqlite3_stmt* m_pStmt;
};
extern PACKAGE dataDBManager *pdataDBManager;
//---------------------------------------------------------------------------
#endif
