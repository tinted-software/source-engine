//========= Copyright � 1996-2005, Valve Corporation, All rights reserved.
//============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//

#if !defined(CVAR_H)
#define CVAR_H
#ifdef _WIN32
#pragma once
#endif

#include "icvar.h"
#include "vstdlib/vstdlib.h"

//-----------------------------------------------------------------------------
// Returns a CVar dictionary for tool usage
//-----------------------------------------------------------------------------
VSTDLIB_INTERFACE CreateInterfaceFn VStdLib_GetICVarFactory();

#endif // CVAR_H
