/**
 * This header file defines the ExpressionBinaryTree DoubleLogicalOperator EQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_DOUBLE_LOGICAL_OPERATOR_DOUBLE_EQ_H
#define EBT_DOUBLE_LOGICAL_OPERATOR_DOUBLE_EQ_H

#include "utilities/trees/expression_binary_tree/logical/double_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class EQ : public DoubleLogicalOperator<E>
{
public:
  EQ(Node<double, E>* left, Node<double, E>* right);
  EQ(const EQ<E>& operatorr);
  virtual ~EQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual EQ<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string EQ<E>::SYMBOL = "==";

template <typename E>
EQ<E>::EQ(Node<double, E>* left, Node<double, E>* right)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(left, right)
{
}

template <typename E>
EQ<E>::EQ(const EQ<E>& operatorr)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(operatorr)
{
}

template <typename E> EQ<E>::~EQ() {}

template <typename E> bool EQ<E>::process() const
{
  return DoubleLogicalOperator<E>::getDoubleLeft()->process() ==
         DoubleLogicalOperator<E>::getDoubleRight()->process();
}

template <typename E> std::string EQ<E>::getSymbol() const
{
  return EQ<E>::SYMBOL;
}

template <typename E> EQ<E>* EQ<E>::clone() const { return new EQ<E>(*this); }
}
}
}
}

#endif // EBT_DOUBLE_LOGICAL_OPERATOR_DOUBLE_EQ_H
