//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================//

#ifndef BUYMENU_H
#define BUYMENU_H
#ifdef _WIN32
#pragma once
#endif

#include "vgui/KeyCode.h"
#include <game/client/iviewport.h>
#include <vgui_controls/WizardPanel.h>

class CBuySubMenu;

namespace vgui {
class Panel;
}

//-----------------------------------------------------------------------------
// Purpose: Draws the class menu
//-----------------------------------------------------------------------------
class CBuyMenu : public vgui::WizardPanel, public IViewPortPanel {
private:
  DECLARE_CLASS_SIMPLE(CBuyMenu, vgui::WizardPanel);

public:
  CBuyMenu(IViewPort *pViewPort);
  ~CBuyMenu();

  virtual const char *GetName(void) { return PANEL_BUY; }
  virtual void SetData(KeyValues *data) {};
  virtual void Reset() {};
  virtual void Update();
  virtual bool NeedsUpdate(void) { return false; }
  virtual bool HasInputElements(void) { return true; }
  virtual void ShowPanel(bool bShow);

  // both vgui::Frame and IViewPortPanel define these, so explicitly define them
  // here as passthroughs to vgui
  vgui::VPANEL GetVPanel(void) { return BaseClass::GetVPanel(); }
  virtual bool IsVisible() { return BaseClass::IsVisible(); }
  virtual void SetParent(vgui::VPANEL parent) { BaseClass::SetParent(parent); }

  virtual void OnKeyCodePressed(vgui::KeyCode code);
  virtual void OnKeyCodeTyped(vgui::KeyCode code);

  virtual GameActionSet_t GetPreferredActionSet() {
    return GAME_ACTION_SET_MENUCONTROLS;
  }

public:
  virtual void OnClose();

protected:
  CBuySubMenu *m_pMainMenu;
  IViewPort *m_pViewPort;

  int m_iTeam;
  int m_iClass;
};

#endif // BUYMENU_H
