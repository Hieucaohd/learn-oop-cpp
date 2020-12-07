output: Main.o LinkedList.o ListIterator.o Nope.o
	g++ Main.o LinkedList.o ListIterator.o Nope.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

LinkedList.o: LinkedList/LinkedList.cpp LinkedList/LinkedList.h
	g++ -c LinkedList/LinkedList.cpp

ListIterator.o: ListIterator/ListIterator.cpp ListIterator/ListIterator.h
	g++ -c ListIterator/ListIterator.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

clean: 
	rm *.o Main

