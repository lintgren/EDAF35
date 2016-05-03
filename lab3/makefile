CC		= gcc

CFLAGS		= -g -Wall -pedantic -std=c11 -O2

LDFLAGS		= -g

# OUT		= fifo
# OBJS		= fifo.c second.c

all: fifo second

fifo: fifo.c
	$(CC) $(LDFLAGS) fifo.c -o fifo

second: second.c
	$(CC) $(LDFLAGS) second.c -o second

clean:
	rm -f *.o sh core out
