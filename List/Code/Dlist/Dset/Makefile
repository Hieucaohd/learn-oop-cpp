build_Main: Main.o Dset.o Dlist.o DlistIterator.o
	g++ Main.o Dset.o Dlist.o DlistIterator.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Dset.o: Dset/Dset.cpp Dset/Dset.h
	g++ -c Dset/Dset.cpp

Dlist.o: Dlist/Dlist.cpp Dlist/Dlist.h
	g++ -c Dlist/Dlist.cpp

DlistIterator.o: DlistIterator/DlistIterator.cpp DlistIterator/DlistIterator.h
	g++ -c DlistIterator/DlistIterator.cpp

clean: 
	rm *.o Main
