/**
 * This source file implements specific parse and evaluation operations
 * for a Disjoint Set of integer numbers.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include "utilities/lists/disjoint_set/integer_expression_parser.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

IntegerDisjointSet::IntegerDisjointSet(std::string expression)
    : DisjointSet<int>::DisjointSet(new IntegerExpressionParser(), expression)
{
}

IntegerDisjointSet::IntegerDisjointSet(const IntegerDisjointSet& set)
    : DisjointSet<int>::DisjointSet(set)
{
}

IntegerDisjointSet::~IntegerDisjointSet() {}

int IntegerDisjointSet::sumNodes()
{
  return !DisjointSet<int>::isEmpty() ? sum(DisjointSet<int>::getRoot()) : 0;
}

int IntegerDisjointSet::sum(Node<int>* node)
{
  if (!node)
  {
    return 0;
  }
  int total(0);
  if (node->isElement())
  {
    total += node->getElement();
  }
  else if (node->isSubset())
  {
    total += sum(node->getSubset());
  }
  if (node->hasNext())
  {
    total += sum(node->getNext());
  }
  return total;
}
}
}
}
