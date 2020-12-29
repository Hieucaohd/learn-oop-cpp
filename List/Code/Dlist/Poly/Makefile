build_Main: Main.o Dlist.o DlistIterator.o Poly.o Term.o
	g++ Main.o Dlist.o DlistIterator.o Poly.o Term.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Dlist.o: Dlist/Dlist.cpp Dlist/Dlist.h
	g++ -c Dlist/Dlist.cpp

DlistIterator.o: DlistIterator/DlistIterator.cpp DlistIterator/DlistIterator.h
	g++ -c DlistIterator/DlistIterator.cpp

Poly.o: Poly/Poly.cpp Poly/Poly.h
	g++ -c Poly/Poly.cpp

Term.o: Term/Term.cpp Term/Term.h
	g++ -c Term/Term.cpp

clean: 
	rm *.o Main
