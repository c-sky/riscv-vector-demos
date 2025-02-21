
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint16x7xm1_t test_vlsseg7wuv_mask_uint16x7xm1 (uint16x7xm1_t merge, const unsigned short *address, long stride, e16xm1_t mask, unsigned int gvl) {
    return vlsseg7wuv_mask_uint16x7xm1 (merge, address, stride, mask, gvl);
}


uint32x7xm1_t test_vlsseg7wuv_mask_uint32x7xm1 (uint32x7xm1_t merge, const unsigned int *address, long stride, e32xm1_t mask, unsigned int gvl) {
    return vlsseg7wuv_mask_uint32x7xm1 (merge, address, stride, mask, gvl);
}


uint64x7xm1_t test_vlsseg7wuv_mask_uint64x7xm1 (uint64x7xm1_t merge, const unsigned long *address, long stride, e64xm1_t mask, unsigned int gvl) {
    return vlsseg7wuv_mask_uint64x7xm1 (merge, address, stride, mask, gvl);
}


uint8x7xm1_t test_vlsseg7wuv_mask_uint8x7xm1 (uint8x7xm1_t merge, const unsigned char *address, long stride, e8xm1_t mask, unsigned int gvl) {
    return vlsseg7wuv_mask_uint8x7xm1 (merge, address, stride, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1\n\tvlsseg7wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1\n\tvlsseg7wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1\n\tvlsseg7wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1\n\tvlsseg7wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

