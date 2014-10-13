#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char *name;
  float percent;

} CensusData;


const int US_POPULATION = 248709873;


void bubbleData(CensusData *cd, int n, int col);

void readData(CensusData *cd, int size){
  float tmpf;
  int tmpi;
  int err;
  for(int i = 0; i < size; i++){
    cd[i].name = new char[30];
    err = scanf("%s %f %f %d\n", cd[i].name, &(cd[i].percent), &tmpf, &tmpi);
    if (err < 4){
      printf("Error reading: %d\n", err);
    }
  }
  return;
}

void printData(CensusData *cd, int size){
  for(int i = 0; i < size; i++){
    printf("%20s %7.3f %8.2f\n", cd[i].name, cd[i].percent, US_POPULATION * cd[i].percent/100.0 );
  }
}

int main(int argc, char *argv[]){
  int size = 88799;
  int sortColumn = 0;
  if (argc != 3){
    fprintf(stderr, "Usage: ./bsStruct n sortColumn\nn is the number of lines to read. sortColumn is 0 for names and 1 for percentage\n");
    exit(1);
  } else {
    size = atoi(argv[1]);
    sortColumn = atoi(argv[2]);
  }

  CensusData censusData[size];

  readData(censusData, size);
  bubbleData(censusData, size, sortColumn);
  printData(censusData, size);

}

void swap(CensusData *cd, int i, int j){
  CensusData tmp = cd[i];
  cd[i] = cd[j];
  cd[j] = tmp;
}


void bubbleData(CensusData *cd, int size, int sortColumn){
  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i < size-1; i++){
      if(sortColumn == 0){
	if (strcmp(cd[i].name, cd[i+1].name) > 0)    {
	  swap(cd, i, i+1); //
	  sorted = false;
	}
      } else if (sortColumn == 1) {
	if(cd[i].percent < cd[i].percent){ 
	  swap(cd, i, i+1); //
	  sorted = false;
	}	  

      }
    }
  }
}

