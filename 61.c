#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,d,i,j,m = 0;
	scanf("%d %d",&n,&d);
	int *a = (int*)malloc(sizeof(int)*d);
	
	for (i = 0;i < n; i++)
		scanf("%d",&a[i]);
		
	for (i = 1;i < n; i++)
		while(a[i] <= a[i-1]) {
			a[i] += d;
			m++;
		}
	
	printf("%d",m);
	
	free(a);	
	return 0;
}
