#include <stdio.h>
#include <stdlib.h>

unsigned long int factorial (int);

int main(int argc, char *argv[]){

  int n = 10;
  if (argc == 2){
    n = atoi(argv[1]);
  }
  printf ("Factorial of %i is %lu\n", n, factorial(n));
  return 0;
}

unsigned long int factorial(int n){
  if (n <= 1)
    return 1;
  else
    return n * factorial(n-1);
}

