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
  NGEQ(Node<double, E>* left, Node<double, E>* right);
  NGEQ(const NGEQ<E>& operatorr);
  virtual ~NGEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual NGEQ<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string NGEQ<E>::SYMBOL = "<";

template <typename E>
NGEQ<E>::NGEQ(Node<double, E>* left, Node<double, E>* right)
    : BetweenOperands<E>::BetweenOperands(left, right)
{
}

template <typename E>
NGEQ<E>::NGEQ(const NGEQ<E>& operatorr)
    : BetweenOperands<E>::BetweenOperands(operatorr)
{
}

template <typename E> NGEQ<E>::~NGEQ() {}

template <typename E> bool NGEQ<E>::process() const
{
  return BetweenOperands<E>::getDoubleLeft()->process() <
         BetweenOperands<E>::getDoubleRight()->process();
}

template <typename E> std::string NGEQ<E>::getSymbol() const
{
  return NGEQ<E>::SYMBOL;
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
