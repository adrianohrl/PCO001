/**
 * This header file defines the ArithmeticExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef ARITHMETIC_EXPRESSION_BINARY_TREE_H
#define ARITHMETIC_EXPRESSION_BINARY_TREE_H

#include "utilities/trees/expression_binary_tree/expression_binary_tree.h"
#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E>
class ArithmeticExpressionBinaryTree : public ExpressionBinaryTree<double, E>
{
public:
  ArithmeticExpressionBinaryTree(const ArithmeticExpressionBinaryTree<E>& ebt);
  virtual ~ArithmeticExpressionBinaryTree();

protected:
  ArithmeticExpressionBinaryTree();
  ArithmeticExpressionBinaryTree(ArithmeticExpressionParser<E>* parser,
                                 std::string expression);
};

template <typename E>
ArithmeticExpressionBinaryTree<E>::ArithmeticExpressionBinaryTree()
    : ExpressionBinaryTree<double, E>::ExpressionBinaryTree()
{
}

template <typename E>
ArithmeticExpressionBinaryTree<E>::ArithmeticExpressionBinaryTree(
    ArithmeticExpressionParser<E>* parser, std::string expression)
    : ExpressionBinaryTree<double, E>::ExpressionBinaryTree(parser, expression)
{
}

template <typename E>
ArithmeticExpressionBinaryTree<E>::ArithmeticExpressionBinaryTree(
    const ArithmeticExpressionBinaryTree<E>& ebt)
    : ExpressionBinaryTree<double, E>::ExpressionBinaryTree(ebt)
{
}

template <typename E>
ArithmeticExpressionBinaryTree<E>::~ArithmeticExpressionBinaryTree()
{
}
}
}
}
}

#endif // ARITHMETIC_EXPRESSION_BINARY_TREE_H
