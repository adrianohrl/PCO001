/**
 * This source file implements a main function in order to test the
 * functionalities of the created ExpressionBinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/trees/expression_binary_tree/expression_binary_tree.h"
#include "utilities/trees/expression_binary_tree/arithmetic/addition.h"
#include "utilities/trees/expression_binary_tree/arithmetic/subtraction.h"
#include "utilities/trees/expression_binary_tree/arithmetic/multiplication.h"
#include "utilities/trees/expression_binary_tree/arithmetic/division.h"
#include "utilities/trees/expression_binary_tree/arithmetic/negation.h"
#include "utilities/trees/expression_binary_tree/arithmetic/double_operand.h"
#include "utilities/trees/expression_binary_tree/arithmetic/double_expression_parser.h"
#include "utilities/trees/expression_binary_tree/logical/and.h"
#include "utilities/trees/expression_binary_tree/logical/or.h"
#include "utilities/trees/expression_binary_tree/logical/beq.h"
#include "utilities/trees/expression_binary_tree/logical/bneq.h"
#include "utilities/trees/expression_binary_tree/logical/not.h"
#include "utilities/trees/expression_binary_tree/logical/ngeq.h"
#include "utilities/trees/expression_binary_tree/logical/leq.h"
#include "utilities/trees/expression_binary_tree/logical/eq.h"
#include "utilities/trees/expression_binary_tree/logical/neq.h"
#include "utilities/trees/expression_binary_tree/logical/geq.h"
#include "utilities/trees/expression_binary_tree/logical/nleq.h"
#include "utilities/trees/expression_binary_tree/logical/bool_operand.h"
#include "utilities/trees/expression_binary_tree/logical/bool_expression_parser.h"

using namespace utilities::trees::expression_binary_tree;
using namespace utilities::trees::expression_binary_tree::arithmetic;
using namespace utilities::trees::expression_binary_tree::logical;

int main()
{
  std::cout << "\nArithmetic Operations and Operator ...\n";
  DoubleOperand* d1 = new DoubleOperand(-1.5);
  std::cout << d1->str() << " = " << d1->getContent() << "\n";
  Addition<double>* add1 =
      new Addition<double>(new DoubleOperand(2.4), new DoubleOperand(2.6));
  std::cout << add1->str() << " = " << add1->process() << "\n";
  Subtraction<double>* sub1 =
      new Subtraction<double>(new DoubleOperand(6.5), add1);
  std::cout << sub1->str() << " = " << sub1->process() << "\n";
  Multiplication<double>* mult1 =
      new Multiplication<double>(new DoubleOperand(2), sub1);
  std::cout << mult1->str() << " = " << mult1->process() << "\n";
  Division<double>* div1 = new Division<double>(mult1, new DoubleOperand(0.5));
  std::cout << div1->str() << " = " << div1->process() << "\n";
  Negation<double>* neg1 = new Negation<double>(div1);
  std::cout << neg1->str() << " = " << neg1->process() << "\n";

  std::cout << "\nBool Logical Operations and Operator ...\n";
  BoolOperand* bool1 = new BoolOperand(false);
  std::cout << bool1->str() << " = " << (bool1->process() ? "true" : "false")
            << "\n";
  AND<bool>* and1 = new AND<bool>(new BoolOperand(true), new BoolOperand(true));
  std::cout << and1->str() << " = " << (and1->process() ? "true" : "false")
            << "\n";
  OR<bool>* or1 = new OR<bool>(and1, bool1);
  std::cout << or1->str() << " = " << (or1->process() ? "true" : "false")
            << "\n";
  BEQ<bool>* beq1 = new BEQ<bool>(new BoolOperand(true), new BoolOperand(true));
  std::cout << beq1->str() << " = " << (beq1->process() ? "true" : "false")
            << "\n";
  BNEQ<bool>* bneq1 =
      new BNEQ<bool>(new BoolOperand(true), new BoolOperand(true));
  std::cout << bneq1->str() << " = " << (bneq1->process() ? "true" : "false")
            << "\n";
  NOT<bool>* not1 = new NOT<bool>(bool1);
  std::cout << not1->str() << " = " << (not1->process() ? "true" : "false")
            << "\n";

  std::cout << "\nDouble Logical Operations and Operator ...\n";
  NGEQ<double>* ngeq1 = new NGEQ<double>(add1, d1);
  std::cout << ngeq1->str() << " = " << (ngeq1->process() ? "true" : "false")
            << "\n";
  LEQ<double>* leq1 = new LEQ<double>(sub1, div1);
  std::cout << leq1->str() << " = " << (leq1->process() ? "true" : "false")
            << "\n";
  EQ<double>* eq1 = new EQ<double>(d1, d1);
  std::cout << eq1->str() << " = " << (eq1->process() ? "true" : "false")
            << "\n";
  NEQ<double>* neq1 = new NEQ<double>(mult1, neg1);
  std::cout << neq1->str() << " = " << (neq1->process() ? "true" : "false")
            << "\n";
  GEQ<double>* geq1 = new GEQ<double>(add1, mult1);
  std::cout << geq1->str() << " = " << (geq1->process() ? "true" : "false")
            << "\n";
  NLEQ<double>* nleq1 = new NLEQ<double>(div1, sub1);
  std::cout << nleq1->str() << " = " << (nleq1->process() ? "true" : "false")
            << "\n";
  delete ngeq1, leq1, eq1, neq1, geq1, nleq1;
  delete or1, beq1, bneq1, not1;

  std::cout << "\nTesting Double Expression Parser ...\n";
  DoubleExpressionParser double_parser;
  std::string double_expression("(-((4 + 5) * 2 - 9) / 10))");
  Node<double, double>* double_node = double_parser.parse(double_expression);
  std::cout << "debt: " << double_node->str() << " = " << double_node->process() << "\n";
  delete double_node;

  std::cout << "\nTesting Bool Expression Parser ...\n";
  BoolExpressionParser bool_parser;
  std::string bool_expression("(!((true == false) && (false || true)))");
  Node<bool, bool>* bool_node = bool_parser.parse(bool_expression);
  std::cout << "cebt: " << bool_node->str() << " = " << bool_node->process() << "\n";
  delete bool_node;

  return EXIT_SUCCESS;
}
