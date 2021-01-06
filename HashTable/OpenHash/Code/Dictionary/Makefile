build_Main: Main.o Dictionary.o Entry.o
	g++ Main.o Dictionary.o Entry.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Dictionary.o: Dictionary/Dictionary.cpp Dictionary/Dictionary.h
	g++ -c Dictionary/Dictionary.cpp

Entry.o: Entry/Entry.cpp Entry/Entry.h
	g++ -c Entry/Entry.cpp

clean: 
	rm *.o Main

