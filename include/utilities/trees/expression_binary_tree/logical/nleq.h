/**
 * This header file defines the ExpressionBinaryTree DoubleLogicalOperator NLEQ
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_DOUBLE_LOGICAL_OPERATOR_NLEQ_H
#define EBT_DOUBLE_LOGICAL_OPERATOR_NLEQ_H

#include "utilities/trees/expression_binary_tree/logical/double_logical_operator.h"
#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NLEQ : public DoubleLogicalOperator<E>
{
public:
  NLEQ(Node<double, E>* left = NULL, Node<double, E>* right = NULL);
  NLEQ(const NLEQ<E>& operatorr);
  virtual ~NLEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual int getPriority() const;
  virtual NLEQ<E>* clone() const;

  static const std::string SYMBOL;
  static const int PRIORITY;
};

template <typename E> const std::string NLEQ<E>::SYMBOL = ">";
template <typename E> const int NLEQ<E>::PRIORITY = 5;

template <typename E>
NLEQ<E>::NLEQ(Node<double, E>* left, Node<double, E>* right)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(left, right)
{
}

template <typename E>
NLEQ<E>::NLEQ(const NLEQ<E>& operatorr)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(operatorr)
{
}

template <typename E> NLEQ<E>::~NLEQ() {}

template <typename E> bool NLEQ<E>::process() const
{
  return DoubleLogicalOperator<E>::getDoubleLeft()->process() >
         DoubleLogicalOperator<E>::getDoubleRight()->process();
}

template <typename E> std::string NLEQ<E>::getSymbol() const
{
  return NLEQ<E>::SYMBOL;
}

template <typename E> int NLEQ<E>::getPriority() const
{
  return NLEQ<E>::PRIORITY;
}

template <typename E> NLEQ<E>* NLEQ<E>::clone() const
{
  return new NLEQ<E>(*this);
}
}
}
}
}

#endif // EBT_DOUBLE_LOGICAL_OPERATOR_NLEQ_H
