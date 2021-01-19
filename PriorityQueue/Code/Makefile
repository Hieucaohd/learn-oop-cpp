build_Main: Main.o PriorityQueue.o Nope.o HuffmanCode.o
	g++ Main.o PriorityQueue.o Nope.o HuffmanCode.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

PriorityQueue.o: PriorityQueue/PriorityQueue.h PriorityQueue/PriorityQueue.cpp
	g++ -c PriorityQueue/PriorityQueue.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

HuffmanCode.o: HuffmanCode/HuffmanCode.cpp HuffmanCode/HuffmanCode.h
	g++ -c HuffmanCode/HuffmanCode.cpp

clean:
	rm *.o Main
