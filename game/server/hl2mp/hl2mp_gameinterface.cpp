//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#include "hl2mp_gameinterface.h"
#include "cbase.h"
#include "gameinterface.h"
#include "mapentities.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// --------------------------------------------------------------------------------------------
// // Mod-specific CServerGameClients implementation.
// --------------------------------------------------------------------------------------------
// //

void CServerGameClients::GetPlayerLimits(int &minplayers, int &maxplayers,
                                         int &defaultMaxPlayers) const {
  minplayers = defaultMaxPlayers = 2;
  maxplayers = 16;
}

// --------------------------------------------------------------------------------------------
// // Mod-specific CServerGameDLL implementation.
// --------------------------------------------------------------------------------------------
// //

void CServerGameDLL::LevelInit_ParseAllEntities(const char *pMapEntities) {}
