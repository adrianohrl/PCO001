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
  Negation(Node<double, E>* operatorr);
  Negation(const Negation<E>& operatorr);
  virtual ~Negation();
  virtual std::string getSymbol() const;
  virtual double process() const;
  virtual Negation<E>* clone() const;

  static const std::string SYMBOL;
};

template <typename E> const std::string Negation<E>::SYMBOL = "-";

template <typename E>
Negation<E>::Negation(Node<double, E>* operatorr)
    : ArithmeticOperator<E>::ArithmeticOperator(operatorr)
{
}

template <typename E>
Negation<E>::Negation(const Negation<E>& operatorr)
    : ArithmeticOperator<E>::ArithmeticOperator(operatorr)
{
}

template <typename E> Negation<E>::~Negation() {}

template <typename E> std::string Negation<E>::getSymbol() const
{
  return Negation<E>::SYMBOL;
}

template <typename E> double Negation<E>::process() const
{
  return -Operator<double, E>::getLeft()->process();
}

template <typename E> Negation<E>* Negation<E>::clone() const
{
  return new Negation<E>(*this);
}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_NEGATION_H
