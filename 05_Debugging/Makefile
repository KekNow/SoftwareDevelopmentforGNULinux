TRASH = range test*.txt out*.txt

range:	range.c
	gcc range.c -o range -g -O0

test:	range test1 test2

test1:	test1.gdb
	gdb --command=test1.gdb ./range | grep @@@ | sed s/@@@// > out1.txt
	cmp out1.txt standart_out1.txt

test2:	test2.gdb
	gdb  --command=test2.gdb ./range | grep @@@ | sed s/@@@// > out2.txt
	cmp out2.txt standart_out2.txt

clean:
	rm -rf $(TRASH)
