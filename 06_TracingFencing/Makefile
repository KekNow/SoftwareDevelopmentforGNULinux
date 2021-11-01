TRASH = move protect.so *file.txt 

protect: protect.c
	cc -shared -fPIC -Wall protect.c -o protect.so -ldl

move:	move.c
	gcc move.c -o move -O0

inputs: source.txt
	cp source.txt infile.txt
	cp source.txt PROTECT_infile.txt

internal_test: protect move inputs test1 test2 clean

test1:	move
	./move infile.txt outfile.txt

test2:	move
	LD_PRELOAD=`pwd`/protect.so ./move PROTECT_infile.txt PROTECT_outfile.txt
	test -f `pwd`/PROTECT_infile.txt && echo "INPUT FILE PROTECT_infile.txt EXIST"

tests:	protect move tests.sh
	./tests.sh

clean:
	rm -rf $(TRASH)
