#pragma once
using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

namespace model{
	ref class Word : public Object
	{
	public:
		Word(String^ value);
		Word(void);
		//bool existsInDictionary(List<String^>^ dictionary);
		property String^ value{
			String^ get(){ return this->contents; }
			void set(String^ letter){ this->contents = letter; }
		}
		virtual bool Equals(Object^ obj) override;
		property int length{
			int get(){ return this->letterCount; };
			void set(int value){ this->letterCount = value; };
		}

		int Word::getMidpoint(int first, int last) {
			return (last + first) / 2;
		}

		bool Word::binarySearch(List<String^>^ wordList, int first, int last) {

			if (first > last) {
				return false;
			}

			int mid = this->getMidpoint(first, last);
			if (wordList[mid] == this->value) {

				return true;
			}
			if (String::Compare(wordList[mid], this->value) > 0) {
				return this->binarySearch(wordList, first, mid - 1);
			}
			else {
				return this->binarySearch(wordList, mid + 1, last);
			}

		}
		virtual String^ ToString() override;
	private:
		String^ contents;
		int letterCount;
	};
}
