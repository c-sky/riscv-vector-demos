
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm1_t test_vfncvtfxuv_mask_float16xm1_uint32xm2 (float16xm1_t merge, uint32xm2_t a, e16xm1_t mask, unsigned int gvl) {
    return vfncvtfxuv_mask_float16xm1_uint32xm2 (merge, a, mask, gvl);
}


float16xm2_t test_vfncvtfxuv_mask_float16xm2_uint32xm4 (float16xm2_t merge, uint32xm4_t a, e16xm2_t mask, unsigned int gvl) {
    return vfncvtfxuv_mask_float16xm2_uint32xm4 (merge, a, mask, gvl);
}


float16xm4_t test_vfncvtfxuv_mask_float16xm4_uint32xm8 (float16xm4_t merge, uint32xm8_t a, e16xm4_t mask, unsigned int gvl) {
    return vfncvtfxuv_mask_float16xm4_uint32xm8 (merge, a, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvfncvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2\n\tvfncvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4\n\tvfncvt\.f\.xu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

