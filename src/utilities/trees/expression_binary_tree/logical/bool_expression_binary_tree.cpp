/**
 * This header file implements the BoolExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/trees/expression_binary_tree/logical/bool_expression_binary_tree.h"
#include "utilities/trees/expression_binary_tree/logical/bool_expression_parser.h"
#include "utilities/trees/expression_binary_tree/arithmetic/double_expression_binary_tree.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

BoolExpressionBinaryTree::BoolExpressionBinaryTree()
    : LogicalExpressionBinaryTree<double>::LogicalExpressionBinaryTree(
          new arithmetic::DoubleExpressionBinaryTree())
{
}

BoolExpressionBinaryTree::BoolExpressionBinaryTree(std::string expression)
    : LogicalExpressionBinaryTree<double>::LogicalExpressionBinaryTree(
          new arithmetic::DoubleExpressionBinaryTree(),
          new BoolExpressionParser(), expression)
{
}

BoolExpressionBinaryTree::BoolExpressionBinaryTree(
    const BoolExpressionBinaryTree& ebt)
    : LogicalExpressionBinaryTree<double>::LogicalExpressionBinaryTree(ebt)
{
}

BoolExpressionBinaryTree::~BoolExpressionBinaryTree() {}
}
}
}
}
