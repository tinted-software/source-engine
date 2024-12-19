//========= Copyright Valve Corporation, All rights reserved. ============//
//
// A general list element for the MDL pipeline
//
//===========================================================================//

#include "mdlobjects/dmemdllist.h"
#include "datamodel/dmelementfactoryhelper.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// Expose this class to the scene database
//-----------------------------------------------------------------------------
IMPLEMENT_ELEMENT_FACTORY(DmeMdlList, CDmeMdlList);

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void CDmeMdlList::OnConstruction() {}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void CDmeMdlList::OnDestruction() {}
