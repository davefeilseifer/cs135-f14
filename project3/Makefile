CFLAGS=-Wall -O9
LDFLAGS=
LDLIBS=-lcrypt -lc

all: crypt crack
clean:
	rm *.o
	rm crypt
	rm crack

OBJS=crack.o parse_dict.o parse_passwd.o 

%.o: %.cpp
	g++ -g -c $(CFLAGS) $<

crypt: crypt.o 
	g++ $(LDFLAGS) -o crypt crypt.o $(LDLIBS)

crack: $(OBJS)
	g++ $(LDFLAGS) -o crack $(OBJS) $(LDLIBS)
