//---------------------------------------------------------------------------
#pragma hdrstop

#include "data.h"
#define DATA_INFO_DBNAME       "\\dataInfo.db3"
#define DATA_INFO_COUNTTABLE       "datacountInfo"
#define DATA_INFO_TEACHERTABLE       "datateacherInfo"
#define DIV_CHAR ","
#define SINGLE_MARK "\'"
dataDBManager *pdataDBManager = NULL;
dataDBManager::dataDBManager()
{
    sl3 = NULL;
    m_pStmt = NULL;
    AnsiString datapath = ExtractFilePath(Application->ExeName)+"data";
    datapath += DATA_INFO_DBNAME;
    AnsiString file = MbcsToUtf8(datapath.c_str());
    int ret = sqlite3_open(file.c_str(),&sl3);
}

void dataDBManager::dataDBManagerInt()
{
    CreateCountTable();  //创建账号表
    CreateTeacherTable(); //创建老师表
}


void dataDBManager::CreateCountTable()
{
    AnsiString sqlStr = "";

    sqlStr = "CREATE TABLE ";
    sqlStr += DATA_INFO_COUNTTABLE;
    sqlStr += " ( id INTEGER PRIMARY KEY autoincrement,\
                aount TEXT,\
                password TEXT,\
                UNIQUE (aount));";
    sqlite3_exec(sl3,sqlStr.c_str(), NULL, NULL, NULL);
}

void dataDBManager::CreateTeacherTable()
{
    AnsiString sqlStr = "";

    sqlStr = "CREATE TABLE ";
    sqlStr += DATA_INFO_TEACHERTABLE;
    sqlStr += " ( id INTEGER PRIMARY KEY autoincrement,\
                teacherNo TEXT,\
                teacherName TEXT,\
                teacherPosition TEXT,\
                teacherSex TEXT,\
                class1 TEXT,\
                class2 TEXT,\
                class3 TEXT,\
                grade TEXT,\
                UNIQUE (teacherNo));";
    sqlite3_exec(sl3,sqlStr.c_str(), NULL, NULL, NULL);
}

bool dataDBManager::InsertCount(AnsiString& count, AnsiString& password)
{
    AnsiString sqlStr="REPLACE INTO ";
    sqlStr+=DATA_INFO_COUNTTABLE;

    sqlStr+=" (id,aount,password) VALUES (NULL,";
    sqlStr+=SINGLE_MARK + count + SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + password+ SINGLE_MARK;
    sqlStr+=");";

    int ret = sqlite3_exec(sl3,sqlStr.c_str(), NULL, NULL, NULL);
    if(ret == 0)
    {
        return true;
    }
    return  False;
}

bool dataDBManager::isHaveCount(AnsiString& count, AnsiString& password)
{
    AnsiString sqlStr="SELECT COUNT(*) FROM ";
    sqlStr+=DATA_INFO_COUNTTABLE;

    sqlStr += " WHERE aount='" + count + "' and password='" +password +"';";
    int ret = sqlite3_prepare_v2(sl3,sqlStr.c_str(),-1,&m_pStmt,0);
    int ret1 = sqlite3_column_int(m_pStmt,0);
    while (sqlite3_step(m_pStmt) == SQLITE_ROW)
    {
        int i = sqlite3_column_int(m_pStmt, 0);
        if(i == 1) //查到有此账号和密码
        {
            return true;
        }
    }
    return  False;
}

bool dataDBManager::InsertTeacher(AnsiString& Num, AnsiString& Name, AnsiString& Position,
    AnsiString& Sex, AnsiString& Class1, AnsiString& Class2, AnsiString& Class3, AnsiString& Grade) //插入教师信息
{
    AnsiString sqlStr="REPLACE INTO ";
    sqlStr+=DATA_INFO_TEACHERTABLE;

    sqlStr+=" (id,teacherNo,teacherName,teacherPosition,teacherSex,class1,class2,class3,grade) VALUES (NULL,";
    sqlStr+=SINGLE_MARK + Num + SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Name+ SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Position + SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Sex+ SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Class1 + SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Class2+ SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Class3 + SINGLE_MARK + DIV_CHAR;
    sqlStr+=SINGLE_MARK + Grade+ SINGLE_MARK;
    sqlStr+=");";

    AnsiString sqlStr1 = MbcsToUtf8(sqlStr.c_str());
    int ret = sqlite3_exec(sl3,sqlStr1.c_str(), NULL, NULL, NULL);
    if(ret == 0)
    {
        return true;
    }
    return  False;
}

bool dataDBManager::GetTeacher(ST_VECT_MESSAGE* teacherList) //获取教师数据
{
    AnsiString sqlStr="SELECT * FROM ";
    sqlStr+=DATA_INFO_TEACHERTABLE;
    sqlStr += ";";
    int ret = sqlite3_prepare_v2(sl3,sqlStr.c_str(),-1,&m_pStmt,0);
    while (sqlite3_step(m_pStmt) == SQLITE_ROW)
    {
        teacherMessage info;
        char* pstrValue1=(char*)sqlite3_column_text(m_pStmt,1);
        char* pstrValue2=(char*)sqlite3_column_text(m_pStmt,2);
        char* pstrValue3=(char*)sqlite3_column_text(m_pStmt,3);
        char* pstrValue4=(char*)sqlite3_column_text(m_pStmt,4);
        char* pstrValue5=(char*)sqlite3_column_text(m_pStmt,5);
        char* pstrValue6=(char*)sqlite3_column_text(m_pStmt,6);
        char* pstrValue7=(char*)sqlite3_column_text(m_pStmt,7);
        char* pstrValue8=(char*)sqlite3_column_text(m_pStmt,8);
        if(pstrValue1==NULL || pstrValue2==NULL || pstrValue3==NULL || pstrValue4==NULL ||
            pstrValue5==NULL || pstrValue6==NULL || pstrValue7==NULL || pstrValue8==NULL)
        {
            return false;
        }

        info.Num = *pstrValue1;
        info.Name = *pstrValue2;
        info.Position = *pstrValue3;
        info.Sex = *pstrValue4;
        info.Class1 = *pstrValue5;
        info.Class2 = *pstrValue6;
        info.Class3 = *pstrValue7;
        info.Grade = *pstrValue8;

        teacherList->push_back(info);
    }
}

//---------------------------------------------------------------------------
AnsiString dataDBManager::MbcsToUtf8(const char *file)  //转码成utf-8
{
    AnsiString str;
    WCHAR   *pwchar=0;
    CHAR    *pchar=0;
    int len=0;
    int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;
    len=MultiByteToWideChar(codepage, 0, file, -1, NULL,0);
    pwchar=new WCHAR[len];
    if(pwchar!=0)
    {
        len = MultiByteToWideChar(codepage, 0, file, -1, pwchar, len);
        if( len!=0 ) 
        {
            len = WideCharToMultiByte(CP_UTF8, 0, pwchar, -1, 0, 0, 0, 0);
            pchar=new CHAR[len];
            if(pchar!=0)
            {
                len = WideCharToMultiByte(CP_UTF8, 0, pwchar, -1, pchar, len,0, 0);
                if(len!=0)                 
                {
                    str=pchar;                    
                }
                delete pchar;
            }
            delete pwchar; 
        }
    }
    return str;
}

#pragma package(smart_init)





