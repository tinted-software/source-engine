//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================

#ifndef CBASE_H
#define CBASE_H
#ifdef _WIN32
#pragma once
#endif

#ifdef _WIN32
// Silence certain warnings
#pragma warning(disable : 4244) // int or float down-conversion
#pragma warning(disable : 4305) // int or float data truncation
#pragma warning(disable : 4201) // nameless struct/union
#pragma warning(disable : 4511) // copy constructor could not be generated
#pragma warning(disable : 4675) // resolved overload was found by argument
                                // dependent lookup
#pragma warning(disable : 4706) // assignment within conditional expression
#endif

#ifdef _DEBUG
#define DEBUG 1
#endif

// Misc C-runtime library headers
#include "minmax.h"
#include <math.h>
#include <stdio.h>

// tier 0
#include "basetypes.h"
#include "tier0/dbg.h"
#include "tier0/platform.h"

// tier 1
#include "filesystem.h"
#include "mathlib/vmatrix.h"
#include "tier1/strtools.h"
#include "utlvector.h"

#include "icvar.h"
#include "tier1/ConVar.h"

#endif // CBASE_H
