#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<riscv-vector.h>

#define vlen 128 
#define sew 32
#define vmul 1
#define ISUNSIGN 0
#define VCTYPE "uint32"

int main(int argc, char **argv) {
        int vlmax = vmul*vlen/sew;  // vmax <= 8/1
        int N=6;
	int nf=8;
        int avl[6] = {vlmax, vlmax-1, 2*vlmax-1, 2*vlmax+1000, 2*vlmax, 0};
        unsigned int expect;
        uint32x8xm1_t bb;
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
	long strid = stride*4;
	long nstride = 0-stride;
        unsigned int input0[nstride*vlmax];
        unsigned int input1[nstride*vlmax];
        if (argc != 8*vlmax+1)
        {
                for(int j=0;j<8*vlmax;j++){
                        input1[j] = j;
                }
        } else {
        	for(int j=0;j<8*vlmax;j++){
        	        input1[j] = strtol(argv[j+1],0,10);
        	}
	}
        int m=0, n=0;
        for(m=0; m < vlmax;m++){
                 for(n=0; n<nstride; n++ ) {
                  input0[n+(vlmax-1-m)*nstride] = input1[n+m*8];
                }
        }
        const unsigned int *a1 = (const unsigned int *)&input0[nstride*(vlmax-1)];
	unsigned int *aa;

        for(int t=0; t<N; t++) {
                gvl = vsetvli(avl[t], RVV_E32, RVV_M1);
                bb=vlsseg8wuv_uint32x8xm1(a1, strid, gvl);
		aa = (unsigned int *) &bb.v.val[0];
                for(int i=0; i<8*vlmax; i++) {
			if ( (i < avl[t] ) || (i < avl[t]+vlmax && i >= vlmax) || (i < avl[t]+2*vlmax && i >= 2*vlmax) || (i < avl[t]+3*vlmax && i >= 3*vlmax) || (i < avl[t]+4*vlmax && i >= 4*vlmax) || (i < avl[t]+5*vlmax && i >= 5*vlmax) || (i < avl[t]+6*vlmax && i >= 6*vlmax) || (i < avl[t]+7*vlmax && i >= 7*vlmax) )  {
                                if (i < vlmax)
                                        expect = input1[8*i];
                                else if(i >= vlmax && i< 2*vlmax)
                                        expect = input1[8*(i-vlmax)+1];
                                else if(i >= 2*vlmax && i< 3*vlmax)
                                        expect = input1[8*(i-2*vlmax)+2];
                                else if (i >= 3*vlmax && i< 4*vlmax)
                                        expect = input1[8*(i-3*vlmax)+3];
                                else if (i >= 4*vlmax && i< 5*vlmax)
                                        expect = input1[8*(i-4*vlmax)+4];
                                else if (i >= 5*vlmax && i< 6*vlmax)
                                        expect = input1[8*(i-5*vlmax)+5];
                                else if (i >= 6*vlmax && i< 7*vlmax)
                                        expect = input1[8*(i-6*vlmax)+6];
                                else if (i >= 7*vlmax && i< 8*vlmax)
                                        expect = input1[8*(i-7*vlmax)+7];
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
