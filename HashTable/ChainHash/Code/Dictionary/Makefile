build_Main: Main.o Cell.o Dictionary.o
	g++ Main.o Cell.o Dictionary.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Cell.o: Cell/Cell.cpp Cell/Cell.h
	g++ -c Cell/Cell.cpp

Dictionary.o: Dictionary/Dictionary.cpp Dictionary/Dictionary.h
	g++ -c Dictionary/Dictionary.cpp

clean: 
	rm *.o Main
