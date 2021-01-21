build_Main: Main.o PriorityQueue.o Nope.o HuffmanCode.o Stack.o NopeStack.o
	g++ Main.o PriorityQueue.o Nope.o HuffmanCode.o Stack.o NopeStack.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

PriorityQueue.o: PriorityQueue/PriorityQueue.h PriorityQueue/PriorityQueue.cpp
	g++ -c PriorityQueue/PriorityQueue.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

HuffmanCode.o: HuffmanCode/HuffmanCode.cpp HuffmanCode/HuffmanCode.h
	g++ -c HuffmanCode/HuffmanCode.cpp

Stack.o: Stack/Stack.cpp Stack/Stack.h
	g++ -c Stack/Stack.cpp

NopeStack.o: NopeStack/NopeStack.cpp NopeStack/NopeStack.h
	g++ -c NopeStack/NopeStack.cpp

clean:
	rm *.o Main
