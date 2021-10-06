main: main.o quit.o collect.o display.o

main.o:
	gcc -c src/main.c
quit.o:
	gcc -c src/quit.c
collect.o:
	gcc -c src/collect.c
display.o:
	gcc -c src/display.c

clean:
	rm main \
	*.o
