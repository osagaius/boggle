#pragma once
using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

namespace model{
	/// <summary>
	/// Models a Word object in the Boggle game.
	/// </summary>
	ref class Word : public Object
	{
	public:
		Word(String^ value);
		Word(void);
		virtual bool Equals(Object^ obj) override;
		virtual String^ ToString() override;
		int getMidpoint(int first, int last);
		bool binarySearch(List<String^>^ wordList, int first, int last);

#pragma region Properties
		property String^ value{
			String^ get(){ return this->contents; }
			void set(String^ letter){ this->contents = letter; }
		}
		property int length{
			int get(){ return this->letterCount; };
			void set(int value){ this->letterCount = value; };
		}
#pragma endregion


	private:
		String^ contents;
		int letterCount;
	};
}
