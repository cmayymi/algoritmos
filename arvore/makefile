all: BinTree
	@$(MAKE) --no-print-directory clean

BinTree: main.o libBinTree.a
	gcc -o BinTree main.o -L. -lBinTree -lm -g

main.o: main.c BinTree.h
	gcc -c main.c

libBinTree.a: BinTree.o
	ar rcs libBinTree.a BinTree.o
   
BinTree.o: BinTree.c BinTree.h
	gcc -c BinTree.c

clean:
	rm -f *.o *.a

.PHONY: all clean