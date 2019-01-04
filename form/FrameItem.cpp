//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzPanel"
#pragma resource "*.dfm"
TFrameItemCom *FrameItemCom;
//---------------------------------------------------------------------------
__fastcall TFrameItemCom::TFrameItemCom(TComponent* Owner)
    : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
