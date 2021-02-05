build_Main: Main.o DynamicSet.o Nope.o 
	g++ Main.o DynamicSet.o Nope.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

DynamicSet.o: DynamicSet/DynamicSet.cpp DynamicSet/DynamicSet.h
	g++ -c DynamicSet/DynamicSet.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

clean:
	rm *.o Main
