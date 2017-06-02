
/**
 * This header file defines the ArithmeticExpressionParser class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef ARITHMETIC_EXPRESSION_PARSER_H
#define ARITHMETIC_EXPRESSION_PARSER_H

#include "utilities/trees/expression_binary_tree/expression_parser.h"
#include "utilities/lists/disjoint_set/string_disjoint_set.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

template <typename E>
class ArithmeticExpressionParser : public ExpressionParser<double, E>
{
public:
  ArithmeticExpressionParser();
  ArithmeticExpressionParser(const ArithmeticExpressionParser<E>& parser);
  virtual ~ArithmeticExpressionParser();
  virtual Node<double, E>* parse(std::string expression) const;
};

template <typename E>
ArithmeticExpressionParser<E>::ArithmeticExpressionParser()
{
}

template <typename E>
ArithmeticExpressionParser<E>::ArithmeticExpressionParser(
    const ArithmeticExpressionParser<E>& parser)
    : ExpressionParser<double, E>::ExpressionParser(parser)
{
}

template <typename E>
ArithmeticExpressionParser<E>::~ArithmeticExpressionParser()
{
}

#include <iostream>

template <typename E>
Node<double, E>*
ArithmeticExpressionParser<E>::parse(std::string expression) const
{
  lists::disjoint_set::StringDisjointSet set("", "/+-*", "(", ")", "", expression);
  std::cout << "\n\n" << set.toString() << "\n\n";

  return NULL;
}
}
}
}
}

#endif // ARITHMETIC_EXPRESSION_PARSER_H
