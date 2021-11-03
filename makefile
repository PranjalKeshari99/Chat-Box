CC=gcc
CFLAGS=-w -std=c99
PROG=s-talk
OBJS= main.o myFunction.o

PTHREADFLAGS=-pthread

#s-talk making and keeping it upto date
s-talk: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(PTHREADFLAGS) $(OBJS)

myFunction.o: myFunction.c myFunction.h
	$(CC) $(CFLAGS) -c myFunction.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c


clean:
	rm *.o
