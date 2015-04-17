#pragma once
using namespace System;
using namespace System::Configuration;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;


/// <summary>
/// Models a Player within the game.
/// </summary>
namespace model
{
	ref class Player : public IComparable<Player^>
	{
	public:
		Player();
		Player(String^ name, int score);
		virtual int CompareTo(Player^ player);

#pragma region Properties
		property String^ Name
		{
			String^ get(){ return this->name; };
			void set(String^ value){ this->name = value; };
		}

		property int Score
		{
			int get(){ return this->score; };
			void set(int value){ this->score = value; };
		}
#pragma endregion

	private:
		String^ name;
		int score;
	};
}

