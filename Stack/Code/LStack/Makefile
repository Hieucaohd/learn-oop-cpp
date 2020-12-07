output: Main.o Stack.o Nope.o 
	g++ Main.o Stack.o Nope.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Stack.o: Stack/Stack.cpp Stack/Stack.h
	g++ -c Stack/Stack.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

clean: 
	rm *.o Main

