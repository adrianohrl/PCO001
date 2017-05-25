/**
 * This header file defines the ExpressionBinaryTree LogicalOperator
 *BetweenOperators abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_BETWEEN_OPERATORS_H
#define EBT_LOGICAL_OPERATOR_BETWEEN_OPERATORS_H

#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class BetweenOperators : public LogicalOperator<E>
{
public:
  virtual ~BetweenOperators();

protected:
  BetweenOperators(Node<bool, E>* left, Node<bool, E>* right);
  BetweenOperators(const BetweenOperators<E>& operatorr);
};

template <typename E>
BetweenOperators<E>::BetweenOperators(Node<bool, E>* left, Node<bool, E>* right)
    : LogicalOperator<E>::LogicalOperator(left, right)
{
}

template <typename E>
BetweenOperators<E>::BetweenOperators(const BetweenOperators<E>& operatorr)
    : LogicalOperator<E>::LogicalOperator(operatorr)
{
}

template <typename E> BetweenOperators<E>::~BetweenOperators() {}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_BETWEEN_OPERATORS_H
