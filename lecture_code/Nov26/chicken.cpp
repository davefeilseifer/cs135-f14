
#include <stdio.h>

float chickenToCalories(float clucks){
  return clucks * 64064;

}

int main(){
  float chicken;
  for (int i = 0; i < 10 ; i++){
    printf("Enter Cubic feet of chicken: ");
    scanf("%f", &chicken);
    //    float calories = chicken * 64064.0;
    float calories = chickenToCalories(chicken);

    printf ("There are %f calories in %f cubic feet of chicken\n", calories, chicken);
  }
  return 0;
}

