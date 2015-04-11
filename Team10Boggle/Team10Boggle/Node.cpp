#include "Node.h"

namespace model{
	Node::Node(void)
	{
		this->contents = gcnew Char();
		this->children = gcnew List<Node^>();
		this->isAtEnd = false;
	}

	Node::Node(Char^ value){
		this->children = gcnew List<Node^>();
		this->isAtEnd = false;
		this->contents = value;
	}

	void Node::addChild(Node^ child){
		this->children->Add(child);
	}

	List<Node^>^ Node::getChildren(){
		return this->children;
	}

	Node^ Node::getChild(Char^ value){
		for (int i = 0; i < this->children->Count; i++)
		{
			Node^ tmp = this->children[i];
			if (tmp->contents->Equals(value))
			{
				return tmp;
			}
		}

		return nullptr;
	}
}