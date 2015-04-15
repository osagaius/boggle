#pragma once
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include "Trie.h"
#include "PlayerManager.h"
#include "Player.h"
using namespace model;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Text;

namespace fileio{
	ref class FileIO
	{
	public:
		FileIO();
		Trie^ loadDictionary();
		List<Player^>^ loadPlayers();
		void savePlayers(List<Player^>^ players);
	private:
		array<String^>^ splitString(String^ text);
	};
}
