CC = g++
CXXFLAGS = -std=c++11
 
all: ClienMain.cpp ServerMain.cpp Server.o Client.o
	$(CC) $(CFLAGS) ServerMain.cpp  Server.o -o chatroom_server
	$(CC) $(CFLAGS) ClienMain.cpp Clien.o -o chatroom_client
 
Server.o: Server.cpp Server.h Common.h
	$(CC) $(CFLAGS) -c Server.cpp
 
Client.o: Clien.cpp Clien.h Common.h
	$(CC) $(CFLAGS) -c Clien.cpp
 
clean:
	rm -f *.o chatroom_server chatroom_client
