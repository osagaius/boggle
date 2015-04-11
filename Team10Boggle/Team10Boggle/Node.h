#pragma once
using namespace System;
using namespace System::Collections::Generic;
namespace model{
	ref class Node
	{
	public:
		Node(void);
		Node(Char^ value);
		property Char^ value{
			Char^ get(){ return this->contents; }
			void set(Char^ value){ this->contents = value; }
		}
		property bool marker{
			bool get(){ return this->isAtEnd; }
			void set(bool value){ this->isAtEnd = value; }
		}

		List<Node^>^ getChildren();
		void addChild(Node^ child);
		Node^ getChild(Char^ value);
	private:
		Char^ contents;
		bool isAtEnd;
		List<Node^>^ children;
	};

}