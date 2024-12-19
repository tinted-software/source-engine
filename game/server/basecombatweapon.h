//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $Workfile:     $
// $NoKeywords: $
//=============================================================================//

#ifndef COMBATWEAPON_H
#define COMBATWEAPON_H
#ifdef _WIN32
#pragma once
#endif

#include "basecombatweapon_shared.h"
#include "entityoutput.h"

//-----------------------------------------------------------------------------
// Bullet types
//-----------------------------------------------------------------------------

// -----------------------------------------
//	Sounds
// -----------------------------------------

struct animevent_t;

extern void SpawnBlood(Vector vecSpot, const Vector &vecDir, int bloodColor,
                       float flDamage);

#endif // COMBATWEAPON_H
