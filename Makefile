CC = gcc

all: testpower
#all: lib electrotest
	#ar rcs libcomponent.a libcomponent.o
	#ar rcs libpower.a libresistance.o
	#ar rcs libresistance.a libresistance.o

#lib: libcomponent libpower libresistance

#electrotest:

libpower:	src/libpower.c src/libpower.h
	$(CC) -c -fPIC src/libpower.c -lm
	$(CC) -shared -o libpower.so libpower.o -lm

testpower:	src/test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static src/test_libpower.c -o testpower -L. -lpower -lm

clean:
	rm -f libpower.so libpower.o testpower libpower.a
