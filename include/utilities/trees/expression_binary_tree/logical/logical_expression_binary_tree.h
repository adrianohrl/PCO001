/**
 * This header file defines the LogicalExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef LOGICAL_EXPRESSION_BINARY_TREE_H
#define LOGICAL_EXPRESSION_BINARY_TREE_H

#include "utilities/trees/expression_binary_tree/expression_binary_tree.h"
#include "utilities/trees/expression_binary_tree/logical/logical_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E>
class LogicalExpressionBinaryTree : public ExpressionBinaryTree<bool, E>
{
public:
  LogicalExpressionBinaryTree(const LogicalExpressionBinaryTree<E>& ebt);
  virtual ~LogicalExpressionBinaryTree();
  using ExpressionBinaryTree<bool, E>::insert;
  virtual Node<bool, E>* insert(Node<double, E>* node);
  virtual Node<bool, E>*
  insert(const ExpressionBinaryTree<double, E>& arithmetic_expression_tree);

protected:
  LogicalExpressionBinaryTree();
  LogicalExpressionBinaryTree(LogicalExpressionParser<E>* parser,
                              std::string expression);
};

template <typename E>
LogicalExpressionBinaryTree<E>::LogicalExpressionBinaryTree()
    : ExpressionBinaryTree<bool, E>::ExpressionBinaryTree()
{
}

template <typename E>
LogicalExpressionBinaryTree<E>::LogicalExpressionBinaryTree(
    LogicalExpressionParser<E>* parser, std::string expression)
    : ExpressionBinaryTree<bool, E>::ExpressionBinaryTree(parser, expression)
{
}

template <typename E>
LogicalExpressionBinaryTree<E>::LogicalExpressionBinaryTree(
    const LogicalExpressionBinaryTree<E>& ebt)
    : ExpressionBinaryTree<bool, E>::ExpressionBinaryTree(ebt)
{
}

template <typename E>
LogicalExpressionBinaryTree<E>::~LogicalExpressionBinaryTree()
{
}

template <typename E>
Node<bool, E>* LogicalExpressionBinaryTree<E>::insert(Node<double, E>* node)
{
  throw utilities::Exception("Not implemented yet!!!");
}

template <typename E>
Node<bool, E>* LogicalExpressionBinaryTree<E>::insert(
    const ExpressionBinaryTree<double, E>& arithmetic_expression_tree)
{
  throw utilities::Exception("Not implemented yet!!!");
}
}
}
}
}

#endif // LOGICAL_EXPRESSION_BINARY_TREE_H
