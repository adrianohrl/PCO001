/**
 * This header file defines the DijkstraAdjacentList class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DIJKSTRA_ADJACENCY_LIST_H
#define DIJKSTRA_ADJACENCY_LIST_H

#include <list>
#include "utilities/graphes/AdjacencyList.h"
#include "utilities/graphes/DijkstraVertex.h"

namespace utilities
{

namespace graphes
{

template<typename T>
class DijkstraAdjacencyList : public AdjacencyList<T>
{
public:
	DijkstraAdjacencyList(const unsigned int max_size);
  virtual ~DijkstraAdjacencyList();
	std::list<T> getShortestPath(const T &origin, const T &destiny);
	std::list<T> getShortestPath(unsigned int origin, unsigned int destiny);
	virtual bool insert(const T &content);
	std::string str() const;
private:
	void reset();
	void reset(unsigned int start_vertex);
	DijkstraVertex<T> *visitMinimumDistanceVertex();
	bool isEmpty() const;
};

template<typename T>
DijkstraAdjacencyList<T>::DijkstraAdjacencyList(const unsigned int max_size)
	: AdjacencyList<T>::AdjacencyList(max_size)
{}

template<typename T>
DijkstraAdjacencyList<T>::~DijkstraAdjacencyList()
{}

template<typename T>
std::list<T> DijkstraAdjacencyList<T>::getShortestPath(const T &origin, const T &destiny)
{
	return getShortestPath(AdjacencyList<T>::getIndex(origin), AdjacencyList<T>::getIndex(destiny));
}

template<typename T>
std::list<T> DijkstraAdjacencyList<T>::getShortestPath(unsigned int origin, unsigned int destiny)
{
	std::list<T> path;
	unsigned int size = AdjacencyList<T>::getSize();
	if (origin >= size || destiny >= size)
	{
		return path;
	}
	reset(origin);
	DijkstraVertex<T> *vertex = NULL, *successor = NULL;
	Arc<T> *arc = NULL;
	while (!isEmpty())
	{
		vertex = visitMinimumDistanceVertex();
		arc = vertex->getAdjacent();
		while (arc)
		{
			successor = (DijkstraVertex<T> *) arc->getDestiny();
			double distance(vertex->getMinimumDistance() + arc->getWeight());
			if (!successor->isVisited() && successor->getMinimumDistance() > distance)
			{
				successor->setMinimumDistance(distance);
				successor->setPredecessor(vertex);
			}
			arc = arc->getNext();
		}
	}
	DijkstraVertex<T> *predecessor = (DijkstraVertex<T> *) AdjacencyList<T>::getVertex(destiny);
	while (predecessor)
	{
		path.insert(path.begin(), predecessor->getContent());
		predecessor = predecessor->getPredecessor();
	}
	if (*path.begin() != AdjacencyList<T>::getVertex(origin)->getContent())
	{
		path.clear();
	}
	return path;
}

template<typename T>
bool DijkstraAdjacencyList<T>::insert(const T &content)
{
	return AdjacencyList<T>::insert(new DijkstraVertex<T>(content));
}

template<typename T>
std::string DijkstraAdjacencyList<T>::str() const
{
	unsigned int size(AdjacencyList<T>::getSize());
  std::string str("Vertices:");
	for (int i(0); i < size; i++)
  {
		str += "\n\t" + AdjacencyList<T>::getVertex(i)->str();
  }
	return str;
}

template<typename T>
void DijkstraAdjacencyList<T>::reset()
{
	unsigned int size(AdjacencyList<T>::getSize());
	for (int i(0); i < size; i++)
	{
		DijkstraVertex<T> *vertex = (DijkstraVertex<T> *) AdjacencyList<T>::getVertex(i);
		vertex->setVisited(false);
		vertex->setPredecessor(NULL);
		vertex->setMinimumDistance(INFINITY);
	}
}

template<typename T>
void DijkstraAdjacencyList<T>::reset(unsigned int start_vertex)
{
	reset();
	if (start_vertex < AdjacencyList<T>::getSize())
	{
		DijkstraVertex<T> *vertex = (DijkstraVertex<T> *) AdjacencyList<T>::getVertex(start_vertex);
		vertex->setMinimumDistance(0);
	}
}

template<typename T>
DijkstraVertex<T> *DijkstraAdjacencyList<T>::visitMinimumDistanceVertex()
{
	double minimum_distance(INFINITY);
	unsigned int size(AdjacencyList<T>::getSize());
	DijkstraVertex<T> *successor = NULL;
	for (int i(0); i < size; i++)
	{
		DijkstraVertex<T> *vertex = (DijkstraVertex<T> *) AdjacencyList<T>::getVertex(i);
		if (!vertex->isVisited() && vertex->getMinimumDistance() <= minimum_distance)
		{
			minimum_distance = vertex->getMinimumDistance();
			successor = vertex;
		}
	}
	if (successor)
	{
		successor->setVisited();
	}
	return successor;
}

template<typename T>
bool DijkstraAdjacencyList<T>::isEmpty() const
{
	unsigned int size(AdjacencyList<T>::getSize());
	for (int i(0); i < size; i++)
	{
		DijkstraVertex<T> *vertex = (DijkstraVertex<T> *) AdjacencyList<T>::getVertex(i);
		if (!vertex->isVisited())
		{
			return false;
		}
	}
	return true;
}

}

}

#endif // DIJKSTRA_ADJACENCY_LIST_H
