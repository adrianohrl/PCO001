/**
 * This header file defines the ExpressionBinaryTree LogicalOperator
 *BetweenOperands abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_BETWEEN_OPERANDS_H
#define EBT_LOGICAL_OPERATOR_BETWEEN_OPERANDS_H

#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class BetweenOperands : public LogicalOperator<E>
{
public:
  virtual ~BetweenOperands();
  virtual std::string getSymbol() const = 0;
  virtual std::string str() const;

protected:
  BetweenOperands(Node<double, E>* left, Node<double, E>* right);
  BetweenOperands(const BetweenOperands<E>& operatorr);
  Node<double, E>* getDoubleLeft() const;
  Node<double, E>* getDoubleRight() const;

private:
  Node<double, E>* left__;
  Node<double, E>* right__;
};

template <typename E>
BetweenOperands<E>::BetweenOperands(Node<double, E>* left,
                                    Node<double, E>* right)
    : LogicalOperator<E>::LogicalOperator(NULL, NULL), left__(left), right__(right)
{
}

template <typename E>
BetweenOperands<E>::BetweenOperands(const BetweenOperands<E>& operatorr)
    : LogicalOperator<E>::LogicalOperator(operatorr), left__(operatorr.left__),
      right__(operatorr.right__)
{
}

template <typename E> BetweenOperands<E>::~BetweenOperands()
{
  if (left__)
  {
    delete left__;
    left__ = NULL;
  }
  if (right__)
  {
    delete right__;
    right__ = NULL;
  }
}

template <typename E> std::string BetweenOperands<E>::str() const
{
  std::stringstream ss;
  if (Operator<bool, E>::isUnary())
  {
    ss << getSymbol();
  }
  ss << (left__ ? left__->str() : "");
  if (!Operator<bool, E>::isUnary())
  {
    ss << " " + getSymbol() + " ";
    ss << (right__ ? right__->str() : "");
  }
  return "(" + ss.str() + ")";
}

template <typename E> Node<double, E>* BetweenOperands<E>::getDoubleLeft() const
{
  return left__;
}

template <typename E>
Node<double, E>* BetweenOperands<E>::getDoubleRight() const
{
  return right__;
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_BETWEEN_OPERANDS_H
