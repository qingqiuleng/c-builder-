//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TeacherMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pngimage"
#pragma link "RzLabel"
#pragma link "RzBmpBtn"
#pragma link "RzEdit"
#pragma link "RzPanel"
#pragma link "FrameItem"
#pragma resource "*.dfm"
TFormTeacherMessage *FormTeacherMessage;
//---------------------------------------------------------------------------
__fastcall TFormTeacherMessage::TFormTeacherMessage(TComponent* Owner)
    : TForm(Owner)
{
    m_pMessageList = new TList();
}
//---------------------------------------------------------------------------
void __fastcall TFormTeacherMessage::lblTitleMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ReleaseCapture();
    SendMessage(this->Handle,WM_NCLBUTTONDOWN,HTCAPTION,0);
}
//---------------------------------------------------------------------------
void __fastcall TFormTeacherMessage::LbCloseClick(TObject *Sender)
{
    this->Hide();    
}
//---------------------------------------------------------------------------
void __fastcall TFormTeacherMessage::btnokClick(TObject *Sender)
{
    //添加信息
    if(NULL == FormAddTeacher)
    {
        Application->CreateForm(__classid(TFormAddTeacher), &FormAddTeacher);
    }
    FormAddTeacher->Top = this->Top + (this->Height - FormAddTeacher->Height)/2;
    FormAddTeacher->Left = this->Left + (this->Width - FormAddTeacher->Width)/2;
    FormAddTeacher->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormTeacherMessage::FormShow(TObject *Sender)
{
    //展示
    ST_VECT_MESSAGE* teacherList = new ST_VECT_MESSAGE();
    if(!pdataDBManager)
    {
        pdataDBManager = new dataDBManager();
    }

    TFrameMessage* pFrameMessage;
    pdataDBManager->GetTeacher(teacherList);
    unsigned int size = teacherList->size();
    int nTop = 0;
    for(unsigned int i=0 ; i<size; i++)
    {
        teacherMessage info = teacherList->at(i);
        pFrameMessage = getFrameItem(i);

        
        pFrameMessage->Parent = TFrameItemCom1->LbDishesItemBackground;
        //pFrameMessage->setItemInfo(info,i);

        pFrameMessage->Top = nTop;
        nTop += pFrameMessage->Height;
    }


}
//---------------------------------------------------------------------------

TFrameMessage* TFormTeacherMessage::getFrameItem(int idx)
{
    if(idx < m_pMessageList->Count)
    {
        return reinterpret_cast<TFrameMessage *>(m_pMessageList->Items[idx]);
    }
    else
    {
        TFrameMessage *pLbitemes = new TFrameMessage(NULL);
        pLbitemes->Name = AnsiString("LbOrder_") + IntToStr(idx);
        m_pMessageList->Add(pLbitemes);

        return pLbitemes;
    }
}

