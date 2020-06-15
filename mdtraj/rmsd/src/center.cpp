#include "center.h"
#include "msvccompat.h"
#if defined(__ARM_NEON) || defined(USE_SIMDE)
#include "center_arm.h"
#else
#include "center_sse.h"
#endif
