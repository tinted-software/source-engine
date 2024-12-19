//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#include "c_te_effect_dispatch.h"
#include "fx.h"
#include "particles_localspace.h"
#include "particles_simple.h"

class CMuzzleFlashEmitter_1stPerson : public CLocalSpaceEmitter {
public:
  DECLARE_CLASS(CMuzzleFlashEmitter_1stPerson, CLocalSpaceEmitter);

  static CSmartPtr<CMuzzleFlashEmitter_1stPerson>
  Create(const char *pDebugName, int entIndex, int nAttachment, int fFlags = 0);

  virtual void Update(float t) { BaseClass::Update(t); }

protected:
  CMuzzleFlashEmitter_1stPerson(const char *pDebugName);

private:
  CMuzzleFlashEmitter_1stPerson(const CMuzzleFlashEmitter_1stPerson &);

  int m_iMuzzleFlashType;
};