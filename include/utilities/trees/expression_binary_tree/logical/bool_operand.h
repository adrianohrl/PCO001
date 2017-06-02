/**
 * This header file defines the ExpressionBinaryTree Unary Logical
 *BoolOperand class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_LOGICAL_BOOL_OPERAND_H
#define EBT_LOGICAL_BOOL_OPERAND_H

#include "utilities/trees/expression_binary_tree/operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

class BoolOperand : public Operand<bool, double>
{
public:
  BoolOperand(bool content);
  BoolOperand(const BoolOperand& operand);
  virtual ~BoolOperand();
  virtual bool process() const;
  virtual BoolOperand* clone() const;
  virtual std::string str() const;
};
}
}
}
}

#endif // EBT_LOGICAL_BOOL_OPERAND_H
