
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int16x2xm1_t test_vlxseg2wv_mask_int16x2xm1_int16xm1 (int16x2xm1_t merge, const short *address, int16xm1_t index, e16xm1_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int16x2xm1_int16xm1 (merge, address, index, mask, gvl);
}


int16x2xm2_t test_vlxseg2wv_mask_int16x2xm2_int16xm2 (int16x2xm2_t merge, const short *address, int16xm2_t index, e16xm2_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int16x2xm2_int16xm2 (merge, address, index, mask, gvl);
}


int16x2xm4_t test_vlxseg2wv_mask_int16x2xm4_int16xm4 (int16x2xm4_t merge, const short *address, int16xm4_t index, e16xm4_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int16x2xm4_int16xm4 (merge, address, index, mask, gvl);
}


int32x2xm1_t test_vlxseg2wv_mask_int32x2xm1_int32xm1 (int32x2xm1_t merge, const int *address, int32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int32x2xm1_int32xm1 (merge, address, index, mask, gvl);
}


int32x2xm2_t test_vlxseg2wv_mask_int32x2xm2_int32xm2 (int32x2xm2_t merge, const int *address, int32xm2_t index, e32xm2_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int32x2xm2_int32xm2 (merge, address, index, mask, gvl);
}


int32x2xm4_t test_vlxseg2wv_mask_int32x2xm4_int32xm4 (int32x2xm4_t merge, const int *address, int32xm4_t index, e32xm4_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int32x2xm4_int32xm4 (merge, address, index, mask, gvl);
}


int64x2xm1_t test_vlxseg2wv_mask_int64x2xm1_int64xm1 (int64x2xm1_t merge, const long *address, int64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int64x2xm1_int64xm1 (merge, address, index, mask, gvl);
}


int64x2xm2_t test_vlxseg2wv_mask_int64x2xm2_int64xm2 (int64x2xm2_t merge, const long *address, int64xm2_t index, e64xm2_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int64x2xm2_int64xm2 (merge, address, index, mask, gvl);
}


int64x2xm4_t test_vlxseg2wv_mask_int64x2xm4_int64xm4 (int64x2xm4_t merge, const long *address, int64xm4_t index, e64xm4_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int64x2xm4_int64xm4 (merge, address, index, mask, gvl);
}


int8x2xm1_t test_vlxseg2wv_mask_int8x2xm1_int8xm1 (int8x2xm1_t merge, const signed char *address, int8xm1_t index, e8xm1_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int8x2xm1_int8xm1 (merge, address, index, mask, gvl);
}


int8x2xm2_t test_vlxseg2wv_mask_int8x2xm2_int8xm2 (int8x2xm2_t merge, const signed char *address, int8xm2_t index, e8xm2_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int8x2xm2_int8xm2 (merge, address, index, mask, gvl);
}


int8x2xm4_t test_vlxseg2wv_mask_int8x2xm4_int8xm4 (int8x2xm4_t merge, const signed char *address, int8xm4_t index, e8xm4_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int8x2xm4_int8xm4 (merge, address, index, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m2\n\tvlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m4\n\tvlxseg2w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

