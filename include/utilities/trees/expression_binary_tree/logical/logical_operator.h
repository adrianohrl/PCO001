/**
 * This header file defines the ExpressionBinaryTree LogicalOperator abstract
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_OPERATOR_H
#define EBT_LOGICAL_OPERATOR_H

#include <list>
#include "utilities/trees/expression_binary_tree/operand.h"
#include "utilities/trees/expression_binary_tree/operator.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E> class LogicalOperator : public Operator<bool, E>
{
public:
  LogicalOperator(const LogicalOperator<E>& operatorr);
  virtual ~LogicalOperator();
  bool isBoolLogical() const;
  bool isDoubleLogical() const;

  static std::list<std::string> OPERATORS;

protected:
  LogicalOperator(Node<bool, E>* operatorr, bool bool_logical = false);
  LogicalOperator(Node<bool, E>* left, Node<bool, E>* right,
                  bool bool_logical = false);

private:
  static std::list<std::string> getOperators();

  bool bool_logical_;
};

template <typename E>
std::list<std::string>
    LogicalOperator<E>::OPERATORS(LogicalOperator<E>::getOperators());

template <typename E>
LogicalOperator<E>::LogicalOperator(Node<bool, E>* operatorr, bool bool_logical)
    : Operator<bool, E>::Operator(operatorr, true), bool_logical_(bool_logical)
{
}

template <typename E>
LogicalOperator<E>::LogicalOperator(Node<bool, E>* left, Node<bool, E>* right,
                                    bool bool_logical)
    : Operator<bool, E>::Operator(left, right, true),
      bool_logical_(bool_logical)
{
}

template <typename E>
LogicalOperator<E>::LogicalOperator(const LogicalOperator<E>& operatorr)
    : Operator<bool, E>::Operator(operatorr),
      bool_logical_(operatorr.bool_logical_)
{
}

template <typename E> LogicalOperator<E>::~LogicalOperator() {}

template <typename E> bool LogicalOperator<E>::isBoolLogical() const
{
  return bool_logical_;
}

template <typename E> bool LogicalOperator<E>::isDoubleLogical() const
{
  return !bool_logical_;
}

template <typename E> std::list<std::string> LogicalOperator<E>::getOperators()
{
  std::list<std::string> operators;
  operators.push_back("&&");
  operators.push_back("||");
  operators.push_back("!");
  operators.push_back("<");
  operators.push_back("<=");
  operators.push_back("==");
  operators.push_back("!=");
  operators.push_back(">=");
  operators.push_back(">");
  return operators;
}
}
}
}
}

#endif // EBT_LOGICAL_OPERATOR_H
