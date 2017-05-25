/**
 * This header file defines the ExpressionBinaryTree LogicalOperator NEQ class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_NEQ_H
#define EBT_LOGICAL_OPERATOR_NEQ_H

#include "utilities/trees/expression_binary_tree/logical/between_operands.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NEQ : public BetweenOperands<E>
{
public:
  NEQ(Node<double, E>* left, Node<double, E>* right);
  NEQ(const NEQ<E>& operatorr);
  virtual ~NEQ();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual NEQ<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string NEQ<E>::SYMBOL = "!=";

template <typename E>
NEQ<E>::NEQ(Node<double, E>* left, Node<double, E>* right)
    : BetweenOperands<E>::BetweenOperands(left, right)
{
}

template <typename E>
NEQ<E>::NEQ(const NEQ<E>& operatorr)
    : BetweenOperands<E>::BetweenOperands(operatorr)
{
}

template <typename E> NEQ<E>::~NEQ() {}

template <typename E> bool NEQ<E>::process() const
{
  return BetweenOperands<E>::getDoubleLeft()->process() !=
         BetweenOperands<E>::getDoubleRight()->process();
}

template <typename E> std::string NEQ<E>::getSymbol() const
{
  return NEQ<E>::SYMBOL;
}

template <typename E> NEQ<E>* NEQ<E>::clone() const
{
  return new NEQ<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_NEQ_H
