#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<riscv-vector.h>

#define vlen 128 
#define sew 8
#define vmul 2
#define ISUNSIGN 0
#define VCTYPE "int8"

int main(int argc, char **argv) {
        int vlmax = vmul*vlen/sew;  // vmax <= 8/1
        int N=1;
	int nf=3;
        int avl[6] = {vlmax, vlmax-1, 2*vlmax-1, 2*vlmax+1000, 2*vlmax, 0};
        signed char input1[3*vlmax];
        signed char expect;
        int8x3xm2_t bb;
        int rte = 0;
        int gvl=0;
        unsigned int vst = 0;
        long long max = 0;
        long long min = 0;
        char *name = argv[0];
        if (argc != 3*vlmax+1)
        {
                for(int j=0;j<3*vlmax;j++){
                        input1[j] = j;
                }
        } else {
        	for(int j=0;j<3*vlmax;j++){
        	        input1[j] = strtol(argv[j+1],0,10);
        	}
	}
	
	int8x3xm2_t *a1 = (int8x3xm2_t *)input1;
	signed char address[20480]={0};
	signed char *aa;

        for(int t=0; t<N; t++) {
                gvl = vsetvli(avl[t], RVV_E8, RVV_M2);
		vsseg3ev_int8x3xm2(address, *a1, gvl);
                bb=vlseg3ev_int8x3xm2(address, gvl);
		aa = (signed char *) &bb.v.val[0];
                for(int i=0; i<3*vlmax; i++) {

		   	     	if ( (i < avl[t] ) || (i < avl[t]+vlmax && i >= vlmax) || (i < avl[t]+2*vlmax && i >= 2*vlmax) || (i < avl[t]+3*vlmax && i >= 3*vlmax) || (i < avl[t]+4*vlmax && i >= 4*vlmax) || (i < avl[t]+5*vlmax && i >= 5*vlmax) || (i < avl[t]+6*vlmax && i >= 6*vlmax) || (i < avl[t]+7*vlmax && i >= 7*vlmax) )  {
                   	                     expect = input1[i];
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
