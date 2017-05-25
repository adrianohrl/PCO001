/**
 * This header file defines the AdjacentList Arc class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef ADJACENCY_LIST_ARC_H
#define ADJACENCY_LIST_ARC_H

#include "utilities/Exception.h"

namespace utilities
{

namespace graphes
{

template <typename T> class Vertex;

template <typename T> class Arc
{
public:
  Arc(Vertex<T>* destiny, double weight, Arc<T>* next = NULL);
  virtual ~Arc();
  Vertex<T>* getDestiny() const;
  double getWeight() const;
  Arc<T>* getNext() const;
  bool hasNext() const;
  void setWeight(double weight);
  void setNext(Arc<T>* arc);
  std::string str() const;
  bool operator<(const Arc<T>& arc) const;
  bool operator<=(const Arc<T>& arc) const;
  bool operator==(const Arc<T>& arc) const;
  bool operator!=(const Arc<T>& arc) const;
  bool operator>(const Arc<T>& arc) const;
  bool operator>=(const Arc<T>& arc) const;
  bool operator<(const Vertex<T>& vertex) const;
  bool operator<=(const Vertex<T>& vertex) const;
  bool operator==(const Vertex<T>& vertex) const;
  bool operator!=(const Vertex<T>& vertex) const;
  bool operator>(const Vertex<T>& vertex) const;
  bool operator>=(const Vertex<T>& vertex) const;

private:
  Vertex<T>* destiny_;
  double weight_;
  Arc<T>* next_;
};
}
}

#include "utilities/graphes/Vertex.h"

namespace utilities
{

namespace graphes
{

template <typename T>
Arc<T>::Arc(Vertex<T>* destiny, double weight, Arc<T>* next)
    : destiny_(destiny), weight_(weight), next_(next)
{
  if (!destiny_)
  {
    throw utilities::Exception("An arc must have origin and destiny!!!");
  }
}

template <typename T> Arc<T>::~Arc()
{
  destiny_ = NULL;
  if (next_)
  {
    delete next_;
    next_ = NULL;
  }
}

template <typename T> Vertex<T>* Arc<T>::getDestiny() const { return destiny_; }

template <typename T> double Arc<T>::getWeight() const { return weight_; }

template <typename T> Arc<T>* Arc<T>::getNext() const { return next_; }

template <typename T> bool Arc<T>::hasNext() const { return next_; }

template <typename T> void Arc<T>::setWeight(double weight)
{
  weight_ = weight;
}

template <typename T> void Arc<T>::setNext(Arc<T>* arc) { next_ = arc; }

template <typename T> std::string Arc<T>::str() const
{
  std::stringstream ss;
  ss << destiny_->getContent() << "(" << weight_ << ")";
  if (next_)
  {
    ss << ", " << next_->str();
  }
  return ss.str();
}

template <typename T> bool Arc<T>::operator<(const Arc<T>& arc) const
{
  return weight_ < arc.weight_;
}

template <typename T> bool Arc<T>::operator<=(const Arc<T>& arc) const
{
  return weight_ <= arc.weight_;
}

template <typename T> bool Arc<T>::operator==(const Arc<T>& arc) const
{
  return weight_ == arc.weight_;
}

template <typename T> bool Arc<T>::operator!=(const Arc<T>& arc) const
{
  return !operator==(arc);
}

template <typename T> bool Arc<T>::operator>=(const Arc<T>& arc) const
{
  return weight_ >= arc.weight_;
}

template <typename T> bool Arc<T>::operator>(const Arc<T>& arc) const
{
  return weight_ > arc.weight_;
}

template <typename T> bool Arc<T>::operator<(const Vertex<T>& vertex) const
{
  return *destiny_ < vertex;
}

template <typename T> bool Arc<T>::operator<=(const Vertex<T>& vertex) const
{
  return *destiny_ <= vertex;
}

template <typename T> bool Arc<T>::operator==(const Vertex<T>& vertex) const
{
  return *destiny_ == vertex;
}

template <typename T> bool Arc<T>::operator!=(const Vertex<T>& vertex) const
{
  return !operator==(vertex);
}

template <typename T> bool Arc<T>::operator>=(const Vertex<T>& vertex) const
{
  return *destiny_ >= vertex;
}

template <typename T> bool Arc<T>::operator>(const Vertex<T>& vertex) const
{
  return *destiny_ > vertex;
}
}
}

#endif // ADJACENCY_LIST_ARC_H
