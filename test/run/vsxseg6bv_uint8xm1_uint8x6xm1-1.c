#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<riscv-vector.h>

#define vlen 128 
#define sew 8
#define vmul 1
#define ISUNSIGN 0
#define VCTYPE "uint8"

int main(int argc, char **argv) {
        int vlmax = vmul*vlen/sew;  // vmax <= 8/1
        int N=1;
	int nf=6;
        int avl[6] = {vlmax, vlmax-1, 2*vlmax-1, 2*vlmax+1000, 2*vlmax, 0};
        unsigned char input1[6*vlmax];
        unsigned char expect;
        uint8x6xm1_t bb;
        int rte = 0;
        int gvl=0;
        unsigned int vst = 0;
        long long max = 0;
        long long min = 0;
        char *name = argv[0];
        if (argc != 6*vlmax+1)
        {
                for(int j=0;j<6*vlmax;j++){
                        input1[j] = j;
                }
        } else {
        	for(int j=0;j<6*vlmax;j++){
        	        input1[j] = strtol(argv[j+1],0,10);
        	}
	}

	unsigned char stride[20480]={sew/vmul*0,sew/vmul*1,sew/vmul*2,sew/vmul*3,sew/vmul*4,sew/vmul*5,sew/vmul*6,sew/vmul*7,sew/vmul*8,sew/vmul*9,sew/vmul*10,sew/vmul*11,sew/vmul*12,sew/vmul*13,sew/vmul*14,sew/vmul*15,sew/vmul*16,sew/vmul*17,sew/vmul*18,sew/vmul*19,sew/vmul*20,sew/vmul*21,sew/vmul*22,sew/vmul*23,sew/vmul*24,sew/vmul*25,sew/vmul*26,sew/vmul*27,sew/vmul*28,sew/vmul*29,sew/vmul*30,sew/vmul*31,sew/vmul*32,sew/vmul*33,sew/vmul*34,sew/vmul*35,sew/vmul*36,sew/vmul*37,sew/vmul*38,sew/vmul*39,sew/vmul*40,sew/vmul*41,sew/vmul*42,sew/vmul*43,sew/vmul*44,sew/vmul*45,sew/vmul*46,sew/vmul*47,sew/vmul*48,sew/vmul*49,sew/vmul*50,sew/vmul*51,sew/vmul*52,sew/vmul*53,sew/vmul*54,sew/vmul*55,sew/vmul*56,sew/vmul*57,sew/vmul*58,sew/vmul*59,sew/vmul*60,sew/vmul*61,sew/vmul*62,sew/vmul*63,sew/vmul*64,sew/vmul*65,sew/vmul*66,sew/vmul*67,sew/vmul*68,sew/vmul*69,sew/vmul*70,sew/vmul*71,sew/vmul*72,sew/vmul*73,sew/vmul*74,sew/vmul*75,sew/vmul*76,sew/vmul*77,sew/vmul*78,sew/vmul*79,sew/vmul*80,sew/vmul*81,sew/vmul*82,sew/vmul*83,sew/vmul*84,sew/vmul*85,sew/vmul*86,sew/vmul*87,sew/vmul*88,sew/vmul*89,sew/vmul*90,sew/vmul*91,sew/vmul*92,sew/vmul*93,sew/vmul*94,sew/vmul*95,sew/vmul*96,sew/vmul*97,sew/vmul*98,sew/vmul*99,sew/vmul*100,sew/vmul*101,sew/vmul*102,sew/vmul*103,sew/vmul*104,sew/vmul*105,sew/vmul*106,sew/vmul*107,sew/vmul*108,sew/vmul*109,sew/vmul*110,sew/vmul*111,sew/vmul*112,sew/vmul*113,sew/vmul*114,sew/vmul*115,sew/vmul*116,sew/vmul*117,sew/vmul*118,sew/vmul*119,sew/vmul*120,sew/vmul*121,sew/vmul*122,sew/vmul*123,sew/vmul*124,sew/vmul*125,sew/vmul*126,sew/vmul*127,sew/vmul*128};
	uint8x6xm1_t *a1 = (uint8x6xm1_t *)input1;
	uint8xm1_t *a7 = (uint8xm1_t *)stride;
	unsigned char address[20480]={0};
	unsigned char *aa;

        for(int t=0; t<N; t++) {
                gvl = vsetvli(avl[t], RVV_E8, RVV_M1);
		vsxseg6bv_uint8xm1_uint8x6xm1(address, *a7, *a1, gvl);
                bb=vlxseg6buv_uint8x6xm1_uint8xm1(address, *a7, gvl);
		aa = (unsigned char *) &bb.v.val[0];
                for(int i=0; i<6*vlmax; i++) {

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
