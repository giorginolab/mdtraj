#include "rotation.h"
#if defined(__ARM_NEON) || defined(USE_SIMDE)
#include "rotation_arm.h"
#else
#include "rotation_sse.h"
#endif

void sgemm33(const float A[9], const float B[9], float out[9]) {
    int i, j, k;
    float o;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            o = 0.0f;
            for (k = 0; k < 3; k++)
                o += A[i*3 + k] * B[k*3 + j];
            out[i*3 + j] = o;
        }
    }
}
