#pragma once
#include <windows.h>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include "Trie.h"
#include "Word.h"
#include "PlayerManager.h"
#include "BoggleSolver.h"
using namespace model;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::ComponentModel;


/// <summary>
/// Models a Boggle game.
/// </summary>
namespace model{

	ref class Boggle : INotifyPropertyChanged
	{

	public:
		Boggle(array<String^, 2>^ board);
		virtual event PropertyChangedEventHandler^ PropertyChanged;
		virtual void OnPropertyChanged(String^ property);
		void addWord(Word^ word);
		bool isDefinedWord(Word^ word);
		void scoreWord(Word^ word);
		void sortPlayersByScore();

#pragma region Properties
		property BindingList<Word^>^ PlayersWords{
			BindingList<Word^>^ get(){ return this->submittedWords; }
			void set(BindingList<Word^>^ listOfWords){ this->submittedWords = listOfWords; }
		}
		property BindingList<Word^>^ AllPossibleWords{
			BindingList<Word^>^ get(){ return this->allPossibleWords; }
			void set(BindingList<Word^>^ listOfWords){ this->allPossibleWords = listOfWords; }
		}
		property Trie^ Dictionary{
			Trie^ get(){ return this->dictionary; }
		}

		property int PlayerScore{
			int get(){ return this->score; }
			void set(int value){ this->score = value; OnPropertyChanged("PlayerScore"); }
		}

		property PlayerManager^ Players{
			PlayerManager^ get(){ return this->playerManager; }
		}
#pragma endregion

	private:
		Trie^ dictionary;
		array<String^, 2>^ board;
		BoggleSolver^ boggleSolver;
		BindingList<Word^>^ submittedWords;
		int score;
		PlayerManager^ playerManager;
		BindingList<Word^>^ allPossibleWords;
	};
}
