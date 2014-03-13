CC = gcc
CFLAGS = -Wall -Werror -fomit-frame-pointer
LINEAR = -DLINEAR
QUAD = -DQUAD
OBJS = main.o hash_linear.o


2208496_lab7: $(OBJS)
	$(CC) $(CFLAGS) -o 2208496_lab7 $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) $(LINEAR) -c main.c
hash_linear.o: hash_linear.h hash_linear.c
	$(CC) $(CFLAGS) -c hash_linear.c
.PHONY:clean
clean:
	rm -rf *.o 2208496_lab7
