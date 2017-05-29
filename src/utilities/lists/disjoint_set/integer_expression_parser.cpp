/**
 * This header file implements the StringExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/exception.h"
#include "utilities/lists/disjoint_set/integer_expression_parser.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

const std::string IntegerExpressionParser::VALID_CHARACTERS = "0123456789";

IntegerExpressionParser::IntegerExpressionParser(std::string separators,
                                                 std::string opening_bounds,
                                                 std::string closing_bounds,
                                                 std::string spacers)
    : ExpressionParser<int>::ExpressionParser(
          IntegerExpressionParser::VALID_CHARACTERS, separators, opening_bounds,
          closing_bounds, spacers)
{
}

IntegerExpressionParser::IntegerExpressionParser(
    std::list<std::string> separators, std::list<std::string> opening_bounds,
    std::list<std::string> closing_bounds, std::list<std::string> spacers)
    : ExpressionParser<int>::ExpressionParser(
          IntegerExpressionParser::VALID_CHARACTERS, separators, opening_bounds,
          closing_bounds, spacers)
{
}

IntegerExpressionParser::IntegerExpressionParser(
    const IntegerExpressionParser& parser)
    : ExpressionParser<int>::ExpressionParser(parser)
{
}

IntegerExpressionParser::~IntegerExpressionParser() {}

Node<int>* IntegerExpressionParser::parse(std::string expression) const
{
  if (!ExpressionParser<int>::evaluate(expression))
  {
    throw Exception("Invalid string expression: " + expression + " !!!");
  }
  std::string next(ExpressionParser<int>::getNext(expression));
  expression = expression.substr(next.length());
  if (!expression.empty() && ExpressionParser<int>::isSeparator(expression[0]))
  {
    expression = expression.substr(1);
  }
  Node<int>* node;
  if (ExpressionParser<int>::isOpeningBound(&next[0]) &&
      ExpressionParser<int>::isClosingBound(&next[next.length() - 1]))
  {
    next = next.substr(1, next.length() - 2);
    node = new Node<int>();
    node->setSubset(IntegerExpressionParser::parse(next));
  }
  else
  {
    node = new Node<int>(atoi(next.c_str()));
  }
  if (!expression.empty())
  {
    node->setNext(IntegerExpressionParser::parse(expression));
  }
  return node;
}
}
}
}
