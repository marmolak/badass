all: lib prog
	LD_LIBRARY_PATH=./ ./badass

prog:
	gcc -ggdb3 -Wall -Wextra -o badass badass.c -ldl

lib:
	gcc -ggdb3 -Wall -Wextra -c -fPIC libbadass.c -o libbadass.o -pthread
	gcc -ggdb3 -shared -o libbadass.so libbadass.o -pthread

clean:
	rm -rf badass libbadass.so libbadass.o
