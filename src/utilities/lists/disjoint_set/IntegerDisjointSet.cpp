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

#include "utilities/lists/disjoint_set/IntegerDisjointSet.h"
#include "utilities/stacks/stack/Stack.h"
#include <stdlib.h>

namespace utilities
{
  namespace lists
  {
    namespace disjoint_set
    {

    /*IntegerDisjointSet::IntegerDisjointSet(const IntegerDisjointSet& set)
      : DisjointSet(set)
    {
    }*/

    IntegerDisjointSet::~IntegerDisjointSet()
    {
    }

    bool IntegerDisjointSet::insert(std::string expression)
    {
      if (!evaluate(expression))
      {
        return false;
      }
      Node<int>* node = create(expression.substr(1, expression.length() - 2));
      return DisjointSet<int>::insert(node);
    }

    bool IntegerDisjointSet::remove(std::string expression)
    {
      if (!evaluate(expression))
      {
        return false;
      }
      Node<int>* node = create(expression.substr(1, expression.length() - 2));
      return DisjointSet<int>::remove(node);
    }

    bool IntegerDisjointSet::find(std::string expression)
    {
      if (!evaluate(expression))
      {
        return false;
      }
      Node<int>* node = create(expression.substr(1, expression.length() - 2));
      return DisjointSet<int>::find(node);
    }

    Node<int>* IntegerDisjointSet::create(std::string expression)
    {
      if (expression == "")
      {
        return NULL;
      }
      std::string next = DisjointSet<int>::getNext(expression);
      expression = expression.substr(next.length());
      if (expression != "" && expression.at(0) == ',')
      {
        expression = expression.substr(1);
      }
      Node<int>* node;
      if (next.at(0) == '(' && next.at(next.length() - 1) == ')')
      {
        next = next.substr(1, next.length() - 2);
        node = new Node<int>();
        node->setSubset(create(next));
      }
      else
      {
        int number = atoi(next.c_str());
        node = new Node<int>(number);
      }
      if (expression != "")
      {
        node->setNext(create(expression));
      }
      return node;
    }

    bool IntegerDisjointSet::evaluate(std::string expression)
    {
      if (!DisjointSet<int>::evaluate(expression))
      {
        return false;
      }
      for (std::string::iterator it = expression.begin() + 1; it != expression.end(); ++it)
      {
        if ((*it < '0' || *it > '9') && *it != '(' && *it != ',' && *it != ')')
        {
          return false;
        }
      }
      return true;
    }

    }
  }
}
