.PHONY = all clean
CC = gcc
FLAGS = -Wall -Werror -g

all: encode decode

encode: encode.o codec.h codec1.so codec2.so
	$(CC) encode.o codec.h $(FLAGS) -fPIC -ldl -o encode

decode: decode.o codec.h codec1.so codec2.so
	$(CC) decode.o codec.h $(FLAGS) -fPIC -ldl -o decode

codec1.so: codec1.c codec.h
	$(CC) $(FLAGS) -shared codec1.c -fPIC -o codec1.so

codec2.so: codec2.c codec.h
	$(CC) $(FLAGS) -shared codec2.c -fPIC -o codec2.so

encode.o: encode.c
	$(CC) $(FLAGS) -c encode.c

decode.o: decode.c
	$(CC) $(FLAGS) -c decode.c

cmp: cmp.c
	$(CC) $(FLAGS) cmp.c -o cmp

clean:
	rm -f *.a *.o *.so *.gch encode decode cmp