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
#include "utilities/exception.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class Node
{
public:
  Node(const Node<T, E>& node);
  virtual ~Node();
  virtual Node<T, E>* insert(Node<T, E>* node) = 0;
  virtual T process() const = 0;
  virtual Node<T, E>* getLeft() const = 0;
  virtual Node<T, E>* getRight() const = 0;
  virtual Node<T, E>* getParent() const;
  virtual bool hasLeft() const = 0;
  virtual bool hasRight() const = 0;
  bool hasParent() const;
  virtual bool isLeaf() const = 0;
  bool isOperand() const;
  bool isOperator() const;
  bool isLogical() const;
  virtual void setLeft(Node<T, E>* node) = 0;
  virtual void setRight(Node<T, E>* node) = 0;
  void setParent(Node<T, E>* node);
  virtual Node<T, E>* clone() const = 0;
  virtual std::string str() const = 0;
  const char* c_str();

protected:
  Node(bool operand, bool logical);

private:
  Node<T, E>* parent_;
  bool operand_;
  bool logical_;
};

template <typename T, typename E>
Node<T, E>::Node(bool operand, bool logical)
    : parent_(NULL), operand_(operand), logical_(logical)
{
}

template <typename T, typename E>
Node<T, E>::Node(const Node<T, E>& node)
    : parent_(NULL), operand_(node.operand_), logical_(node.logical_)
{
}

template <typename T, typename E> Node<T, E>::~Node() { parent_ = NULL; }

template <typename T, typename E> Node<T, E>* Node<T, E>::getParent() const
{
  return parent_;
}

template <typename T, typename E> bool Node<T, E>::hasParent() const
{
  return parent_;
}

template <typename T, typename E> bool Node<T, E>::isOperand() const
{
  return operand_;
}

template <typename T, typename E> bool Node<T, E>::isOperator() const
{
  return !operand_;
}

template <typename T, typename E> bool Node<T, E>::isLogical() const
{
  return logical_;
}

template <typename T, typename E> void Node<T, E>::setParent(Node<T, E>* node)
{
  if (node && node->isOperand())
  {
    throw utilities::Exception("An operand node must be a leaf node!!!");
  }
  parent_ = node;
}

template <typename T, typename E> const char* Node<T, E>::c_str()
{
  return str().c_str();
}
}
}
}

#endif // EBT_NODE_H
