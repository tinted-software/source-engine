//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//===========================================================================//
#include "clientmode_sdk.h"
#include "buymenu.h"
#include "c_playerresource.h"
#include "cbase.h"
#include "cdll_client_int.h"
#include "dlight.h"
#include "filesystem.h"
#include "hud.h"
#include "hud_chat.h"
#include "iefx.h"
#include "iinput.h"
#include "ivmodemanager.h"
#include "ivrenderview.h"
#include "model_types.h"
#include "panelmetaclassmgr.h"
#include "text_message.h"
#include "vgui/IPanel.h"
#include "vgui/ISurface.h"
#include "vgui/IVGui.h"
#include "view.h"
#include "view_shared.h"
#include <KeyValues.h>
#include <imapoverview.h>
#include <vgui_controls/AnimationController.h>

ConVar default_fov("default_fov", "90", FCVAR_CHEAT);

IClientMode *g_pClientMode = NULL;

// ---------------------------------------------------------------------------------
// // CSDKModeManager.
// ---------------------------------------------------------------------------------
// //

class CSDKModeManager : public IVModeManager {
public:
  virtual void Init();
  virtual void SwitchMode(bool commander, bool force) {}
  virtual void LevelInit(const char *newmap);
  virtual void LevelShutdown(void);
  virtual void ActivateMouse(bool isactive) {}
};

static CSDKModeManager g_ModeManager;
IVModeManager *modemanager = (IVModeManager *)&g_ModeManager;

// ---------------------------------------------------------------------------------
// // CSDKModeManager implementation.
// ---------------------------------------------------------------------------------
// //

#define SCREEN_FILE "scripts/vgui_screens.txt"

void CSDKModeManager::Init() {
  g_pClientMode = GetClientModeNormal();

  PanelMetaClassMgr()->LoadMetaClassDefinitionFile(SCREEN_FILE);
}

void CSDKModeManager::LevelInit(const char *newmap) {
  g_pClientMode->LevelInit(newmap);
}

void CSDKModeManager::LevelShutdown(void) { g_pClientMode->LevelShutdown(); }

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
ClientModeSDKNormal::ClientModeSDKNormal() {}

//-----------------------------------------------------------------------------
// Purpose: If you don't know what a destructor is by now, you are probably
// going to get fired
//-----------------------------------------------------------------------------
ClientModeSDKNormal::~ClientModeSDKNormal() {}

void ClientModeSDKNormal::InitViewport() {
  m_pViewport = new SDKViewport();
  m_pViewport->Start(gameuifuncs, gameeventmanager);
}

ClientModeSDKNormal g_ClientModeNormal;

IClientMode *GetClientModeNormal() { return &g_ClientModeNormal; }

ClientModeSDKNormal *GetClientModeSDKNormal() {
  Assert(dynamic_cast<ClientModeSDKNormal *>(GetClientModeNormal()));

  return static_cast<ClientModeSDKNormal *>(GetClientModeNormal());
}

float ClientModeSDKNormal::GetViewModelFOV(void) { return 74.0f; }

int ClientModeSDKNormal::GetDeathMessageStartHeight(void) {
  return m_pViewport->GetDeathMessageStartHeight();
}

void ClientModeSDKNormal::PostRenderVGui() {}
