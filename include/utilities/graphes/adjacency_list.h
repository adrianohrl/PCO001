/**
 * This header file defines the AdjacentList class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <queue>
#include "utilities/graphes/vertex.h"

namespace utilities
{

namespace graphes
{

template <typename T> class AdjacencyList
{
public:
  AdjacencyList(const std::size_t max_size, bool directed = false);
  virtual ~AdjacencyList();
  std::list<T> getVertices() const;
  std::list<std::pair<T, double> > getArcs(const T& content) const;
  Vertex<T>* getVertex(const T& content) const;
  T* getContentReference(const T& content);
  double getWeight(const T& origin, const T& destiny) const;
  std::size_t getSize() const;
  bool isDirected() const;
  bool isAcyclic();
  bool isEmpty() const;
  bool isConnected(const T& origin, const T& destiny) const;
  bool isDisconnected(const T& origin, const T& destiny) const;
  bool hasVertex(const T& content) const;
  virtual bool insert(const T& content);
  bool connect(const T& origin, const T& destiny, double weight = 0.0);
  bool disconnect(const T& origin, const T& destiny);
  std::queue<T> getTopologicalOrdering();
  std::list<std::pair<T, double> > getPredecessors(const T& content);
  std::list<std::pair<T, double> > getSuccessors(const T& content) const;
  virtual std::string str() const;

protected:
  std::list<std::pair<T, double> > getArcs(Vertex<T>* vertex) const;
  Vertex<T>* get(std::size_t index);
  std::size_t getIndex(const T& content) const;
  double getWeight(Vertex<T>* origin, Vertex<T>* destiny) const;
  bool isConnected(Vertex<T>* origin, Vertex<T>* destiny) const;
  bool isDisconnected(Vertex<T>* origin, Vertex<T>* destiny) const;
  bool insert(Vertex<T>* vertex);
  bool connect(Vertex<T>* origin, Vertex<T>* destiny, double weight = 0.0);
  bool disconnect(Vertex<T>* origin, Vertex<T>* destiny);
  void visiteInDepthFirst(Vertex<T>* vertex);
  std::list<std::pair<T, double> > getPredecessors(Vertex<T>* vertex) const;
  std::list<std::pair<T, double> > getSuccessors(Vertex<T>* vertex) const;

private:
  const std::size_t max_size_;
  const bool directed_;
  std::size_t size_;
  Vertex<T>** vertices_;
  virtual void reset();
  Vertex<T>* getNextVertexInTopologicalOrdering();
};

template <typename T>
AdjacencyList<T>::AdjacencyList(const std::size_t max_size, bool directed)
    : max_size_(max_size), directed_(directed), size_(0), vertices_(NULL)
{
  vertices_ = new Vertex<T>* [max_size];
  for (int i(0); i < max_size; i++)
  {
    vertices_[i] = NULL;
  }
}

template <typename T> AdjacencyList<T>::~AdjacencyList()
{
  for (int i(0); i < max_size_; i++)
  {
    if (vertices_[i])
    {
      delete vertices_[i];
      vertices_[i] = NULL;
    }
  }
  delete[] vertices_;
  vertices_ = NULL;
}

template <typename T> std::list<T> AdjacencyList<T>::getVertices() const
{
  std::list<T> vertices;
  for (int i(0); i < size_; i++)
  {
    vertices.push_back(vertices_[i]->getContent());
  }
  return vertices;
}

template <typename T>
std::list<std::pair<T, double> >
AdjacencyList<T>::getArcs(const T& content) const
{
  return getArcs(getVertex(content));
}

template <typename T>
std::list<std::pair<T, double> >
AdjacencyList<T>::getArcs(Vertex<T>* vertex) const
{
  if (!vertex)
  {
    return std::list<std::pair<T, double> >();
  }
  return vertex->getArcs();
}

template <typename T>
Vertex<T>* AdjacencyList<T>::getVertex(const T& content) const
{
  std::size_t index(getIndex(content));
  if (index >= size_)
  {
    return NULL;
  }
  return vertices_[index];
}

template <typename T> T* AdjacencyList<T>::getContentReference(const T& content)
{
  return getVertex(content)->getContentReference();
}

template <typename T> std::size_t AdjacencyList<T>::getSize() const
{
  return size_;
}

template <typename T> bool AdjacencyList<T>::isDirected() const
{
  return directed_;
}

template <typename T> bool AdjacencyList<T>::isAcyclic()
{
  if (isEmpty())
  {
    return false;
  }
  for (int i(0); i < size_; i++)
  {
    reset();
    visiteInDepthFirst(vertices_[i]);
    if (vertices_[i]->isVisited())
    {
      return false;
    }
  }
  return true;
}

template <typename T> bool AdjacencyList<T>::isEmpty() const
{
  return size_ == 0;
}

template <typename T>
bool AdjacencyList<T>::isConnected(const T& origin, const T& destiny) const
{
  return isConnected(getVertex(origin), getVertex(destiny));
}

template <typename T>
bool AdjacencyList<T>::isConnected(Vertex<T>* origin, Vertex<T>* destiny) const
{
  if (!origin || !destiny)
  {
    return false;
  }
  return origin->isConnected(destiny);
}

template <typename T>
bool AdjacencyList<T>::isDisconnected(const T& origin, const T& destiny) const
{
  return isDisconnected(getVertex(origin), getVertex(destiny));
}

template <typename T>
bool AdjacencyList<T>::isDisconnected(Vertex<T>* origin,
                                      Vertex<T>* destiny) const
{
  if (!origin || !destiny)
  {
    return false;
  }
  return origin->isDisconnected(destiny);
}

template <typename T> bool AdjacencyList<T>::hasVertex(const T& content) const
{
  return getIndex(content) < size_;
}

template <typename T> bool AdjacencyList<T>::insert(const T& content)
{
  return insert(new Vertex<T>(content));
}

template <typename T> bool AdjacencyList<T>::insert(Vertex<T>* vertex)
{
  if (size_ == max_size_)
  {
    return false;
  }
  vertices_[size_++] = vertex;
  return true;
}

template <typename T>
bool AdjacencyList<T>::connect(const T& origin, const T& destiny, double weight)
{
  return connect(getVertex(origin), getVertex(destiny), weight);
}

template <typename T>
bool AdjacencyList<T>::connect(Vertex<T>* origin, Vertex<T>* destiny,
                               double weight)
{
  if (!origin || !destiny)
  {
    return false;
  }
  if (directed_)
  {
    return origin->connect(destiny, weight);
  }
  return origin->connect(destiny, weight) && destiny->connect(origin, weight);
}

template <typename T>
bool AdjacencyList<T>::disconnect(const T& origin, const T& destiny)
{
  return disconnect(getVertex(origin), getVertex(destiny));
}

template <typename T>
bool AdjacencyList<T>::disconnect(Vertex<T>* origin, Vertex<T>* destiny)
{
  if (!origin || !destiny)
  {
    return false;
  }
  if (directed_)
  {
    return origin->disconnect(destiny);
  }
  return origin->disconnect(destiny) && destiny->disconnect(origin);
}

template <typename T>
void AdjacencyList<T>::visiteInDepthFirst(Vertex<T>* vertex)
{
  for (int i(0); i < size_; i++)
  {
    if (isConnected(vertex, vertices_[i]) && !vertices_[i]->isVisited())
    {
      vertices_[i]->setVisited(true);
      visiteInDepthFirst(vertices_[i]);
    }
  }
}

template <typename T> void AdjacencyList<T>::reset()
{
  for (int i(0); i < size_; i++)
  {
    vertices_[i]->setVisited(false);
  }
}

template <typename T> std::string AdjacencyList<T>::str() const
{
  std::string str("Vertices:");
  for (int i(0); i < size_; i++)
  {
    str += "\n\t" + vertices_[i]->str();
  }
  return str;
}

template <typename T> Vertex<T>* AdjacencyList<T>::get(std::size_t index)
{
  if (index >= size_)
  {
    return NULL;
  }
  return vertices_[index];
}

template <typename T>
std::size_t AdjacencyList<T>::getIndex(const T& content) const
{
  for (int i(0); i < size_; i++)
  {
    if (vertices_[i]->getContent() == content)
    {
      return i;
    }
  }
  return size_;
}

template <typename T>
double AdjacencyList<T>::getWeight(const T& origin, const T& destiny) const
{
  return getWeight(getVertex(origin), getVertex(destiny));
}

template <typename T>
double AdjacencyList<T>::getWeight(Vertex<T>* origin, Vertex<T>* destiny) const
{
  return origin->getWeight(destiny);
}

template <typename T> std::queue<T> AdjacencyList<T>::getTopologicalOrdering()
{
  std::queue<T> topological_ordering;
  if (isEmpty() || !isDirected() || !isAcyclic())
  {
    return topological_ordering;
  }
  reset();
  Vertex<T>* vertex = getNextVertexInTopologicalOrdering();
  while (vertex)
  {
    topological_ordering.push(vertex->getContent());
    vertex = getNextVertexInTopologicalOrdering();
  }
  return topological_ordering;
}

template <typename T>
Vertex<T>* AdjacencyList<T>::getNextVertexInTopologicalOrdering()
{
  for (int i(0); i < size_; i++)
  {
    Vertex<T>* vertex = vertices_[i];
    if (!vertex->isVisited() && getPredecessors(vertex).empty())
    {
      vertex->setVisited(true);
      return vertex;
    }
  }
  return NULL;
}

template <typename T>
std::list<std::pair<T, double> >
AdjacencyList<T>::getPredecessors(const T& content)
{
  reset();
  return getPredecessors(getVertex(content));
}

template <typename T>
std::list<std::pair<T, double> >
AdjacencyList<T>::getPredecessors(Vertex<T>* vertex) const
{
  // nao esta implementado da forma mais eficiente. Seria melhor mudar a
  // estrutura de Vertex.
  // ao inves dessa classe ter uma lista de vertices adjacentes, ela teria uma
  // lista de
  // vertices sucessores e outra de vertices predecessores.

  // ou fazer controle do grau de entrada e saida de cada vertice (o q e mais
  // facil de implementar);
  std::list<std::pair<T, double> > predecessors;
  if (!vertex)
  {
    return predecessors;
  }
  std::list<std::pair<T, double> > successors;
  typename std::list<std::pair<T, double> >::const_iterator it;
  for (int i(0); i < size_; i++)
  {
    if (vertices_[i]->isVisited())
    {
      continue;
    }
    successors = getArcs(vertices_[i]);
    it = successors.begin();
    while (it != successors.end())
    {
      if (it->first == vertex->getContent())
      {
        predecessors.push_back(
            std::pair<T, double>(vertices_[i]->getContent(), it->second));
      }
      it++;
    }
  }
  return predecessors;
}

template <typename T>
std::list<std::pair<T, double> >
AdjacencyList<T>::getSuccessors(const T& content) const
{
  return getArcs(getVertex(content));
}

template <typename T>
std::list<std::pair<T, double> >
AdjacencyList<T>::getSuccessors(Vertex<T>* vertex) const
{
  return getArcs(vertex);
}
}
}

#endif // ADJACENCY_LIST_H
