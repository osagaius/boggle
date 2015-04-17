#include "BoggleSolver.h"
#include "FileIO.h"

using namespace fileio;
using namespace System;

/// <summary>
/// Solves a specified Boggle board using
/// depth first search.
/// </summary>
namespace model
{
	const int boardLength = 4;

	/// <summary>
	/// Initializes a new instance of the <see cref="BoggleSolver"/> class.
	/// </summary>
	/// <param name="lexicon">The lexicon.</param>
	/// <param name="board">The board.</param>
	BoggleSolver::BoggleSolver(Trie^ trie, array<String^, 2>^ board)
	{
		this->allWords = gcnew List<String^>();
		this->validWords = gcnew List<String^>();
		items = gcnew List<Vertex^>(16);
		this->lexicon = trie;
		this->generateWords(board);
	}

	/// <summary>
	/// Generates the valid words.
	/// </summary>
	/// <param name="lexicon">The lexicon.</param>
	/// <param name="board">The board.</param>
	void BoggleSolver::generateWords(array<String^, 2>^ board) {

		array<Vertex^, 2>^ boardg = this->getBoard(board);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i > 0){
					boardg[i, j]->addNeighbor(boardg[i - 1, j]);
					if (j > 0){
						boardg[i, j]->addNeighbor(boardg[i, j - 1]);
						boardg[i, j]->addNeighbor(boardg[i - 1, j - 1]);
					}
					if (j < 3){
						boardg[i, j]->addNeighbor(boardg[i, j + 1]);
						boardg[i, j]->addNeighbor(boardg[i - 1, j + 1]);
					}
				}
				if (i < 3){
					boardg[i, j]->addNeighbor(boardg[i + 1, j]);
					if (j > 0){
						boardg[i, j]->addNeighbor(boardg[i, j - 1]);
						boardg[i, j]->addNeighbor(boardg[i + 1, j - 1]);
					}
						
					if (j < 3){
						boardg[i, j]->addNeighbor(boardg[i, j + 1]);
						boardg[i, j]->addNeighbor(boardg[i + 1, j + 1]);
					}
				}
					
				
			}
		}

		this->generateAllWords();
		this->setValidWords();
	}

	/// <summary>
	/// Sets the valid words.
	/// </summary>
	/// <param name="lexicon">The lexicon.</param>
	void BoggleSolver::setValidWords() {
		for each (String^ currWord in this->allWords){
			if (lexicon->searchWord(currWord) && !validWords->Contains(currWord)) {
				this->validWords->Add(currWord);
			}
		}
	}

	/// <summary>
	/// Gets the board.
	/// </summary>
	/// <param name="board">The board.</param>
	/// <returns></returns>
	array<Vertex^, 2>^ BoggleSolver::getBoard(array<String^, 2>^ board) {
		array<Vertex^, 2>^ boardg = gcnew array<Vertex^, 2>(4, 4);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				boardg[i, j] = gcnew Vertex(board[i, j]);
				this->items->Add(boardg[i, j]);
			}
		}
		return boardg;
	}

	/// <summary>
	/// Generates all words.
	/// </summary>
	void BoggleSolver::generateAllWords() {
		for each (Vertex^ vert in this->items){
			this->depthFirstSearch(vert, "");
		}
	}

	/// <summary>
	/// Performs the depth first search recursively.
	/// </summary>
	/// <param name="vertex">The vertex.</param>
	/// <param name="currentWord">The current word.</param>
	void BoggleSolver::depthFirstSearch(Vertex^ vertex, String^ currentWord){
		String^ currentLetter = vertex->visit();
		currentWord += currentLetter;
		if (currentWord->Length > 2){
		this->allWords->Add(currentWord);
		}
		vertex->Visited = true;
		List<Vertex^>^ vertices = vertex->getVertices();
		for each (Vertex^ v in vertices){
			if (v->Visited != true){
				if (this->lexicon->isPrefix((currentWord + v->Item)->ToLower())){

				depthFirstSearch(v, currentWord);
			}
		}
		}

		vertex->Visited = false;
	}

}
