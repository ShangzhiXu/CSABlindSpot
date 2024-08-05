#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int sps[32]; /* range allowed in the spec is 0..31 */
    int sensitive;
	int sps_id[255]; /* range allowed in the spec is 0..255 */

} AVCState;

int main()
{
    AVCState *avc = (AVCState *)malloc(sizeof(AVCState));
    avc->sensitive = 0;
    int i;
    //scanf("%d", &i);
    /*f( i >= 255)
    {
        exit(0);
    }*/
    for(i=0; i<255; i++)
    {
        avc->sps[i] = i;
    }
    
    printf("success, avc->sps[%d] = %d\n",i , avc->sps[i]);

    printf("avc->sensitive = %d\n", avc->sensitive);
    for(i=0; i<255; i++)
    {
        avc->sps_id[i] = i;
    }
    return 0;
}