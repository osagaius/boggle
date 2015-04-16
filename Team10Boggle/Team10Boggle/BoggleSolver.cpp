#include "BoggleSolver.h"
#include "FileIO.h"

using namespace fileio;
using namespace System;

namespace model
{
	BoggleSolver::BoggleSolver(Trie^ lexicon, array<String^, 2>^ board)
	{
		FileIO^ fileio = gcnew FileIO();
		this->generateWords(lexicon, board);
		this->words = gcnew List<String^>();
	}

	/// <summary>
	/// Generates the words.
	/// </summary>
	/// <param name="lexicon">The lexicon.</param>
	/// <param name="board">The board.</param>
	void BoggleSolver::generateWords(Trie^ lexicon, array<String^, 2>^ board) {
		List<String^>^  result = gcnew List<String^>();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array<boolean, 2>^ tracker = gcnew array<boolean, 2>(4, 4);
				solveBoard(board, tracker, lexicon, board[i,j] + "", i, j, result);
			}
		}
		this->words = result;
	}

	void BoggleSolver::solveBoard(array<String^, 2>^ board, array<boolean, 2>^ tracker, Trie^ lexicon, String^ word, int x, int y, List<String^>^ result) {
		if (lexicon->searchWord(word))
		{
			result->Add(word);
		}

		if (!lexicon->isPrefix(word))
		{
			return;
		}

		array<boolean, 2>^ tmp = gcnew array<boolean, 2>(4, 4);
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
	}

}
