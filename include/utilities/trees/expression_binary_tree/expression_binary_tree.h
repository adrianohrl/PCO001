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

#include <iostream>
#include "utilities/trees/expression_binary_tree/node.h"
//#include "utilities/trees/expression_binary_tree/string_expression_parser.h"

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
  virtual std::string str() const;
  const char* c_str() const;

protected:
  Node<T, E>* getRoot() const;
  bool hasRoot() const;

private:
  void parse();

  std::string expression_;
  Node<T, E>* root_;
};

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree(std::string expression)
    : expression_(expression), root_(NULL)
{
  ExpressionBinaryTree<T, E>::parse();
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

template <typename T, typename E> void ExpressionBinaryTree<T, E>::parse()
{
  /*StringExpressionParser parser;
  lists::disjoint_set::StringDisjointSet *set = parser.parse(expression_);
  std::cout << "\n" << set->toString() << "\n\n" ;
  if (set)
  {
    delete set;
    set = NULL;
  }*/
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
