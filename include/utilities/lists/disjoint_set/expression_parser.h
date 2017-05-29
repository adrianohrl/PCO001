/**
 * This header file defines the ExpressionParser abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DISJOINT_SET_EXPRESSION_PARSER_H
#define DISJOINT_SET_EXPRESSION_PARSER_H

#include <iostream>
#include <algorithm>
#include <list>
#include "utilities/lists/disjoint_set/disjoint_set.h"
#include "utilities/stacks/stack/stack.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

template <typename T> class ExpressionParser
{
public:
  ExpressionParser(std::string valid_characters, std::string separators,
                   std::string opening_bounds, std::string closing_bounds,
                   std::string spacers);
  ExpressionParser(std::string valid_characters,
                   std::list<std::string> separators,
                   std::list<std::string> opening_bounds,
                   std::list<std::string> closing_bounds,
                   std::list<std::string> spacers);
  ExpressionParser(const ExpressionParser<T>& parser);
  virtual ~ExpressionParser();
  virtual bool evaluate(std::string expression) const;
  virtual Node<T>* parse(std::string expression) const = 0;

protected:
  std::string getNext(std::string expression) const;
  bool isValid(char c) const;
  bool isValid(std::string str) const;
  bool isOpeningBound(char c) const;
  bool isOpeningBound(std::string str) const;
  bool isClosingBound(char c) const;
  bool isClosingBound(std::string str) const;
  bool isBound(char c) const;
  bool isBound(std::string str) const;
  bool isSeparator(char c) const;
  bool isSeparator(std::string str) const;
  bool isSpacer(char c) const;
  bool isSpacer(std::string str) const;
  bool isSpecialCharacter(char c) const;
  bool isSpecialCharacter(std::string str) const;

private:
  std::string valid_characters_;
  std::list<std::string> separators_;
  std::list<std::string> opening_bounds_;
  std::list<std::string> closing_bounds_;
  std::list<std::string> spacers_;
};

template <typename T>
ExpressionParser<T>::ExpressionParser(std::string valid_characters,
                                      std::string separators,
                                      std::string opening_bounds,
                                      std::string closing_bounds,
                                      std::string spacers)
    : valid_characters_(valid_characters)
{
  if (valid_characters_.empty())
  {
    char c(32);
    for (int counter(0); counter < 256 - 32; counter++, c++)
    {
      valid_characters_.append(&c);
    }
  }
  std::string::const_iterator it;
  if (separators_.empty())
  {
    separators_.push_back(",");
  }
  else
  {
    for (it = separators.begin(); it != separators.end(); ++it)
    {
      separators_.push_back("" + *it);
    }
  }
  valid_characters_.append(separators.c_str());
  if (opening_bounds.empty())
  {
    opening_bounds_.push_back("(");
  }
  else
  {
    for (it = opening_bounds.begin(); it != opening_bounds.end(); ++it)
    {
      opening_bounds_.push_back("" + *it);
    }
  }
  valid_characters_.append(opening_bounds.c_str());
  if (closing_bounds_.empty())
  {
    closing_bounds_.push_back(")");
  }
  else
  {
    for (it = closing_bounds.begin(); it != closing_bounds.end(); ++it)
    {
      closing_bounds_.push_back("" + *it);
    }
  }
  valid_characters_.append(closing_bounds.c_str());
  if (spacers_.empty())
  {
    spacers_.push_back(" ");
  }
  else
  {
    for (it = spacers.begin(); it != spacers.end(); ++it)
    {
      spacers_.push_back("" + *it);
    }
  }
  valid_characters_.append(spacers.c_str());
}

template <typename T>
ExpressionParser<T>::ExpressionParser(std::string valid_characters,
                                      std::list<std::string> separators,
                                      std::list<std::string> opening_bounds,
                                      std::list<std::string> closing_bounds,
                                      std::list<std::string> spacers)
    : valid_characters_(valid_characters), separators_(separators),
      opening_bounds_(opening_bounds), closing_bounds_(closing_bounds),
      spacers_(spacers)
{
  if (valid_characters_.empty())
  {
    char c(32);
    for (int counter(0); counter < 256 - 32; counter++, c++)
    {
      valid_characters_ += c;
    }
  }
  std::list<std::string>::const_iterator it;
  if (separators_.empty())
  {
    separators_.push_back(",");
  }
  for (it = separators_.begin(); it != separators_.end(); it++)
  {
    if (valid_characters_.find(*it) == std::string::npos)
    {
      valid_characters_ += *it;
    }
  }
  if (opening_bounds.empty())
  {
    opening_bounds_.push_back("(");
  }
  for (it = opening_bounds_.begin(); it != opening_bounds_.end(); it++)
  {
    if (valid_characters_.find(*it) == std::string::npos)
    {
      valid_characters_ += *it;
    }
  }
  if (closing_bounds_.empty())
  {
    closing_bounds_.push_back(")");
  }
  for (it = closing_bounds_.begin(); it != closing_bounds_.end(); it++)
  {
    if (valid_characters_.find(*it) == std::string::npos)
    {
      valid_characters_ += *it;
    }
  }
  if (spacers_.empty())
  {
    spacers_.push_back(" ");
  }
  for (it = spacers_.begin(); it != spacers_.end(); it++)
  {
    if (valid_characters_.find(*it) == std::string::npos)
    {
      valid_characters_ += *it;
    }
  }
}

template <typename T>
ExpressionParser<T>::ExpressionParser(const ExpressionParser<T>& parser)
    : valid_characters_(parser.valid_characters_),
      separators_(parser.separators_), opening_bounds_(parser.opening_bounds_),
      closing_bounds_(parser.closing_bounds_), spacers_(parser.spacers_)
{
}

template <typename T> ExpressionParser<T>::~ExpressionParser() {}

template <typename T>
bool ExpressionParser<T>::evaluate(std::string expression) const
{
  if (expression.empty())
  {
    return false;
  }
  std::string::const_iterator it(expression.begin());
  if (!ExpressionParser<T>::isValid(*it))
  {
    return false;
  }
  if (expression.length() == 1 && !ExpressionParser<T>::isSpecialCharacter(*it))
  {
    return true;
  }
  stacks::stack::Stack<char> evaluator;
  evaluator.push(*it);
  while (++it != expression.end())
  {
    if (ExpressionParser<T>::isSpacer(*it))
    {
      continue;
    }
    if (!ExpressionParser<T>::isValid(*it))
    {
      return false;
    }
    if (ExpressionParser<T>::isClosingBound(*it))
    {
      do
      {
        if (evaluator.isEmpty())
        {
          return false;
        }
      } while (!ExpressionParser<T>::isOpeningBound(evaluator.pop()));
    }
    else if (ExpressionParser<T>::isClosingBound(evaluator.top()) &&
             !ExpressionParser<T>::isSeparator(*it))
    {
      return false;
    }
    evaluator.push(*it);
  }
  if (ExpressionParser<T>::isClosingBound(evaluator.top()))
  {
    evaluator.pop();
  }
  return evaluator.isEmpty();
}

template <typename T>
std::string ExpressionParser<T>::getNext(std::string expression) const
{
  int counter(0);
  std::string output("");
  for (std::string::const_iterator it(expression.begin());
       it != expression.end(); ++it)
  {
    if (ExpressionParser<T>::isSeparator(*it) && counter == 0)
    {
      return output;
    }
    output += *it;
    if (ExpressionParser<T>::isOpeningBound(*it))
    {
      counter++;
    }
    else if (ExpressionParser<T>::isClosingBound(*it))
    {
      if (counter == 0)
      {
        return "";
      }
      counter--;
    }
  }
  return output;
}

template <typename T> bool ExpressionParser<T>::isValid(char c) const
{
    return ExpressionParser<T>::isValid(std::string() + c);
}

template <typename T> bool ExpressionParser<T>::isValid(std::string str) const
{
  return valid_characters_.find(str) != std::string::npos;
}

template <typename T> bool ExpressionParser<T>::isOpeningBound(char c) const
{
  return ExpressionParser<T>::isOpeningBound(std::string() + c);
}

template <typename T>
bool ExpressionParser<T>::isOpeningBound(std::string str) const
{
  return std::find(opening_bounds_.begin(), opening_bounds_.end(), str) !=
         opening_bounds_.end();
}

template <typename T> bool ExpressionParser<T>::isClosingBound(char c) const
{
  return ExpressionParser<T>::isClosingBound(std::string() + c);
}

template <typename T>
bool ExpressionParser<T>::isClosingBound(std::string str) const
{
  return std::find(closing_bounds_.begin(), closing_bounds_.end(), str) !=
         closing_bounds_.end();
}

template <typename T> bool ExpressionParser<T>::isBound(char c) const
{
  return ExpressionParser<T>::isBound(std::string() + c);
}

template <typename T> bool ExpressionParser<T>::isBound(std::string str) const
{
  return ExpressionParser<T>::isOpeningBound(str) ||
         ExpressionParser<T>::isClosingBound(str);
}

template <typename T> bool ExpressionParser<T>::isSeparator(char c) const
{
  return ExpressionParser<T>::isSeparator(std::string() + c);
}

template <typename T>
bool ExpressionParser<T>::isSeparator(std::string str) const
{
  return std::find(separators_.begin(), separators_.end(), str) !=
         separators_.end();
}

template <typename T> bool ExpressionParser<T>::isSpacer(char c) const
{
  return ExpressionParser<T>::isSpacer(std::string() + c);
}

template <typename T> bool ExpressionParser<T>::isSpacer(std::string str) const
{
  return std::find(spacers_.begin(), spacers_.end(), str) != spacers_.end();
}

template <typename T> bool ExpressionParser<T>::isSpecialCharacter(char c) const
{
  return ExpressionParser<T>::isSpecialCharacter(std::string() + c);
}

template <typename T>
bool ExpressionParser<T>::isSpecialCharacter(std::string str) const
{
  return ExpressionParser<T>::isOpeningBound(str) ||
         ExpressionParser<T>::isSeparator(str) ||
         ExpressionParser<T>::isClosingBound(str) ||
         ExpressionParser<T>::isSpacer(str);
}
}
}
}

#endif // DISJOINT_SET_EXPRESSION_PARSER_H
