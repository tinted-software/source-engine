//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: includes all the headers required for the GC SDK. Include this
//			in your stdafx.h
//
//=============================================================================

#ifndef GCSDK_H
#define GCSDK_H
#ifdef _WIN32
#pragma once
#endif

#if defined(_WIN32) || defined(_WIN64)
#pragma once
#include <intrin.h>
#pragma intrinsic(_BitScanReverse)
#endif

#include "tier0/platform.h"

#include "gcsteamdefines.h"

#include "steam/steamtypes.h"

#include "tier0/dbg.h"
#ifdef DBGFLAG_VALIDATE
#include "tier0/validator.h"
#endif
#include "tier0/fasttimer.h"
#include "tier0/vprof.h"

// include this before checksum_crc specifically to avoid the
// CRC references
#include "steam/steamclientpublic.h"

#include "tier1/KeyValues.h"
#include "tier1/checksum_crc.h"
#include "tier1/fmtstr.h"
#include "tier1/mempool.h"
#include "tier1/strtools.h"
#include "tier1/tsmempool.h"
#include "tier1/tsmultimempool.h"
#include "tier1/utlbuffer.h"
#include "tier1/utldict.h"
#include "tier1/utlhashmaplarge.h"
#include "tier1/utllinkedlist.h"
#include "tier1/utlmap.h"
#include "tier1/utlpriorityqueue.h"
#include "tier1/utlstring.h"
#include "tier1/utlsymbol.h"
#include "tier1/utlsymbollarge.h"

#include "vstdlib/coroutine.h"
#include "vstdlib/osversion.h"

// public stuff
#include "gamecoordinator/igcsqlresultsetlist.h"
#include "misc.h"

// These are first since they're used all over
#include "gc_convar.h"
#include "gcconstants.h"
#include "gcmsg.h"
#include "msgprotobuf.h"
#include "netpacket.h"
#include "refcount.h"

// SQL Access stuff
#include "sqlaccess/columnset.h"
#include "sqlaccess/record.h"
#include "sqlaccess/recordinfo.h"
#include "sqlaccess/schema.h"
#include "sqlaccess/schemafull.h"
#include "sqlaccess/sqlaccess.h"
#include "sqlaccess/sqlrecord.h"
#include "sqlaccess/sqlutil.h"

#include "gc_sharedobjectcache.h"
#include "gcbase.h"
#include "gcdirtyfield.h"
#include "gchost.h"
#include "gcjob.h"
#include "gclogger.h"
#include "gcsession.h"
#include "gcsqlquery.h"
#include "gcsystemmsgs.h"
#include "gcwebapi.h"
#include "gcwebapikey.h"
#include "gcwgjobmgr.h"
#include "http.h"
#include "job.h"
#include "jobmgr.h"
#include "jobtime.h"
#include "messagelist.h"
#include "msgprotobuf.h"
#include "netpacketpool.h"
#include "protobufsharedobject.h"
#include "schemasharedobject.h"
#include "sdocache.h"
#include "sharedobject.h"
#include "sharedobjectcache.h"
#include "webapi_response.h"

#endif // GCSDK_H
