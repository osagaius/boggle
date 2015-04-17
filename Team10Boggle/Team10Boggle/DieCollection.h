#pragma once
#include "Die.h"
namespace model
{
	/// <summary>
	/// Models a collection of die.
	/// </summary>
	ref class DieCollection
	{

	public:
		DieCollection();
		void generateListOfDie();
		Die^ getRandomDie();

	private:
		List<Die^>^ listOfDie;
	};
}


