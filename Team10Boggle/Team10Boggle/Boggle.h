#pragma once
#include <windows.h>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include "Trie.h"
#include "Word.h"
#include "PlayerManager.h"
using namespace model;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::ComponentModel;

namespace model{
	ref class Boggle : INotifyPropertyChanged
	{

	public:
		Boggle();
		virtual event PropertyChangedEventHandler^ PropertyChanged;
		virtual void OnPropertyChanged(String^ property);


		property BindingList<Word^>^ playersWords{
			BindingList<Word^>^ get(){ return this->submittedWords; }
			void set(BindingList<Word^>^ listOfWords){ this->submittedWords = listOfWords; }
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

		void addWord(Word^ word);
		bool isDefinedWord(Word^ word);
		void scoreWord(Word^ word);
		void sortPlayersByScore();
	private:
		Trie^ dictionary;
		BindingList<Word^>^ submittedWords;
		int score;
		PlayerManager^ playerManager;
	};
}
