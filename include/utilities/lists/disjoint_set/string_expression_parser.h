/**
 * This header file defines the StringExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DISJOINT_SET_STRING_EXPRESSION_PARSER_H
#define DISJOINT_SET_STRING_EXPRESSION_PARSER_H

#include "utilities/lists/disjoint_set/string_disjoint_set.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

class StringExpressionParser : public ExpressionParser<std::string>
{
public:
  StringExpressionParser(std::string separators, std::string opening_bounds,
                         std::string closing_bounds, std::string spacers);
  StringExpressionParser(std::string valid_characters, std::string separators,
                         std::string opening_bounds, std::string closing_bounds,
                         std::string spacers);
  StringExpressionParser(
      std::list<std::string> separators = std::list<std::string>(),
      std::list<std::string> opening_bounds = std::list<std::string>(),
      std::list<std::string> closing_bounds = std::list<std::string>(),
      std::list<std::string> spacers = std::list<std::string>());
  StringExpressionParser(
      std::string valid_characters,
      std::list<std::string> separators = std::list<std::string>(),
      std::list<std::string> opening_bounds = std::list<std::string>(),
      std::list<std::string> closing_bounds = std::list<std::string>(),
      std::list<std::string> spacers = std::list<std::string>());
  StringExpressionParser(const StringExpressionParser& parser);
  virtual ~StringExpressionParser();
  virtual Node<std::string>* parse(std::string expression) const;

  static const std::string VALID_CHARACTERS;
};
}
}
}

#endif // DISJOINT_SET_STRING_EXPRESSION_PARSER_H
