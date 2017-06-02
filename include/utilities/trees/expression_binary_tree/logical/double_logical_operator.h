/**
 * This header file defines the ExpressionBinaryTree DoubleLogicalOperator
 *abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_DOUBLE_LOGICAL_OPERATOR_H
#define EBT_DOUBLE_LOGICAL_OPERATOR_H

#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class DoubleLogicalOperator : public LogicalOperator<E>
{
public:
  DoubleLogicalOperator(const DoubleLogicalOperator<E>& operatorr);
  virtual ~DoubleLogicalOperator();
  using Operator<bool, E>::insert;
  virtual Node<bool, E>* insert(Node<double, E>* node);
  virtual Node<bool, E>* getLeft() const;
  virtual Node<bool, E>* getRight() const;
  Node<double, E>* getDoubleLeft() const;
  Node<double, E>* getDoubleRight() const;
  virtual bool hasLeft() const;
  virtual bool hasRight() const;
  virtual void setLeft(Node<bool, E>* node);
  void setLeft(Node<double, E>* node);
  virtual void setRight(Node<bool, E>* node);
  void setRight(Node<double, E>* node);
  virtual std::string getSymbol() const = 0;
  virtual std::string str() const;

protected:
  DoubleLogicalOperator(Node<double, E>* left, Node<double, E>* right);

private:
  Node<double, E>* left__, *right__;
};

template <typename E>
DoubleLogicalOperator<E>::DoubleLogicalOperator(Node<double, E>* left,
                                                Node<double, E>* right)
    : LogicalOperator<E>::LogicalOperator(NULL, NULL, false), left__(left),
      right__(right)
{
}

template <typename E>
DoubleLogicalOperator<E>::DoubleLogicalOperator(
    const DoubleLogicalOperator<E>& operatorr)
    : LogicalOperator<E>::LogicalOperator(operatorr), left__(operatorr.left__),
      right__(operatorr.right__)
{
}

template <typename E> DoubleLogicalOperator<E>::~DoubleLogicalOperator()
{
  if (left__)
  {
    delete left__;
    left__ = NULL;
  }
  if (right__)
  {
    delete right__;
    right__ = NULL;
  }
}

template <typename E>
Node<bool, E>* DoubleLogicalOperator<E>::insert(Node<double, E>* node)
{
  if (!left__)
  {
    left__ = node;
  }
  else if (!right__)
  {
    right__ = node;
  }
  else
  {
    throw utilities::Exception(
        "This DoubleLogicalOperator is already filled!!!");
  }
  Node<bool, E>* root = Node<bool, E>::getParent();
  while (root && root->hasParent()) {
      root = root->getParent();
  }
  return root ? root : this;
}

template <typename E> Node<bool, E>* DoubleLogicalOperator<E>::getLeft() const
{
  throw utilities::Exception(
      "DoubleLogicalOperator does not have bool operands!!!");
}

template <typename E> Node<bool, E>* DoubleLogicalOperator<E>::getRight() const
{
  throw utilities::Exception(
      "DoubleLogicalOperator does not have bool operands!!!");
}

template <typename E>
Node<double, E>* DoubleLogicalOperator<E>::getDoubleLeft() const
{
  return left__;
}

template <typename E>
Node<double, E>* DoubleLogicalOperator<E>::getDoubleRight() const
{
  return right__;
}

template <typename E> bool DoubleLogicalOperator<E>::hasLeft() const
{
  return left__;
}

template <typename E> bool DoubleLogicalOperator<E>::hasRight() const
{
  return right__;
}

template <typename E>
void DoubleLogicalOperator<E>::setLeft(Node<bool, E>* node)
{
  throw utilities::Exception(
      "DoubleLogicalOperator does not have bool child nodes!!!");
}

template <typename E>
void DoubleLogicalOperator<E>::setRight(Node<bool, E>* node)
{
  throw utilities::Exception(
      "DoubleLogicalOperator does not have bool child nodes!!!");
}

template <typename E>
void DoubleLogicalOperator<E>::setLeft(Node<double, E>* node)
{
  left__ = node;
}

template <typename E>
void DoubleLogicalOperator<E>::setRight(Node<double, E>* node)
{
  right__ = node;
}

template <typename E> std::string DoubleLogicalOperator<E>::str() const
{
  std::stringstream ss;
  if (Operator<bool, E>::isUnary())
  {
    ss << getSymbol();
  }
  ss << (left__ ? left__->str() : "");
  if (!Operator<bool, E>::isUnary())
  {
    ss << " " + getSymbol() + " ";
    ss << (right__ ? right__->str() : "");
  }
  return "(" + ss.str() + ")";
}
}
}
}
}

#endif // EBT_DOUBLE_LOGICAL_OPERATOR_H
