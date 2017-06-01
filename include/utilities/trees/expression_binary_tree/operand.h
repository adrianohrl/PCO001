/**
 * This header file defines the ExpressionBinaryTree Operand abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_OPERAND_H
#define EBT_OPERAND_H

#include <sstream>
#include "utilities/trees/expression_binary_tree/node.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class Operand : public Node<T, E>
{
public:
  Operand(const Operand<T, E>& operand);
  virtual ~Operand();
  virtual Node<T, E>* insert(Node<T, E>* node);
  virtual T process() const;
  const E& getContent() const;
  virtual Node<T, E>* getLeft() const;
  virtual Node<T, E>* getRight() const;
  virtual bool hasLeft() const;
  virtual bool hasRight() const;
  virtual bool isLeaf() const;
  virtual void setLeft(Node<T, E>* node);
  virtual void setRight(Node<T, E>* node);
  virtual std::string str() const;

protected:
  Operand(const E& operand);

private:
  const E content_;
};

template <typename T, typename E>
Operand<T, E>::Operand(const E& content)
    : Node<T, E>::Node(true), content_(content)
{
}

template <typename T, typename E>
Operand<T, E>::Operand(const Operand<T, E>& operand)
    : Node<T, E>::Node(operand), content_(operand.content_)
{
}

template <typename T, typename E> Operand<T, E>::~Operand() {}

template <typename T, typename E>
Node<T, E>* Operand<T, E>::insert(Node<T, E>* node)
{
  if (!node)
  {
    throw utilities::Exception("Node must not be NULL!!!");
  }
  if (node->isOperand())
  {
    throw utilities::Exception("Operand must be a leaf node!!!");
  }
  Node<T, E>* root = Node<T, E>::getParent();
  node->setLeft(this);
  if (root)
  {
    root->setRight(NULL);
    root = root->insert(node);
  }
  return root ? root : node;
}

template <typename T, typename E> T Operand<T, E>::process() const
{
  throw Exception("Invalid operation!!!");
}

template <typename T, typename E> const E& Operand<T, E>::getContent() const
{
  return content_;
}

template <typename T, typename E> Node<T, E>* Operand<T, E>::getLeft() const
{
  return NULL;
}

template <typename T, typename E> Node<T, E>* Operand<T, E>::getRight() const
{
  return NULL;
}

template <typename T, typename E> bool Operand<T, E>::hasLeft() const
{
  return false;
}

template <typename T, typename E> bool Operand<T, E>::hasRight() const
{
  return false;
}

template <typename T, typename E> bool Operand<T, E>::isLeaf() const
{
  return true;
}

template <typename T, typename E> void Operand<T, E>::setLeft(Node<T, E>* node)
{
  throw Exception("Invalid operation!!!");
}

template <typename T, typename E> void Operand<T, E>::setRight(Node<T, E>* node)
{
  throw Exception("Invalid operation!!!");
}

template <typename T, typename E> std::string Operand<T, E>::str() const
{
  std::stringstream ss;
  ss << content_;
  return ss.str();
}
}
}
}

#endif // EBT_OPERAND_H
