#include <stdio.h>
#include <stdlib.h>

int main(){

  for (long int i = 0; i < 1000000; i++){
    int number = random();
    printf ("%3i\n",  (number%100));
  }
  return 0;
}
