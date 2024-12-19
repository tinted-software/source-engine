//========= Copyright Valve Corporation, All rights reserved. ============//

#include "platform.h"

#include <assert.h>
#include <float.h>
#include <math.h>
#include <vector>

// Prevent OpenCV and other Vortex modules from using D3D (they will want D3D11,
// and we're a D3D9 game)
#define NO_D3D
