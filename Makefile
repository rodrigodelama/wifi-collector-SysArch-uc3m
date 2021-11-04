main: cells.o collect.o main.o quit.o delete_net.o

cells.o:
	gcc -c src/cells.c
collect.o:
	gcc -c src/collect.c
main.o:
	gcc -c src/main.c
quit.o:
	gcc -c src/quit.c
delete_net.o:
	gcc -c src/delete_net.c

implement-wifi-collector: cp /.main wifi-collector \
				rm main

clean:
	rm main \
	*.o

//TODO: save .o files to temp obj folder, compile from that folder and then delete it
//TODO: change output name to wifi-collector