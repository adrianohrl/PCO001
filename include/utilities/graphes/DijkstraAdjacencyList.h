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
	void reset();
	std::string str() const;
};

template<typename T>
DijkstraAdjacencyList<T>::DijkstraAdjacencyList(const unsigned int max_size)
	: AdjacencyList<T>::AdjacencyList(max_size)
{}

template<typename T>
DijkstraAdjacencyList<T>::~DijkstraAdjacencyList()
{}

template<typename T>
void DijkstraAdjacencyList<T>::reset()
{
	unsigned int size(AdjacencyList<T>::getSize());
	for (int i(0); i < size; i++)
  {
		DijkstraVertex<T> *vertex = (DijkstraVertex<T> *) AdjacencyList<T>::getVertex(i);
		vertex->setVisited(false);
  }
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

}

}

#endif // DIJKSTRA_ADJACENCY_LIST_H
