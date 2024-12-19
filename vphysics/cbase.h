//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//
// system
#include <stdio.h>
#ifdef _XBOX
#include <ctype.h>
#endif

// Valve
#include "commonmacros.h"
#include "convert.h"
#include "mathlib/mathlib.h"
#include "mathlib/vector.h"
#include "tier0/dbg.h"
#include "utlvector.h"

// vphysics
#include "physics_environment.h"
#include "physics_material.h"
#include "physics_object.h"
#include "vphysics_interface.h"
#include "vphysics_internal.h"
#include "vphysics_saverestore.h"

// ivp
#include "ivp_core.hxx"
#include "ivp_physics.hxx"
#include "ivp_templates.hxx"

// havok