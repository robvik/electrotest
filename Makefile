# -lm = Compile against the math lib
# -fPIC = Necessary when using -shared

CC = gcc

all: lib electrotest

lib: libcomponent libpower libresistance

electrotest:
	ar rcs libcomponent.a libcomponent.o
	ar rcs libpower.a libresistance.o
	ar rcs libresistance.a libresistance.o
	$(CC) -static src/main.c -o electrotest -L. -lcomponent -lpower -lresistance

libcomponent:	src/libcomponent.c src/libcomponent.h
	$(CC) -c -fPIC src/libcomponent.c
	$(CC) -shared -o libcomponent.so libcomponent.o

libpower:	src/libpower.c src/libpower.h
	$(CC) -c -fPIC src/libpower.c -lm
	$(CC) -shared -o libpower.so libpower.o

libresistance:	src/libresistance.c src/libresistance.h
	$(CC) -c -fPIC src/libresistance.c
	$(CC) -shared -o libresistance.so libresistance.o

testpower:	src/test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static src/test_libpower.c -o testpower -L. -lpower

clean:
	rm -f *.a *.so *.o electrotest testpower
