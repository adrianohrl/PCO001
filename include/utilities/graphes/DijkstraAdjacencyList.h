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

template <typename T> class DijkstraAdjacencyList : public AdjacencyList<T>
{
public:
  DijkstraAdjacencyList(const std::size_t max_size);
  virtual ~DijkstraAdjacencyList();
  std::list<T> getShortestPath(const T& origin, const T& destiny);
  double getShortestPathTotalWeight(const T& destiny) const;
  double getShortestPathTotalWeight(std::list<T> path) const;
  virtual bool insert(const T& content);

private:
  virtual void reset();
  void reset(DijkstraVertex<T>* origin);
  DijkstraVertex<T>* getDijkstraVertex(const T& destiny) const;
  DijkstraVertex<T>* visitMinimumDistanceVertex();
  bool isEmpty();
  std::list<T> getShortestPath(DijkstraVertex<T>* origin,
                               DijkstraVertex<T>* destiny);
};

template <typename T>
DijkstraAdjacencyList<T>::DijkstraAdjacencyList(const std::size_t max_size)
    : AdjacencyList<T>::AdjacencyList(max_size)
{
}

template <typename T> DijkstraAdjacencyList<T>::~DijkstraAdjacencyList() {}

template <typename T>
std::list<T> DijkstraAdjacencyList<T>::getShortestPath(const T& origin,
                                                       const T& destiny)
{
  return getShortestPath(getDijkstraVertex(origin), getDijkstraVertex(destiny));
}

template <typename T>
std::list<T>
DijkstraAdjacencyList<T>::getShortestPath(DijkstraVertex<T>* origin,
                                          DijkstraVertex<T>* destiny)
{
  std::list<T> path;
  if (!origin || !destiny)
  {
    return path;
  }
  reset(origin);
  DijkstraVertex<T>* vertex = NULL, * successor = NULL;
  Arc<T>* arc = NULL;
  while (!isEmpty())
  {
    vertex = visitMinimumDistanceVertex();
    arc = vertex->getAdjacent();
    while (arc)
    {
      successor = (DijkstraVertex<T>*)arc->getDestiny();
      double distance(vertex->getMinimumDistance() + arc->getWeight());
      if (!successor->isVisited() && successor->getMinimumDistance() > distance)
      {
        successor->setMinimumDistance(distance);
        successor->setPredecessor(vertex);
      }
      arc = arc->getNext();
    }
  }
  DijkstraVertex<T>* predecessor = destiny;
  while (predecessor)
  {
    path.insert(path.begin(), predecessor->getContent());
    predecessor = predecessor->getPredecessor();
  }
  if (*path.begin() != origin->getContent())
  {
    path.clear();
  }
  return path;
}

template <typename T>
double
DijkstraAdjacencyList<T>::getShortestPathTotalWeight(const T& destiny) const
{
  double total_weight(0);
  DijkstraVertex<T>* predecessor = NULL, * vertex = getDijkstraVertex(destiny);
  while (vertex)
  {
    predecessor = vertex->getPredecessor();
    if (!predecessor)
    {
      break;
    }
    total_weight += predecessor->getWeight(vertex);
    vertex = predecessor;
  }
  return total_weight;
}

template <typename T>
double
DijkstraAdjacencyList<T>::getShortestPathTotalWeight(std::list<T> path) const
{
  double total_weight(0);
  typename std::list<T>::const_iterator it(path.begin());
  while (*it != path.back())
  {
    Vertex<T>* vertex = AdjacencyList<T>::getVertex(*it++);
    total_weight += vertex->getWeight(*it);
  }
  return total_weight;
}

template <typename T> bool DijkstraAdjacencyList<T>::insert(const T& content)
{
  return AdjacencyList<T>::insert(new DijkstraVertex<T>(content));
}

template <typename T> void DijkstraAdjacencyList<T>::reset()
{
  std::size_t size(AdjacencyList<T>::getSize());
  for (int i(0); i < size; i++)
  {
    DijkstraVertex<T>* vertex = (DijkstraVertex<T>*)AdjacencyList<T>::get(i);
    vertex->setVisited(false);
    vertex->setPredecessor(NULL);
    vertex->setMinimumDistance(INFINITY);
  }
}

template <typename T>
void DijkstraAdjacencyList<T>::reset(DijkstraVertex<T>* origin)
{
  reset();
  if (origin)
  {
    origin->setMinimumDistance(0);
  }
}

template <typename T>
DijkstraVertex<T>*
DijkstraAdjacencyList<T>::getDijkstraVertex(const T& content) const
{
  return (DijkstraVertex<T>*)AdjacencyList<T>::getVertex(content);
}

template <typename T>
DijkstraVertex<T>* DijkstraAdjacencyList<T>::visitMinimumDistanceVertex()
{
  double minimum_distance(INFINITY);
  std::size_t size(AdjacencyList<T>::getSize());
  DijkstraVertex<T>* successor = NULL;
  for (int i(0); i < size; i++)
  {
    DijkstraVertex<T>* vertex = (DijkstraVertex<T>*)AdjacencyList<T>::get(i);
    if (!vertex->isVisited() &&
        vertex->getMinimumDistance() <= minimum_distance)
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

template <typename T> bool DijkstraAdjacencyList<T>::isEmpty()
{
  std::size_t size(AdjacencyList<T>::getSize());
  for (int i(0); i < size; i++)
  {
    DijkstraVertex<T>* vertex = (DijkstraVertex<T>*)AdjacencyList<T>::get(i);
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
