//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddTeacherMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzEdit"
#pragma link "RzLabel"
#pragma link "RzPanel"
#pragma link "pngimage"
#pragma link "RzBmpBtn"
#pragma resource "*.dfm"
TFormAddTeacher *FormAddTeacher;
//---------------------------------------------------------------------------
__fastcall TFormAddTeacher::TFormAddTeacher(TComponent* Owner)
    : TForm(Owner)
{
    initComboBox1();
}
//---------------------------------------------------------------------------
void __fastcall TFormAddTeacher::lblcloseClick(TObject *Sender)
{
    this->Hide();    
}
//---------------------------------------------------------------------------
void __fastcall TFormAddTeacher::lbltiltleMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(this->Handle,WM_NCLBUTTONDOWN,HTCAPTION,0);
}
//---------------------------------------------------------------------------

void __fastcall TFormAddTeacher::initComboBox1()
{
    AnsiString str = "男";
    ComboBox1->Items->Add(str);
    str = "女";
    ComboBox1->Items->Add(str);
    str = "其他";
    ComboBox1->Items->Add(str);
}
void __fastcall TFormAddTeacher::btnokClick(TObject *Sender)
{
    //新增一条教师信息
    AnsiString Num = edtNum->Text;
    AnsiString Name = edtName->Text;
    AnsiString Position = edtPosition->Text;
    AnsiString Sex = ComboBox1->Text;
    AnsiString Class1 = edtClass1->Text;
    AnsiString Class2 = edtClass2->Text;
    AnsiString Class3 = edtClass3->Text;
    AnsiString Grade = edtGrade->Text;

    if(!pdataDBManager)
    {
        pdataDBManager = new dataDBManager();
    }

    if(pdataDBManager->InsertTeacher(Num,Name,Position,Sex,Class1,Class2,Class3,Grade)) //成功新增
    {
        this->Hide();
    }
    else
    {
        lbltip->Caption = "新增失败,请重试";
    }
}
//---------------------------------------------------------------------------

