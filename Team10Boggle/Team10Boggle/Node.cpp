#include "Node.h"

namespace model{
	/// <summary>
	/// Initializes a new instance of the <see cref="Node"/> class.
	/// </summary>
	Node::Node(void)
	{
		this->contents = gcnew Char();
		this->children = gcnew List<Node^>();
		this->isAtEnd = false;
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="Node"/> class.
	/// </summary>
	/// <param name="value">The value.</param>
	Node::Node(Char^ value){
		this->children = gcnew List<Node^>();
		this->isAtEnd = false;
		this->contents = value;
	}

	/// <summary>
	/// Adds the child.
	/// </summary>
	/// <param name="child">The child.</param>
	void Node::addChild(Node^ child){
		this->children->Add(child);
	}

	/// <summary>
	/// Gets the children.
	/// </summary>
	/// <returns></returns>
	List<Node^>^ Node::getChildren(){
		return this->children;
	}

	/// <summary>
	/// Gets the child.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <returns></returns>
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