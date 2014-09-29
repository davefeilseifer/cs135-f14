#include <stdio.h>

void bubbleSort(int *a, int n){
  while (n > 0) {
    int newn = 0;
    for (int i = 0; i < n - 1; i++){
      if (a[i] > a[i+1]) {
	int tmp = a[i];
	a[i] = a[i+1];
	a[i+1] = tmp;
	newn = i;
      }
    }
    n = newn;
  }
}

void readArray(int *a, int n){
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
}

void printArray(int *a, int n){
  for (int i = 0; i < n; i++){
    printf("%d\n", a[i]);
  }
}

int main(){
  int input[1024];
  readArray(input, 10);
  printArray(input, 10);
  printf("\n--------------\n");
  bubbleSort(input, 10);
  printArray(input, 10);
  return 0;
}
