/**
 * This header file defines the BoolExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BOOL_EXPRESSION_PARSER_H
#define BOOL_EXPRESSION_PARSER_H

#include "utilities/trees/expression_binary_tree/logical/logical_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

class BoolExpressionParser : public LogicalExpressionParser<bool>
{
public:
  BoolExpressionParser();
  BoolExpressionParser(const BoolExpressionParser& parser);
  virtual ~BoolExpressionParser();
};
}
}
}
}

#endif // BOOL_EXPRESSION_PARSER_H
