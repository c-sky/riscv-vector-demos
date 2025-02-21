#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<riscv-vector.h>

#define vlen 128 
#define sew 64
#define vmul 2
#define ISUNSIGN 0
#define VCTYPE "uint64"

int main(int argc, char **argv) {
        int vlmax = vmul*vlen/sew;  // vmax <= 8/1
        int N=6;
	int nf=4;
        int avl[6] = {vlmax, vlmax-1, 2*vlmax-1, 2*vlmax+1000, 2*vlmax, 0};
        unsigned long long expect;
        uint64x4xm2_t bb;
        int rte = 0;
        int gvl=0;
        unsigned int vst = 0;
        long long max = 0;
        long long min = 0;
        char *name = argv[0];

        long stride = -rand();
        if ( stride > -nf )
                stride = -nf;
        else if ( stride < -20480 )
                stride = -20480;
        long strid = stride*2;
        long nstride = 0-stride;

	unsigned long long input1[4*vlmax];
        unsigned short int input0[nstride*vlmax];
        unsigned short int input2[nstride*vlmax];
	unsigned long long input3[4*vlmax];
        if (argc != 3*4*vlmax+1)
        {
                for(int j=0;j<4*vlmax;j++){
                        input1[j] = j;
                        input2[j] = j;
                        input3[j] = j;
                }
        } else {
        	for(int j=0;j<4*vlmax;j++){
        	        input1[j] = strtol(argv[j+1],0,10);
        	        input2[j] = strtol(argv[j+1+4*vlmax],0,10);
        	        input3[j] = strtol(argv[j+1+2*4*vlmax],0,10);
        	}
	}

        int m=0, n=0;
        for(m=0; m < vlmax;m++){
                 for(n=0; n<nstride; n++ ) {
                  input0[n+(vlmax-1-m)*nstride] = input2[n+m*4];
                }
        }

        uint64x4xm2_t *a1 = (uint64x4xm2_t *)input1;
	const unsigned long long *a2 = (const unsigned long long *)&input0[nstride*(vlmax-1)];
	uint64xm2_t *a8 = (uint64xm2_t *)input3;
	e64xm2_t a3;
	unsigned long long *aa;

        for(int t=0; t<N; t++) {
                gvl = vsetvli(avl[t], RVV_E64, RVV_M2);
		a3 = vmsnevi_e64xm2_uint64xm2(*a8, 0, gvl);
                bb=vlsseg4huv_mask_uint64x4xm2(*a1, a2, strid, a3, gvl);
		aa = (unsigned long long *) &bb.v.val[0];
                for(int i=0; i<4*vlmax; i++) {
			if ( (i < avl[t] ) || (i < avl[t]+vlmax && i >= vlmax) || (i < avl[t]+2*vlmax && i >= 2*vlmax) || (i < avl[t]+3*vlmax && i >= 3*vlmax) || (i < avl[t]+4*vlmax && i >= 4*vlmax) || (i < avl[t]+5*vlmax && i >= 5*vlmax) || (i < avl[t]+6*vlmax && i >= 6*vlmax) || (i < avl[t]+7*vlmax && i >= 7*vlmax) )  {
				if( input3[i%vlmax]!=0 ) {
                       		                 if (i < vlmax)
                       		                         expect = input2[4*i];
                       		                 else if(i >= vlmax && i< 2*vlmax)
                       		                         expect = input2[4*(i-vlmax)+1];
                       		                 else if(i >= 2*vlmax && i< 3*vlmax)
                       		                         expect = input2[4*(i-2*vlmax)+2];
                       		                 else if (i >= 3*vlmax && i< 4*vlmax)
                       		                         expect = input2[4*(i-3*vlmax)+3];
                       		                 else if (i >= 4*vlmax && i< 5*vlmax)
                       		                         expect = input2[4*(i-4*vlmax)+4];
                       		                 else if (i >= 5*vlmax && i< 6*vlmax)
                       		                         expect = input2[4*(i-5*vlmax)+5];
                       		                 else if (i >= 6*vlmax && i< 7*vlmax)
                       		                         expect = input2[4*(i-6*vlmax)+6];
                       		                 else if (i >= 7*vlmax && i< 8*vlmax)
                       		                         expect = input2[4*(i-7*vlmax)+7];
				} else {
					expect = input1[i];
				}
		       } else {
                                expect =  0;
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
