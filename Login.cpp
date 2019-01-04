//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzPanel"
#pragma link "pngimage"
#pragma link "RzLabel"
#pragma link "RzEdit"
#pragma link "RzBmpBtn"
#pragma resource "*.dfm"
TFormLogin *FormLogin;
//---------------------------------------------------------------------------
__fastcall TFormLogin::TFormLogin(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::LbCloseClick(TObject *Sender)
{
    this->Hide();    
}
//---------------------------------------------------------------------------

void __fastcall TFormLogin::lblTitleMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(this->Handle,WM_NCLBUTTONDOWN,HTCAPTION,0);
}
//---------------------------------------------------------------------------

void __fastcall TFormLogin::lblTip2Click(TObject *Sender)
{
    //ע��
    if(NULL == FormRegister)
    {
        Application->CreateForm(__classid(TFormRegister), &FormRegister);
    }
    FormRegister->Top = this->Top + (this->Height - FormRegister->Height)/2;
    FormRegister->Left = this->Left + (this->Width - FormRegister->Width)/2;
    FormRegister->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormLogin::FormCreate(TObject *Sender)
{
    //���ݿ⽨��
    AnsiString datapath = ExtractFilePath(Application->ExeName)+"data\\";
    if (!DirectoryExists(datapath))
    {
        CreateDir(datapath);
    }
    if(!pdataDBManager)
    {
        pdataDBManager = new dataDBManager();
    }
    pdataDBManager->dataDBManagerInt();
}
//---------------------------------------------------------------------------

void __fastcall TFormLogin::btnokClick(TObject *Sender)
{
    //��¼
    AnsiString Acount = edtCount->Text;
    AnsiString Password = edtpassword->Text;
    if(!pdataDBManager)
    {
        pdataDBManager = new dataDBManager();
    }

    if(pdataDBManager->isHaveCount(Acount,Password)) //�ɹ���¼
    {
        //��ʦ���Ϲ������
        if(NULL == FormTeacherMessage)
        {
            Application->CreateForm(__classid(TFormTeacherMessage), &FormTeacherMessage);
        }
        FormTeacherMessage->Top = this->Top + (this->Height - FormTeacherMessage->Height)/2;
        FormTeacherMessage->Left = this->Left + (this->Width - FormTeacherMessage->Width)/2;
        FormTeacherMessage->Show();
    }
    else
    {
        this->lblTip->Caption = "��¼ʧ��,�����˺ź�����";
    }
}
//---------------------------------------------------------------------------

