# -fPIC = Necessary when using -shared

CC = gcc

MYLIB = ./lib/

all: lib electrotest

lib: libDir libcomponent libpower libresistance

electrotest:
	ar rcs $(MYLIB)libcomponent.a libcomponent.o
	ar rcs $(MYLIB)libpower.a libpower.o
	ar rcs $(MYLIB)libresistance.a libresistance.o
	$(CC) -static src/main.c -o electrotest -L$(MYLIB) -lcomponent -lpower -lresistance
	
libDir:
	mkdir -p lib/

libcomponent:	src/libcomponent.c src/libcomponent.h
	$(CC) -c -fPIC src/libcomponent.c
	$(CC) -shared -o $(MYLIB)libcomponent.so libcomponent.o

libpower:	src/libpower.c src/libpower.h
	$(CC) -c -fPIC src/libpower.c
	$(CC) -shared -o $(MYLIB)libpower.so libpower.o

libresistance:	src/libresistance.c src/libresistance.h
	$(CC) -c -fPIC src/libresistance.c
	$(CC) -shared -o $(MYLIB)libresistance.so libresistance.o

testpower:	src/test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static src/test_libpower.c -o testpower -L$(MYLIB) -lpower

testresistance:	src/test_libresistance.c libresistance
	ar rcs libresistance.a libresistance.o
	$(CC) -static src/test_libresistance.c -o testresistance -L$(MYLIB) -lresistance

testcomponent:	src/test_libComponent.c libcomponent
	ar rcs libcomponent.a libcomponent.o
	$(CC) -static src/test_libcomponent.c -o testcomponent -L$(MYLIB) -lcomponent
	
clean:
	rm -f $(MYLIB)*.a $(MYLIB)*.so *.o electrotest testpower testresistance

install: lib electrotest
	install electrotest /usr/local/bin/electrotest
	install $(MYLIB)libcomponent.so /usr/lib
	install $(MYLIB)libpower.so /usr/lib
	install $(MYLIB)libresistance.so /usr/lib

uninstall:
	rm -f /usr/local/bin/electrotest
	rm -f /usr/libcomponent.so
	rm -f /usr/libpower.so
	rm -f /usr/libresistance.so
