//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $Workfile:     $
// $NoKeywords: $
//=============================================================================//

#if defined(_WIN32) && !defined(_X360)
#define WIN32_LEAN_AND_MEAN
// 0x0601 gives us access to Windows 7 features. We have to be careful not to
// depend on these features because we still support Windows XP.
#define _WIN32_WINNT 0x0601
#include <assert.h>
#include <windows.h>
#endif

// tier0
#include "tier0/basetypes.h"
#include "tier0/dbg.h"
#include "tier0/dbgflag.h"
#ifdef STEAM
#include "tier0/memhook.h"
#endif
#include "tier0/validator.h"

// First include standard libraries
#include "tier0/valve_off.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#ifdef OSX
#include <malloc/malloc.h>
#else
#include <malloc.h>
#endif
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <memory.h>

#include "tier0/valve_minmax_off.h" // GCC 4.2.2 headers screw up our min/max defs.
#include "tier0/valve_minmax_on.h" // GCC 4.2.2 headers screw up our min/max defs.
#include <map>

#include <stddef.h>
#ifdef POSIX
#include <ctype.h>
#include <limits.h>
#define _MAX_PATH PATH_MAX
#endif

#include "tier0/valve_on.h"
