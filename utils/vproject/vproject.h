//========= Copyright Valve Corporation, All rights reserved. ============//
//
//	VPROJECT.H
//
//	Master Header.
//=====================================================================================//
#pragma once

#include "resource.h"
#include "sys_utils.h"
#include <assert.h>
#include <commctrl.h>
#include <malloc.h>
#include <richedit.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <windows.h>
#include <windowsx.h>
#include <winsock2.h>

#define VPROJECT_VERSION "1.0"
#define VPROJECT_CLASSNAME "VPROJECTCLASS"
#define VPROJECT_TITLE "VProject"
#define VPROJECT_MAGIC "2\\"
#define VPROJECT_REGISTRY                                                      \
  "HKEY_CURRENT_USER\\Software\\VProject\\" VPROJECT_MAGIC
#ifdef _DEBUG
#define VPROJECT_BUILDTYPE "Debug"
#else
#define VPROJECT_BUILDTYPE "Release"
#endif
