main: 
	gcc -g *.c -o hsh

flags:
	gcc -g *.c -Wall -Werror -Wextra -pedantic -o hsh

clean:
	rm -f *~

valgrind: main
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./hsh
