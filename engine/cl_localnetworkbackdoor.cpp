//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#include "cl_localnetworkbackdoor.h"
#include "LocalNetworkBackdoor.h"
#include "basehandle.h"
#include "client_class.h"
#include "client_pch.h"
#include "dt_localtransfer.h"
#include "iclientnetworkable.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

static CLocalNetworkBackdoor s_LocalNetworkBackdoor;

void CL_SetupLocalNetworkBackDoor(bool bUseBackDoor) {
  if (bUseBackDoor) {
    if (!g_pLocalNetworkBackdoor) {
      // start using local backdoor mode
      g_pLocalNetworkBackdoor = &s_LocalNetworkBackdoor;
      g_pLocalNetworkBackdoor->StartBackdoorMode();
    }
  } else {
    if (g_pLocalNetworkBackdoor) {
      // stop using localbackdooor mode
      g_pLocalNetworkBackdoor->StopBackdoorMode();
      g_pLocalNetworkBackdoor = NULL;
      cl.ForceFullUpdate(); // clear baselines, request full packet update
    }
  }
}
