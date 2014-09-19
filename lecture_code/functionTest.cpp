#include <stdio.h>

int add (int a, int b);

int main(){
	int foo, bar;
	int result;
	//read two  
	
	scanf("%d %d", &foo, &bar);
    // add them
	result = add(foo, bar);

    // print the result

	printf("Result of adding %d and %d is %d\n", foo, bar, result);

	return 0;	

}

int add (int a, int b)
{

	int value = a + b;

	return value;
}




