#include <stdio.h>
#include <stdlib.h>

#include "censusData.h"

void findMinMax(int &mini, int &maxi, CensusData *cd, int count, int category);

int main(int argc, char *argv[]){

  int count = 151671;
  int category = 1;

  if(argc != 3){
    fprintf(stderr, "Usage: ./minmax n category\nHere n is the number of lines, and category is a number from 0..5 indicating which category you want the min and max numbers for\n");
    exit(1);
  } else {
    count    = atoi(argv[1]);
    category = atoi(argv[2]);
  }

  CensusData *cd = new CensusData[count];

  readCensusData(cd, count);
  int minIndex = 0;
  int maxIndex = 0;
  findMinMax(minIndex, maxIndex, cd, count, category);

  printPercentsInfo(minIndex, cd);
  printPercentsInfo(maxIndex, cd);

  return 0;
}


void findMinMax(int &mini, int &maxi, CensusData *cd, int size, int category){
  mini = maxi = 0;
  for (int i = 0; i < size; i++){
    if (cd[i].counts[category] < cd[mini].counts[category])
      mini = i;
    if  (cd[i].counts[category] > cd[maxi].counts[category])
      maxi = i;
  }
}

