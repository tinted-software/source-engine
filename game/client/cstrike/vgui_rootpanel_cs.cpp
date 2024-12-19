//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================//
#include "c_csrootpanel.h"
#include "cbase.h"
#include "ienginevgui.h"
#include "vgui_int.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

C_CSRootPanel *g_pCSRootPanel = NULL;

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void VGUI_CreateClientDLLRootPanel(void) {
  g_pCSRootPanel = new C_CSRootPanel(enginevgui->GetPanel(PANEL_CLIENTDLL));
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void VGUI_DestroyClientDLLRootPanel(void) {
  delete g_pCSRootPanel;
  g_pCSRootPanel = NULL;
}

//-----------------------------------------------------------------------------
// Purpose: Game specific root panel
// Output : vgui::Panel
//-----------------------------------------------------------------------------
vgui::VPANEL VGui_GetClientDLLRootPanel(void) {
  return g_pCSRootPanel->GetVPanel();
}