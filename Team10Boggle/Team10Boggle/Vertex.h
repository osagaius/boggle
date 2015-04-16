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
		bool isVisited();
		String^ visit();
		void addNeighbor(Vertex^ neighbor);
	private:
		List<Vertex^>^ neighbors;
		bool visited;
		String^ item;
	};

}
