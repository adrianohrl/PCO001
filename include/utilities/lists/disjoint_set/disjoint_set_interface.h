/**
 * This header file defines and implements a generic DisjointSet object.
 *
 * OBS.: The class implementation is stated in this file because it make its
 *usage
 * easier (due to the template use).
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DISJOINT_SET_INTERFACE_H
#define DISJOINT_SET_INTERFACE_H

#include <string>
#include "utilities/lists/disjoint_set/node.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

template <typename Element> class DisjointSetInterface
{
public:
  virtual bool insert(Element element) = 0;
  virtual bool insert(const char* element) = 0;
  virtual bool remove(Element element) = 0;
  virtual bool remove(const char* element) = 0;
  virtual bool find(Element element) = 0;
  virtual bool find(const char* element) = 0;
  virtual bool isEmpty() = 0;
  virtual std::string toString(bool reversed = false) const = 0;

protected:
  virtual bool insert(Node<Element>* node) = 0;
  virtual bool remove(Node<Element>* node) = 0;
  virtual bool find(Node<Element>* node) = 0;
};
}
}
}

#endif // DISJOINT_SET_INTERFACE_H
