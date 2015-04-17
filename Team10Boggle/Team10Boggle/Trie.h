#pragma once

#include "Node.h"
using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
namespace model{
	/// <summary>
	/// Models a Trie data structure.
	/// </summary>
	ref class Trie
	{

	public:
		Trie();
		void addWord(String^ word);
		bool searchWord(String^ word);
		bool isPrefix(String^ word);

	private:
		Node^ root;
	};
}
