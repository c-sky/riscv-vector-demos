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
        int N=6;
        int avl[6] = {vlmax, vlmax-1, 2*vlmax-1, 2*vlmax+1000, 2*vlmax, 0};
        unsigned long long expect;
        uint64xm1_t bb;
        int rte = 0;
        int gvl=0;
        unsigned int vst = 0;
        long long max = 0;
        long long min = 0;
        char *name = argv[0];

        long stride = -rand();
        if ( stride < -20480 )
                stride = -20480;
        long strid = stride*4;
        long nstride = 0-stride;

	unsigned long long input1[vlmax];
        unsigned int input0[nstride*vlmax];
        unsigned int input2[nstride*vlmax];
	unsigned long long input3[vlmax];
        if (argc != 3*vlmax+1)
        {
                for(int j=0;j<vlmax;j++){
                        input1[j] = j;
                        input2[j] = j;
                        input3[j] = j;
                }
        } else {
        	for(int j=0;j<vlmax;j++){
        	        input1[j] = strtol(argv[j+1],0,10);
        	        input2[j] = strtol(argv[j+1+vlmax],0,10);
        	        input3[j] = strtol(argv[j+1+2*vlmax],0,10);
        	}
	}

        int m=0, n=0;
        for(m=0; m < vlmax;m++){
                 for(n=0; n<nstride; n++ ) {
                  input0[n+(vlmax-1-m)*nstride] = input2[n+m];
                }
        }

        uint64xm1_t *a1 = (uint64xm1_t *)input1;
	const unsigned long long *a2 = (const unsigned long long *)&input0[nstride*(vlmax-1)];
	uint64xm1_t *a8 = (uint64xm1_t *)input3;
	e64xm1_t a3;

        for(int t=0; t<N; t++) {
                gvl = vsetvli(avl[t], RVV_E64, RVV_M1);
		a3 = vmsnevi_e64xm1_uint64xm1(*a8, 0, gvl);
                bb=vlswuv_mask_uint64xm1(*a1, a2, strid, a3, gvl);
                for(int i=0; i<vlmax; i++) {
			if ( i < avl[t] )  {
				if( input3[i]!=0 ) {
                       		       expect = input2[i];
				} else {
					expect = input1[i];
				}
		       } else {
                                expect =  0;
                       }

                        if ( bb[i]- expect != 0) {
                                rte = -1;
                        }
                        printf("Expect=%d,Actual=%d, avl=%d\n",expect, bb[i], avl[t]);
                }
        }

        if ( rte != 0 )
                printf("FAIL: %s\n",name);
        else
                printf("PASS: %s\n",name);
        return rte;
}
