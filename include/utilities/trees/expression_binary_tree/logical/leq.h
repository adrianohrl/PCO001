/**
 * This header file defines the ExpressionBinaryTree LogicalOperator LEQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_LEQ_H
#define EBT_LOGICAL_OPERATOR_LEQ_H

#include "utilities/trees/expression_binary_tree/logical/between_operands.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class LEQ : public BetweenOperands<E>
{
public:
  LEQ(Node<double, E>* left, Node<double, E>* right);
  LEQ(const LEQ<E>& operatorr);
  virtual ~LEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual LEQ<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string LEQ<E>::SYMBOL = "<=";

template <typename E>
LEQ<E>::LEQ(Node<double, E>* left, Node<double, E>* right)
    : BetweenOperands<E>::BetweenOperands(left, right)
{
}

template <typename E>
LEQ<E>::LEQ(const LEQ<E>& operatorr)
    : BetweenOperands<E>::BetweenOperands(operatorr)
{
}

template <typename E> LEQ<E>::~LEQ() {}

template <typename E> bool LEQ<E>::process() const
{
  return BetweenOperands<E>::getDoubleLeft()->process() <=
         BetweenOperands<E>::getDoubleRight()->process();
}

template <typename E> std::string LEQ<E>::getSymbol() const
{
  return LEQ<E>::SYMBOL;
}

template <typename E> LEQ<E>* LEQ<E>::clone() const
{
  return new LEQ<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_LEQ_H