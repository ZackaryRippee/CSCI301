CC = g++
CFLAGS = -g -Wall -Wextra

TARGET = montyhall

default: all

all: main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
