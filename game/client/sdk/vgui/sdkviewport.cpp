//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Client DLL VGUI2 Viewport
//
// $Workfile:     $
// $Date:         $
//
//-----------------------------------------------------------------------------
// $Log: $
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"

#pragma warning(                                                               \
    disable : 4800) // disable forcing int to bool performance warning

// VGUI panel includes
#include <KeyValues.h>
#include <vgui/Cursor.h>
#include <vgui/ILocalize.h>
#include <vgui/IScheme.h>
#include <vgui/ISurface.h>
#include <vgui/IVGui.h>
#include <vgui/VGUI.h>
#include <vgui_controls/Panel.h>

// client dll/engine defines
#include "hud.h"
#include <voice_status.h>

// viewport definitions
#include "SDKViewport.h"
#include <baseviewport.h>

#include "text_message.h"
#include "vguicenterprint.h"

void SDKViewport::ApplySchemeSettings(vgui::IScheme *pScheme) {
  BaseClass::ApplySchemeSettings(pScheme);

  gHUD.InitColors(pScheme);

  SetPaintBackgroundEnabled(false);
}

IViewPortPanel *SDKViewport::CreatePanelByName(const char *szPanelName) {
  IViewPortPanel *newpanel = NULL;

  // Up here, strcmp against each type of panel we know how to create.
  //	else if ( Q_strcmp(PANEL_OVERVIEW, szPanelName) == 0 )
  //	{
  //		newpanel = new CCSMapOverview( this );
  //	}

  // create a generic base panel, don't add twice
  newpanel = BaseClass::CreatePanelByName(szPanelName);

  return newpanel;
}

void SDKViewport::CreateDefaultPanels(void) {
  BaseClass::CreateDefaultPanels();
}

int SDKViewport::GetDeathMessageStartHeight(void) {
  int x = YRES(2);

  IViewPortPanel *spectator =
      gViewPortInterface->FindPanelByName(PANEL_SPECGUI);

  // TODO: Link to actual height of spectator bar
  if (spectator && spectator->IsVisible()) {
    x += YRES(52);
  }

  return x;
}
