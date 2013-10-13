all: lib prog
	LD_LIBRARY_PATH=./ ./badass

prog:
	gcc -Wall -Wextra -o badass badass.c -ldl

lib:
	gcc -Wall -Wextra -c -fPIC libbadass.c -o libbadass.o -pthread
	gcc -shared -o libbadass.so libbadass.o -pthread

clean:
	rm -rf badass libbadass.so libbadass.o
