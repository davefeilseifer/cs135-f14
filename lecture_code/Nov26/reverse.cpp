#include <stdio.h>

int main(){

  int foo[100];
  for (int i = 0; i < 100 ; i++){
    scanf("%d", &foo[i]);
  }

  for (int i = 99; i >= 0 ; i--){
    printf("%d\n", foo[i]);
  }


  return 0;
}
