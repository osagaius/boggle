#pragma once
#include <windows.h>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include "Trie.h"
#include "Word.h"
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

		property int PlayerScore{
			int get(){ return this->score; }
			void set(int value){ this->score = value; OnPropertyChanged("PlayerScore"); }
		}
		void addWord(Word^ word);
		bool isDefinedWord(Word^ word);
		void scoreWord(Word^ word);
	private:
		Trie^ dictionary;
		BindingList<Word^>^ submittedWords;
		int score;
	};
}
