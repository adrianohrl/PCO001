/**
 * This header file defines the available person info.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW4_INTEGER_DISJOINT_SETS_H
#define HW4_INTEGER_DISJOINT_SETS_H

#include "utilities/lists/disjoint_set/IntegerDisjointSet.h"

namespace homeworks
{
  namespace homework4
  {
    namespace sets
    {

    enum IntegerDisjointSetEnum
    {
      A,
      B
    };

    }

    typedef typename sets::IntegerDisjointSetEnum IntegerDisjointSetEnum;

    class IntegerDisjointSets
    {
    public:
      IntegerDisjointSets();
      IntegerDisjointSets(std::string expression_A, std::string expression_B);
      IntegerDisjointSets(const IntegerDisjointSets& ids);
      virtual ~IntegerDisjointSets();

      bool insert(IntegerDisjointSetEnum set, int element);
      bool insert(IntegerDisjointSetEnum set, std::string expression);
      bool removeZeros(IntegerDisjointSetEnum set);
      bool remove(IntegerDisjointSetEnum set, int element = 0);
      bool remove(IntegerDisjointSetEnum set, std::string expression);
      bool find(IntegerDisjointSetEnum set, int element);
      bool find(IntegerDisjointSetEnum set, std::string expression);
      int sumNodes(IntegerDisjointSetEnum set);
      int calculateHeight(IntegerDisjointSetEnum set);
      int countElements(IntegerDisjointSetEnum set);
      bool compareDisjointSets();
      std::string toString(IntegerDisjointSetEnum set) const;
      std::string toStringReversed(IntegerDisjointSetEnum set);
      bool setDisjointSetA(std::string expression);
      bool setDisjointSetB(std::string expression);
      friend std::ostream& operator<<(std::ostream& os, const IntegerDisjointSets& sets);
      void operator=(const IntegerDisjointSets& sets);

    private:
      utilities::lists::disjoint_set::IntegerDisjointSet *set_A_, *set_B_;

    };
  }
}

#endif // HW4_INTEGER_DISJOINT_SETS_H
