main: main.o quit.o

main.o:
	gcc -c src/main.c
quit.o:
	gcc -c src/quit.c
clean:
	rm main \
	   *.o
