#include "Trie.h"

using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

namespace model{

	/// <summary>
	/// Initializes a new instance of the <see cref="Trie"/> class.
	/// </summary>
	Trie::Trie()
	{
		this->root = gcnew Node();
	}

	/// <summary>
	/// Adds the word.
	/// </summary>
	/// <param name="word">The word.</param>
	void Trie::addWord(String^ word){
		Node^ current = this->root;

		if (word->Length == 0){
			current->marker = true;
			return;
		}

		for (int i = 0; i < word->Length; i++)
		{
			Node^ child = current->getChild(word[i]);

			if (child != nullptr)
			{
				current = child;
			}
			else
			{
				Node^ tmp = gcnew Node(word[i]);
				current->addChild(tmp);
				current = tmp;
			}
			if (i == word->Length - 1){
				current->marker = true;
			}
		}
	}

	/// <summary>
	/// Searches the word.
	/// </summary>
	/// <param name="word">The word.</param>
	/// <returns></returns>
	bool Trie::searchWord(String^ word){

		word = word->ToLower();
		Node^ current = this->root;

		while (current != nullptr){

			for (int i = 0; i < word->Length; i++){
				Node^ tmp = current->getChild(word[i]);

				if (tmp == nullptr){
					return false;
				}
				current = tmp;
			}

			if (current->marker == true){
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	/// <summary>
	/// Determines whether the specified word is prefix.
	/// </summary>
	/// <param name="word">The word.</param>
	/// <returns></returns>
	bool Trie::isPrefix(String^ word){

		Node^ current = this->root;
		int i;
		while (current->getChildren() != nullptr){
			for (i = 0; i < word->Length; i++){

				Node^ tmp = current->getChild(word[i]);

				if (tmp == nullptr){
					return false;
				}

				current = tmp;
			}
			return true;
		}
		
		return false;
	}
}