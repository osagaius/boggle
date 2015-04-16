#include "Vertex.h"


namespace model
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Vertex"/> class.
	/// </summary>
	/// <param name="item">The item.</param>
	Vertex::Vertex(String^ item) {
		this->neighbors = gcnew List<Vertex^>();
		this->item = item;
	}
	/// <summary>
	/// Gets the vertices.
	/// </summary>
	/// <returns></returns>
	List<Vertex^>^ Vertex::getVertices() {
		return this->neighbors;
	}

	/// <summary>
	/// Visits this instance.
	/// </summary>
	/// <returns></returns>
	String^ Vertex::visit() {
		return this->item;
	}
	/// <summary>
	/// Adds the neighbor.
	/// </summary>
	/// <param name="neighbor">The neighbor.</param>
	void Vertex::addNeighbor(Vertex^ neighbor) {
		this->neighbors->Add(neighbor);
	}

}