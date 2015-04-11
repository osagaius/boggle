#include "Die.h"
#include <random>
#include <time.h>
Die::Die(String^ firstLetter, String^ secondLetter, String^ thirdLetter, String^ fourthLetter, String^ fifthLetter, String^ sixthLetter){
	this->faces = gcnew array < String^ >{ firstLetter, secondLetter, thirdLetter, fourthLetter, fifthLetter, sixthLetter };
	this->roll();
}

void Die::roll(){
	uniform_int_distribution<int> distribution(0, 5);
	unsigned int dieNumber = distribution(default_random_engine(time(NULL)));
	this->dieLetter = this->faces[dieNumber];
}
