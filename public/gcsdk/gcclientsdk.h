//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: includes all the headers required for the cliend side of the GC
//			SDK GC SDK. Include this in your stdafx.h
//
//=============================================================================

#ifndef GCCLIENTSDK_H
#define GCCLIENTSDK_H
#ifdef _WIN32
#pragma once
#endif

#include "gcsteamdefines.h"
#include "steam/steamtypes.h"
#include "tier0/platform.h"

#include "tier0/dbg.h"
#include "tier0/fasttimer.h"
#include "tier0/t0constants.h"
#include "tier0/vprof.h"

#include "tier1/checksum_crc.h"
#include "tier1/fmtstr.h"
#include "tier1/mempool.h"
#include "tier1/tsmempool.h"
#include "tier1/tsmultimempool.h"
#include "tier1/utlbuffer.h"
#include "tier1/utllinkedlist.h"
#include "tier1/utlmap.h"
#include "tier1/utlpriorityqueue.h"
#include "tier1/utlstring.h"

#include "vstdlib/coroutine.h"

// public stuff
#include "misc.h"
#include "steam/isteamclient.h"
#include "steam/isteamgamecoordinator.h"
#include "steam/steam_api.h"
#include "steam/steamclientpublic.h"

// stuff to include early because it is widely depended on
#include "gcconstants.h"
#include "gcmsg.h"
#include "msgprotobuf.h"
#include "netpacket.h"
#include "refcount.h"

#include "gcclient.h"
#include "gcclient_sharedobjectcache.h"
#include "gcclientjob.h"
#include "gclogger.h"
#include "gcsystemmsgs.h"
#include "job.h"
#include "jobmgr.h"
#include "jobtime.h"
#include "messagelist.h"
#include "netpacketpool.h"
#include "protobufsharedobject.h"
#include "sharedobject.h"
#include "sharedobjectcache.h"

#include "webapi_response.h"

#endif // GCCLIENTSDK_H
