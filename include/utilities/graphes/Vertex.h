/**
 * This header file defines the AdjacentList Vertex class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef ADJACENCY_LIST_VERTEX_H
#define ADJACENCY_LIST_VERTEX_H

#include <sstream>
#include "utilities/graphes/Arc.h"

namespace utilities
{

namespace graphes
{

template <typename T>
class Vertex
{
public:
	Vertex(const T &content);
  virtual ~Vertex();
	T getContent() const;
	Arc<T> *getAdjacent() const;
  bool isConnected(Vertex<T> *vertex) const;
  bool isDisconnected(Vertex<T> *vertex) const;
	void setAdjancent(Arc<T> *vertex);
	bool connect(Vertex<T> *vertex, double weight);
	bool disconnect(Vertex<T> *vertex, double weight);
	virtual std::string str() const;
	bool operator<(const Vertex<T> &vertex) const;
	bool operator<=(const Vertex<T> &vertex) const;
	bool operator==(const Vertex<T> &vertex) const;
	bool operator!=(const Vertex<T> &vertex) const;
	bool operator>=(const Vertex<T> &vertex) const;
	bool operator>(const Vertex<T> &vertex) const;
protected:
	virtual bool insert(Arc<T> *arc);
private:
  T content_;
  unsigned int degree_;
	Arc<T> *adjacent_;
	virtual bool insert(Vertex<T> *vertex, double weight);
};

template <typename T>
Vertex<T>::Vertex(const T& content)
  : content_(content),
    degree_(0),
		adjacent_(NULL)
{}

template <typename T>
Vertex<T>::~Vertex()
{
  if (adjacent_)
  {
    delete adjacent_;
    adjacent_ = NULL;
	}
}

template<typename T>
T Vertex<T>::getContent() const
{
	return content_;
}

template <typename T>
Arc<T> *Vertex<T>::getAdjacent() const
{
  return adjacent_;
}

template <typename T>
bool Vertex<T>::isConnected(Vertex<T> *vertex) const
{
	for (Arc<T> *arc = adjacent_; arc; arc = arc->getNext())
	{
		if (arc == vertex)
		{
			return true;
		}
	}
  return false;
}

template <typename T>
bool Vertex<T>::isDisconnected(Vertex<T> *vertex) const
{
	if (!adjacent_)
	{
		return false;
	}
	for (Arc<T> *arc = adjacent_; arc; arc = arc->getNext())
	{
		if (arc == vertex)
		{
			return false;
		}
	}
	return true;
}

template <typename T>
void Vertex<T>::setAdjancent(Arc<T> *vertex)
{
  adjacent_ = vertex;
}

template <typename T>
bool Vertex<T>::connect(Vertex<T> *vertex, double weight)
{
	for (Arc<T> *arc = adjacent_; arc; arc = arc->getNext())
	{
		if (*arc == *vertex)
		{
			arc->setWeight(weight);
			return true;
		}
	}
	degree_++;
	return insert(vertex, weight);
}

template <typename T>
bool Vertex<T>::disconnect(Vertex<T> *vertex, double weight)
{
  // implementar ainda
  return false;
}

template <typename T>
std::string Vertex<T>::str() const
{
  std::stringstream ss;
	ss << "Vertex " << content_;
	if (adjacent_)
	{
		ss << ": Arcs: {" << adjacent_->str() << "}";
	}
	return ss.str();
}

template<typename T>
bool Vertex<T>::operator<(const Vertex<T> &vertex) const
{
	return content_ < vertex.content_;
}

template<typename T>
bool Vertex<T>::operator<=(const Vertex<T> &vertex) const
{
	return content_ <= vertex.content_;
}

template<typename T>
bool Vertex<T>::operator==(const Vertex<T> &vertex) const
{
	return content_ == vertex.content_;
}

template<typename T>
bool Vertex<T>::operator!=(const Vertex<T> &vertex) const
{
	return !operator==(vertex);
}

template<typename T>
bool Vertex<T>::operator>=(const Vertex<T> &vertex) const
{
	return content_ >= vertex.content_;
}

template<typename T>
bool Vertex<T>::operator>(const Vertex<T> &vertex) const
{
	return content_ > vertex.content_;
}

template<typename T>
bool Vertex<T>::insert(Arc<T> *arc)
{
	if (!adjacent_)
	{
		adjacent_ = arc;
		return true;
	}
	Arc<T> *next = adjacent_, *previous = NULL;
	while (*next < *arc->getDestiny() && next->hasNext())
	{
		previous = next;
		next = next->getNext();
	}
	if (*next < *arc->getDestiny())
	{
		next->setNext(arc);
	}
	else
	{
		arc->setNext(next);
		previous->setNext(arc);
	}
	return true;
}

template<typename T>
bool Vertex<T>::insert(Vertex<T> *vertex, double weight)
{
	return insert(new Arc<T>(vertex, weight));
}

}

}

#endif // ADJACENCY_LIST_VERTEX_H
