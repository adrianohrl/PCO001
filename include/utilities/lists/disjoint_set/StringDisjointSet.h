/**
 * This header file defines the features of a StringDisjointSet object,
 * which is based on DisjointSet class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef STRING_DISJOINT_SET_H
#define STRING_DISJOINT_SET_H

#include "utilities/lists/disjoint_set/DisjointSet.h"

namespace utilities
{
	namespace lists
	{
		namespace disjoint_set
		{

    class StringDisjointSet : public DisjointSet<std::string>
    {
    public:
      virtual ~StringDisjointSet();

      virtual bool insert(std::string expression);
      virtual bool remove(std::string expression);
      virtual bool find(std::string expression);

    private:
      Node<std::string>* create(std::string expression);

    };

		}
	}
}

#endif // STRING_DISJOINT_SET_H
