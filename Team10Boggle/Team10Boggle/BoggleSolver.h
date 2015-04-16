#pragma once
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

namespace model
{
	ref class BoggleSolver
	{
	public:
		BoggleSolver();
		void generateWords(Trie^ dictionary, array<String^, 2>^ board);

		property List<String^>^ Words
		{
			List<String^>^ get(){ return this->words; };
			void set(List<String^>^ listOfWords){ this->words = listOfWords; };
		}

	private:
		List<String^>^ words;
		Trie^ dictionary;
		bool isDefinedWord(String^ word);
		void solveBoard(array<String^, 2>^ board, array<boolean, 2>^ tracker, Trie^ lexicon, String^ word, int x, int y, List<String^>^ result);
	};

}
