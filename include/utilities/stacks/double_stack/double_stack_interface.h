/**
 * This header file defines the DoubleStackInterface interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DOUBLE_STACK_INTERFACE_H
#define DOUBLE_STACK_INTERFACE_H

#include <string>

namespace utilities
{
namespace stacks
{
namespace double_stack
{

template <typename Element> class DoubleStackInterface
{
public:
  virtual bool pushToA(Element element) = 0;
  virtual bool pushToB(Element element) = 0;
  virtual Element popFromA() = 0;
  virtual Element popFromB() = 0;
  virtual Element topOfA() = 0;
  virtual Element topOfB() = 0;
  virtual bool isAEmpty() = 0;
  virtual bool isBEmpty() = 0;
  virtual std::string toStringA() = 0;
  virtual std::string toStringB() = 0;
  virtual std::string toStringAInOrder() = 0;
  virtual std::string toStringBInOrder() = 0;
};
}
}
}

#endif // DOUBLE_STACK_INTERFACE_H
