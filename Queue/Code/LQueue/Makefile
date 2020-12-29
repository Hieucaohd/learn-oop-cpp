build_Main: Main.o Nope.o Queue.o
	g++ Main.o Nope.o Queue.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

Queue.o: Queue/Queue.cpp Queue/Queue.h
	g++ -c Queue/Queue.cpp

clean: 
	rm *.o Main
