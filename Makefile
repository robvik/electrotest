CC = gcc

all: testpower

testpower:	src/test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static src/test_libpower.c -o testpower -L. -lpower -lm

libpower:	src/libpower.c src/libpower.h
	$(CC) -c -fPIC src/libpower.c -lm
	$(CC) -shared -o libpower.so libpower.o -lm

clean:
	rm -f libpower.so libpower.o testpower libpower.a
