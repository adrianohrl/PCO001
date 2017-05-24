/**
 * This header file defines the ExpressionBinaryTree ArithmeticOperator Negation
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_OPERATOR_NEGATION_H
#define EBT_ARITHMETIC_OPERATOR_NEGATION_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E> class Negation : public ArithmeticOperator<E>
{
public:
  Negation(ArithmeticOperator<E>* operatorr);
  Negation(const Negation<E>& operatorr);
  virtual ~Subtraction();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Negation<E>* clone() const;

  static const std::string SYMBOL;
};

const std::string Negation::SYMBOL = "-";

template <typename E>
Negation::Negation(ArithmeticOperator<E>* operatorr)
    : ArithmeticOperator(operatorr)
{
}

template <typename E>
Negation::Negation(const Negation<E>& operatorr)
    : ArithmeticOperator(operatorr)
{
}

template <typename E> Negation::~Negation() {}

template <typename E> std::string Negation::getSymbol() const
{
  return Negation::SYMBOL;
}

template <typename E> double Negation::process() const
{
  Node<double, E>* left = Node<double, E>::getLeft();
  return -left->process();
}

template <typename E> Negation<E>* Negation::clone() const
{
  return new Negation<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_NEGATION_H
