//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#ifndef PORTAL_WEAPON_PARSE_H
#define PORTAL_WEAPON_PARSE_H
#ifdef _WIN32
#pragma once
#endif

#include "networkvar.h"
#include "weapon_parse.h"

//--------------------------------------------------------------------------------------------------------
class CPortalSWeaponInfo : public FileWeaponInfo_t {
public:
  DECLARE_CLASS_GAMEROOT(CPortalSWeaponInfo, FileWeaponInfo_t);

  CPortalSWeaponInfo();

  virtual void Parse(::KeyValues *pKeyValuesData, const char *szWeaponName);

public:
  int m_iPlayerDamage;
};

#endif // PORTAL_WEAPON_PARSE_H
