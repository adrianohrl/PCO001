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

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class ExpressionBinaryTree
{
public:
  ExpressionBinaryTree(std::string expression);
  virtual ~ExpressionBinaryTree();
  T process() const;

protected:
  Node<T, E>* getRoot() const;
  bool hasRoot() const;

private:
  std::string expression_;
  Node<T, E>* root_;
};

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree(std::string expression)
    : expression_(expression), root_(NULL)
{
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
}
}
}

#endif // EXPRESSION_BINARY_TREE_H
