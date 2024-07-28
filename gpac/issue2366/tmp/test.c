#include<stdio.h>

typedef struct
{
	int sps[32]; /* range allowed in the spec is 0..31 */
	int pps[255];
    
} AVCState;