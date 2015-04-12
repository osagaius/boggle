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
	ref class Player : public Object
	{
	public:
		Player();
		Player(String^ name, int score);

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

	private:
		String^ name;
		int score;
	};
}

