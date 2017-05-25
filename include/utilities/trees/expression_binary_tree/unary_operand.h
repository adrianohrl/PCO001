/**
 * This header file defines the ExpressionBinaryTree UnaryOperand abstract
 *class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_UNARY_OPERAND_H
#define EBT_UNARY_OPERAND_H

#include "utilities/trees/expression_binary_tree/operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename E> class UnaryOperand : public Operand<E, E>
{
public:
  UnaryOperand(const UnaryOperand<E>& operand);
  virtual ~UnaryOperand();
  virtual E process() const;

protected:
  UnaryOperand(const E& operand);
};

template <typename E>
UnaryOperand<E>::UnaryOperand(const E& content)
    : Operand<E, E>::Operand(content)
{
}

template <typename E>
UnaryOperand<E>::UnaryOperand(const UnaryOperand<E>& operand)
    : Operand<E, E>::Operand(operand)
{
}

template <typename E> UnaryOperand<E>::~UnaryOperand() {}

template <typename E> E UnaryOperand<E>::process() const
{
  return Operand<E, E>::getContent();
}
}
}
}

#endif // EBT_UNARY_OPERAND_H
