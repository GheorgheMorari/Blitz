#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? x : y)

struct plate {
	float xrez,yrez,percx, percy;
};

struct plate* plates;
int* order;
float* sum;
float totalx = 0;
float totaly = 0;
int n = 0;

void sort(float *number,int *ord) {
    int j, i;
    float temp = 0;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (number[j] < number[j + 1]) {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
                temp = ord[j];
                ord[j] = ord[j+1];
                ord[j+1] = temp;
            }
        }
    }
}

void perc(){
	int i;
	for (i = 0; i < n; i ++){
		plates[i].percx = plates[i].xrez / totalx;
		plates[i].percy = plates[i].yrez / totaly;
		sum[i] = plates[i].percx - plates[i].percy;
		order[i] = i;
	}
}

float time() {
	int i = 0, j = n-1;
	float xrest = 0, yrest = 0, lastOp, remainingx, remainingy, temp;
	while (j != i) {
		if (xrest <= yrest) {
			temp = plates[order[i]].xrez;
			xrest += temp;
			i++;
			lastOp = 0;
		}
		else {
			temp = plates[order[j]].yrez;
			yrest += temp;
			j--;
			lastOp = 1;
		}
	}
	if (xrest != yrest) {
		if (lastOp == 1) {
			remainingx = plates[order[i]].xrez - yrest + xrest;
			remainingy = remainingx / plates[order[i]].xrez * plates[order[i]].yrez;
		}
		else {
			remainingy = plates[order[i]].yrez - xrest + yrest;
			remainingx = remainingy / plates[order[i]].yrez * plates[order[i]].xrez;
		}
		return (1 / (1 / remainingx + 1 / remainingy) + max(xrest, yrest));
	}
	return xrest;
}

void print(){
	int i;
	for (i = 0; i < n; i ++){
	//	printf("%f \n",sum[i]);
		printf("%d ",order[i]+1);
	}
	printf("\n%f",time());
//	printf("%f  %f",totalx,totaly);
}

int main(){
	int i;
	scanf("%d",&n);
	plates = (struct plate*)malloc(sizeof(struct plate)*n);
	order = (int*)malloc(sizeof(int)*n);
	sum = (float*)malloc(sizeof(float)*n);
	for (i = 0; i < n; i ++){
		scanf("%f %f",&plates[i].xrez,&plates[i].yrez);
		totalx += plates[i].xrez;
		totaly += plates[i].yrez;
	}
	perc();
	sort(sum,order);
	print();
	free(plates);
	free(order);
	free(sum);
	return 0;
}
