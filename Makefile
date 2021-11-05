main: cells.o collect.o main.o quit.o

cells.o:
	gcc -c -g src/cells.c
collect.o:
	gcc -c -g src/collect.c
main.o:
	gcc -c -g src/main.c
quit.o:
	gcc -c -g src/quit.c
OLD delete_net.o:
	gcc -c -g src/delete_net.c

implement-wifi-collector: cp /.main wifi-collector \
				rm main

clean:
	rm main \
	*.o

//TODO: save .o files to temp obj folder, compile from that folder and then delete it
//TODO: change output name to wifi-collector