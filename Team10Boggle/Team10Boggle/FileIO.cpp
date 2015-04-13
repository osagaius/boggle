#include "FileIO.h"
#include "PlayerManager.h"
#include <sstream>

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

	PlayerManager^ FileIO::loadPlayers(){
		PlayerManager^ players = gcnew PlayerManager();

		String^ fileName = L"players.txt";

		try {
			StreamReader^ input = File::OpenText(fileName);

			String^ line;
			while ((line = input->ReadLine()) != nullptr) {
				List<String^>^ playerInfo = splitString(line);
				//players->addPlayer(line);
			}
			input->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}

		return players;
	}

	List<String^>^ FileIO::splitString(String^ text) {
		//stringstream ss(text);
		List<String^>^ result = gcnew List<String^>();

		/*while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			result.push_back(substr);
		}*/

		return result;
	}
}