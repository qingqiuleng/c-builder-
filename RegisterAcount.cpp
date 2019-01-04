//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegisterAcount.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pngimage"
#pragma link "RzBmpBtn"
#pragma link "RzEdit"
#pragma link "RzLabel"
#pragma link "RzPanel"
#pragma resource "*.dfm"
TFormRegister *FormRegister;
//---------------------------------------------------------------------------
__fastcall TFormRegister::TFormRegister(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRegister::lblTitleMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(this->Handle,WM_NCLBUTTONDOWN,HTCAPTION,0);
}
//---------------------------------------------------------------------------
void __fastcall TFormRegister::LbCloseClick(TObject *Sender)
{
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormRegister::btnokClick(TObject *Sender)
{
    //ȷ�ϴ���һ���˺�
    AnsiString count = edtCount->Text;
    AnsiString password = edtpassword->Text;
    if(pdataDBManager->InsertCount(count,password))
    {
        this->Hide();
    }
    else
    {
        this->lblTip->Caption = "ע��ʧ��,������";
    }
}
//---------------------------------------------------------------------------
