#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "censusData.h"

void bubbleSortCensusData(CensusData *cs, int count, int column);

int main(int argc, char *argv[]){

  int dataCount = 10;
  int column    = 2;
  if(argc != 2) {
    fprintf(stderr, "Usage: ./bs n \n n is the number of lines to read and sort\n");
    exit(1);
  } else {
    dataCount = atoi(argv[1]);
    //    column = atoi(argv[2]); not used for this version
  }

  // Big arrays MUST be dynamically allocated in Ubuntu
  CensusData *censusData = new CensusData[dataCount]; 

  readCensusData(censusData, dataCount);
  fprintf(stderr, "read Census data\n");
  
  bubbleSortCensusData(censusData, dataCount, column);
  printPercentsCensusData(censusData, dataCount);
  printf("Most Common Name: \n");
  printPercentsInfo(0, censusData);
  printf("Median Name: \n");
  printPercentsInfo(dataCount/2, censusData);

  return 0;
}

void swap(CensusData *cd, int i, int j){
  CensusData tmp;
  tmp = cd[i];
  cd[i] = cd[j];
  cd[j] = tmp;
}

void checkSwapNames(CensusData *cd, int i, bool &isSorted){
  if(strcmp(cd[i].lastName, cd[i+1].lastName) > 0){
    swap(cd, i, i+1);
    isSorted = false;
  }
}

void checkSwapTotals(CensusData *cd, int i, bool &isSorted){
  if(cd[i].total < cd[i+1].total){
    swap(cd, i, i+1);
    isSorted = false;
  }
}

void bubbleSortCensusData(CensusData *cd, int size, int column){

  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;
    for (int i = 0; i < size - 1; i++){
      if (column == 1){
	checkSwapNames(cd, i, isSorted);
      } else if (column == 2) {
	checkSwapTotals(cd, i, isSorted);
      } else {
	fprintf(stderr, "Illegal value for column to be sorted. Legal values are 1, 2. Got: %i\nExiting...\n", column);
	exit(1);
      }
    }
  }
  return;
}
