#include "FileIO.h"
#include "PlayerManager.h"

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

	List<Player^>^ FileIO::loadPlayers(){
		List<Player^>^ players = gcnew List<Player^>();

		String^ fileName = L"players.txt";

		try {
			StreamReader^ input = File::OpenText(fileName);

			String^ line;
			while ((line = input->ReadLine()) != nullptr) {
				array<String^>^ playerInfo = splitString(line);
				Player^ newPlayer = gcnew Player(playerInfo[0], Convert::ToInt32(playerInfo[1]));
				players->Add(newPlayer);
			}
			input->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}

		return players;
	}

	void FileIO::savePlayers(List<Player^>^ players){
		String^ fileName = L"players.txt";

		try {
			StreamWriter^ output = gcnew StreamWriter(fileName);

			for each (Player^ currPlayer in players)
			{
				output->WriteLine(currPlayer->Name, currPlayer->Score);
			}
			output->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}
	}

	array<String^>^ FileIO::splitString(String^ text) {
		String^ delimStr = ",";
		Console::WriteLine("delimiter : '{0}'", delimStr);
		array<Char>^ delimiter = delimStr->ToCharArray();
		array<String^>^ words;
		String^ line = "one,two";

		Console::WriteLine("text : '{0}'", line);
		words = line->Split(delimiter);
		Console::WriteLine("Number of Words : {0}", words->Length);
		return words;
	}
}