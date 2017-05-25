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
#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

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
  NLEQ(Node<double, E>* left, Node<double, E>* right);
  NLEQ(const NLEQ<E>& operatorr);
  virtual ~NLEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual NLEQ<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string NLEQ<E>::SYMBOL = ">";

template <typename E>
NLEQ<E>::NLEQ(Node<double, E>* left, Node<double, E>* right)
    : BetweenOperands<E>::BetweenOperands(left, right) // problem
{
}

template <typename E>
NLEQ<E>::NLEQ(const NLEQ<E>& operatorr)
    : BetweenOperands<E>::BetweenOperands(operatorr)
{
}

template <typename E> NLEQ<E>::~NLEQ() {}

template <typename E> bool NLEQ<E>::process() const
{
  return BetweenOperands<E>::getDoubleLeft()->process() >
         BetweenOperands<E>::getDoubleRight()->process();
}

template <typename E> std::string NLEQ<E>::getSymbol() const
{
  return NLEQ<E>::SYMBOL;
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
