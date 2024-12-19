//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================

#ifndef NET_WS_HEADERS_H
#define NET_WS_HEADERS_H
#ifdef _WIN32
#pragma once
#endif

#ifdef _WIN32
#if !defined(_X360)
#include "winlite.h"
#endif
#endif

#include "../utils/bzip2/bzlib.h"
#include "convar.h"
#include "filesystem_engine.h"
#include "inetmsghandler.h"
#include "matchmaking.h"
#include "net_chan.h"
#include "proto_oob.h"
#include "protocol.h" // CONNECTIONLESS_HEADER
#include "sv_filter.h"
#include "sys.h"
#include "tier0/icommandline.h"
#include "tier0/tslist.h"
#include "tier0/vcrmode.h"
#include "tier1/mempool.h"
#include "vstdlib/random.h"

#if defined(_WIN32)

#if !defined(_X360)
#include <winsock.h>
#else
#include "winsockx.h"
#endif

// #include <process.h>
typedef int socklen_t;

#elif defined POSIX

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>

#define WSAEWOULDBLOCK EWOULDBLOCK
#define WSAEMSGSIZE EMSGSIZE
#define WSAEADDRNOTAVAIL EADDRNOTAVAIL
#define WSAEAFNOSUPPORT EAFNOSUPPORT
#define WSAECONNRESET ECONNRESET
#define WSAECONNREFUSED ECONNREFUSED
#define WSAEADDRINUSE EADDRINUSE
#define WSAENOTCONN ENOTCONN

#define ioctlsocket ioctl
#define closesocket close

#undef SOCKET
typedef int SOCKET;
#define FAR

#endif

#include "sv_rcon.h"
#ifndef SWDS
#include "cl_rcon.h"
#endif

#if defined(_X360)
#include "xbox/xbox_win32stubs.h"
#endif

#endif // NET_WS_HEADERS_H
