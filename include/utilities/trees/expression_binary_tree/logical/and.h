/**
 * This header file defines the ExpressionBinaryTree BoolLogicalOperator AND
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_BOOL_LOGICAL_OPERATOR_AND_H
#define EBT_BOOL_LOGICAL_OPERATOR_AND_H

#include "utilities/trees/expression_binary_tree/logical/bool_logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class AND : public BoolLogicalOperator<E>
{
public:
  AND(Node<bool, E>* left, Node<bool, E>* right);
  AND(const AND<E>& operatorr);
  virtual ~AND();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual int getPriority() const;
  virtual AND<E>* clone() const;

  static const std::string SYMBOL;
  static const int PRIORITY;
};

template <typename E> const std::string AND<E>::SYMBOL = "&&";
template <typename E> const int AND<E>::PRIORITY = 6;

template <typename E>
AND<E>::AND(Node<bool, E>* left, Node<bool, E>* right)
    : BoolLogicalOperator<E>::BoolLogicalOperator(left, right)
{
}

template <typename E>
AND<E>::AND(const AND<E>& operatorr)
    : BoolLogicalOperator<E>::BoolLogicalOperator(operatorr)
{
}

template <typename E> AND<E>::~AND() {}

template <typename E> bool AND<E>::process() const
{
  return Operator<bool, E>::getLeft()->process() &&
         Operator<bool, E>::getRight()->process();
}

template <typename E> std::string AND<E>::getSymbol() const
{
  return AND<E>::SYMBOL;
}

template <typename E> int AND<E>::getPriority() const
{
  return AND<E>::PRIORITY;
}

template <typename E> AND<E>* AND<E>::clone() const
{
  return new AND<E>(*this);
}
}
}
}
}

#endif // EBT_BOOL_LOGICAL_OPERATOR_AND_H
