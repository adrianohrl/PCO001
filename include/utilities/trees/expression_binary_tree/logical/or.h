/**
 * This header file defines the ExpressionBinaryTree LogicalOperator OR class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_OR_H
#define EBT_LOGICAL_OPERATOR_OR_H

#include "utilities/trees/expression_binary_tree/logical/between_operators.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class OR : public BetweenOperators<E>
{
public:
  OR(LogicalOperator<E>* left, LogicalOperator<E>* right);
  OR(const OR<E>& operatorr);
  virtual ~OR();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual OR<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string OR::SYMBOL = "||";

template <typename E>
OR<E>::OR(LogicalOperator<E>* left, LogicalOperator<E>* right)
    : BetweenOperators(left, right)
{
}

template <typename E>
OR<E>::OR(const OR<E>& operatorr)
    : BetweenOperators(operatorr)
{
}

template <typename E> OR<E>::~OR() {}

template <typename E> bool OR<E>::process() const
{
  Node<bool, E>* left = Node<bool, E>::getLeft();
  Node<bool, E>* right = Node<bool, E>::getRight();
  return left->process() || right->process();
}

template <typename E> std::string OR<E>::getSymbol() const
{
  return OR::SYMBOL;
}

template <typename E> OR<E>* OR<E>::clone() const { return new OR<E>(*this); }
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_OR_H
