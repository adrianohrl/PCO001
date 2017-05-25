/**
 * This header file defines the ExpressionBinaryTree ArithmeticOperator
 *Multiplication class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_OPERATOR_MULTIPLICATION_H
#define EBT_ARITHMETIC_OPERATOR_MULTIPLICATION_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E> class Multiplication : public ArithmeticOperator<E>
{
public:
  Multiplication(Node<double, E>* left, Node<double, E>* right);
  Multiplication(const Multiplication<E>& operatorr);
  virtual ~Multiplication();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Multiplication<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string Multiplication<E>::SYMBOL = "*";

template <typename E>
Multiplication<E>::Multiplication(Node<double, E>* left, Node<double, E>* right)
    : ArithmeticOperator<E>::ArithmeticOperator(left, right)
{
}

template <typename E>
Multiplication<E>::Multiplication(const Multiplication<E>& operatorr)
    : ArithmeticOperator<E>::ArithmeticOperator(operatorr)
{
}

template <typename E> Multiplication<E>::~Multiplication() {}

template <typename E> std::string Multiplication<E>::getSymbol() const
{
  return Multiplication<E>::SYMBOL;
}

template <typename E> double Multiplication<E>::process() const
{
  return Operator<double, E>::getLeft()->process() *
         Operator<double, E>::getRight()->process();
}

template <typename E> Multiplication<E>* Multiplication<E>::clone() const
{
  return new Multiplication<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_MULTIPLICATION_H
