//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#include "portal_weapon_parse.h"
#include "ammodef.h"
#include "cbase.h"
#include <KeyValues.h>

FileWeaponInfo_t *CreateWeaponInfo() { return new CPortalSWeaponInfo; }

CPortalSWeaponInfo::CPortalSWeaponInfo() { m_iPlayerDamage = 0; }

void CPortalSWeaponInfo::Parse(KeyValues *pKeyValuesData,
                               const char *szWeaponName) {
  BaseClass::Parse(pKeyValuesData, szWeaponName);

  m_iPlayerDamage = pKeyValuesData->GetInt("damage", 0);
}
