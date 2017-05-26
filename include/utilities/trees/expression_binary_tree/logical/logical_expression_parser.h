/**
 * This header file defines the LogicalExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef LOGICAL_EXPRESSION_PARSER_H
#define LOGICAL_EXPRESSION_PARSER_H

#include "utilities/trees/expression_binary_tree/expression_parser.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

template <typename E>
class LogicalExpressionParser : public ExpressionParser<bool, E>
{
public:
  LogicalExpressionParser();
  LogicalExpressionParser(const LogicalExpressionParser<E>& parser);
  virtual ~LogicalExpressionParser();
  virtual Node<bool, E>* parse(std::string expression) const;
};

template <typename E>
LogicalExpressionParser<E>::LogicalExpressionParser()
{
}

template <typename E>
LogicalExpressionParser<E>::LogicalExpressionParser(const LogicalExpressionParser<E>& parser)
    : ExpressionParser<bool, E>::ExpressionParser(parser)
{
}

template <typename E> LogicalExpressionParser<E>::~LogicalExpressionParser()
{
}

template <typename E>
Node<bool, E>*
LogicalExpressionParser<E>::parse(std::string expression) const
{
  return NULL;
}
}
}
}
}

#endif // LOGICAL_EXPRESSION_PARSER_H
