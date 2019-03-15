all: q12 q13

q12: q12.cpp
	g++ -o Q12 q12.cpp

q13: q13.cpp
	g++ -o Q13 q13.cpp tddFuncs.cpp
