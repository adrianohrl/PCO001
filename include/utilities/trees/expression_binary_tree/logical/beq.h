/**
 * This header file defines the ExpressionBinaryTree BoolLogicalOperator BEQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_BOOL_LOGICAL_OPERATOR_EQ_H
#define EBT_BOOL_LOGICAL_OPERATOR_EQ_H

#include "utilities/trees/expression_binary_tree/logical/bool_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class BEQ : public BoolLogicalOperator<E>
{
public:
  BEQ(Node<bool, E>* left, Node<bool, E>* right);
  BEQ(const BEQ<E>& operatorr);
  virtual ~BEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual BEQ<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string BEQ<E>::SYMBOL = "==";

template <typename E>
BEQ<E>::BEQ(Node<bool, E>* left, Node<bool, E>* right)
    : BoolLogicalOperator<E>::BoolLogicalOperator(left, right)
{
}

template <typename E>
BEQ<E>::BEQ(const BEQ<E>& operatorr)
    : BoolLogicalOperator<E>::BoolLogicalOperator(operatorr)
{
}

template <typename E> BEQ<E>::~BEQ() {}

template <typename E> bool BEQ<E>::process() const
{
  return Operator<bool, E>::getLeft()->process() ==
         Operator<bool, E>::getRight()->process();
}

template <typename E> std::string BEQ<E>::getSymbol() const
{
  return BEQ<E>::SYMBOL;
}

template <typename E> BEQ<E>* BEQ<E>::clone() const { return new BEQ<E>(*this); }
}
}
}
}

#endif // EBT_BOOL_LOGICAL_OPERATOR_EQ_H
