#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<riscv-vector.h>

#define vlen 128 
#define sew 64
#define vmul 1
#define ISUNSIGN 0
#define VCTYPE "uint64"

int main(int argc, char **argv) {
        int vlmax = vmul*vlen/sew;  // vmax <= 8/1
        int N=1;
	int nf=6;
        int avl[6] = {vlmax, vlmax-1, 2*vlmax-1, 2*vlmax+1000, 2*vlmax, 0};
        unsigned long long input1[6*vlmax];
        unsigned long long input2[6*vlmax];
        unsigned long long input3[6*vlmax];
        unsigned long long expect;
        uint64x6xm1_t bb;
        int rte = 0;
        int gvl=0;
        unsigned int vst = 0;
        long long max = 0;
        long long min = 0;
        char *name = argv[0];
        if (argc != 3*6*vlmax+1)
        {
		for(int j=0;j<6*vlmax;j++){
                        input1[j] = j;
                        input2[j] = j;
                        input3[j] = j;
                }
        } else {
        	for(int j=0;j<6*vlmax;j++){
        	        input1[j] = strtol(argv[j+1],0,10);
			input2[j] = strtol(argv[j+1+6*vlmax],0,10);
        	        input3[j] = strtol(argv[j+1+2*6*vlmax],0,10);
        	}
	}

	long stride=128;
//	if(stride < 4*nf)
//		stride = 4*nf;
//	else if(stride > 128)
//		stride = 128;	
	uint64x6xm1_t *a1 = (uint64x6xm1_t *)input1;
	uint64x6xm1_t *a2 = (uint64x6xm1_t *)input2;
	uint64xm1_t *a8 = (uint64xm1_t *)input3;
	unsigned long long address[20480]={0};
	e64xm1_t a3;
	unsigned long long *aa;

        for(int t=0; t<N; t++) {
                gvl = vsetvli(avl[t], RVV_E64, RVV_M1);
		a3 = vmsnevi_e64xm1_uint64xm1(*a8, 0, gvl);
		vssseg6bv_mask_uint64x6xm1(address, stride, *a2, a3, gvl);
                bb=vlsseg6buv_mask_uint64x6xm1(*a1, address, stride, a3, gvl);
		aa = (unsigned long long *) &bb.v.val[0];
                for(int i=0; i<6*vlmax; i++) {
			if ( (i < avl[t] ) || (i < avl[t]+vlmax && i >= vlmax) || (i < avl[t]+2*vlmax && i >= 2*vlmax) || (i < avl[t]+3*vlmax && i >= 3*vlmax) || (i < avl[t]+4*vlmax && i >= 4*vlmax) || (i < avl[t]+5*vlmax && i >= 5*vlmax) || (i < avl[t]+6*vlmax && i >= 6*vlmax) || (i < avl[t]+7*vlmax && i >= 7*vlmax) )  {
				if( input3[i%vlmax]!=0 ) {
                       		                expect = input2[i];
		       		 } else {
                       		                 expect =  input1[i];
                       		 }
                       	} else {
                       		   expect = 0;
                       	}
                        if ( aa[i]- expect != 0) {
                                rte = -1;
                        }
                        printf("Expect=%d,Actual=%d, avl=%d\n",expect, aa[i], avl[t]);
                }
        }

        if ( rte != 0 )
                printf("FAIL: %s\n",name);
        else
                printf("PASS: %s\n",name);
        return rte;
}
