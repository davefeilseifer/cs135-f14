#include <stdio.h>

int main(){
  
  int storage[100];
  for(int i = 0; i < 100; i++){
    storage[i] = i * i;
    printf("testing: %d\n", storage[i]);//only for testing, not in specification by justin
  }

  return 0;
}
