#include "FileIO.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
namespace fileio{
	FileIO::FileIO()
	{

	}

	Trie^ FileIO::loadDictionary(){
		Trie^ trie = gcnew Trie();

		String^ fileName = L"dictionary.txt";

		try {
			StreamReader^ input = File::OpenText(fileName);

			String^ line;
			while ((line = input->ReadLine()) != nullptr) {
				trie->addWord(line);
			}
			input->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}

		return trie;
	}
}