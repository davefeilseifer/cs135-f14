#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "censusData.h"

int searchFor(char *name, CensusData *cd, int count);
int lsearch (char *name, CensusData *cd, int l, int h);

int main(int argc, char *argv[]) {

  int dataCount = 151671;
  char name[30];
  if(argc != 3) {
    fprintf(stderr, "usage: ./lsearch n name\nWhere n is the number of lines, and name is the name to be searched for\n");
    exit(1);
  } else {
    dataCount = atoi(argv[1]);
    strcpy(name, argv[2]);
  }

  CensusData *censusData = new CensusData[dataCount];

  readCensusData(censusData, dataCount); 
  int index = searchFor(name, censusData, dataCount);
  if (index >= 0)
    printPercentsInfo(index, censusData);

}



int searchFor(char *name, CensusData *cd, int count){
  printf("Searching for: %s\n", name);
  return lsearch(name, cd, 0, count);

}

int lsearch(char *name, CensusData *cd, int lower, int upper){
  for(int i = lower; i < upper; i++){
    if (strcmp(name, cd[i].lastName) == 0)
      return i;
  }
  return -1;
}
