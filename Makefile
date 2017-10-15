# -fPIC = Necessary when using -shared

CC = gcc

all: lib electrotest

lib: libcomponent libpower libresistance

electrotest:
	ar rcs libcomponent.a libcomponent.o
	ar rcs libpower.a libpower.o
	ar rcs libresistance.a libresistance.o
	$(CC) -static src/main.c -o electrotest -L. -lcomponent -lpower -lresistance

libcomponent:	src/libcomponent.c src/libcomponent.h
	$(CC) -c -fPIC src/libcomponent.c
	$(CC) -shared -o libcomponent.so libcomponent.o

libpower:	src/libpower.c src/libpower.h
	$(CC) -c -fPIC src/libpower.c
	$(CC) -shared -o libpower.so libpower.o

libresistance:	src/libresistance.c src/libresistance.h
	$(CC) -c -fPIC src/libresistance.c
	$(CC) -shared -o libresistance.so libresistance.o

testpower:	src/test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static src/test_libpower.c -o testpower -L. -lpower

testresistance:	src/test_libresistance.c libresistance
	ar rcs libresistance.a libresistance.o
	$(CC) -static src/test_libresistance.c -o testresistance -L. -lresistance
	
clean:
	rm -f *.a *.so *.o electrotest testpower testresistance

install: lib electrotest
	install electrotest /usr/local/bin/electrotest
	install libcomponent.so /usr/lib
	install libpower.so /usr/lib
	install libresistance.so /usr/lib

uninstall:
	rm -f /usr/local/bin/electrotest
	rm -f /usr/libcomponent.so
	rm -f /usr/libpower.so
	rm -f /usr/libresistance.so
