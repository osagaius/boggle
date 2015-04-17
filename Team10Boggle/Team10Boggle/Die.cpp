#include "Die.h"
#include <random>
#include <time.h>
namespace model
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Die"/> class.
	/// </summary>
	/// <param name="firstLetter">The first letter.</param>
	/// <param name="secondLetter">The second letter.</param>
	/// <param name="thirdLetter">The third letter.</param>
	/// <param name="fourthLetter">The fourth letter.</param>
	/// <param name="fifthLetter">The fifth letter.</param>
	/// <param name="sixthLetter">The sixth letter.</param>
	Die::Die(String^ firstLetter, String^ secondLetter, String^ thirdLetter, String^ fourthLetter, String^ fifthLetter, String^ sixthLetter){
		this->faces = gcnew array < String^ >{ firstLetter, secondLetter, thirdLetter, fourthLetter, fifthLetter, sixthLetter };
		this->roll();
	}

	/// <summary>
	/// Rolls this instance.
	/// </summary>
	void Die::roll(){
		uniform_int_distribution<int> distribution(0, 5);
		unsigned int dieNumber = distribution(default_random_engine(time(NULL)));
		this->dieLetter = this->faces[dieNumber];
	}

}