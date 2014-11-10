CFLAGS=-Wall -O9
LDFLAGS=
LDLIBS= -lc -lopencv_core -lopencv_highgui

all: count_balloons
clean:
	rm *.o

OBJS=count_balloons.o main.o

%.o: %.cpp
	g++ -g -c $(CFLAGS) $<

count_balloons: $(OBJS)
	g++ $(LDFLAGS) -o count_balloons $(OBJS) $(LDLIBS)
