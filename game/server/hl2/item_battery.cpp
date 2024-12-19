//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Handling for the suit batteries.
//
// $NoKeywords: $
//=============================================================================//

#include "basecombatweapon.h"
#include "cbase.h"
#include "engine/IEngineSound.h"
#include "gamerules.h"
#include "hl2_player.h"
#include "items.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CItemBattery : public CItem {
public:
  DECLARE_CLASS(CItemBattery, CItem);

  void Spawn(void) {
    Precache();
    SetModel("models/items/battery.mdl");
    BaseClass::Spawn();
  }
  void Precache(void) {
    PrecacheModel("models/items/battery.mdl");

    PrecacheScriptSound("ItemBattery.Touch");
  }
  bool MyTouch(CBasePlayer *pPlayer) {
    CHL2_Player *pHL2Player = dynamic_cast<CHL2_Player *>(pPlayer);
    return (pHL2Player && pHL2Player->ApplyBattery());
  }
};

LINK_ENTITY_TO_CLASS(item_battery, CItemBattery);
PRECACHE_REGISTER(item_battery);
