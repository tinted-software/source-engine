//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Implementation of CPlayerSpecifics
//
// $Workfile:     $
// $Date:         $
//
//------------------------------------------------------------------------------------------------------
// $Log: $
//
// $NoKeywords: $
//=============================================================================//
#include "PlayerSpecifics.h"
#include "PlayerReport.h"

//------------------------------------------------------------------------------------------------------
// Function:	CPlayerSpecifics::init
// Purpose:	 intializes the object
//------------------------------------------------------------------------------------------------------
void CPlayerSpecifics::init() {}

//------------------------------------------------------------------------------------------------------
// Function:	CPlayerSpecifics::generate
// Purpose:	generates intermediate data from match info
//------------------------------------------------------------------------------------------------------
void CPlayerSpecifics::generate() {}

//------------------------------------------------------------------------------------------------------
// Function:	CPlayerSpecifics::writeHTML
// Purpose:	writes out html based on the intermediate data generated by
// generate() Input:	html - the html file to output to
//------------------------------------------------------------------------------------------------------
void CPlayerSpecifics::writeHTML(CHTMLFile &html) {
  int numteams = 0;
  for (int t = 0; t < MAX_TEAMS; t++)
    if (g_pMatchInfo->teamExists(t))
      numteams++;

  html.write("<table cols=%li cellspacing=0 border=0 cellpadding=10 "
             "bordercolor=black>\n",
             numteams);

  CPlayerListIterator i;
  // multimap<double,CPlayer,greater<double> > ranksort;

  // split playerlist into teams;
  multimap<double, CPlayer, greater<double>> rankedteams[MAX_TEAMS];

  for (i = g_pMatchInfo->playerBegin(); i != g_pMatchInfo->playerEnd(); ++i) {
    PID pid = (*i).first;
    CPlayer p = (*i).second;
    for (int t = 0; t < MAX_TEAMS; t++) {
      if (p.teams.contains(t)) {
        double rank = p.perteam[t].rank();
        pair<double, CPlayer> insertme(rank, p);
        rankedteams[t].insert(insertme);
      }
    }
  }

  while (!rankedteams[0].empty() || !rankedteams[1].empty() ||
         !rankedteams[2].empty() || !rankedteams[3].empty()) {
    html.write("<tr>\n");
    int t;

    for (t = 0; t < MAX_TEAMS; t++) {
      if (!g_pMatchInfo->teamExists(t))
        continue;

      html.write("<td width=250 valign=top>");

      if (rankedteams[t].begin() == rankedteams[t].end())
        continue;
      else {
        CPlayer &plr = (*(rankedteams[t].begin())).second;
        CPlayerReport cpr(&plr, t);
        cpr.writeHTML(html);
        rankedteams[t].erase(rankedteams[t].begin());
        // break;
      }
      html.write("</td>\n");
    }
    html.write("</tr>\n");
  }
  html.write("</table>");
}
