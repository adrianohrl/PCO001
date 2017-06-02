/**
 * This header file implements the BoolExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/trees/expression_binary_tree/logical/bool_expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

BoolExpressionParser::BoolExpressionParser() {}

BoolExpressionParser::BoolExpressionParser(const BoolExpressionParser& parser)
    : LogicalExpressionParser<double>::LogicalExpressionParser(parser)
{
}

BoolExpressionParser::~BoolExpressionParser() {}
}
}
}
}
