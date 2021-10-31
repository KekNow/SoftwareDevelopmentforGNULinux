TRASH = move *file.txt

move:	move.c
	gcc move.c -o move -O0
	cp -R move.c infile.txt

test:	move test1

test1:	move infile.txt
	./move infile.txt outfile.txt

clean:
	rm -rf $(TRASH)