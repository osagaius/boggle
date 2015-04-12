#include "Player.h"


/// <summary>
/// Models a Player within the game.
/// </summary>
namespace model
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	Player::Player(void)
	{
		this->name = "";
		this->score = 0;
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="score">The score.</param>
	Player::Player(String^ name, int score)
	{
		this->name = name;
		this->score = score;
	}

}
