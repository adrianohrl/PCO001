/**
 * This header file defines the ExpressionBinaryTree LogicalOperator NOT class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_NOT_H
#define EBT_LOGICAL_OPERATOR_NOT_H

#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class NOT : public LogicalOperator<E>
{
public:
  NOT(Node<bool, E>* operatorr);
  NOT(const NOT<E>& operatorr);
  virtual ~NOT();
  virtual bool process() const;
  virtual std::string getSymbol() const;
  virtual int getPriority() const;
  virtual NOT<E>* clone() const;

  static const std::string SYMBOL;
  static const int PRIORITY;
};

template <typename E> const std::string NOT<E>::SYMBOL = "!";
template <typename E> const int NOT<E>::PRIORITY = 4;

template <typename E>
NOT<E>::NOT(Node<bool, E>* operatorr)
    : LogicalOperator<E>::LogicalOperator(operatorr)
{
}

template <typename E>
NOT<E>::NOT(const NOT<E>& operatorr)
    : LogicalOperator<E>::LogicalOperator(operatorr)
{
}

template <typename E> NOT<E>::~NOT() {}

template <typename E> bool NOT<E>::process() const
{
  return !Operator<bool, E>::getRight()->process();
}

template <typename E> std::string NOT<E>::getSymbol() const
{
  return NOT<E>::SYMBOL;
}

template <typename E> int NOT<E>::getPriority() const
{
  return NOT<E>::PRIORITY;
}

template <typename E> NOT<E>* NOT<E>::clone() const
{
  return new NOT<E>(*this);
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_NOT_H
