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

#include "utilities/graphes/Vertex.h"

namespace utilities
{

namespace graphes
{

template<typename T>
class AdjacencyList
{
public:
	AdjacencyList(const unsigned int max_size);
	virtual ~AdjacencyList();
  Vertex<T> *getVertex(unsigned int vertex) const;
  unsigned int getSize() const;
  bool isConnected(unsigned int origin, unsigned int destiny) const;
  bool isDisconnected(unsigned int origin, unsigned int destiny) const;
  bool insert(const T &content);
	bool insert(Vertex<T> *vertex);
	bool connect(unsigned int origin, unsigned int destiny, double weight);
	bool connect(const T &origin, const T &destiny, double weight);
	bool disconnect(unsigned int origin, unsigned int destiny, double weight);
	std::string str() const;
private:
	const unsigned int max_size_;
	unsigned int size_;
  Vertex<T> **vertices_;
	unsigned int getIndex(const T &content) const;
};

template<typename T>
AdjacencyList<T>::AdjacencyList(const unsigned int max_size)
	: max_size_(max_size),
    size_(0),
    vertices_(NULL)
{
	vertices_ = new Vertex<T>*[max_size];
	for (int i(0); i < max_size; i++)
  {
    vertices_[i] = NULL;
  }
}

template<typename T>
AdjacencyList<T>::~AdjacencyList()
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

template<typename T>
Vertex<T> *AdjacencyList<T>::getVertex(unsigned int vertex) const
{
  if (vertex >= size_)
  {
    return NULL;
  }
  return vertices_[vertex];
}

template<typename T>
unsigned int AdjacencyList<T>::getSize() const
{
  return size_;
}

template<typename T>
bool AdjacencyList<T>::isConnected(unsigned int origin, unsigned int destiny) const
{
  if (origin >= size_ || destiny >= size_)
  {
    return false;
  }
  return vertices_[origin]->isConnected(vertices_[destiny]);
}

template<typename T>
bool AdjacencyList<T>::isDisconnected(unsigned int origin, unsigned int destiny) const
{
  if (origin >= size_ || destiny >= size_)
  {
    return false;
  }
  return vertices_[origin]->isDisconnected(vertices_[destiny]);
}

template<typename T>
bool AdjacencyList<T>::insert(const T &content)
{
  return insert(new Vertex<T>(content));
}

template<typename T>
bool AdjacencyList<T>::insert(Vertex<T> *vertex)
{
  if (size_ == max_size_)
  {
    return false;
  }
  vertices_[size_++] = vertex;
  return true;
}

template<typename T>
bool AdjacencyList<T>::connect(unsigned int origin, unsigned int destiny, double weight)
{
  if (origin >= size_ || destiny >= size_)
  {
    return false;
  }
	return vertices_[origin]->connect(vertices_[destiny], weight);
}

template<typename T>
bool AdjacencyList<T>::connect(const T &origin, const T &destiny, double weight)
{
	return connect(getIndex(origin), getIndex(destiny), weight);
}

template<typename T>
bool AdjacencyList<T>::disconnect(unsigned int origin, unsigned int destiny, double weight)
{
  if (origin >= size_ || destiny >= size_)
  {
    return false;
  }
	return vertices_[origin]->disconnect(vertices_[destiny], weight);
}

template<typename T>
std::string AdjacencyList<T>::str() const
{
  std::string str("Vertices:");
  for (int i(0); i < size_; i++)
  {
    str += "\n\t" + vertices_[i]->str();
  }
	return str;
}

template<typename T>
unsigned int AdjacencyList<T>::getIndex(const T &content) const
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

}

}

#endif // ADJACENCY_LIST_H
