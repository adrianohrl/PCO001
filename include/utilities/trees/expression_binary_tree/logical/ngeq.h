/**
 * This header file defines the ExpressionBinaryTree DoubleLogicalOperator NGEQ
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_DOUBLE_LOGICAL_OPERATOR_NGEQ_H
#define EBT_DOUBLE_LOGICAL_OPERATOR_NGEQ_H

#include "utilities/trees/expression_binary_tree/logical/double_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NGEQ : public DoubleLogicalOperator<E>
{
public:
  NGEQ(Node<double, E>* left = NULL, Node<double, E>* right = NULL);
  NGEQ(const NGEQ<E>& operatorr);
  virtual ~NGEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual int getPriority() const;
  virtual NGEQ<E>* clone() const;

  static const std::string SYMBOL;
  static const int PRIORITY;
};

template <typename E> const std::string NGEQ<E>::SYMBOL = "<";
template <typename E> const int NGEQ<E>::PRIORITY = 5;

template <typename E>
NGEQ<E>::NGEQ(Node<double, E>* left, Node<double, E>* right)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(left, right)
{
}

template <typename E>
NGEQ<E>::NGEQ(const NGEQ<E>& operatorr)
    : DoubleLogicalOperator<E>::DoubleLogicalOperator(operatorr)
{
}

template <typename E> NGEQ<E>::~NGEQ() {}

template <typename E> bool NGEQ<E>::process() const
{
  return DoubleLogicalOperator<E>::getDoubleLeft()->process() <
         DoubleLogicalOperator<E>::getDoubleRight()->process();
}

template <typename E> std::string NGEQ<E>::getSymbol() const
{
  return NGEQ<E>::SYMBOL;
}

template <typename E> int NGEQ<E>::getPriority() const
{
  return NGEQ<E>::PRIORITY;
}

template <typename E> NGEQ<E>* NGEQ<E>::clone() const
{
  return new NGEQ<E>(*this);
}
}
}
}
}

#endif // EBT_DOUBLE_LOGICAL_OPERATOR_NGEQ_H
