//========= Copyright © 1996-2005, Valve Corporation, All rights reserved.
//============//
//
// Purpose:
//
// $Workfile:     $
// $NoKeywords: $
//===========================================================================//

#if defined(PLATFORM_WINDOWS_PC)
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0403
#include <windows.h>
#elif defined(_PS3)
#include <cellstatus.h>
#include <sys/prx.h>
#endif

#include "tier0/platform.h"

// First include standard libraries
#include "tier0/valve_off.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#include <stddef.h>
#ifdef PLATFORM_POSIX
#include <ctype.h>
#include <limits.h>
#include <unistd.h>
#define _MAX_PATH PATH_MAX
#endif

#include "tier0/valve_on.h"

#include "tier0/basetypes.h"
#include "tier0/dbg.h"
#include "tier0/dbgflag.h"
#ifdef STEAM
#include "tier0/memhook.h"
#endif
#include "tier0/fasttimer.h"
#include "tier0/validator.h"
