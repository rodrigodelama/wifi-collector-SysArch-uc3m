main: cells.o collect.o display.o main.o quit.o

cells.o:
	gcc -c src/cells.c
collect.o:
	gcc -c src/collect.c
display.o:
	gcc -c src/display.c
main.o:
	gcc -c src/main.c
quit.o:
	gcc -c src/quit.c

clean:
	rm main \
	*.o
