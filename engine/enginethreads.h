//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================

#ifndef ENGINETHREADS_H
#define ENGINETHREADS_H

#include "const.h"
#include "tier0/threadtools.h"

#if defined(_WIN32)
#pragma once
#endif

#ifdef SOURCE_MT

extern bool g_bThreadedEngine;
extern int g_nMaterialSystemThread;
extern int g_nServerThread;

#define IsEngineThreaded() (g_bThreadedEngine)

#else

#define IsEngineThreaded() (false)

#endif

#endif // ENGINETHREADS_H
