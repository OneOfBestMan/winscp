//---------------------------------------------------------------------------
#ifndef CustomWinConfigurationH
#define CustomWinConfigurationH
//---------------------------------------------------------------------------
#include "GUIConfiguration.h"
//---------------------------------------------------------------------------
#define WM_LOCALE_CHANGE (WM_USER + 1)
//---------------------------------------------------------------------------
class TCustomWinConfiguration : public TGUIConfiguration
{
static const int MaxHistoryCount = 50;
private:
  TLogView FLogView;
  TInterface FInterface;
  bool FShowAdvancedLoginOptions;
  TStringList * FHistory;
  TStrings * FEmptyHistory;

  void __fastcall SetInterface(TInterface value);
  void __fastcall SetLogView(TLogView value);
  void __fastcall SetShowAdvancedLoginOptions(bool value);
  void __fastcall SetHistory(const AnsiString Index, TStrings * value);
  TStrings * __fastcall GetHistory(const AnsiString Index);

protected:
  virtual void __fastcall SaveSpecial(THierarchicalStorage * Storage);
  virtual void __fastcall LoadSpecial(THierarchicalStorage * Storage);
  virtual void __fastcall ModifyAll();
  void __fastcall ClearHistory();

public:
  __fastcall TCustomWinConfiguration();
  virtual __fastcall ~TCustomWinConfiguration();
  virtual void __fastcall Default();

  __property TLogView LogView = { read = FLogView, write = SetLogView };
  __property TInterface Interface = { read = FInterface, write = SetInterface };
  __property bool ShowAdvancedLoginOptions = { read = FShowAdvancedLoginOptions, write = SetShowAdvancedLoginOptions};
  __property TStrings * History[AnsiString Name] = { read = GetHistory, write = SetHistory };
};
//---------------------------------------------------------------------------
#define CustomWinConfiguration \
  (dynamic_cast<TCustomWinConfiguration *>(Configuration))
//---------------------------------------------------------------------------
#endif
