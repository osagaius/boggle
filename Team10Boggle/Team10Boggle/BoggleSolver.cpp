#include "BoggleSolver.h"
#include "FileIO.h"

using namespace fileio;
using namespace System;

namespace model
{
	BoggleSolver::BoggleSolver()
	{
		FileIO^ fileio = gcnew FileIO();
		this->words = gcnew List<String^>();
		this->dictionary = fileio->loadDictionary();

	}

	void BoggleSolver::solveBoard(array<String^, 2>^ board, array<boolean, 2>^ tracker, Trie^ lexicon, String^ word, int x, int y, List<String^>^ result) {
		if (lexicon->searchWord(word)) { result->Add(word); }
		//check if the word is a valid prefix
	
		array<boolean, 2>^ tmp;
		Array::Copy(tracker, 0, tmp, 0, tracker->Length);

		tmp[x, y] = true;

		//upper left
		if (0 <= x - 1 && 0 <= y - 1 && !tmp[x - 1, y - 1]){
			solveBoard(board, tmp, lexicon, word + board[x - 1, y - 1], x - 1, y - 1, result);
		}

		//up
		if (0 <= y - 1 && !tmp[x, y - 1]){
			solveBoard(board, tmp, lexicon, word + board[x, y - 1], x, y - 1, result);
		}

		//upper right
		if (x + 1 < board->Length && 0 <= y - 1 && !tmp[x + 1, y - 1]){
			solveBoard(board, tmp, lexicon, word + board[x + 1, y - 1], x + 1, y - 1, result);
		}

		//right
		if (x + 1 < board->Length && !tmp[x + 1, y]){
			solveBoard(board, tmp, lexicon, word + board[x + 1, y], x + 1, y, result);
		}

		//lower right
		if ((x + 1) < board->Length && y + 1 < board->GetLength(0) && !tmp[x + 1, y + 1]){
			solveBoard(board, tmp, lexicon, word + board[x + 1, y + 1], x + 1, y + 1, result);
		}

		//down
		if (y + 1 < board->GetLength(0) && !tmp[x, y + 1]){
			solveBoard(board, tmp, lexicon, word + board[x, y + 1], x, y + 1, result);
		}

		//lower left
		if (0 <= x - 1 && y + 1 < board->GetLength(0) && !tmp[x - 1, y + 1]){
			solveBoard(board, tmp, lexicon, word + board[x - 1, y + 1], x - 1, y + 1, result);
		}

		//left
		if (0 <= x - 1 && !tmp[x - 1, y]){
			solveBoard(board, tmp, lexicon, word + board[x - 1, y], x - 1, y, result);
		}
		this->words = result;
	}

	bool BoggleSolver::isDefinedWord(String^ word){
		return this->dictionary->searchWord(word);
	}
}
