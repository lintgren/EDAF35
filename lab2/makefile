CC		= gcc

CFLAGS		= -g -Wall -pedantic -std=c11 -O2

LDFLAGS		= -g

OUT		= crash
OBJS		= crash.o

all: main loop sh loopseconds

main: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUT)

loop: loop.o
	$(CC) $(LDFLAGS) loop.o -o loop

loopseconds: loopseconds.o
		$(CC) $(LDFLAGS) loopseconds.o -o loopseconds

sh: sh.o list.o
	$(CC) $(LDFLAGS) sh.o list.o -o sh

clean:
	rm -f *.o sh core out
