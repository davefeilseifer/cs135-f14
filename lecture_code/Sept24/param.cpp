#include <stdio.h>

void bar(int a, float b){
  //does something
  return;
}


float foo(int a, float b){
  a++;
  ++b;
  printf("a: %d, b: %f\n", a, b);

  bar (a, b);

  return a + b;
}

int main(){
  int a;
  float b;

  a = 5;
  b = 6.7f;

  float result = foo(a, b);

  printf( "a: %d\n", a );

  printf ("a: %d, b = %f result = %f\n", a, b, result);
  return 0;
}
