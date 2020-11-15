main: main.o message.o
	g++ -o main main.o message.o

main.o: main.cpp message.h
	g++ -o main.cpp

message.o: message.cpp message.h
	g++ -o message.cpp