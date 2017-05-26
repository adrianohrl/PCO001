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
  virtual ~DoubleLogicalOperator();
  virtual std::string getSymbol() const = 0;
  virtual std::string str() const;

protected:
  DoubleLogicalOperator(Node<double, E>* left, Node<double, E>* right);
  DoubleLogicalOperator(const DoubleLogicalOperator<E>& operatorr);
  Node<double, E>* getDoubleLeft() const;
  Node<double, E>* getDoubleRight() const;

private:
  Node<double, E> *left__, *right__;
};

template <typename E>
DoubleLogicalOperator<E>::DoubleLogicalOperator(Node<double, E>* left,
                                    Node<double, E>* right)
    : LogicalOperator<E>::LogicalOperator(NULL, NULL), left__(left), right__(right)
{
}

template <typename E>
DoubleLogicalOperator<E>::DoubleLogicalOperator(const DoubleLogicalOperator<E>& operatorr)
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

template <typename E> Node<double, E>* DoubleLogicalOperator<E>::getDoubleLeft() const
{
  return left__;
}

template <typename E>
Node<double, E>* DoubleLogicalOperator<E>::getDoubleRight() const
{
  return right__;
}
}
}
}
}

#endif // EBT_DOUBLE_LOGICAL_OPERATOR_H
