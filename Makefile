CC = gcc
CFLAGS = -Wall -Werror -fomit-frame-pointer
LINEAR = -DLINEAR
QUAD = -DQUAD
QUAD_OBJS = main.o hash_quad.o
LINEAR_OBJS = linear_main.o hash_linear.o

2208496_lab7: $(QUAD_OBJS)
	$(CC) $(CFLAGS) -o 2208496_lab7 $(QUAD_OBJS)
quad: $(QUAD_OBJS)
	$(CC) $(CFLAGS) -o quad $(QUAD_OBJS)
linear: $(LINEAR_OBJS)
	$(CC) $(CFLAGS) -o linear $(LINEAR_OBJS)
main.o: main.c
	$(CC) $(CFLAGS) $(QUAD) -c main.c
linear_main.o: main.c
	$(CC) $(CFLAGS) $(LINEAR) -o linear_main.o -c main.c
hash_linear.o: hash_linear.h hash_linear.c
	$(CC) $(CFLAGS) -c hash_linear.c
hash_quad.o: hash_quad.h hash_quad.c
	$(CC) $(CFLAGS) -c hash_quad.c
tar: clean
	mkdir 2208496_lab7
	cp *.c *.h *.txt 2208496_lab7
	tar -cvzf 2208496_lab7.tar.gz 2208496_lab7
.PHONY:clean
clean:
	rm -rf *.o 2208496_lab7 linear quad
