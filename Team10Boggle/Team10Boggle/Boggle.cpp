#include <windows.h>
#include "Boggle.h"
#include "FileIO.h"

using namespace fileio;
namespace model{
	Boggle::Boggle()
	{
		FileIO^ fileio = gcnew FileIO();
		this->score = 0;
		this->dictionary = fileio->loadDictionary();
		this->submittedWords = gcnew BindingList<Word^>();
		this->playerManager = gcnew PlayerManager();
		this->playerManager->Players = fileio->loadPlayers();
	}

	void Boggle::sortPlayersByScore(){
		this->playerManager->Players->Sort();
		this->playerManager->Players->Reverse();
	}

	void Boggle::addWord(Word^ word){
		this->submittedWords->Add(word);
	}

	 void Boggle::OnPropertyChanged(String^ property)
	{
		 PropertyChanged(this, gcnew PropertyChangedEventArgs(property));
	}

	void Boggle::scoreWord(Word^ word){
		if (word->length == 3 || word->length == 4){
			this->PlayerScore += 1;
		}
		else if (word->length == 5){
			this->PlayerScore += 2;
		}
		else if (word->length == 6){
			this->PlayerScore += 3;
		}
		else if (word->length == 7){
			this->PlayerScore += 5;
		}
		else if (word->length >= 8){
			this->PlayerScore += 11;
		}
	}

	bool Boggle::isDefinedWord(Word^ word){
		return this->dictionary->searchWord(word->value);
	}
}