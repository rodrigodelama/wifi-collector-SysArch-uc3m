main: cells.o collect.o main.o quit.o

cells.o:
	gcc -c src/cells.c
collect.o:
	gcc -c src/collect.c
main.o:
	gcc -c src/main.c
quit.o:
	gcc -c src/quit.c

clean:
	rm main \
	*.o
