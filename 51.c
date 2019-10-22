#include <stdio.h>
#include <stdlib.h>
#define min(x, y) ((x) > (y) ? y : x)


int main(){
	int i,j,n,minim = 2000000;
	float area = 0;
	scanf("%d",&n);
	int* x = (int*)malloc(sizeof(int)*n);
	int* y = (int*)malloc(sizeof(int)*n);
	for (i = 0; i< n; i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			minim = min(minim,x[i]);
			minim = min(minim,y[i]);
		}
//	for( i = 0; i < n; i ++ )
//		{
//			x[i] -= minim;
//			y[i] -= minim;
//		}
	for( i = 0; i < n; i ++ )
    	area += abs((x[i]+x[(i+1)%(n)])*(y[(i+1)%(n)]-y[i]));
	area /= 2;
	printf("\n%d",area);
	return 0;
}





