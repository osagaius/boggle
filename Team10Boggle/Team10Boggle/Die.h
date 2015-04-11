#pragma once


using namespace std;
using namespace System;
using namespace System::Collections::Generic;


ref class Die{

public:
	Die(String^ firstLetter, String^ secondLetter, String^ thirdLetter, String^ fourthLetter, String^ fifthLetter, String^ sixthLetter);
	void roll();
	property String^ letter{
		String^ get(){ return this->dieLetter; }
		void set(String^ value){ this->dieLetter = value; }
	}
private:
	String^ dieLetter;
	array<String^>^ faces;
};


