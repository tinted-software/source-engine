//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Dme body part base class
//
//===========================================================================//

#include "mdlobjects/dmebodypart.h"
#include "datamodel/dmelementfactoryhelper.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// Expose this class to the scene database
//-----------------------------------------------------------------------------
IMPLEMENT_ELEMENT_FACTORY(DmeBodyPart, CDmeBodyPart);

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void CDmeBodyPart::OnConstruction() {}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void CDmeBodyPart::OnDestruction() {}