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
#include "utilities/trees/expression_binary_tree/string_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

utilities::trees::expression_binary_tree::StringExpressionParser::StringExpressionParser(std::string valid_characters, std::string opening_bounds, std::string closing_bounds, std::string separators)
{

}

StringExpressionParser::~StringExpressionParser() {}

lists::disjoint_set::StringDisjointSet*
StringExpressionParser::parse(std::string expression) const
{
  if (!ExpressionParser<std::string>::evaluate(expression))
  {
      throw Exception("Invalid expression!!!");
  }
  return new lists::disjoint_set::StringDisjointSet(expression);
}
}
}
}
