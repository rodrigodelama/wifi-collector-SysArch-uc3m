main: main.o quit.o collect.o

main.o:
	gcc -c src/main.c
quit.o:
	gcc -c src/quit.c
collect.o:
	gcc -c src/collect.c

clean:
	rm main \
	*.o
