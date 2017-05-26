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
                   std::string opening_bounds, std::string closing_bounds);
  ExpressionParser(std::string valid_characters,
                   std::list<std::string> separators,
                   std::list<std::string> opening_bounds,
                   std::list<std::string> closing_bounds);
  virtual ~ExpressionParser();
  virtual bool evaluate(std::string expression) const;
  virtual Node<T>* parse(std::string expression) const = 0;
  bool isValid(char c) const;
  bool isValid(const char* c) const;
  bool isOpeningBound(char c) const;
  bool isOpeningBound(const char* c) const;
  bool isClosingBound(char c) const;
  bool isClosingBound(const char* c) const;
  bool isSeparator(char c) const;
  bool isSeparator(const char* c) const;

protected:
  std::string getNext(std::string expression) const;

private:
  std::string valid_characters_;
  std::list<std::string> separators_;
  std::list<std::string> opening_bounds_;
  std::list<std::string> closing_bounds_;
};

template <typename T>
ExpressionParser<T>::ExpressionParser(std::string valid_characters,
                                      std::string separators,
                                      std::string opening_bounds,
                                      std::string closing_bounds)
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
  if (separators_.empty())
  {
    separators_.push_back(",");
  }
  else
  {
    for (std::string::const_iterator it(separators.begin());
         it != separators.end(); ++it)
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
    for (std::string::const_iterator it(opening_bounds.begin());
         it != opening_bounds.end(); ++it)
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
    for (std::string::const_iterator it(closing_bounds.begin());
         it != closing_bounds.end(); ++it)
    {
      closing_bounds_.push_back("" + *it);
    }
  }
  valid_characters_.append(closing_bounds.c_str());
}

template <typename T>
ExpressionParser<T>::ExpressionParser(std::string valid_characters,
                                      std::list<std::string> separators,
                                      std::list<std::string> opening_bounds,
                                      std::list<std::string> closing_bounds)
    : valid_characters_(valid_characters), separators_(separators),
      opening_bounds_(opening_bounds), closing_bounds_(closing_bounds)
{
  if (valid_characters_.empty())
  {
    char c(32);
    for (int counter(0); counter < 256 - 32; counter++, c++)
    {
      valid_characters_.append(&c);
    }
  }
  if (separators_.empty())
  {
    separators_.push_back(",");
  }
  std::list<std::string>::const_iterator it(separators_.begin());
  while (it != separators_.end())
  {
    valid_characters_ += *it;
    it++;
  }
  if (opening_bounds.empty())
  {
    opening_bounds_.push_back("(");
  }
  it = opening_bounds_.begin();
  while (it != opening_bounds_.end())
  {
    valid_characters_ += *it;
    it++;
  }
  if (closing_bounds_.empty())
  {
    closing_bounds_.push_back(")");
  }
  it = closing_bounds_.begin();
  while (it != closing_bounds_.end())
  {
    valid_characters_ += *it;
    it++;
  }
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
  if (expression.length() == 1 && !ExpressionParser<T>::isSeparator(*it) &&
      ExpressionParser<T>::isValid(*it))
  {
    return true;
  }
  stacks::stack::Stack<char> evaluator;
  evaluator.push(*it);
  while (++it != expression.end())
  {
    if (ExpressionParser<T>::isClosingBound(evaluator.top()) &&
        !ExpressionParser<T>::isSeparator(*it) &&
        !ExpressionParser<T>::isClosingBound(*it))
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
    if (ExpressionParser<T>::isSeparator("" + *it) && counter == 0)
    {
      return output;
    }
    output += *it;
    if (ExpressionParser<T>::isOpeningBound("" + *it))
    {
      counter++;
    }
    else if (ExpressionParser<T>::isClosingBound("" + *it))
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
  return ExpressionParser<T>::isValid(&c);
}

template <typename T> bool ExpressionParser<T>::isValid(const char* c) const
{
  return valid_characters_.find(*c) != std::string::npos;
}

template <typename T> bool ExpressionParser<T>::isOpeningBound(char c) const
{
  return ExpressionParser<T>::isOpeningBound(&c);
}

template <typename T>
bool ExpressionParser<T>::isOpeningBound(const char* c) const
{
  return std::find(opening_bounds_.begin(), opening_bounds_.end(),
                   std::string(c)) != opening_bounds_.end();
}

template <typename T> bool ExpressionParser<T>::isClosingBound(char c) const
{
  return ExpressionParser<T>::isClosingBound(&c);
}

template <typename T>
bool ExpressionParser<T>::isClosingBound(const char* c) const
{
  return std::find(closing_bounds_.begin(), closing_bounds_.end(),
                   std::string(c)) != closing_bounds_.end();
}

template <typename T> bool ExpressionParser<T>::isSeparator(char c) const
{
  return ExpressionParser<T>::isClosingBound(&c);
}

template <typename T> bool ExpressionParser<T>::isSeparator(const char* c) const
{
  return std::find(separators_.begin(), separators_.end(), std::string(c)) !=
         separators_.end();
}
}
}
}

#endif // DISJOINT_SET_EXPRESSION_PARSER_H
