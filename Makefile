CC = gcc

all: lib electrotest
	ar rcs libcomponent.a libcomponent.o
	ar rcs libpower.a libresistance.o
	ar rcs libresistance.a libresistance.o

lib: libcomponent libpower libresistance

electrotest:
	$(CC) -o electrotest src/main.c -lcomponent -lpower -lresistance -lm

libcomponent:	src/libcomponent.c src/libcomponent.h
	$(CC) -c -fPIC src/libcomponent.c -lm
	$(CC) -shared -o libcomponent.so libcomponent.o -lm

libpower:	src/libpower.c src/libpower.h
	$(CC) -c -fPIC src/libpower.c -lm
	$(CC) -shared -o libpower.so libpower.o -lm

libresistance:	src/libresistance.c src/libresistance.h
	$(CC) -c -fPIC src/libresistance.c -lm
	$(CC) -shared -o libresistance.so libresistance.o -lm

testpower:	src/test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static src/test_libpower.c -o testpower -L. -lpower -lm

clean:
	rm -f *.a *.so *.o testpower
