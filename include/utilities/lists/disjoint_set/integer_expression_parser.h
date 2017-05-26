/**
 * This header file defines the IntegerExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DISJOINT_SET_INTEGER_EXPRESSION_PARSER_H
#define DISJOINT_SET_INTEGER_EXPRESSION_PARSER_H

#include "utilities/lists/disjoint_set/integer_disjoint_set.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

class IntegerExpressionParser : public ExpressionParser<int>
{
public:
  IntegerExpressionParser(std::string opening_bounds,
                          std::string closing_bounds, std::string separators);
  IntegerExpressionParser(
      std::list<std::string> separators = std::list<std::string>(),
      std::list<std::string> opening_bounds = std::list<std::string>(),
      std::list<std::string> closing_bounds = std::list<std::string>());
  virtual ~IntegerExpressionParser();
  virtual Node<int>* parse(std::string expression) const;

  static const std::string VALID_CHARACTERS;
};
}
}
}

#endif // DISJOINT_SET_INTEGER_EXPRESSION_PARSER_H
