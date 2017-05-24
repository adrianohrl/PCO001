/**
 * This header file defines the ExpressionBinaryTree ArithmeticOperator abstract
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_OPERATOR_H
#define EBT_ARITHMETIC_OPERATOR_H

#include "utilities/trees/expression_binary_tree/operator.h"
#include "utilities/trees/expression_binary_tree/operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E> class ArithmeticOperator : public Operator<double, E>
{
public:
  virtual ~ArithmeticOperator();

protected:
  ArithmeticOperator(ArithmeticOperator<E>* operatorr);
  ArithmeticOperator(Operand<E>* left, Operand<E>* right);
  ArithmeticOperator(const ArithmeticOperator& operatorr);
};

template <typename E>
ArithmeticOperator<E>::ArithmeticOperator(ArithmeticOperator<E>* operatorr)
    : Operator(operatorr)
{
}

template <typename E>
ArithmeticOperator<E>::ArithmeticOperator(Operand<E>* left, Operand<E>* right)
    : Operator(left, right)
{
}

template <typename E>
ArithmeticOperator<E>::ArithmeticOperator(const ArithmeticOperator& operatorr)
    : Operator(operatorr)
{
}

template <typename E> ArithmeticOperator<E>::~ArithmeticOperator() {}
}
}
}
}

#endif // EBT_ARITHMETIC_OPERATOR_ADDITION_H
