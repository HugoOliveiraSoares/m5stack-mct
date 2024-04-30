#pragma once

#if defined(CARDPUTER)

#include "infrastructure/Cardputer/Device.h"
using namespace Infrastructure::cardputer;

#elif defined(CPLUS2)

#include "infrastructure/Cplus2/Device.h"
using namespace Infrastructure::cplus2;

#endif

Device device = Device();
