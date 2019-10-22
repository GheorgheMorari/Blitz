#include <stdio.h>

#include <stdlib.h>

char a1[] = " _     _  _     _  _  _  _  _ ";
char a2[] = "| |  | _| _||_||_ |_   ||_||_|";
char a3[] = "|_|  ||_  _|  | _||_|  ||_| _|";
int digit(char temp[3][3]) {
  int i, j, t;
  for (i = 0; i < 10; i++) {
    t = 0;
    for (j = 0; j < 3; j++) {
      if ((a1[i * 3 + j] == temp[0][j]) && (a2[i * 3 + j] == temp[1][j]) && (a3[i * 3 + j] == temp[2][j])) 
        t++;
    }
    if (t == 3) return i;
  }
  return -1000;
}

int main() {
  int i, j, z, k = 0, t = 0, tempVal, tempIndex,minusCount = 0;
  char nl;
  char str[3][9 * 3];
  char temp[3][3];
  int number[9];
  FILE * fp = fopen("input.txt", "r");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 9 * 3; j++)
      fscanf(fp, "%c", & str[i][j]);  //inputting the whole line 3 times
    fscanf(fp, "%c", & nl); 
  }
  for (z = 0; z < 9; z++) {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++)
        temp[i][j] = str[i][j + z * 3];  //segmenting the string into 3x3 chunks for identification
    }
    number[z] = digit(temp);
    k += number[z] * (9 - z);
    if (number[z] < 0)
		minusCount ++;
  }
  if ((k % 11 == 0)&&(minusCount ==0))  //separating between failures good numbers and ambiguous ones
    for (i = 0; i < 9; i++) {
      printf("%d", number[i]);
    } else {
      for (i = 0; i < 9; i++) {   //finding all possible combinations 
      	k-= number[i] * (9 - i);
        for (j = 0; j < 10; j++) {
          if (((k + j * (9 - i))% 11 == 0)&& (k+ j * (9 - i))>0) {
            t++;
            tempVal = j;
            tempIndex = i;
          }
        }
        k+= number[i] * (9 - i);
      }
      if (minusCount > 1){
      	printf("failure");
	  } else 
	  		if (t > 1){
      			printf("ambiguous");
      			} 
      		else 
	      if (t == 1) {
        number[tempIndex] = tempVal;
        for (i = 0; i < 9; i++) {
          printf("%d", number[i]);
        }
      } else printf("failure");
    }

  fclose(fp);
  return 0;
}
