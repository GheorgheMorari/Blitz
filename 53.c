#include <stdio.h>
#include <stdlib.h>

float area(int x0, int y0, int x1, int y1, int x2, int y2){
	return (abs((x0*(y1-y2) + x1*(y2-y0) + x2*(y0-y1))/2.0));
}

int main(){
	int i,j,n,tx0,ty0,tx1,ty1,tx2,ty2,num = 0;
	float areal;
	scanf("%d",&n);
	int* x = (int*)malloc(sizeof(int)*n);
	int* y = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i ++){
		scanf("%d %d", &x[i],&y[i]);
	}
		scanf("%d %d %d %d %d %d",&tx0,&ty0,&tx1,&ty1,&tx2,&ty2);
	areal = area(tx0,ty0,tx1,ty1,tx2,ty2);
	for (i = 0; i < n; i ++){
		if (area(x[i],y[i],tx1,ty1,tx2,ty2)+ area(tx0,ty0,x[i],y[i],tx2,ty2)+area(tx0,ty0,tx1,ty1,x[i],y[i]) == areal )
			num++;
	}
		printf("\n%d",num);
	
	free(x);
	free(y);
	return 0;
}
