//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//
/*

===== h_export.cpp ========================================================

  Entity classes exported by Halflife.

*/

#if defined(_WIN32) && !defined(_XBOX)

#include "datamap.h"
#include "tier0/dbg.h"
#include "winlite.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

HMODULE win32DLLHandle;

// Required DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  // ensure data sizes are stable
  if (sizeof(inputfunc_t) != sizeof(uintp)) {
    Assert(sizeof(inputfunc_t) == sizeof(uintp));
    return FALSE;
  }

  if (fdwReason == DLL_PROCESS_ATTACH) {
    win32DLLHandle = hinstDLL;
  } else if (fdwReason == DLL_PROCESS_DETACH) {
  }
  return TRUE;
}

#endif
