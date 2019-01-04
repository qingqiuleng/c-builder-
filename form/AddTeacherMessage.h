//---------------------------------------------------------------------------

#ifndef AddTeacherMessageH
#define AddTeacherMessageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RzEdit.hpp"
#include "RzLabel.hpp"
#include "RzPanel.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "pngimage.hpp"
#include "RzBmpBtn.hpp"
#include "data.h"
//---------------------------------------------------------------------------
class TFormAddTeacher : public TForm
{
__published:	// IDE-managed Components
    TRzPanel *LbDishesItemBackground;
    TRzLabel *lblline1;
    TRzLabel *lblline2;
    TRzLabel *lblline3;
    TRzLabel *lblline4;
    TRzLabel *lblline5;
    TRzLabel *lblLineDown;
    TRzLabel *lblline6;
    TRzLabel *lblline8;
    TRzLabel *lblline7;
    TRzLabel *lblline9;
    TRzLabel *lblNum;
    TRzLabel *lblName;
    TRzLabel *lblPosition;
    TRzLabel *lblClass2;
    TRzLabel *lblClass3;
    TRzLabel *lblClass1;
    TRzEdit *edtNum;
    TRzEdit *edtName;
    TRzEdit *edtPosition;
    TRzEdit *edtClass2;
    TRzEdit *edtClass3;
    TRzEdit *edtClass1;
    TImage *imgBG;
    TRzLabel *lbltiltle;
    TRzLabel *lblclose;
    TRzLabel *lblUp;
    TRzLabel *lblGrade;
    TRzBmpButton *btnok;
    TRzBmpButton *btnno;
    TComboBox *ComboBox1;
    TRzEdit *edtGrade;
    TRzLabel *lbltip;
    void __fastcall lblcloseClick(TObject *Sender);
    void __fastcall lbltiltleMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall initComboBox1();
    void __fastcall btnokClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormAddTeacher(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAddTeacher *FormAddTeacher;
//---------------------------------------------------------------------------
#endif
