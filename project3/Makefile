CFLAGS=-Wall 
LDFLAGS=
LDLIBS=

OBJS=crack.o

%.o: %.cpp
	g++ -g -c $(CFLAGS) $<

crack: $(OBJS)
	g++ $(LDFLAGS) -o crack $(OBJS) $(LDLIBS)
