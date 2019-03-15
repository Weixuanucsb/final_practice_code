#include <iostream>
#include <string>
#include "tddFuncs.h"

using namespace std;

//returns the number of vowels in a string
int numVowels(string str){

	//what's the simplest case for calculating the number of vowels? An empty string, of course.
	if(str.size() == 0) return 0;

	//now I need to call a function on a smaller input
	int vowelsBefore = numVowels(str.substr(1));

	//now I know how many vowels are in a string that is 1 character shorter (starts with the second letter)
	
	//if i have a string paparazzi, i know that 'aparazzi' contains 4 vowels (I assume that my function works correctly in this step)
	//now I need to figure out what to do with the first character.
	if(str[0] == 'a' || str[0] == 'o' || str[0] == 'e' || str[0] == 'u' || str[0] == 'i') vowelsBefore++;

	//I increas vowelsBefore if the first character is a vowel
	
	return vowelsBefore;


}

int main(){

	assertEquals(2, numVowels("apple"), "numVowels(apple)");
	assertEquals(0, numVowels(""), "numVowels(empty)");
	assertEquals(5, numVowels("kharitonova"), "numVowels(kharitonova)");
	assertEquals(16, numVowels("supercalifragilisticexpialidocious"), "numVoewls(long word)");


	return 0;
}
