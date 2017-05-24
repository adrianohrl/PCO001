/**
 * This header file defines the ExpressionBinaryTree LogicalOperator
 *BetweenOperands abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_BETWEEN_OPERANDS_H
#define EBT_LOGICAL_OPERATOR_BETWEEN_OPERANDS_H

#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class BetweenOperands : public LogicalOperator<E>
{
public:
  virtual ~BetweenOperands();

protected:
  BetweenOperands(Operand<E>* left, Operand<E>* right);
  BetweenOperands(const BetweenOperands<E>& operatorr);
};

template <typename E>
BetweenOperands<E>::BetweenOperands(Operand<E> *left,
                                    Operand<E> *right)
    : LogicalOperator(left, right)
{
}

template <typename E>
BetweenOperands<E>::BetweenOperands(const BetweenOperands<E>& operatorr)
    : LogicalOperator(operatorr)
{
}

template <typename E> BetweenOperands<E>::~BetweenOperands() {}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_BETWEEN_OPERANDS_H
