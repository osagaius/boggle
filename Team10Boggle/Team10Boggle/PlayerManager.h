#pragma once
using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
#include "Player.h"
#include "FileIO.h"

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
		void updatePlayer(String^ name, int newScore);

		property List<Player^>^ Players
		{
			List<Player^>^ get(){ return this->players; };
		}
		
	private:
		List<Player^>^ players;
		bool playerExists(String^ name);
	};

}