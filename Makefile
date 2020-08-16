
vpath %.c src

.PHONY: all
all: l18n

l18n: main.o
	gcc -std=c17 -Wall -Wextra -O3 -march=native -DLOCAL_LOCALE_DIRECTORY -o $@ $^

main.o: main.c
	gcc -std=c17 -Wall -Wextra -O3 -march=native -DLOCAL_LOCALE_DIRECTORY -c -o $@ $^

.PHONY: clean
clean:
	rm -f *.o l18n
