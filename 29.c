#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? x : y)

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int *prim = malloc(sizeof(int)*1001);
	int *sec = malloc(sizeof(int)*1001);
	int *fin = malloc(sizeof(int)*1002);
	int primN,secN,maxLen,zeros,i,temp;
	scanf("%d %d",primN,secN);
	maxLen = max(primN,secN);
	if (secN >= primN){
		for(i = 0;i < maxLen;i++){
			if (i < secN-primN){
				prim[i] = 0;
			} else {
				scanf("%d",&prim[i]);
			}
		}
		for(i = 0;i < maxLen;i++){
			scanf("%d",&sec[i]);
		}
	}	else {
		for(i = 0;i < maxLen;i++){
			scanf("%d",prim[i]);
		}
		for(i = 0;i < maxLen;i++){
			if (i < primN-secN){
				sec[i] = 0;
			} else {
				scanf("%d",&sec[i]);
			}
		}
	}
	for(i = 0;i < maxLen;i++){
		fin[i] = prim[i]+sec[i];
	}
	for(i =maxLen-1;i > 0;i--){
		fin[i-1] = fin[i]/10; 
		fin[i] = fin[i]%10;
	}
	for(i = 0;i < maxLen;i++){
	printf("%d",fin[i]);
}
	free(prim);
	free(fin);
	free(sec);
	return 0;
}
