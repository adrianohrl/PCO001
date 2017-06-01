/**
 * This header file defines the ExpressionBinaryTree Operator abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_OPERATOR_H
#define EBT_OPERATOR_H

#include <sstream>
#include "utilities/trees/expression_binary_tree/node.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class Operator : public Node<T, E>
{
public:
  Operator(const Operator<T, E>& operatorr);
  virtual ~Operator();
  virtual Node<T, E>* insert(Node<T, E>* node);
  virtual void upgrade(Operator<T, E>* node);
  virtual Node<T, E>* getLeft() const;
  virtual Node<T, E>* getRight() const;
  virtual Operator<T, E>* getParent() const;
  virtual bool hasLeft() const;
  virtual bool hasRight() const;
  virtual bool isLeaf() const;
  int getLevel() const;
  bool isUnary() const;
  bool isSameLevel(const Operator& operatorr) const;
  virtual std::string getSymbol() const = 0;
  virtual int getPriority() const = 0;
  bool hasLowerPriority(const Operator& operatorr);
  bool hasHigherPriority(const Operator& operatorr);
  virtual void setLeft(Node<T, E>* node);
  virtual void setRight(Node<T, E>* node);
  void setLevel(int level);
  virtual std::string str() const;

protected:
  Operator(Node<T, E>* operand, int level = 0);
  Operator(Node<T, E>* left, Node<T, E>* right, int level = 0);

private:
  int level_;
  bool unary_;
  Node<T, E>* left_, *right_;
};

template <typename T, typename E>
Operator<T, E>::Operator(Node<T, E>* operand, int level)
    : Node<T, E>::Node(false), level_(level), unary_(true), left_(NULL),
      right_(operand)

{
}

template <typename T, typename E>
Operator<T, E>::Operator(Node<T, E>* left, Node<T, E>* right, int level)
    : Node<T, E>::Node(false), level_(level), unary_(false), left_(left),
      right_(right)
{
}

template <typename T, typename E>
Operator<T, E>::Operator(const Operator<T, E>& operatorr)
    : Node<T, E>::Node(operatorr), level_(operatorr.level_),
      unary_(operatorr.unary_), left_(NULL), right_(NULL)
{
  if (operatorr.left_)
  {
    left_ = operatorr.left_->clone();
    left_->setParent(this);
  }
  if (operatorr.right_)
  {
    right_ = operatorr.right_->clone();
    right_->setParent(this);
  }
}

template <typename T, typename E> Operator<T, E>::~Operator()
{
  if (left_)
  {
    delete left_;
    left_ = NULL;
  }
  if (right_)
  {
    delete right_;
    right_ = NULL;
  }
}

template <typename T, typename E>
Node<T, E>* Operator<T, E>::insert(Node<T, E>* node)
{
  if (!node)
  {
    throw utilities::Exception("Node must not be NULL!!!");
  }
  if (right_)
  {
    throw utilities::Exception("Unable to insert the input node!!!");
  }
  Operator<T, E>::setRight(node);
  if (node->isOperator())
  {
    Operator<T, E>::upgrade((Operator<T, E>*)node);
  }
  Node<T, E>* root = Node<T, E>::getParent();
  while (root && root->hasParent())
  {
    root = root->getParent();
  }
  return root ? root : this;
}

template <typename T, typename E>
void Operator<T, E>::upgrade(Operator<T, E>* node)
{
  if (!Operator<T, E>::isSameLevel(*node) ||
      !Operator<T, E>::hasHigherPriority(*node))
  {
    return;
  }
  Operator<T, E>* parent = Operator<T, E>::getParent();
  Operator<T, E>::setRight(node->left_);
  node->setLeft(this);
  if (parent)
  {
    parent->setRight(node);
    parent->upgrade(node);
  }
  else
  {
    node->setParent(NULL);
  }
}

template <typename T, typename E> Node<T, E>* Operator<T, E>::getLeft() const
{
  return left_;
}

template <typename T, typename E> Node<T, E>* Operator<T, E>::getRight() const
{
  return right_;
}

template <typename T, typename E>
Operator<T, E>* Operator<T, E>::getParent() const
{
  return (Operator<T, E>*)Node<T, E>::getParent();
}

template <typename T, typename E> bool Operator<T, E>::hasLeft() const
{
  return left_;
}

template <typename T, typename E> bool Operator<T, E>::hasRight() const
{
  return right_;
}

template <typename T, typename E> bool Operator<T, E>::isLeaf() const
{
  return false;
}

template <typename T, typename E> bool Operator<T, E>::isUnary() const
{
  return unary_;
}

template <typename T, typename E>
bool Operator<T, E>::isSameLevel(const Operator& operatorr) const
{
  return Operator<T, E>::getLevel() == operatorr.getLevel();
}

template <typename T, typename E>
bool Operator<T, E>::hasLowerPriority(const Operator& operatorr)
{
  return Operator<T, E>::getPriority() > operatorr.getPriority();
}

template <typename T, typename E>
bool Operator<T, E>::hasHigherPriority(const Operator& operatorr)
{
  return getPriority() < operatorr.getPriority();
}

template <typename T, typename E> int Operator<T, E>::getLevel() const
{
  return level_;
}

template <typename T, typename E> void Operator<T, E>::setLeft(Node<T, E>* node)
{
  left_ = node;
  if (node)
  {
    node->setParent(this);
  }
}

template <typename T, typename E>
void Operator<T, E>::setRight(Node<T, E>* node)
{
  right_ = node;
  if (node)
  {
    node->setParent(this);
  }
}

template <typename T, typename E> void Operator<T, E>::setLevel(int level)
{
  level_ = level;
}

template <typename T, typename E> std::string Operator<T, E>::str() const
{
  std::stringstream ss;
  ss << (left_ ? left_->str() : "");
  ss << (!unary_ ? " " : "") << getSymbol() << (!unary_ ? " " : "");
  ss << (right_ ? right_->str() : "");
  return "(" + ss.str() + ")";
}
}
}
}

#endif // EBT_OPERATOR_H
