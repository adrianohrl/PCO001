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
  Subtraction(Operand<E>* left, Operand<E>* right);
  Subtraction(const Subtraction<E>& operatorr);
  virtual ~Subtraction();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Subtraction<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string Subtraction::SYMBOL = "-";

template <typename E>
Subtraction::Subtraction(Operand<E>* left, Operand<E>* right)
    : ArithmeticOperator(left, right)
{
}

template <typename E>
Subtraction::Subtraction(const Subtraction<E>& operatorr)
    : ArithmeticOperator(operatorr)
{
}

template <typename E> Subtraction::~Subtraction() {}

template <typename E> std::string Subtraction::getSymbol() const
{
  return Subtraction::SYMBOL;
}

template <typename E> double Subtraction::process() const
{
  Node<double, E>* left = Node<double, E>::getLeft();
  Node<double, E>* right = Node<double, E>::getRight();
  return left->process() - right->process();
}

template <typename E> Subtraction<E>* Subtraction::clone() const
{
  return new Subtraction<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_SUBTRACTION_H
