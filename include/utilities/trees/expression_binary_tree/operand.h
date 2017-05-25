/**
 * This header file defines the ExpressionBinaryTree Operand abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_OPERAND_H
#define EBT_OPERAND_H

#include <sstream>
#include "utilities/trees/expression_binary_tree/node.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename T, typename E> class Operand : public Node<T, E>
{
public:
  Operand(const Operand<T, E>& operand);
  virtual ~Operand();
  const E& getContent() const;
  virtual std::string str() const;

protected:
  Operand(const E& operand);

private:
  const E content_;
};

template <typename T, typename E>
Operand<T, E>::Operand(const E& content)
    : content_(content)
{
}

template <typename T, typename E>
Operand<T, E>::Operand(const Operand<T, E>& operand)
    : content_(operand.content_)
{
}

template <typename T, typename E> Operand<T, E>::~Operand() {}

template <typename T, typename E> const E& Operand<T, E>::getContent() const
{
  return content_;
}

template <typename T, typename E> std::string Operand<T, E>::str() const
{
  std::stringstream ss;
  ss << content_;
  return ss.str();
}
}
}
}

#endif // EBT_OPERAND_H
