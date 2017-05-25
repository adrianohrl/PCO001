/**
 * This header file defines the ExpressionBinaryTree BoolLogicalOperator OR class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_BOOL_LOGICAL_OPERATOR_OR_H
#define EBT_BOOL_LOGICAL_OPERATOR_OR_H

#include "utilities/trees/expression_binary_tree/logical/bool_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class OR : public BoolLogicalOperator<E>
{
public:
  OR(Node<bool, E>* left, Node<bool, E>* right);
  OR(const OR<E>& operatorr);
  virtual ~OR();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual OR<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string OR<E>::SYMBOL = "||";

template <typename E>
OR<E>::OR(Node<bool, E>* left, Node<bool, E>* right)
    : BoolLogicalOperator<E>::BoolLogicalOperator(left, right)
{
}

template <typename E>
OR<E>::OR(const OR<E>& operatorr)
    : BoolLogicalOperator<E>::BoolLogicalOperator(operatorr)
{
}

template <typename E> OR<E>::~OR() {}

template <typename E> bool OR<E>::process() const
{
  return Operator<bool, E>::getLeft()->process() ||
         Operator<bool, E>::getRight()->process();
}

template <typename E> std::string OR<E>::getSymbol() const
{
  return OR<E>::SYMBOL;
}

template <typename E> OR<E>* OR<E>::clone() const { return new OR<E>(*this); }
}
}
}
}

#endif // EBT_BOOL_LOGICAL_OPERATOR_OR_H
