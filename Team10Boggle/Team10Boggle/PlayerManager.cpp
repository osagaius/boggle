#include "PlayerManager.h"

/// <summary>
/// Models a collection of Players.
/// </summary>
namespace model
{
	PlayerManager::PlayerManager()
	{
		this->players = gcnew List<Player^>();
	}


	PlayerManager::~PlayerManager()
	{
	}

	void PlayerManager::loadPlayers()
	{

	}

}
