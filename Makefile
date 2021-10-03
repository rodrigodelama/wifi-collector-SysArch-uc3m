main: main.o

main.o:
	gcc -c src/main.c
clean:
	rm main \
	   *.o
