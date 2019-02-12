/*****************************************************************
 * NEC CONFIDENTIAL AND PROPRIETARY
 *
 * Copyright (C) NEC Corporation 2011  All Rights Reserved.
 *
 * [Abstract]: Average of last 8 values
 * 
 * [Author]
 * Jul/29/98 Original

 * 
 * [Function Detail]:

 * [Compile Option]:
 *   BDL:  For Cyber. (bdlpars -DBDL foo.c)
 *     C:  For C simulation with ANSI C compiler. (gcc -DC foo.c)
 * [Notice]:
 ****************************************************************/
#include <bdlstd.h>
#include "attrs.h"

in ter(0:8)  in0;
out ter(0:8)  out0;
var(0:8)  buff[8] /* ATTR1 */= {0, 0, 0, 0, 0, 0, 0, 0};


process ave8(){

   /* Variables declaration */
    int  out0_v, sum,  i; 

	/* ATTR2 */
        for (i = 7; i > 0; i--) { 	
            buff[i] = buff[i- 1];
        }
	
    buff[0] = in0;
    sum= buff[0]; 	
        
      /* ATTR3 */
      for (i= 1; i< 8; i++) { 	
            sum += buff[i]; 	
        }
        out0_v= sum / 8; 
        out0 = out0_v;	

    return (0); 	
}

/*------------------------------------------------------  
 * ANSI-C test bench 
 *------------------------------------------------------  */
#ifdef C
int main(){

    FILE *fp_i, *fp_o;
    int i;
    

    if((fp_i = fopen("indata.txt", "r")) == NULL){
	printf(" \"indata.txt \" could not be opened.\n");
	exit(1);
    }
    if((fp_o = fopen("outdata.txt", "w")) == NULL){
	printf(" \"outdata.txt \" could not be opened.\n");
	exit(1);
    }

    for (;;){

    	if (fscanf(fp_i, "%d", &in0) == EOF) break	;
	ave8();
	fprintf(fp_o, "%d\n", out0);
    }

    fclose(fp_i);
    fclose(fp_o);
}
#endif
