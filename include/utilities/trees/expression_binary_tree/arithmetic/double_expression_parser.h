/**
 * This header file defines the DoubleExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DOUBLE_EXPRESSION_PARSER_H
#define DOUBLE_EXPRESSION_PARSER_H

#include "utilities/trees/expression_binary_tree/arithmetic/arithmetic_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

class DoubleExpressionParser : public ArithmeticExpressionParser<double>
{
public:
  DoubleExpressionParser();
  DoubleExpressionParser(const DoubleExpressionParser& parser);
  virtual ~DoubleExpressionParser();
};
}
}
}
}

#endif // DOUBLE_EXPRESSION_PARSER_H
