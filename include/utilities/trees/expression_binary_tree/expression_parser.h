/**
 * This header file defines the ExpressionParser abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include "utilities/lists/disjoint_set/disjoint_set.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T> class ExpressionParser
{
public:
  ExpressionParser();
  ExpressionParser(std::string separators);
  virtual ~ExpressionParser();
  virtual lists::disjoint_set::DisjointSet<T>*
  parse(std::string expression) const = 0;
  virtual bool evaluate(std::string expression) const;
  virtual bool isInRange(char c) const;
  virtual bool isSeparator(char c) const;

private:
  std::string separators_;
};

template <typename T>
ExpressionParser<T>::ExpressionParser()
    : separators_("(,)")
{
}

template <typename T>
ExpressionParser<T>::ExpressionParser(std::string separators)
    : separators_(separators)
{
}

template <typename T> ExpressionParser<T>::~ExpressionParser() {}

template <typename T>
bool ExpressionParser<T>::evaluate(std::string expression) const
{
  if (!lists::disjoint_set::DisjointSet<T>::evaluate(expression))
  {
    return false;
  }
  for (std::string::iterator it(expression.begin() + 1); it != expression.end();
       ++it)
  {
    if (!ExpressionParser<T>::isInRange(*it) &&
        !ExpressionParser<T>::isSeparator(*it))
    {
      return false;
    }
  }
  return true;
}

template <typename T> bool ExpressionParser<T>::isInRange(char c) const
{
  return true;
}

template <typename T> bool ExpressionParser<T>::isSeparator(char c) const
{
  return lists::disjoint_set::DisjointSet<T>::isSeparator(c) ||
         separators_.find(c) != -1;
}
}
}
}

#endif // EXPRESSION_BINARY_TREE_H
