PROGNAME = odisk
OBJECTS = main.o config.o parse.o
CFLAGS = -W -Wall -O2 -ggdb

all: $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	gcc -o out/$(PROGNAME) $(OBJECTS) 

$(OBJECTS): Makefile

.c.o:
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm *.o $(PROGNAME)
