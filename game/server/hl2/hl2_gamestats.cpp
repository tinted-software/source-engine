//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================

#include "hl2_gamestats.h"
#include "achievementmgr.h"
#include "cbase.h"

static CHL2GameStats s_HL2GameStats;

CHL2GameStats::CHL2GameStats(void) { gamestats = &s_HL2GameStats; }
