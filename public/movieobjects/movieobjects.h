//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================

#ifndef MOVIEOBJECTS_H
#define MOVIEOBJECTS_H
#ifdef _WIN32
#pragma once
#endif

#include "movieobjects/dmeanimationlist.h"
#include "movieobjects/dmeanimationset.h"
#include "movieobjects/dmeattachment.h"
#include "movieobjects/dmebalancetostereocalculatoroperator.h"
#include "movieobjects/dmecamera.h"
#include "movieobjects/dmechannel.h"
#include "movieobjects/dmeclip.h"
#include "movieobjects/dmecombinationoperator.h"
#include "movieobjects/dmedag.h"
#include "movieobjects/dmedccmakefile.h"
#include "movieobjects/dmedrawsettings.h"
#include "movieobjects/dmeeditortypedictionary.h"
#include "movieobjects/dmeexpressionoperator.h"
#include "movieobjects/dmeeyeball.h"
#include "movieobjects/dmeeyeposition.h"
#include "movieobjects/dmefaceset.h"
#include "movieobjects/dmegamemodel.h"
#include "movieobjects/dmegamemodelinput.h"
#include "movieobjects/dmeinput.h"
#include "movieobjects/dmejoint.h"
#include "movieobjects/dmekeyboardinput.h"
#include "movieobjects/dmelight.h"
#include "movieobjects/dmelog.h"
#include "movieobjects/dmemakefile.h"
#include "movieobjects/dmematerial.h"
#include "movieobjects/dmemdl.h"
#include "movieobjects/dmemdlmakefile.h"
#include "movieobjects/dmemesh.h"
#include "movieobjects/dmemodel.h"
#include "movieobjects/dmemorphoperator.h"
#include "movieobjects/dmemouseinput.h"
#include "movieobjects/dmeoperator.h"
#include "movieobjects/dmepackoperators.h"
#include "movieobjects/dmephonememapping.h"
#include "movieobjects/dmeselection.h"
#include "movieobjects/dmeshape.h"
#include "movieobjects/dmesound.h"
#include "movieobjects/dmetimeframe.h"
#include "movieobjects/dmetimeselection.h"
#include "movieobjects/dmetrack.h"
#include "movieobjects/dmetrackgroup.h"
#include "movieobjects/dmetransform.h"
#include "movieobjects/dmetransformlist.h"
#include "movieobjects/dmetransformoperator.h"
#include "movieobjects/dmeunpackoperators.h"
#include "movieobjects/dmevertexdata.h"

#define USING_ELEMENT_FACTORY(className)                                       \
  extern C##className *g_##C##className##LinkerHack;                           \
  C##className *g_##C##className##PullInModule = g_##C##className##LinkerHack;

#endif // MOVIEOBJECTS_H
