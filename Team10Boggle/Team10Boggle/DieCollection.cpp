#include "DieCollection.h"
#include <random>
#include <time.h>

using namespace std;

DieCollection::DieCollection()
{
	this->listOfDie = gcnew List<Die^>();
	this->generateListOfDie();
}

void DieCollection::generateListOfDie(){
	this->listOfDie->Add(gcnew Die("R", "I", "F", "O", "B", "X"));
	this->listOfDie->Add(gcnew Die("I", "F", "E", "H", "E", "Y"));
	this->listOfDie->Add(gcnew Die("D", "E", "N", "O", "W", "S"));
	this->listOfDie->Add(gcnew Die("U", "T", "O", "K", "N", "D"));
	this->listOfDie->Add(gcnew Die("H", "M", "S", "R", "A", "O"));
	this->listOfDie->Add(gcnew Die("L", "U", "P", "E", "T", "S"));
	this->listOfDie->Add(gcnew Die("A", "C", "I", "T", "O", "A"));
	this->listOfDie->Add(gcnew Die("Y", "L", "G", "K", "U", "E"));
	this->listOfDie->Add(gcnew Die("Qu", "B", "M", "J", "O", "A"));
	this->listOfDie->Add(gcnew Die("E", "H", "I", "S", "P", "N"));
	this->listOfDie->Add(gcnew Die("V", "E", "T", "I", "G", "N"));
	this->listOfDie->Add(gcnew Die("B", "A", "L", "I", "Y", "T"));
	this->listOfDie->Add(gcnew Die("E", "Z", "A", "V", "N", "D"));
	this->listOfDie->Add(gcnew Die("R", "A", "L", "E", "S", "C"));
	this->listOfDie->Add(gcnew Die("U", "W", "I", "L", "R", "G"));
	this->listOfDie->Add(gcnew Die("P", "A", "C", "E", "M", "D"));
}

Die^ DieCollection::getRandomDie(){
	uniform_int_distribution<int> distribution(0, this->listOfDie->Count - 1);
	unsigned int dieNumber = distribution(default_random_engine(time(NULL)));
	Die^ die = this->listOfDie[dieNumber];
	this->listOfDie->RemoveAt(dieNumber);
	return die;
}


