/**
 * This header file defines the ExpressionBinaryTree LogicalOperator EQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_EQ_H
#define EBT_LOGICAL_OPERATOR_EQ_H

#include "utilities/trees/expression_binary_tree/logical/between_operands.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class EQ : public BetweenOperands<E>
{
public:
  EQ(Operand<E>* left, Operand<E>* right);
  EQ(const EQ<E>& operatorr);
  virtual ~EQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual EQ<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string EQ::SYMBOL = "==";

template <typename E>
EQ<E>::EQ(Operand<E>* left, Operand<E>* right)
    : BetweenOperands(left, right)
{
}

template <typename E>
EQ<E>::EQ(const EQ<E>& operatorr)
    : BetweenOperands(operatorr)
{
}

template <typename E> EQ<E>::~EQ() {}

template <typename E> bool EQ<E>::process() const
{
  Node<bool, E>* left = Node<bool, E>::getLeft();
  Node<bool, E>* right = Node<bool, E>::getRight();
  return left->process() == right->process();
}

template <typename E> std::string EQ<E>::getSymbol() const
{
  return EQ::SYMBOL;
}

template <typename E> EQ<E>* EQ<E>::clone() const { return new EQ<E>(*this); }
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_EQ_H
