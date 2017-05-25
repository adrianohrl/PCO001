/**
 * This header file defines the ExpressionBinaryTree ArithmeticOperator Division
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_OPERATOR_DIVISION_H
#define EBT_ARITHMETIC_OPERATOR_DIVISION_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E> class Division : public ArithmeticOperator<E>
{
public:
  Division(Node<double, E>* left, Node<double, E>* right);
  Division(const Division<E>& operatorr);
  virtual ~Division();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Division<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string Division<E>::SYMBOL = "/";

template <typename E>
Division<E>::Division(Node<double, E>* left, Node<double, E>* right)
    : ArithmeticOperator<E>::ArithmeticOperator(left, right)
{
}

template <typename E>
Division<E>::Division(const Division<E>& operatorr)
    : ArithmeticOperator<E>::ArithmeticOperator(operatorr)
{
}

template <typename E> Division<E>::~Division() {}

template <typename E> std::string Division<E>::getSymbol() const
{
  return Division<E>::SYMBOL;
}

template <typename E> double Division<E>::process() const
{
  return Operator<double, E>::getLeft()->process() /
         Operator<double, E>::getRight()->process();
}

template <typename E> Division<E>* Division<E>::clone() const
{
  return new Division<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_DIVISION_H
