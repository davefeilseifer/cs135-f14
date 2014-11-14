#include <stdio.h>
#include <stdlib.h>

#include "censusData.h"

void readCensusData(CensusData *cd, int size){

  char tmp[1024];
  int  tmpi;
  int  err;
  for(int i = 0; i < size && err != -1; i++){
    err = fscanf(stdin, " %i %s %i %f %f %f %f %f %f \n ", 
		 &tmpi, cd[i].lastName, &(cd[i].total), 
		 &(cd[i].percents[CATEGORY_W]), &(cd[i].percents[CATEGORY_B]), &(cd[i].percents[CATEGORY_API]),
		 &(cd[i].percents[CATEGORY_AIAN]), &(cd[i].percents[CATEGORY_2]), &(cd[i].percents[CATEGORY_H]));
    if(err != 9) {
      fprintf(stderr, "Error in reading line: %d...read %d items\n", i, err);
      exit(1);
    }
    for(int j = 0; j < NCATEGORIES; j++)
      cd[i].counts[j] = cd[i].total * cd[i].percents[j]/100.0;
  }

  return;
}

void printPercentsInfo(int i, CensusData *cd){
  printf("%6i %20s %7i   ", i, cd[i].lastName, cd[i].total);
  for(int j = 0; j < NCATEGORIES; j++)
    printf(" %5.2f     ", cd[i].percents[j]);
  printf("\n");
}

void printCountsInfo(int i, CensusData *cd){
  printf("%6i %20s %7i   ", i, cd[i].lastName, cd[i].total);
  for(int j = 0; j < NCATEGORIES; j++)
    printf(" %9.2f     ", (cd[i].percents[j] < 0.0 ? 0.0f : cd[i].counts[j]));
  printf("\n");
}

void printAllInfo(int i, CensusData *cd){
  printf("%6i %20s %7i   ", i, cd[i].lastName, cd[i].total);
  for(int j = 0; j < NCATEGORIES; j++)
    printf(" %5.2f %9.2f   ", cd[i].percents[j], (cd[i].percents[j] < 0.0 ? 0.0f : cd[i].counts[j]));
  printf("\n");
}


void printAllCensusData(CensusData* cd, int count){
  for (int i = 0; i < count; i++){
    printAllInfo(i, cd);
  }
}

void printPercentsCensusData(CensusData* cd, int count){
  for (int i = 0; i < count; i++){
    printPercentsInfo(i, cd);
  }
}

void printCountsCensusData(CensusData* cd, int count){
  for (int i = 0; i < count; i++){
    printCountsInfo(i, cd);
  }
}
