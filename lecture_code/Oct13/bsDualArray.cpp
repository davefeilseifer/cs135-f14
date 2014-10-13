#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int US_POPULATION = 248709873;


void bubbleStrings(char **bar, int n);

void readData(char **names, float *percents, int size){
  float tmpf;
  int tmpi;
  int err;
  for(int i = 0; i < size; i++){
    names[i] = new char[100];
    err = scanf("%s %f %f %d\n", &names[i][0], &percent[i], &tmpf, &tmpi);
    if (err < 4){
      printf("Error reading: %d\n", err);
    }
  }
  return;
}

void printData(char **names, float *percents, int size){
  for(int i = 0; i < size; i++){
    printf("%s %f %f\n", names[i], percent[i], US_POPULATION * percent[i]/100.0 );
  }
}

int main(int argc, char *argv[]){
  int size = 88799;
  int sortColumn = 0;
  if (argc != 2){
    fprintf(stderr, "Usage: ./bsDualArray n sortColumn\nn is the number of lines to read. sortColumn is 0 for names and 1 for percentage\n");
    exit(1);
  } else {
    size = atoi(argv[1]);
    sortColumn = atoi(argv[2]);
  }

  char *names[size];
  float percents[size];

  readData(names, percents, size);
  bubbleData(names, percents, size, sortColumn);
  printData(names, percents, size);

}

void swap(char **a, int i, int j){
  char *tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void swapFloats(float *percents, int i, int j){
  float tmp = percents[i];
  percents[i] = percents[j];
  percents[j] = tmp;
}


void bubbleData(char **names, float *percents, int size, int sortColumn){
  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i < size-1; i++){

      if(sortColumn == 0){
	if (strcmp(names[i], names[i+1]) > 0)    {
	  swap(names, i, i+1); //
	  swapFloats(percents, i, i+1);
	  sorted = false;
	}
      } else if (sortColumn == 1) {
	if(percents[i] < percents[i+1]){ //I give up, this is bs! too much work
	  swap(names, i, i+1); //
	  swapFloats(percents, i, i+1);
	  sorted = false;
	}	  

      }
    }
  }
}

