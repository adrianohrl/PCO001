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

#include "utilities/graphes/vertex.h"

#define INFINITY 1E+37

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
  double getMinimumDistance() const;
	DijkstraVertex<T> *getPredecessor() const;
	void setMinimumDistance(double distance);
	void setPredecessor(DijkstraVertex<T> *vertex);
	virtual std::string str() const;
private:
  double minimum_distance_;
	DijkstraVertex<T> *predecessor_;
	virtual bool insert(DijkstraVertex<T> *vertex, double weight);
};

template <typename T>
DijkstraVertex<T>::DijkstraVertex(const T& content)
	: Vertex<T>::Vertex(content),
		minimum_distance_(INFINITY),
		predecessor_(NULL)
{}

template <typename T>
DijkstraVertex<T>::~DijkstraVertex()
{
	predecessor_ = NULL;
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
void DijkstraVertex<T>::setMinimumDistance(double distance)
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
	ss << Vertex<T>::str();
  if (predecessor_)
  {
		ss << ", Predecessor: " << predecessor_->getContent();
	}
	if (minimum_distance_ != INFINITY)
	{
		ss << ", Distance: " << minimum_distance_;
	}
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
