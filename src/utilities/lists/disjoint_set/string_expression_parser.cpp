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
#include "utilities/lists/disjoint_set/string_expression_parser.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

const std::string StringExpressionParser::VALID_CHARACTERS = "";

StringExpressionParser::StringExpressionParser(std::string separators,
                                               std::string opening_bounds,
                                               std::string closing_bounds)
    : ExpressionParser<std::string>::ExpressionParser(
          StringExpressionParser::VALID_CHARACTERS, separators, opening_bounds,
          closing_bounds)
{
}

StringExpressionParser::StringExpressionParser(std::string valid_characters,
                                               std::string separators,
                                               std::string opening_bounds,
                                               std::string closing_bounds)
    : ExpressionParser<std::string>::ExpressionParser(
          valid_characters, separators, opening_bounds, closing_bounds)
{
}

StringExpressionParser::StringExpressionParser(
    std::list<std::string> separators, std::list<std::string> opening_bounds,
    std::list<std::string> closing_bounds)
    : ExpressionParser<std::string>::ExpressionParser(
          StringExpressionParser::VALID_CHARACTERS, separators, opening_bounds,
          closing_bounds)
{
}

StringExpressionParser::StringExpressionParser(
    std::string valid_characters, std::list<std::string> separators,
    std::list<std::string> opening_bounds,
    std::list<std::string> closing_bounds)
    : ExpressionParser<std::string>::ExpressionParser(
          valid_characters, separators, opening_bounds, closing_bounds)
{
}

StringExpressionParser::StringExpressionParser(
    const StringExpressionParser& set)
    : ExpressionParser<std::string>::ExpressionParser(set)
{
}

StringExpressionParser::~StringExpressionParser() {}

Node<std::string>* StringExpressionParser::parse(std::string expression) const
{
  if (!ExpressionParser<std::string>::evaluate(expression))
  {
    throw Exception("Invalid string expression: '" + expression + "' !!!");
  }
  std::string next(ExpressionParser<std::string>::getNext(expression));
  expression = expression.substr(next.length());
  if (!expression.empty() &&
      ExpressionParser<std::string>::isSeparator(expression[0]))
  {
    expression = expression.substr(1);
  }
  Node<std::string>* node;
  if (ExpressionParser<std::string>::isOpeningBound(&next[0]) &&
      ExpressionParser<std::string>::isClosingBound(&next[next.length() - 1]))
  {
    next = next.substr(1, next.length() - 2);
    node = new Node<std::string>();
    node->setSubset(StringExpressionParser::parse(next));
  }
  else
  {
    node = new Node<std::string>(next);
  }
  if (!expression.empty())
  {
    node->setNext(StringExpressionParser::parse(expression));
  }
  return node;
}
}
}
}
