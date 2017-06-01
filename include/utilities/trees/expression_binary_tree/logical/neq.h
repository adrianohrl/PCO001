/**
 * This header file defines the ExpressionBinaryTree DoubleLogicalOperator NEQ
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_DOUBLE_LOGICAL_OPERATOR_NEQ_H
#define EBT_DOUBLE_LOGICAL_OPERATOR_NEQ_H

#include "utilities/trees/expression_binary_tree/logical/double_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NEQ : public DoubleLogicalOperator<E>
{
public:
  NEQ(Node<double, E>* left, Node<double, E>* right);
  NEQ(const NEQ<E>& operatorr);
  virtual ~NEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual int getPriority() const;
  virtual NEQ<E>* clone() const;

  static const std::string SYMBOL;
  static const int PRIORITY;
};

template <typename E> const std::string NEQ<E>::SYMBOL = "!=";
template <typename E> const int NEQ<E>::PRIORITY = 5;

template <typename E>
NEQ<E>::NEQ(Node<double, E>* left, Node<double, E>* right)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(left, right)
{
}

template <typename E>
NEQ<E>::NEQ(const NEQ<E>& operatorr)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(operatorr)
{
}

template <typename E> NEQ<E>::~NEQ() {}

template <typename E> bool NEQ<E>::process() const
{
  return DoubleLogicalOperator<E>::getDoubleLeft()->process() !=
         DoubleLogicalOperator<E>::getDoubleRight()->process();
}

template <typename E> std::string NEQ<E>::getSymbol() const
{
  return NEQ<E>::SYMBOL;
}

template <typename E> int NEQ<E>::getPriority() const
{
  return NEQ<E>::PRIORITY;
}

template <typename E> NEQ<E>* NEQ<E>::clone() const
{
  return new NEQ<E>(*this);
}
}
}
}
}

#endif // EBT_DOUBLE_LOGICAL_OPERATOR_NEQ_H
