/**
 * This header file implements the ExpressionBinaryTree Unary Logical
 *BoolOperand class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/trees/expression_binary_tree/logical/bool_operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{
namespace logical
{

BoolOperand::BoolOperand(bool content)
    : UnaryOperand<bool>::UnaryOperand(content)
{
}

BoolOperand::BoolOperand(const BoolOperand& operand)
    : UnaryOperand<bool>::UnaryOperand(operand)
{
}

BoolOperand::~BoolOperand() {}

BoolOperand* BoolOperand::clone() const { return new BoolOperand(*this); }

std::string BoolOperand::str() const
{
  return Operand<bool, bool>::getContent() ? "true" : "false";
}
}
}
}
}
