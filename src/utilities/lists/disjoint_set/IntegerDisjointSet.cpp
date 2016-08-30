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

    bool IntegerDisjointSet::insert(std::string expression)
    {
      if (!evaluate(expression))
      {
        return false;
      }
      if (isEmpty() && expression.at(0) == '(')
      {
        expression = expression.substr(1, expression.length() - 2);
      }
      Node<int>* node = create(expression);
      return DisjointSet<int>::insert(node);
    }

    bool IntegerDisjointSet::remove(std::string expression)
    {
      if (!evaluate(expression))
      {
        return false;
      }
      Node<int>* node = create(expression);
      return DisjointSet<int>::remove(node);
    }

    bool IntegerDisjointSet::find(std::string expression)
    {
      if (!evaluate(expression))
      {
        return false;
      }
      Node<int>* node = create(expression);
      return DisjointSet<int>::find(node);
    }

    int IntegerDisjointSet::sumNodes()
    {
      if (DisjointSet<int>::isEmpty())
      {
        return 0;
      }
      return sum(DisjointSet<int>::getRoot());
    }

    int IntegerDisjointSet::sum(Node<int>* node)
    {
      if (!node)
      {
        return 0;
      }
      int total = 0;
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

    bool IntegerDisjointSet::isInRange(char c)
    {
      return c >= '0' && c <= '9';
    }

    bool IntegerDisjointSet::evaluate(std::string expression)
    {
      if (!DisjointSet<int>::evaluate(expression))
      {
        return false;
      }
      for (std::string::iterator it = expression.begin() + 1; it != expression.end(); ++it)
      {
        if (!isInRange(*it) && !isSeparator(*it))
        {
          return false;
        }
      }
      return true;
    }

    }
  }
}
