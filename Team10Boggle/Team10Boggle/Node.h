#pragma once
using namespace System;
using namespace System::Collections::Generic;
namespace model{
	/// <summary>
	/// Models a Node object that can be used
	/// for different purposes, but is meant
	/// for use for the Boggle game's Trie structure.
	/// </summary>
	ref class Node
	{
	public:
		Node(void);
		Node(Char^ value);
		
		List<Node^>^ getChildren();
		void addChild(Node^ child);
		Node^ getChild(Char^ value);

#pragma region Properties
		property Char^ value{
			Char^ get(){ return this->contents; }
			void set(Char^ value){ this->contents = value; }
		}
		property bool marker{
			bool get(){ return this->isAtEnd; }
			void set(bool value){ this->isAtEnd = value; }
		}
#pragma endregion


	private:
		Char^ contents;
		bool isAtEnd;
		List<Node^>^ children;
	};

}