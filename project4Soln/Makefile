bs:	bs.o censusData.o
	g++ -o bs bs.o censusData.o

lsearch:	lsearch.o censusData.o
	g++ -o lsearch lsearch.o censusData.o

minmax:	minmax.o censusData.o
	g++ -o minmax minmax.o censusData.o

%.o:	%.cpp
	g++ $(CC_FLAGS) -c -o $@ $<
