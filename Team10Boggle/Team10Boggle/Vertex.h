#pragma once
using namespace System;
using namespace System::Collections::Generic;

namespace model
{
	/// <summary>
	/// Models a vertex of the Boggle graph.
	/// </summary>
	ref class Vertex
	{
	public:
		Vertex(String^ item);
		List<Vertex^>^ getVertices();
		String^ visit();
		void addNeighbor(Vertex^ neighbor);

		property bool Visited
		{
			bool get(){ return this->visited; };
			void set(bool value){ this->visited = value; };
		}

		property String^ Item
		{
			String^ get(){ return this->item; };
			void set(String^ value){ this->item = value; };
		}
	private:
		List<Vertex^>^ neighbors;
		bool visited;
		String^ item;
	};

}
