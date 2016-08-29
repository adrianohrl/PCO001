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

#include "utilities/lists/disjoint_set/DisjointSet.h"

namespace utilities
{
  namespace lists
  {
    namespace disjoint_set
    {

    class IntegerDisjointSet : public DisjointSet<int>
    {
    public:
      //using DisjointSet<int>::DisjointSet;
      //virtual IntegerDisjointSet(const IntegerDisjointSet& set);
      virtual ~IntegerDisjointSet();

      using DisjointSet<int>::insert;
      virtual bool insert(std::string expression);
      using DisjointSet<int>::remove;
      virtual bool remove(std::string expression);
      using DisjointSet<int>::find;
      virtual bool find(std::string expression);

      static bool evaluate(std::string expression);

    private:
      Node<int>* create(std::string expression);

    };

    }
  }
}

#endif // INTEGER_DISJOINT_SET_H
