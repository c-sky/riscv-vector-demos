
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm1_t test_vfcvtfxv_mask_float16xm1_int16xm1 (float16xm1_t merge, int16xm1_t a, e16xm1_t mask, unsigned int gvl) {
    return vfcvtfxv_mask_float16xm1_int16xm1 (merge, a, mask, gvl);
}


float16xm2_t test_vfcvtfxv_mask_float16xm2_int16xm2 (float16xm2_t merge, int16xm2_t a, e16xm2_t mask, unsigned int gvl) {
    return vfcvtfxv_mask_float16xm2_int16xm2 (merge, a, mask, gvl);
}


float16xm4_t test_vfcvtfxv_mask_float16xm4_int16xm4 (float16xm4_t merge, int16xm4_t a, e16xm4_t mask, unsigned int gvl) {
    return vfcvtfxv_mask_float16xm4_int16xm4 (merge, a, mask, gvl);
}


float16xm8_t test_vfcvtfxv_mask_float16xm8_int16xm8 (float16xm8_t merge, int16xm8_t a, e16xm8_t mask, unsigned int gvl) {
    return vfcvtfxv_mask_float16xm8_int16xm8 (merge, a, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvfcvt\.f\.x\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2\n\tvfcvt\.f\.x\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4\n\tvfcvt\.f\.x\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m8\n\tvfcvt\.f\.x\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

