TicTacToe: main.o TicTacToe.o
	gcc -o TicTacToe main.o TicTacToe.o

main.o: main.c TicTacToe.h
	gcc -c main.c

TicTacToe.o: TicTacToe.c TicTacToe.h
	gcc -c TicTacToe.c

clean :
	rm -f *.o TicTacToe 
