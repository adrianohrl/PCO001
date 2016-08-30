/**
 * This header file defines the BinaryTreeInterface interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BINARY_TREE_INTERFACE_H
#define BINARY_TREE_INTERFACE_H

#include <string>

namespace utilities
{
	namespace trees
	{
		namespace binary_tree
		{

    template<typename Key, typename Element> class BinaryTreeInterface
    {
    public:

      virtual bool insert(Key key, Element element) = 0;
      virtual bool remove(Key key) = 0;
      virtual Element find(Key key) = 0;
      virtual std::string toString() = 0; //in-order

    };

		}
	}
}

#endif // BINARY_TREE_INTERFACE_H
