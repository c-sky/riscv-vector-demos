
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32xm2_t test_vfwsubwf_float32xm2 (float32xm2_t a, float16_t b, unsigned int gvl) {
    return vfwsubwf_float32xm2 (a, b, gvl);
}


float32xm4_t test_vfwsubwf_float32xm4 (float32xm4_t a, float16_t b, unsigned int gvl) {
    return vfwsubwf_float32xm4 (a, b, gvl);
}


float32xm8_t test_vfwsubwf_float32xm8 (float32xm8_t a, float16_t b, unsigned int gvl) {
    return vfwsubwf_float32xm8 (a, b, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvfwsub\.wf" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2\n\tvfwsub\.wf" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4\n\tvfwsub\.wf" } }*/

/* { dg-final { cleanup-saved-temps } } */

