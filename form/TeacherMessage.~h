//---------------------------------------------------------------------------

#ifndef TeacherMessageH
#define TeacherMessageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "pngimage.hpp"
#include "RzLabel.hpp"
#include <ExtCtrls.hpp>
#include "RzBmpBtn.hpp"
#include "RzEdit.hpp"
#include "RzPanel.hpp"
#include <Mask.hpp>
#include "AddTeacherMessage.h"
#include "FrameItem.h"
#include <classes.hpp>
#include <vector>
#include "FrameTeacherMessage.h"
//---------------------------------------------------------------------------
class TFormTeacherMessage : public TForm
{
__published:	// IDE-managed Components
    TRzPanel *DishClassInfo;
    TImage *imgBG;
    TRzLabel *lblclose;
    TRzLabel *lbltiltle;
    TRzLabel *lblTip;
    TRzBmpButton *btnok;
    TRzBmpButton *btnno;
    TRzPanel *LbDishesItemBackground;
    TRzLabel *lblline1;
    TRzLabel *lblline2;
    TRzLabel *lblline3;
    TRzLabel *lblline4;
    TRzLabel *lblline5;
    TRzLabel *lblLineDown;
    TRzLabel *lblline6;
    TRzLabel *lblline8;
    TRzLabel *lblNum;
    TRzLabel *lblPosition;
    TRzLabel *lblSex;
    TRzLabel *lblClass1;
    TRzLabel *lblClass3;
    TRzLabel *lblline7;
    TRzLabel *lblClass2;
    TRzLabel *lblline9;
    TRzLabel *lblGrade;
    TRzLabel *lblName;
    TRzLabel *lblLineUp;
    TRzLabel *lblline10;
    TRzLabel *lblOperate;
    TFrameItemCom *TFrameItemCom1;
    void __fastcall lblTitleMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall LbCloseClick(TObject *Sender);
    void __fastcall btnokClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
public:
    TFrameMessage* getFrameItem(int idx);
private:	// User declarations
    TList*  m_pMessageList;
public:		// User declarations
    __fastcall TFormTeacherMessage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTeacherMessage *FormTeacherMessage;
//---------------------------------------------------------------------------
#endif
