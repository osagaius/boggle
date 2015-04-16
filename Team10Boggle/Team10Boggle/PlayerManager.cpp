#include "PlayerManager.h"
#include "Player.h"
using namespace fileio;


/// <summary>
/// Models a collection of Players.
/// </summary>
namespace model
{
	/// <summary>
	/// Initializes a new instance of the <see cref="PlayerManager"/> class.
	/// </summary>
	PlayerManager::PlayerManager()
	{
		this->players = gcnew List<Player^>();
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="PlayerManager"/> class.
	/// </summary>
	PlayerManager::~PlayerManager()
	{
	}

	/// <summary>
	/// Adds the player.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="score">The score.</param>
	void PlayerManager::addPlayer(String^ name, int score){
		//if (playerExists(name)) {
		//	updatePlayer(name, score);
		//}
		//else {
			this->players->Add(gcnew Player(name, score));
		//}
	}

	/// <summary>
	/// Updates the player.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="newScore">The new score.</param>
	void PlayerManager::updatePlayer(String^ name, int newScore){
		//for each (Player^ currPlayer in this->players)
		//{
		//	if (currPlayer->Name->Equals(name)) {
		//		currPlayer->Score = newScore;
		//	}
		//}
	}

	bool PlayerManager::playerExists(String^ name){
		//for each (Player^ currPlayer in this->players)
		//{
		//	if (currPlayer->Name->Equals(name)) {
		//		return true;
		//	}
		//}
		return false;
	}
}
