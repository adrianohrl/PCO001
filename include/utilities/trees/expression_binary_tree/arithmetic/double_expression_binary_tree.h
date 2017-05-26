/**
 * This header file defines the DoubleExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DOUBLE_EXPRESSION_BINARY_TREE_H
#define DOUBLE_EXPRESSION_BINARY_TREE_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_expression_binary_tree.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

class DoubleExpressionBinaryTree : public ArithmeticExpressionBinaryTree<double>
{
public:
  DoubleExpressionBinaryTree(std::string expression);
  DoubleExpressionBinaryTree(const DoubleExpressionBinaryTree& ebt);
  virtual ~DoubleExpressionBinaryTree();
};
}
}
}
}

#endif // DOUBLE_EXPRESSION_BINARY_TREE_H
