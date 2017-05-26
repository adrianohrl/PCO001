/**
 * This header file implements the DoubleExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/trees/expression_binary_tree/arithmetic/double_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

DoubleExpressionParser::DoubleExpressionParser() {}

DoubleExpressionParser::DoubleExpressionParser(
    const DoubleExpressionParser& parser)
    : ArithmeticExpressionParser<double>::ArithmeticExpressionParser(parser)
{
}

DoubleExpressionParser::~DoubleExpressionParser() {}
}
}
}
}
