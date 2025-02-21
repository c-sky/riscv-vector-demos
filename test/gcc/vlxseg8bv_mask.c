
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int16x8xm1_t test_vlxseg8bv_mask_int16x8xm1_int16xm1 (int16x8xm1_t merge, const short *address, int16xm1_t index, e16xm1_t mask, unsigned int gvl) {
    return vlxseg8bv_mask_int16x8xm1_int16xm1 (merge, address, index, mask, gvl);
}


int32x8xm1_t test_vlxseg8bv_mask_int32x8xm1_int32xm1 (int32x8xm1_t merge, const int *address, int32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg8bv_mask_int32x8xm1_int32xm1 (merge, address, index, mask, gvl);
}


int64x8xm1_t test_vlxseg8bv_mask_int64x8xm1_int64xm1 (int64x8xm1_t merge, const long *address, int64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg8bv_mask_int64x8xm1_int64xm1 (merge, address, index, mask, gvl);
}


int8x8xm1_t test_vlxseg8bv_mask_int8x8xm1_int8xm1 (int8x8xm1_t merge, const signed char *address, int8xm1_t index, e8xm1_t mask, unsigned int gvl) {
    return vlxseg8bv_mask_int8x8xm1_int8xm1 (merge, address, index, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvlxseg8b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1\n\tvlxseg8b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1\n\tvlxseg8b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1\n\tvlxseg8b\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

