/**
 * This header file defines the ExpressionBinaryTree LogicalOperator AND class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_AND_H
#define EBT_LOGICAL_OPERATOR_AND_H

#include "utilities/trees/expression_binary_tree/logical/between_operators.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class AND : public BetweenOperators<E>
{
public:
  AND(LogicalOperator<E>* left, LogicalOperator<E>* right);
  AND(const AND<E>& operatorr);
  virtual ~AND();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual AND<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string AND::SYMBOL = "&&";

template <typename E>
AND<E>::AND(LogicalOperator<E>* left, LogicalOperator<E>* right)
    : BetweenOperators(left, right)
{
}

template <typename E>
AND<E>::AND(const AND<E>& operatorr)
    : BetweenOperators(operatorr)
{
}

template <typename E> AND<E>::~AND() {}

template <typename E> bool AND<E>::process() const
{
  Node<bool, E>* left = Node<bool, E>::getLeft();
  Node<bool, E>* right = Node<bool, E>::getRight();
  return left->process() && right->process();
}

template <typename E> std::string AND<E>::getSymbol() const
{
  return AND::SYMBOL;
}

template <typename E> AND<E>* AND<E>::clone() const
{
  return new AND<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_AND_H
