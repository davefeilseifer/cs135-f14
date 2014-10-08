#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *x, int size){
  for(int i = 0; i < size; i++){
    printf("Element[%3d] = %d\n", i, x[i]);
  }
}


int main(int argc, char *argv[]){


  int foo[1000];
  //srandom(time(NULL));

  for (int i = 0; i < 1000; i++){
    *(foo + i) = random() % 1000;
  }

  int sum = 0;
  int *fooPtr;
  fooPtr = foo;
  for (int i = 0; i < 1000; i++){
    sum += *fooPtr++;
  }

  printArray(foo, 1000);

  printf("Sum: %d\n", sum);


  return 0;
}
