/**
 * This header file defines the DijkstraAdjacentList DijkstraVertex class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DIJKSTRA_ADJACENCY_LIST_VERTEX_H
#define DIJKSTRA_ADJACENCY_LIST_VERTEX_H

#include "utilities/graphes/Vertex.h"

namespace utilities
{

namespace graphes
{

template <typename T>
class DijkstraVertex : public Vertex<T>
{
public:
	DijkstraVertex(const T &content);
  virtual ~DijkstraVertex();
  bool isVisited() const;
  double getMinimumDistance() const;
  DijkstraVertex<T> *getPredecessor() const;
  void setVisited(bool visited = true);
  void setMinimumDistance(double distance) const;
	void setPredecessor(DijkstraVertex<T> *vertex);
	virtual std::string str() const;
private:
  bool visited_;
  double minimum_distance_;
	DijkstraVertex<T> *predecessor_;
	virtual bool insert(DijkstraVertex<T> *vertex, double weight);
};

template <typename T>
DijkstraVertex<T>::DijkstraVertex(const T& content)
	: Vertex<T>::Vertex(content),
    visited_(false),
    minimum_distance_(0.0),
		predecessor_(NULL)
{}

template <typename T>
DijkstraVertex<T>::~DijkstraVertex()
{
	predecessor_ = NULL;
}

template <typename T>
bool DijkstraVertex<T>::isVisited() const
{
  return visited_;
}

template <typename T>
double DijkstraVertex<T>::getMinimumDistance() const
{
  return minimum_distance_;
}

template <typename T>
DijkstraVertex<T> *DijkstraVertex<T>::getPredecessor() const
{
  return predecessor_;
}

template <typename T>
void DijkstraVertex<T>::setVisited(bool visited)
{
  visited_ = visited;
}

template <typename T>
void DijkstraVertex<T>::setMinimumDistance(double distance) const
{
  minimum_distance_ = distance;
}

template <typename T>
void DijkstraVertex<T>::setPredecessor(DijkstraVertex<T> *vertex)
{
  predecessor_ = vertex;
}

template <typename T>
std::string DijkstraVertex<T>::str() const
{
  std::stringstream ss;
	/*ss << "DijkstraVertex " << content_ <<
				" (" << (visited_ ? "T" : "F") << ")";
	if (adjacent_)
	{
		ss << ": Arcs: " << adjacent_->str();
	}
  if (predecessor_)
  {
    ss << ", Predecessor: " << predecessor_->content_ <<
          ", Distance: " << minimum_distance_;
	}*/
	return ss.str();
}

template <typename T>
bool DijkstraVertex<T>::insert(DijkstraVertex<T> *vertex, double weight)
{
	return Vertex<T>::insert(new Arc<T>(vertex, weight));
}

}

}

#endif // DIJKSTRA_ADJACENCY_LIST_VERTEX_H
