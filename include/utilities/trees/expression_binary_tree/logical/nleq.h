/**
 * This header file defines the ExpressionBinaryTree LogicalOperator NLEQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_NLEQ_H
#define EBT_LOGICAL_OPERATOR_NLEQ_H

#include "utilities/trees/expression_binary_tree/logical/between_operands.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NLEQ : public BetweenOperands<E>
{
public:
  NLEQ(Operand<E>* left, Operand<E>* right);
  NLEQ(const NLEQ<E>& operatorr);
  virtual ~NLEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual NLEQ<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string NLEQ::SYMBOL = ">";

template <typename E>
NLEQ<E>::NLEQ(Operand<E>* left, Operand<E>* right)
    : BetweenOperands(left, right)
{
}

template <typename E>
NLEQ<E>::NLEQ(const NLEQ<E>& operatorr)
    : BetweenOperands(operatorr)
{
}

template <typename E> NLEQ<E>::~NLEQ() {}

template <typename E> bool NLEQ<E>::process() const
{
  Node<bool, E>* left = Node<bool, E>::getLeft();
  Node<bool, E>* right = Node<bool, E>::getRight();
  return left->process() > right->process();
}

template <typename E> std::string NLEQ<E>::getSymbol() const
{
  return NLEQ::SYMBOL;
}

template <typename E> NLEQ<E>* NLEQ<E>::clone() const
{
  return new NLEQ<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_NLEQ_H
