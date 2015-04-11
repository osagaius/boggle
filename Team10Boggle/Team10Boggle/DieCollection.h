#pragma once
#include "Die.h"
ref class DieCollection
{
public:
	DieCollection();
	void generateListOfDie();
	Die^ getRandomDie();
private:
	List<Die^>^ listOfDie;
};


