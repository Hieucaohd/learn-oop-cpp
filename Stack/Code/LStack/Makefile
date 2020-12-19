build_Main: Main.o Stack.o Nope.o CheckParentheses.o Calculate.o
	g++ Main.o Stack.o Nope.o CheckParentheses.o Calculate.o -o Main

CheckParentheses.o: CheckParentheses/CheckParentheses.cpp CheckParentheses/CheckParentheses.h
	g++ -c CheckParentheses/CheckParentheses.cpp

Calculate.o: Calculate/Calculate.cpp CheckParentheses/CheckParentheses.h
	g++ -c Calculate/Calculate.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

Stack.o: Stack/Stack.cpp Stack/Stack.h
	g++ -c Stack/Stack.cpp

Nope.o: Nope/Nope.cpp Nope/Nope.h
	g++ -c Nope/Nope.cpp

clean: 
	rm *.o Main 

