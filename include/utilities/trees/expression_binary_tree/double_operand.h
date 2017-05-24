/**
 * This header file defines the ExpressionBinaryTree DoubleOperand class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_DOUBLE_OPERAND_H
#define EBT_DOUBLE_OPERAND_H

#include "utilities/trees/expression_binary_tree/operand.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

class DoubleOperand : public Operand<double>
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

#endif // EBT_DOUBLE_OPERAND_H
