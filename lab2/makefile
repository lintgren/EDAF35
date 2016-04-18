CC		= gcc

CFLAGS		= -g -Wall -pedantic -std=c11 -O2

LDFLAGS		= -g

OUT		= crash

OBJS		= crash.o

main: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUT)

clean:
	rm -f *.o sh core out
