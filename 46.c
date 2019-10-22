#include <stdio.h>
#include <stdlib.h>
#define min(x, y) ((x) > (y) ? y : x)
int isPrime(int k) {
	int i;
	for (i = 2; i <= k / 2; i++) {
		if (k % i == 0) {
			return -1;
		}
	}
	return 1;
}
int* factors;
int* necesary;
int* total;
int totalFactors = 0;

void initFactorisation(int k) {
	int i, index = 0;
	for (i = 2; i <= k; i++) {
		if ((k % i == 0) && (isPrime(i))) {
			if (factors[index] != i) {
				factors[index] = i;
				while (k % i == 0) {
					necesary[index]++;
					k /= i;
				}
				index++;
				totalFactors++;
			}
		}
	}
}
void factorisation(int k) {
	int i;
	for (i = 0; i < totalFactors; i++) {
		while (k % factors[i] == 0) {
			total[i] ++;
			k /= factors[i];
		}
	}
}
int main() {
	int k, n, i, trailingZeroes = 2147482;
	printf("base and then n \n");
	scanf("%d %d", &k, &n);
	factors = (int*)malloc(sizeof(int) * n);
	necesary = (int*)malloc(sizeof(int) * n);
	total = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		factors[i] = 0;
		necesary[i] = 0;
		total[i] = 0;
	}
	initFactorisation(k);
	for (i = 2; i < n+1; i++) {
		factorisation(i);
	}
	for (i = 0; i < totalFactors; i++) {
		total[i] /= necesary[i];
		trailingZeroes = min(trailingZeroes,total[i]);
	}
	printf("%d", trailingZeroes);
	free(factors);
	free(necesary);
	free(total);
	return 0;
}
