#include <stdio.h>
#include <stdlib.h>

struct segm{
	float x,y;
	int	included;
};

int main(){
	int n,t,i,j;
	float t1,t2,common = 0;
	scanf("%d",&n);
	struct segm* segment = (struct segm*)malloc(sizeof(struct segm)*n);
	for (i =0; i < n;i++){
		scanf("%f %f",&segment[i].x,&segment[i].y);
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if ((i!=j)&&(!(segment[j].included)))
				if((segment[j].x >= segment[i].x && segment[j].y <= segment[i].y))
					segment[j].included = 0;
		}
	}
	printf("%d",n-common);
	
	free(segment);
	return 0;
}

