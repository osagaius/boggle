#pragma once
using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
#include "Player.h"

/// <summary>
/// Models a collection of Players.
/// </summary>
namespace model
{
	ref class PlayerManager
	{
	public:
		PlayerManager();
		virtual ~PlayerManager();
		void addPlayer(String^ name, int score);
		void updatePlayer(String^ name);
		
	private:
		List<Player^>^ players;
		void loadPlayers();
		void savePlayers();
	};

}