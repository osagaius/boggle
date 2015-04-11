
#include "Word.h"

namespace model{
	Word::Word(void)
	{
		this->contents = "";
		this->letterCount = 0;
	}

	Word::Word(String^ value)
	{
		this->contents = value;
		this->letterCount = value->Length;
		Dictionary<String^, String^> dict;
	}

	static bool operator ==(Word^ first, Word^ second){
		return first->value == second->value;
	}

	bool Word::Equals(Object^ obj){
		if (obj == nullptr || GetType() != obj->GetType()){
			return false;
		}

		Word^ word = dynamic_cast<Word^>(obj);

		return (this->value == word->value);
	}
	String^ Word::ToString()
	{
		return this->contents;
	}

}