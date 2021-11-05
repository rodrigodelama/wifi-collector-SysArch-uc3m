main: cells.o collect.o delete_net.o main.o quit.o

cells.o:
	gcc -Wall -c -g src/cells.c
collect.o:
	gcc -Wall -c -g src/collect.c
delete_net.o:
	gcc -Wall -c -g src/delete_net.c
main.o:
	gcc -Wall -c -g src/main.c
quit.o:
	gcc -Wall -c -g src/quit.c

implement-wifi-collector: cp /.main wifi-collector \
				rm main

clean:
	rm main \
	*.o

//TODO: save .o files to temp obj folder, compile from that folder and then delete it
//TODO: change output name to wifi-collector