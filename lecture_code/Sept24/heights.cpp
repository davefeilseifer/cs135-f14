#include <stdio.h>

int findMin(int *foo, int n){
  int currentMin = foo[0];
  for (int i = 1; i < n; i++){
    if (foo[i] < currentMin){
      currentMin = foo[i];
    }
  }
  return currentMin;
}

int main(){
  int foo[10];
  int numberOfNumbers;
  scanf("%d", &numberOfNumbers);
  for (int i = 0; i < numberOfNumbers; i++){
    scanf("%d", &foo[i]);
  }
  int shortest = findMin(foo, numberOfNumbers);
  for (int i = 0; i < numberOfNumbers; i++){
    printf("Foo[%d] = %d\n", i, foo[i]);
  }
  printf("Shortest height: %d\n", shortest);
  return 0;
}




/*
  float height[250];

  float[0] = 1.7f;
  float[1] = 2.0f;
  float[2] = 1.85f;
  float[3] = 2.1f;
*/


