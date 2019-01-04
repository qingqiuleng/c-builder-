//---------------------------------------------------------------------------

#ifndef RegisterAcountH
#define RegisterAcountH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "pngimage.hpp"
#include "RzBmpBtn.hpp"
#include "RzEdit.hpp"
#include "RzLabel.hpp"
#include "RzPanel.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "data.h"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TFormRegister : public TForm
{
__published:	// IDE-managed Components
    TRzPanel *DishClassInfo;
    TImage *ImTBg;
    TRzLabel *LbClose;
    TRzLabel *lblTitle;
    TRzLabel *lblCount;
    TRzLabel *lblpassword;
    TRzLabel *lblTip1;
    TRzLabel *lblTip2;
    TRzEdit *edtCount;
    TRzEdit *edtpassword;
    TRzBmpButton *btnok;
    TRzBmpButton *btnno;
    TRzLabel *lblTitle2;
    TRzLabel *lblTitle1;
    TRzLabel *lblTip;
    void __fastcall lblTitleMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall LbCloseClick(TObject *Sender);
    void __fastcall btnokClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormRegister(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegister *FormRegister;
//---------------------------------------------------------------------------
#endif
