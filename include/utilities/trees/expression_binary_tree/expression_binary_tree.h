/**
 * This header file defines the ExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EXPRESSION_BINARY_TREE_H
#define EXPRESSION_BINARY_TREE_H

#include "utilities/trees/expression_binary_tree/node.h"
#include "utilities/trees/expression_binary_tree/expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class ExpressionBinaryTree
{
public:
  ExpressionBinaryTree(const ExpressionBinaryTree<T, E>& ebt);
  virtual ~ExpressionBinaryTree();
  T process() const;
  virtual std::string str() const;
  const char* c_str() const;

protected:
  ExpressionBinaryTree(ExpressionParser<T, E>* parser, std::string expression);
  Node<T, E>* getRoot() const;
  bool hasRoot() const;

private:
  Node<T, E>* root_;
};

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree(ExpressionParser<T, E>* parser,
                                                 std::string expression)
    : root_(NULL)
{
  if (expression.empty())
  {
    throw Exception("Empty expression!!!");
  }
  root_ = parser->parse(expression);
  delete parser;
}

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree(
    const ExpressionBinaryTree<T, E>& ebt)
    : root_(NULL)
{
  if (ebt.root_)
  {
    root_ = ebt.root_->clone();
  }
}

template <typename T, typename E>
ExpressionBinaryTree<T, E>::~ExpressionBinaryTree()
{
  if (root_)
  {
    delete root_;
    root_ = NULL;
  }
}

template <typename T, typename E> T ExpressionBinaryTree<T, E>::process() const
{
  return root_->process();
}

template <typename T, typename E>
Node<T, E>* ExpressionBinaryTree<T, E>::getRoot() const
{
  return root_;
}

template <typename T, typename E>
bool ExpressionBinaryTree<T, E>::hasRoot() const
{
  return root_;
}

template <typename T, typename E>
std::string ExpressionBinaryTree<T, E>::str() const
{
  return root_ ? root_->str() : "";
}

template <typename T, typename E>
const char* ExpressionBinaryTree<T, E>::c_str() const
{
  return ExpressionBinaryTree<T, E>::str().c_str();
}
}
}
}

#endif // EXPRESSION_BINARY_TREE_H
