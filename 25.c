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

