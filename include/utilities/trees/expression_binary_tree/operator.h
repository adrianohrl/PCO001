/**
 * This header file defines the ExpressionBinaryTree Operator abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_OPERATOR_H
#define EBT_OPERATOR_H

#include <sstream>
#include "utilities/trees/expression_binary_tree/node.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class Operator : public Node<T, E>
{
public:
  Operator(const Operator<T, E>& operatorr);
  virtual ~Operator();
  virtual T process() const = 0;
  virtual Node<T, E>* getLeft() const;
  virtual Node<T, E>* getRight() const;
  virtual bool hasLeft() const;
  virtual bool hasRight() const;
  virtual bool isLeaf() const;
  bool isUnary() const;
  virtual getSymbol() const = 0;
  virtual std::string str() const;

protected:
  Operator(Node<T, E>* operand);
  Operator(Node<T, E>* left, Node<T, E>* right);

private:
  bool unary_;
  Node<T, E>* left_;
  Node<T, E>* right_;
};

template <typename T, typename E>
Operator<T, E>::Operator(Node<T, E>* operand)
    : unary_(true), left_(operand), right_(NULL)
{
}

template <typename T, typename E>
Operator<T, E>::Operator(Node<T, E>* left, Node<T, E>* right)
    : unary_(false), left_(left), right_(right)
{
}

template <typename T, typename E>
Operator<T, E>::Operator(const Operator<T, E>& operatorr)
    : unary_(operatorr.unary_), left_(operatorr.left_), right_(operatorr.right_)
{
}

template <typename T, typename E> Operator<T, E>::~Operator() {}

template <typename T, typename E> Node<T, E>* Operator<T, E>::getLeft() const
{
  return left_;
}

template <typename T, typename E> Node<T, E>* Operator<T, E>::getRight() const
{
  return right_;
}

template <typename T, typename E> bool Operator<T, E>::hasLeft() const
{
  return left_;
}

template <typename T, typename E> bool Operator<T, E>::hasRight() const
{
  return right_;
}

template <typename T, typename E> bool Operator<T, E>::isLeaf() const
{
  return false;
}

template <typename T, typename E> bool Operator<T, E>::isUnary() const
{
  return unary_;
}

template <typename T, typename E> std::string Operator<T, E>::str() const
{
  std::stringstream ss;
  if (unary_)
  {
    ss << getSymbol() + " ";
  }
  ss << (left_ ? left_->str() : "");
  if (!unary_)
  {
    ss << " " + getSymbol() + " ";
    ss << (right_ ? right_->str() : "");
  }
  return "(" + ss.str() + ")";
}
}
}
}

#endif // EBT_OPERATOR_H
