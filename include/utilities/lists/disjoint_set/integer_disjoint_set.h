/**
 * This header file defines the features of a IntegerDisjointSet object,
 * which is based on DisjointSet class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef INTEGER_DISJOINT_SET_H
#define INTEGER_DISJOINT_SET_H

#include "utilities/lists/disjoint_set/disjoint_set.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

class IntegerDisjointSet : public DisjointSet<int>
{
public:
  IntegerDisjointSet(std::string expression = "");
  IntegerDisjointSet(const IntegerDisjointSet& set);
  virtual ~IntegerDisjointSet();
  int sumNodes();

private:
  int sum(Node<int>* node);
};
}
}
}

#endif // INTEGER_DISJOINT_SET_H
