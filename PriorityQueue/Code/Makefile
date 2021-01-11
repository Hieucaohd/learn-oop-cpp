build_Main: Main.o PriorityQueue.o Nope.o
	g++ Main.o PriorityQueue.o Nope.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

PriorityQueue.o: PriorityQueue/PriorityQueue.h PriorityQueue/PriorityQueue.cpp
	g++ -c PriorityQueue/PriorityQueue.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

clean:
	rm *.o Main
