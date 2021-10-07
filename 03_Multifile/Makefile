GENERATES = prog README prog-a prog-so
TRASH = *.o *~ *.a o.* *.txt

%.o:	%.c
	cc $< -c -o $@

all:	README prog prog-a prog-so

prog:	const.o fun.o prog.o
	cc $^ -o $@

prog-a:	prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o $@

prog-so:	prog.o liboutput.so
	cc -L. prog.o -loutput -o $@

liboutput_static.a:	fun.o const.o
	ar -rcs $@ const.o fun.o

liboutput.so:	fun.o const.o
	cc -shared $^ -o $@

fun.o:	outlib.h

clean:
	rm -f $(TRASH)

distclean:	clean
	rm -rf $(GENERATES)
