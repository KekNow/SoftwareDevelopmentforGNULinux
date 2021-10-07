CFLAGS = -fPIC
GENERATES = prog *.a *.so prog-a prog-so
TRASH = *.o *~ o.* *.txt

all:	test

liboutput_static.a:	fun.o const.o
	ar -rcs $@ const.o fun.o

liboutput.so:	fun.o const.o
	cc -shared $^ -o $@

prog:	const.o fun.o prog.o
	cc $^ -o $@

prog-a:	prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o $@

prog-so:	prog.o liboutput.so
	cc -L. prog.o -loutput -o $@
	
fun.o:	outlib.h

test_prog: prog
	./prog 2> err.txt 1> res.txt
	./prog a1 2>> err.txt 1>> res.txt
	./prog a1 a2 a3 2>> err.txt 1>> res.txt
	sed 's/prog/<progs>/' err.txt > err.txt

test_prog_a: prog-a
	./prog-a 2> err_a.txt 1> res_a.txt
	./prog-a a1 2>> err_a.txt 1>> res_a.txt
	./prog-a a1 a2 a3 2>> err_a.txt 1>> res_a.txt
	sed 's/prog-a/<progs>/' err_a.txt > err_a.txt

test_prog_so: prog-so
	LD_LIBRARY_PATH=`pwd` ./prog-so 2> err_so.txt 1> res_so.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so a1 2>> err_so.txt 1>> res_so.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so a1 a2 a3 2>> err_so.txt 1>> res_so.txt
	sed 's/prog-so/<progs>/' err_so.txt > err_so.txt

test:	test_prog test_prog_a test_prog_so
	cmp err.txt err_a.txt
	cmp err.txt err_so.txt
	cmp err_a.txt err_so.txt
	cmp res.txt res_a.txt
	cmp res.txt res_so.txt
	cmp res_a.txt res_so.txt

clean:
	rm -f $(TRASH)

distclean:	clean
	rm -rf $(GENERATES)
