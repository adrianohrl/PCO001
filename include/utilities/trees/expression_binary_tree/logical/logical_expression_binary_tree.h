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
#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_expression_binary_tree.h"
#include "utilities/trees/expression_binary_tree/logical/logical_expression_parser.h"
#include "utilities/trees/expression_binary_tree/logical/double_logical_operator.h"

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
  virtual void insert(Node<bool, E>* node);
  virtual void insert(Node<double, E>* node);

protected:
  LogicalExpressionBinaryTree(
      arithmetic::ArithmeticExpressionBinaryTree<E>* tree);
  LogicalExpressionBinaryTree(
      arithmetic::ArithmeticExpressionBinaryTree<E>* tree,
      LogicalExpressionParser<E>* parser, std::string expression);

private:
  arithmetic::ArithmeticExpressionBinaryTree<E>* tree_;
};

template <typename E>
LogicalExpressionBinaryTree<E>::LogicalExpressionBinaryTree(
    arithmetic::ArithmeticExpressionBinaryTree<E>* tree)
    : ExpressionBinaryTree<bool, E>::ExpressionBinaryTree(), tree_(tree)
{
}

template <typename E>
LogicalExpressionBinaryTree<E>::LogicalExpressionBinaryTree(
    arithmetic::ArithmeticExpressionBinaryTree<E>* tree,
    LogicalExpressionParser<E>* parser, std::string expression)
    : ExpressionBinaryTree<bool, E>::ExpressionBinaryTree(parser, expression),
      tree_(tree)
{
}

template <typename E>
LogicalExpressionBinaryTree<E>::LogicalExpressionBinaryTree(
    const LogicalExpressionBinaryTree<E>& ebt)
    : ExpressionBinaryTree<bool, E>::ExpressionBinaryTree(ebt), tree_(ebt.tree_)
{
}

template <typename E>
LogicalExpressionBinaryTree<E>::~LogicalExpressionBinaryTree()
{
  if (tree_)
  {
    delete tree_;
    tree_ = NULL;
  }
}

template <typename E>
void LogicalExpressionBinaryTree<E>::insert(Node<bool, E>* node)
{
  Node<bool, E>* current_node = ExpressionBinaryTree<bool, E>::getNode();
  LogicalOperator<E>* logical_node = NULL;
  DoubleLogicalOperator<E>* double_logical_node = NULL;
  if (current_node && current_node->isOperator())
  {
    logical_node = (LogicalOperator<E>*)current_node;
    if (logical_node->isDoubleLogical())
    {
      if (tree_->isEmpty())
      {
        throw utilities::Exception(
            "There is no arithmetic expression available "
            "for the current DoubleLogicalOperator "
            "node!!!");
      }
      double_logical_node = (DoubleLogicalOperator<E>*)logical_node;
    }
  }
  else if (node->isOperator())
  {
    logical_node = (LogicalOperator<E>*)node;
    if (logical_node->isDoubleLogical())
    {
      if (tree_->isEmpty() && !logical_node->isUnary())
      {
        throw utilities::Exception("There is no arithmetic expression "
                                   "available for the given "
                                   "DoubleLogicalOperator node!!!");
      }
      double_logical_node = (DoubleLogicalOperator<E>*)logical_node;
    }
  }
  if (double_logical_node)
  {
    double_logical_node->insert(tree_->getRoot());
    tree_->clear();
  }
  ExpressionBinaryTree<bool, E>::insert(node);
}

template <typename E>
void LogicalExpressionBinaryTree<E>::insert(Node<double, E>* node)
{
  tree_->insert(node);
}
}
}
}
}

#endif // LOGICAL_EXPRESSION_BINARY_TREE_H
