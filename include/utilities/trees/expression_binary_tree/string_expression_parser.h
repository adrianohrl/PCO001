/**
 * This header file defines the StringExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef STRING_EXPRESSION_PARSER_H
#define STRING_EXPRESSION_PARSER_H

//#include "utilities/lists/disjoint_set/string_disjoint_set.h"
#include "utilities/trees/expression_binary_tree/expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

class StringExpressionParser : public ExpressionParser<std::string>
{
public:
  StringExpressionParser();
  StringExpressionParser(std::string separators);
  virtual ~StringExpressionParser();
  virtual lists::disjoint_set::StringDisjointSet*
  parse(std::string expression) const;
};
}
}
}

#endif // STRING_EXPRESSION_BINARY_TREE_H
