/**
 * This header file defines the ExpressionParser abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include "utilities/trees/expression_binary_tree/node.h"
#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h"
#include "utilities/trees/expression_binary_tree/logical/logical_operator.h"
#include "utilities/lists/disjoint_set/string_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class ExpressionParser
{
public:
  ExpressionParser(const ExpressionParser<T, E>& parser);
  virtual ~ExpressionParser();
  virtual bool evaluate(std::string expression) const;
  virtual Node<T, E>* parse(std::string expression) const = 0;

protected:
  ExpressionParser();
  bool isArithmeticExpression(std::string symbol);
  bool isLogicalExpression(std::string symbol);

private:
  static std::list<std::string> getOperators();
  static std::list<std::string> SEPARATORS;
};

template <typename T, typename E>
std::list<std::string>
    ExpressionParser<T, E>::SEPARATORS(ExpressionParser<T, E>::getOperators());

template <typename T, typename E> ExpressionParser<T, E>::ExpressionParser() {}

template <typename T, typename E>
ExpressionParser<T, E>::ExpressionParser(const ExpressionParser<T, E>& parser)
{
}

template <typename T, typename E> ExpressionParser<T, E>::~ExpressionParser() {}

template <typename T, typename E>
bool ExpressionParser<T, E>::evaluate(std::string expression) const
{
  lists::disjoint_set::StringExpressionParser parser(
      ExpressionParser<T, E>::SEPARATORS);
  return parser.evaluate(expression);
}

template <typename T, typename E>
bool ExpressionParser<T, E>::isArithmeticExpression(std::string symbol)
{
  return std::find(arithmetic::ArithmeticOperator<E>::OPERATORS.begin(),
                   arithmetic::ArithmeticOperator<E>::OPERATORS.end(), symbol);
}

template <typename T, typename E>
bool ExpressionParser<T, E>::isLogicalExpression(std::string symbol)
{
  return std::find(logical::LogicalOperator<E>::OPERATORS.begin(),
                   logical::LogicalOperator<E>::OPERATORS.end(), symbol);
}

template <typename T, typename E>
std::list<std::string> ExpressionParser<T, E>::getOperators()
{
  std::list<std::string> operators;
  operators.push_back("+");
  operators.push_back("-");
  operators.push_back("*");
  operators.push_back("/");
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

#endif // EXPRESSION_BINARY_TREE_H
