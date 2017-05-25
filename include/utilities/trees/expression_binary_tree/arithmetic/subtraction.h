/**
 * This header file defines the ExpressionBinaryTree ArithmeticOperator
 *Subtraction class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_OPERATOR_SUBTRACTION_H
#define EBT_ARITHMETIC_OPERATOR_SUBTRACTION_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E> class Subtraction : public ArithmeticOperator<E>
{
public:
  Subtraction(Node<double, E>* left, Node<double, E>* right);
  Subtraction(const Subtraction<E>& operatorr);
  virtual ~Subtraction();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Subtraction<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string Subtraction<E>::SYMBOL = "-";

template <typename E>
Subtraction<E>::Subtraction(Node<double, E>* left, Node<double, E>* right)
    : ArithmeticOperator<E>::ArithmeticOperator(left, right)
{
}

template <typename E>
Subtraction<E>::Subtraction(const Subtraction<E>& operatorr)
    : ArithmeticOperator<E>::ArithmeticOperator(operatorr)
{
}

template <typename E> Subtraction<E>::~Subtraction() {}

template <typename E> std::string Subtraction<E>::getSymbol() const
{
  return Subtraction<E>::SYMBOL;
}

template <typename E> double Subtraction<E>::process() const
{
  return Operator<double, E>::getLeft()->process() -
         Operator<double, E>::getRight()->process();
}

template <typename E> Subtraction<E>* Subtraction<E>::clone() const
{
  return new Subtraction<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_SUBTRACTION_H
