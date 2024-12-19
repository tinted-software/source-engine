//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================

#include <winlite.h>
#undef CreateDialog
#ifdef WIN32
#include <direct.h>
#include <io.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#include "tier0/memdbgoff.h"
#include "tier0/memdbgon.h"
#include "vgui_controls/Frame.h"
#include "vgui_controls/pch_vgui_controls.h"
#include "vstdlib/pch_vstdlib.h"

#include "tier3/tier3.h"

// steam3 API
// #include "steam/steam_querypackets.h"
#include "steam/isteamfriends.h"
#include "steam/isteammatchmaking.h"
#include "steam/isteamuser.h"
#include "steam/steam_api.h"

#include "IVguiModule.h"
#include "ServerBrowser/IServerBrowser.h"
#include "vgui_controls/Controls.h"

#include "IRunGameEngine.h"
#include "ModList.h"
#include "filesystem.h"
#include "netadr.h"
#include "proto_oob.h"

#include "OfflineMode.h"

// serverbrowser files

#include "DialogAddServer.h"
#include "DialogGameInfo.h"
#include "DialogServerPassword.h"
#include "ServerBrowser.h"
#include "ServerContextMenu.h"
#include "ServerListCompare.h"
#include "VACBannedConnRefusedDialog.h"
#include "igamelist.h"

// game list
#include "BaseGamesPage.h"
#include "FavoriteGames.h"
#include "InternetGames.h"
// #include "SpectateGames.h"
#include "HistoryGames.h"
#include "LanGames.h"
#include "QuickListPanel.h"
#include "ServerBrowserDialog.h"
#include "vgui_controls/PanelListPanel.h"

#include "replay/ienginereplay.h"

extern bool GameSupportsReplay();
extern bool IsReplayServer(newgameserver_t &server);

#pragma warning(disable : 4355) //  warning C4355: 'this' : used in base member
                                //  initializer list

#if defined(STEAM)
#define IsSteam() true
#else
#define IsSteam() false
#endif

using namespace vgui;
