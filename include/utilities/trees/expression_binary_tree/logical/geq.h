/**
 * This header file defines the ExpressionBinaryTree LogicalOperator GEQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_GEQ_H
#define EBT_LOGICAL_OPERATOR_GEQ_H

#include "utilities/trees/expression_binary_tree/logical/between_operands.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class GEQ : public BetweenOperands<E>
{
public:
  GEQ(Operand<E>* left, Operand<E>* right);
  GEQ(const GEQ<E>& operatorr);
  virtual ~GEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual GEQ<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string GEQ::SYMBOL = ">=";

template <typename E>
GEQ<E>::GEQ(Operand<E>* left, Operand<E>* right)
    : BetweenOperands(left, right)
{
}

template <typename E>
GEQ<E>::GEQ(const GEQ<E>& operatorr)
    : BetweenOperands(operatorr)
{
}

template <typename E> GEQ<E>::~GEQ() {}

template <typename E> bool GEQ<E>::process() const
{
  Node<bool, E>* left = Node<bool, E>::getLeft();
  Node<bool, E>* right = Node<bool, E>::getRight();
  return left->process() >= right->process();
}

template <typename E> std::string GEQ<E>::getSymbol() const
{
  return GEQ::SYMBOL;
}

template <typename E> GEQ<E>* GEQ<E>::clone() const
{
  return new GEQ<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_GEQ_H
