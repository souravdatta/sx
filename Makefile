OBJECTS = lst.o err.o
CFLAGS = -fPIC

all : $(OBJECTS)
	@ar rsc libsx.a $(OBJECTS)
	@gcc -shared -Wl,-soname,libsx.so.1 -o libsx.so.0.1 $(OBJECTS)


.PHONY : test clean clobber fruits

clean :
	@rm -f *.o *.a *.so* *~ lst_test err_test #.*#

test : all lst_test err_test

lst_test : lst_test.c $(OBJECTS)
	gcc -o lst_test lst_test.c -L. -lsx
	./lst_test

err_test: err_test.c $(OBJECTS)
	gcc -o err_test err_test.c -L. -lsx
	./err_test
