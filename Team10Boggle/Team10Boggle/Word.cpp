
#include "Word.h"

namespace model{
	/// <summary>
	/// Initializes a new instance of the <see cref="Word"/> class.
	/// </summary>
	Word::Word(void)
	{
		this->contents = "";
		this->letterCount = 0;
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="Word"/> class.
	/// </summary>
	/// <param name="value">The value.</param>
	Word::Word(String^ value)
	{
		this->contents = value;
		this->letterCount = value->Length;
		Dictionary<String^, String^> dict;
	}

	/// <summary>
	/// Overloads the == operator for word.
	/// </summary>
	/// <param name="first">The first.</param>
	/// <param name="second">The second.</param>
	/// <returns></returns>
	static bool operator ==(Word^ first, Word^ second){
		return first->value == second->value;
	}

	/// <summary>
	/// Checks for equality with the specified object.
	/// </summary>
	/// <param name="obj">The object.</param>
	/// <returns></returns>
	bool Word::Equals(Object^ obj){
		if (obj == nullptr || GetType() != obj->GetType()){
			return false;
		}

		Word^ word = dynamic_cast<Word^>(obj);

		return (this->value == word->value);
	}

	/// <summary>
	/// Returns a string representation of the word.
	/// </summary>
	/// <returns></returns>
	String^ Word::ToString()
	{
		return this->contents;
	}

	/// <summary>
	/// Gets the midpoint.
	/// </summary>
	/// <param name="first">The first.</param>
	/// <param name="last">The last.</param>
	/// <returns></returns>
	int Word::getMidpoint(int first, int last) {
		return (last + first) / 2;
	}

	/// <summary>
	/// Performs a binary search.
	/// </summary>
	/// <param name="wordList">The word list.</param>
	/// <param name="first">The first.</param>
	/// <param name="last">The last.</param>
	/// <returns></returns>
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

}