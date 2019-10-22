#include <stdio.h>
#include <stdlib.h>

void sort(float *number, int n) {
    int j, i;
    float temp = 0;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (number[j] > number[j + 1]) {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
}
int findB (int*a,int*b,int i){
	int j = 0,k = 0;
	while(a[i] > b[j])
		j++;
	
	while(a[i+1] < b[j]){
		i++;
		j++;
	}
		
	return j;
}
int main(){
	int n,t,i;
	float t1,t2,total = 0;
	scanf("%d",&n);
	float* a = (float*)malloc(sizeof(float)*n);
	float* b = (float*)malloc(sizeof(float)*n);
	for (i =0; i < n;i++){
		scanf("%f %f",&a[i],&b[i]);
	}
	sort(a, n);
	sort(b, n);
	
	for (i =0; i < n;i++){
		t = findB(a,b,i);
		total += b[t] - a[i];
		i = t;
	}
		
	printf("%f",total);
	
	free(a);
	free(b);
	return 0;
}

