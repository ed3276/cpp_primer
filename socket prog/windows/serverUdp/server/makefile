obj = serverUdp.o
serverUdp : $(obj)
	gcc -o serverUdp $(obj)
serverUdp.o : serverUdp.c
	gcc -c serverUdp.c -o serverUdp.o
	
clean :
	delete serverUdp $(obj)
