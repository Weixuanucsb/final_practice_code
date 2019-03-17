all: q11 q12 q13

q11: q11.o
	g++ -o Q11 q11.o

q12: q12.o
	g++ -o Q12 q12.o

q13: q13.o
	g++ -o Q13 q13.o tddFuncs.cpp

q11.o: q11.cpp
	g++ -c g11.cpp

q12.o: q12.cpp
	g++ -c q12.cpp

q13.o: q13.cpp
	g++ -c q13.cpp
