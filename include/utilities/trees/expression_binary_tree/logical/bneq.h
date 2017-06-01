/**
 * This header file defines the ExpressionBinaryTree BoolLogicalOperator BNEQ
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_BOOL_LOGICAL_OPERATOR_NEQ_H
#define EBT_BOOL_LOGICAL_OPERATOR_NEQ_H

#include "utilities/trees/expression_binary_tree/logical/bool_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class BNEQ : public BoolLogicalOperator<E>
{
public:
  BNEQ(Node<bool, E>* left, Node<bool, E>* right);
  BNEQ(const BNEQ<E>& operatorr);
  virtual ~BNEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual int getPriority() const;
  virtual BNEQ<E>* clone() const;

  static const std::string SYMBOL;
  static const int PRIORITY;
};

template <typename E> const std::string BNEQ<E>::SYMBOL = "!=";
template <typename E> const int BNEQ<E>::PRIORITY = 6;

template <typename E>
BNEQ<E>::BNEQ(Node<bool, E>* left, Node<bool, E>* right)
    : BoolLogicalOperator<E>::BoolLogicalOperator(left, right)
{
}

template <typename E>
BNEQ<E>::BNEQ(const BNEQ<E>& operatorr)
    : BoolLogicalOperator<E>::BoolLogicalOperator(operatorr)
{
}

template <typename E> BNEQ<E>::~BNEQ() {}

template <typename E> bool BNEQ<E>::process() const
{
  return Operator<bool, E>::getLeft()->process() !=
         Operator<bool, E>::getRight()->process();
}

template <typename E> std::string BNEQ<E>::getSymbol() const
{
  return BNEQ<E>::SYMBOL;
}

template <typename E> int BNEQ<E>::getPriority() const
{
  return BNEQ<E>::PRIORITY;
}

template <typename E> BNEQ<E>* BNEQ<E>::clone() const
{
  return new BNEQ<E>(*this);
}
}
}
}
}

#endif // EBT_BOOL_LOGICAL_OPERATOR_NEQ_H
