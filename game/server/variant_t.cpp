//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#include "variant_t.h"
#include "cbase.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

void variant_t::SetEntity(CBaseEntity *val) {
  eVal = val;
  fieldType = FIELD_EHANDLE;
}
