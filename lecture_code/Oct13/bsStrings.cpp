#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleStrings(char **bar, int n);

void readStringArray(char **x, int size){

  FILE *fp = fopen("dist.all.last.txt", "r");
  if(fp == NULL){
    printf("Error, cannot open file: data for reading\n");
    exit(1);
  }
  char tmp[100];
  float tmpf;
  int tmpi;
  int err;
  for(int i = 0; i < size; i++){
    x[i] = new char[100];
    err = fscanf(fp, "%s %f %f %d\n", &x[i][0], &tmpf, &tmpf, &tmpi);
    if (err < 4){
      printf("Error reading: %d\n", err);
    }
  }
  if (fp!= NULL)
    fclose(fp);
  return;
}

void printStringArray(char **x, int size){
  for(int i = 0; i < size; i++){
    printf("Element[%3d] = %s\n", i, x[i]);
  }
}

int main(int argc, char *argv[]){
  //int size = 88799;
  int size = 88799;
  char *foo[100000];
  readStringArray(foo, size);
  bubbleStrings(foo, size);
  printStringArray(foo, size);
}

void swap(char **a, int i, int j){
  char *tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void bubbleStrings(char **x, int size){
  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i < size-1; i++){
      if (strcmp(x[i], x[i+1]) > 0)    {
	//printf("Swapping\n");
	swap(x, i, i+1);
	sorted = false;
      }
    }
  }
}

