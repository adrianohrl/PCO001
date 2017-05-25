/**
 * This header file defines the ExpressionBinaryTree BoolLogicalOperator
 *abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_BOOL_LOGICAL_OPERATOR_H
#define EBT_BOOL_LOGICAL_OPERATOR_H

#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class BoolLogicalOperator : public LogicalOperator<E>
{
public:
  virtual ~BoolLogicalOperator();

protected:
  BoolLogicalOperator(Node<bool, E>* left, Node<bool, E>* right);
  BoolLogicalOperator(const BoolLogicalOperator<E>& operatorr);
};

template <typename E>
BoolLogicalOperator<E>::BoolLogicalOperator(Node<bool, E>* left, Node<bool, E>* right)
    : LogicalOperator<E>::LogicalOperator(left, right)
{
}

template <typename E>
BoolLogicalOperator<E>::BoolLogicalOperator(const BoolLogicalOperator<E>& operatorr)
    : LogicalOperator<E>::LogicalOperator(operatorr)
{
}

template <typename E> BoolLogicalOperator<E>::~BoolLogicalOperator() {}
}
}
}
}

#endif // EBT_BOOL_LOGICAL_OPERATOR_H
