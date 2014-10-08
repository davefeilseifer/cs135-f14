#include <stdio.h>
#include <stdlib.h>

void bubble(int *bar, int n);

void readArray(int *x, int size){

  FILE *fp = fopen("data", "r");
  if(fp == NULL){
    printf("Error, cannot open file: data for reading\n");
    exit(1);
  }

  for(int i = 0; i < size; i++){
    fscanf(fp, "%d", &x[i]);
  }
  return;
}

void printArray(int *x, int size){
  for(int i = 0; i < size; i++){
    printf("Element[%3d] = %d\n", i, x[i]);
  }
}

int main(int argc, char *argv[]){
  int size = 100;
  int foo[100];
  readArray(foo, size);
  bubble(foo, size);
  printArray(foo, size);
}

void swap(int *a, int i, int j){
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void bubble(int *x, int size){
  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i < size; i++){
      if (x[i] > x[i+1]){
	swap(x, i, i+1);
	sorted = false;
      }
    }
  }
}

