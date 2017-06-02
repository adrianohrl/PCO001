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
  virtual void insert(Node<T, E>* node);
  T process() const;
  bool isEmpty() const;
  Node<T, E>* getRoot() const;
  Node<T, E>* getNode() const;
  void clear();
  virtual std::string str() const;
  const char* c_str() const;

protected:
  ExpressionBinaryTree();
  ExpressionBinaryTree(ExpressionParser<T, E>* parser, std::string expression);
  void setRoot(Node<T, E>* node);
  void setNode(Node<T, E>* node);

private:
  Node<T, E>* root_;
  Node<T, E>* node_;
};

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree()
    : root_(NULL), node_(NULL)
{
}

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree(ExpressionParser<T, E>* parser,
                                                 std::string expression)
    : root_(NULL), node_(NULL)
{
  if (expression.empty())
  {
    throw Exception("Empty expression!!!");
  }
  if (parser->evaluate(expression))
  {
    root_ = parser->parse(expression);
  }
  delete parser;
}

template <typename T, typename E>
ExpressionBinaryTree<T, E>::ExpressionBinaryTree(
    const ExpressionBinaryTree<T, E>& ebt)
    : root_(NULL), node_(NULL)
{
  if (ebt.root_)
  {
    root_ = ebt.root_->clone();
    node_ = root_;
  }
}

template <typename T, typename E>
ExpressionBinaryTree<T, E>::~ExpressionBinaryTree()
{
  node_ = NULL;
  if (root_)
  {
    delete root_;
    root_ = NULL;
  }
}

template <typename T, typename E>
void ExpressionBinaryTree<T, E>::insert(Node<T, E>* node)
{
  root_ = root_ ? node_->insert(node) : node;
  node_ = node;
}

template <typename T, typename E> T ExpressionBinaryTree<T, E>::process() const
{
  if (!root_)
  {
    throw utilities::Exception("The expression binary tree is empty!!!");
  }
  return root_->process();
}

template <typename T, typename E>
bool ExpressionBinaryTree<T, E>::isEmpty() const
{
  return !root_;
}

template <typename T, typename E>
Node<T, E>* ExpressionBinaryTree<T, E>::getRoot() const
{
  return root_;
}

template <typename T, typename E>
Node<T, E>* ExpressionBinaryTree<T, E>::getNode() const
{
  return node_;
}

template <typename T, typename E>
void ExpressionBinaryTree<T, E>::setRoot(Node<T, E>* node)
{
  root_ = node;
}

template <typename T, typename E>
void ExpressionBinaryTree<T, E>::setNode(Node<T, E>* node)
{
  node_ = node;
}

template <typename T, typename E>
void ExpressionBinaryTree<T, E>::ExpressionBinaryTree::clear()
{
  root_ = NULL;
  node_ = NULL;
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
