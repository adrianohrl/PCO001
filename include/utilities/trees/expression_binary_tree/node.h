/**
 * This header file defines the ExpressionBinaryTree Node interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_NODE_H
#define EBT_NODE_H

#include <string>
#include "utilities/Exception.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class Node
{
public:
  virtual ~Node();
  virtual T process() const;
  virtual Node<T, E>* getLeft() const;
  virtual Node<T, E>* getRight() const;
  virtual bool hasLeft() const;
  virtual bool hasRight() const;
  virtual bool isLeaf() const;
  virtual Node<T, E>* clone() const = 0;
  virtual std::string str() const = 0;
  virtual const char* c_str();

protected:
  Node();
};

template <typename T, typename E> Node<T, E>::Node() {}

template <typename T, typename E> Node<T, E>::~Node() {}

template <typename T, typename E> T Node<T, E>::process() const
{
  throw Exception("Invalid operation");
}

template <typename T, typename E> Node<T, E>* Node<T, E>::getLeft() const
{
  return NULL;
}

template <typename T, typename E> Node<T, E>* Node<T, E>::getRight() const
{
  return NULL;
}

template <typename T, typename E> bool Node<T, E>::hasLeft() const
{
  return false;
}

template <typename T, typename E> bool Node<T, E>::hasRight() const
{
  return false;
}

template <typename T, typename E> bool Node<T, E>::isLeaf() const
{
  return true;
}

template <typename T, typename E> const char* Node<T, E>::c_str()
{
  return str().c_str();
}
}
}
}

#endif // EBT_NODE_H
