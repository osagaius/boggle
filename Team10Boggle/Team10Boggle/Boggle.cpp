#include <windows.h>
#include "Boggle.h"
#include "FileIO.h"

/// <summary>
/// Models a Boggle game.
/// </summary>
using namespace fileio;
namespace model{
	/// <summary>
	/// Initializes a new instance of the <see cref="Boggle"/> class.
	/// </summary>
	Boggle::Boggle()
	{
		FileIO^ fileio = gcnew FileIO();
		this->score = 0;
		this->dictionary = fileio->loadDictionary();
		this->submittedWords = gcnew BindingList<Word^>();
		this->playerManager = gcnew PlayerManager();
		this->playerManager->Players = fileio->loadPlayers();
	}

	/// <summary>
	/// Sorts the players by score.
	/// </summary>
	void Boggle::sortPlayersByScore(){
		this->playerManager->Players->Sort();
		this->playerManager->Players->Reverse();
	}

	/// <summary>
	/// Adds the word.
	/// </summary>
	/// <param name="word">The word.</param>
	void Boggle::addWord(Word^ word){
		this->submittedWords->Add(word);
	}

	/// <summary>
	/// Called when [property changed].
	/// </summary>
	/// <param name="property">The property.</param>
	void Boggle::OnPropertyChanged(String^ property)
	{
		 PropertyChanged(this, gcnew PropertyChangedEventArgs(property));
	}

	/// <summary>
	/// Scores the word.
	/// </summary>
	/// <param name="word">The word.</param>
	void Boggle::scoreWord(Word^ word){
		switch (word->length)
		{
			case 3:
				this->PlayerScore += 1;
				break;
			case 4:
				this->PlayerScore += 1;
				break;
			case 5:
				this->PlayerScore += 2;
				break;
			case 6:
				this->PlayerScore += 3;
				break;
			case 7:
				this->PlayerScore += 5;
				break;
			case 8:
				this->PlayerScore += 11;
				break;
			default:
				this->PlayerScore += 0;
				break;
		}
	}

	/// <summary>
	/// Determines whether [is defined word] [the specified word].
	/// </summary>
	/// <param name="word">The word.</param>
	/// <returns></returns>
	bool Boggle::isDefinedWord(Word^ word){
		return this->dictionary->searchWord(word->value);
	}
}