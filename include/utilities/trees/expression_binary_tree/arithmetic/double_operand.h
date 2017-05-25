/**
 * This header file defines the ExpressionBinaryTree Unary Arithmetic
 *DoubleOperand class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_ARITHMETIC_DOUBLE_OPERAND_H
#define EBT_ARITHMETIC_DOUBLE_OPERAND_H

#include "utilities/trees/expression_binary_tree/unary_operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace arithmetic
{

class DoubleOperand : public UnaryOperand<double>
{
public:
  DoubleOperand(double content);
  DoubleOperand(const DoubleOperand& operand);
  virtual ~DoubleOperand();
  virtual DoubleOperand* clone() const;
};
}
}
}
}

#endif // EBT_ARITHMETIC_DOUBLE_OPERAND_H
