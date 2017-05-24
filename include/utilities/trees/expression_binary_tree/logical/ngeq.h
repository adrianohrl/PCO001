/**
 * This header file defines the ExpressionBinaryTree LogicalOperator NGEQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_NGEQ_H
#define EBT_LOGICAL_OPERATOR_NGEQ_H

#include "utilities/trees/expression_binary_tree/logical/between_operands.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NGEQ : public BetweenOperands<E>
{
public:
  NGEQ(Operand<E>* left, Operand<E>* right);
  NGEQ(const NGEQ<E>& operatorr);
  virtual ~NGEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual NGEQ<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string NGEQ::SYMBOL = "<";

template <typename E>
NGEQ<E>::NGEQ(Operand<E>* left, Operand<E>* right)
    : BetweenOperands(left, right)
{
}

template <typename E>
NGEQ<E>::NGEQ(const NGEQ<E>& operatorr)
    : BetweenOperands(operatorr)
{
}

template <typename E> NGEQ<E>::~NGEQ() {}

template <typename E> bool NGEQ<E>::process() const
{
  Node<bool, E>* left = Node<bool, E>::getLeft();
  Node<bool, E>* right = Node<bool, E>::getRight();
  return left->process() < right->process();
}

template <typename E> std::string NGEQ<E>::getSymbol() const
{
  return NGEQ::SYMBOL;
}

template <typename E> NGEQ<E>* NGEQ<E>::clone() const
{
  return new NGEQ<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_NGEQ_H
