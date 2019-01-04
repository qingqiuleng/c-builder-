//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RzPanel.hpp"
#include <ExtCtrls.hpp>
#include "pngimage.hpp"
#include "RzLabel.hpp"
#include "RzEdit.hpp"
#include <Mask.hpp>
#include "RzBmpBtn.hpp"
#include "RegisterAcount.h"
#include "data.h"
#include "TeacherMessage.h"
//---------------------------------------------------------------------------
class TFormLogin : public TForm
{
__published:	// IDE-managed Components
    TRzPanel *DishClassInfo;
    TImage *ImTBg;
    TRzLabel *LbClose;
    TRzLabel *lblTitle;
    TRzLabel *lblTitle1;
    TRzLabel *lblTitle2;
    TRzLabel *lblCount;
    TRzEdit *edtCount;
    TRzLabel *lblpassword;
    TRzEdit *edtpassword;
    TRzBmpButton *btnok;
    TRzBmpButton *btnno;
    TRzLabel *lblTip1;
    TRzLabel *lblTip2;
    TRzLabel *lblTip;
    void __fastcall LbCloseClick(TObject *Sender);
    void __fastcall lblTitleMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall lblTip2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnokClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogin *FormLogin;
//---------------------------------------------------------------------------
#endif
