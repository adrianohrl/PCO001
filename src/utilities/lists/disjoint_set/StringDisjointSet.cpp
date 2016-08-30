/**
 * This source file implements specific parse and evaluation operations
 * for a Disjoint Set of String objects.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/lists/disjoint_set/StringDisjointSet.h"

namespace utilities
{
	namespace lists
	{
		namespace disjoint_set
    {

    StringDisjointSet::~StringDisjointSet()
    {
    }

    bool StringDisjointSet::insert(std::string expression)
    {
      if (!DisjointSet::evaluate(expression))
      {
        return false;
      }
      Node<std::string>* node = create(expression.substr(1, expression.length() - 2));
      return DisjointSet<std::string>::insert(node);
    }

    bool StringDisjointSet::remove(std::string expression)
    {
      if (!DisjointSet::evaluate(expression))
      {
        return false;
      }
      Node<std::string>* node = create(expression.substr(1, expression.length() - 2));
      return DisjointSet<std::string>::remove(node);
    }

    bool StringDisjointSet::find(std::string expression)
    {
      if (!DisjointSet::evaluate(expression))
      {
        return false;
      }
      Node<std::string>* node = create(expression.substr(1, expression.length() - 2));
      return DisjointSet<std::string>::find(node);
    }

    Node<std::string>* StringDisjointSet::create(std::string expression)
    {
      if (expression == "")
      {
        return NULL;
      }
      std::string next = DisjointSet::getNext(expression);
      expression = expression.substr(next.length());
      if (expression != "" && expression.at(0) == ',')
      {
        expression = expression.substr(1);
      }
      Node<std::string>* node;
      if (next.at(0) == '(' && next.at(next.length() - 1) == ')')
      {
        next = next.substr(1, next.length() - 2);
        node = new Node<std::string>();
        node->setSubset(create(next));
      }
      else
      {
        node = new Node<std::string>(next);
      }
      if (expression != "")
      {
        node->setNext(create(expression));
      }
      return node;
    }

		}
	}
}
