/**
 * This header file defines the BoolExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BOOL_EXPRESSION_BINARY_TREE_H
#define BOOL_EXPRESSION_BINARY_TREE_H

#include "utilities/trees/expression_binary_tree/logical/logical_expression_binary_tree.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

class BoolExpressionBinaryTree : public LogicalExpressionBinaryTree<bool>
{
public:
  BoolExpressionBinaryTree();
  BoolExpressionBinaryTree(std::string expression);
  BoolExpressionBinaryTree(const BoolExpressionBinaryTree& ebt);
  virtual ~BoolExpressionBinaryTree();
};
}
}
}
}

#endif // BOOL_EXPRESSION_BINARY_TREE_H
