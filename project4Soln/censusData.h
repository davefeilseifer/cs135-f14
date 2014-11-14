
#ifndef __CENSUS_DATA__H__

const int  NCATEGORIES = 6;
const int  NAMELENGTH  = 30;
typedef struct census {
  char  lastName[NAMELENGTH];
  int   total;
  float percents[NCATEGORIES];
  float counts[NCATEGORIES];
  
} CensusData;

enum Categories {CATEGORY_W, CATEGORY_B, CATEGORY_API, CATEGORY_AIAN, CATEGORY_2, CATEGORY_H};


void readCensusData(CensusData *cd, int size);
void printPercentsInfo(int i, CensusData *cd);
void printCountsInfo(int i, CensusData *cd);
void printAllInfo(int i, CensusData *cd);
void printAllCensusData(CensusData* cd, int count);
void printPercentsCensusData(CensusData* cd, int count);
void printCountsCensusData(CensusData* cd, int count);

#endif
