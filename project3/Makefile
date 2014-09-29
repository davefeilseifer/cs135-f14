CFLAGS=-Wall 
LDFLAGS=
LDLIBS=-lcrypt

OBJS=crack.o parse_dict.o

%.o: %.cpp
	g++ -g -c $(CFLAGS) $<

crypt: crypt.o
	g++ $(LDFLAGS) -o crypt crypt.o $(LDLIBS)

crack: $(OBJS)
	g++ $(LDFLAGS) -o crack $(OBJS) $(LDLIBS)
