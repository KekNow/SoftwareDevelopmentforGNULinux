TRASH = move protect.so *.txt 

protect: protect.c
	gcc -shared -fPIC -Wall protect.c -o protect.so -ldl

move:	move.c
	gcc move.c -o move -O0

test:	protect move test1 test2

test1:	move.c
	cp -R move.c infile.txt
	./move infile.txt outfile.txt

test2:	move.c
	cp -R move.c PROTECT_infile.txt
	LD_PRELOAD=`pwd`/protect.so ./move PROTECT_infile.txt PROTECT_outfile.txt
	test -f `pwd`/PROTECT_infile.txt && echo "Input file PROTECT_infile.txt exist"


clean:
	rm -rf $(TRASH)
