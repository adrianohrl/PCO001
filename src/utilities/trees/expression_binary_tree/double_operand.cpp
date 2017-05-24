/**
 * This header file implements the ExpressionBinaryTree DoubleOperand class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/trees/expression_binary_tree/double_operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

DoubleOperand::DoubleOperand(double content) : Operand(&content) {}

DoubleOperand::DoubleOperand(const DoubleOperand& operand) : Operand(operand) {}

DoubleOperand::~DoubleOperand() {}

DoubleOperand* DoubleOperand::clone() const { return new DoubleOperand(*this); }
}
}
}
