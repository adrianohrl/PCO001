/**
 * This header file defines the ExpressionBinaryTree ArithmeticOperator Addition
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_OPERATOR_ADDITION_H
#define EBT_ARITHMETIC_OPERATOR_ADDITION_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E> class Addition : public ArithmeticOperator<E>
{
public:
  Addition(Node<double, E>* left, Node<double, E>* right);
  Addition(const Addition<E>& operatorr);
  virtual ~Addition();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Addition<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string Addition<E>::SYMBOL = "+";

template <typename E>
Addition<E>::Addition(Node<double, E>* left, Node<double, E>* right)
    : ArithmeticOperator<E>::ArithmeticOperator(left, right)
{
}

template <typename E>
Addition<E>::Addition(const Addition<E>& operatorr)
    : ArithmeticOperator<E>::ArithmeticOperator(operatorr)
{
}

template <typename E> Addition<E>::~Addition() {}

template <typename E> std::string Addition<E>::getSymbol() const
{
  return Addition<E>::SYMBOL;
}

template <typename E> double Addition<E>::process() const
{
  return Operator<double, E>::getLeft()->process() +
         Operator<double, E>::getRight()->process();
}

template <typename E> Addition<E>* Addition<E>::clone() const
{
  return new Addition<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_ADDITION_H
