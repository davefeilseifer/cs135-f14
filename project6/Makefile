CFLAGS=-Wall -O9
LDFLAGS=
LDLIBS= -lc -lopencv_core -lopencv_highgui

all: red_to_blue
clean:
	rm *.o

OBJS=image_to_array.o red_to_blue.o

%.o: %.cpp
	g++ -g -c $(CFLAGS) $<

red_to_blue: $(OBJS)
	g++ $(LDFLAGS) -o red_to_blue $(OBJS) $(LDLIBS)
