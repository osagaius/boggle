#pragma once
#include <windows.h>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include "Trie.h"
#include "Word.h"
#include "Vertex.h"
using namespace model;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::ComponentModel;

/// <summary>
/// Solves a specified Boggle board using
/// depth first search.
/// </summary>
namespace model
{

	ref class BoggleSolver
	{
	public:
		BoggleSolver(Trie^ trie, array<String^, 2>^ board);
		void generateWords(array<String^, 2>^ board);

		property BindingList<Word^>^ Words
		{
			BindingList<Word^>^ get(){ return this->validWords; };
		}

	private:
		List<String^>^ allWords;
		BindingList<Word^>^ validWords;
		List<Vertex^>^ items;
		Trie^ lexicon;
		void depthFirstSearch(Vertex^ vertex, String^ currentWord);
		void generateAllWords();
		void setValidWords();
		array<Vertex^, 2>^ getBoard(array<String^, 2>^ board);
	};

}
