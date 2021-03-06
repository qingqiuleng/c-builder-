//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Login.cpp", FormLogin);
USEFORM("RegisterAcount.cpp", FormRegister);
USEFORM("form\TeacherMessage.cpp", FormTeacherMessage);
USEFORM("form\FrameTeacherMessage.cpp", FrameMessage); /* TFrame: File Type */
USEFORM("form\AddTeacherMessage.cpp", FormAddTeacher);
USEFORM("form\FrameItem.cpp", FrameItemCom); /* TFrame: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        AnsiString name = Application->ExeName;
        AnsiString from = "\\";
        AnsiString to = "|";
        AnsiString check = StringReplace(name,from,to,TReplaceFlags() <<rfReplaceAll << rfIgnoreCase);
        HANDLE hMutex = ::CreateMutex(NULL, FALSE, check.c_str());
        if (GetLastError() == ERROR_ALREADY_EXISTS)
        {
            return FALSE;
        }
         Application->Initialize();
         Application->CreateForm(__classid(TFormLogin), &FormLogin);
         Application->CreateForm(__classid(TFormRegister), &FormRegister);
         Application->CreateForm(__classid(TFormTeacherMessage), &FormTeacherMessage);
         Application->CreateForm(__classid(TFormAddTeacher), &FormAddTeacher);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------
