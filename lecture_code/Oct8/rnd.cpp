#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  
  int n = 100;
  if (argc == 2){
    n = atoi(argv[1]);
  }

  for (long int i = 0; i < n; i++){
    int number = random();
    printf ("%3i\n",  (number%100));
  }
  return 0;
}
