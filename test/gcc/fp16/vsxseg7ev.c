
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

void test_vsxseg7ev_float16xm1_float16x7xm1 (float16_t *address, float16xm1_t index, float16x7xm1_t a, unsigned int gvl) {
    return vsxseg7ev_float16xm1_float16x7xm1 (address, index, a, gvl);
}

/* { dg-final { scan-assembler-times "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvsxseg7e\.v" 1 } }*/

/* { dg-final { cleanup-saved-temps } } */

