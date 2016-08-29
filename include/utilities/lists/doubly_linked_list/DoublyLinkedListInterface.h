/**
 * This header file defines the features of a generic doubly
 * linked list object, which is based on DoublyLinkedList class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DOUBLY_LINKED_LIST_INTERFACE_H
#define DOUBLY_LINKED_LIST_INTERFACE_H

#include <string>

namespace utilities
{
	namespace lists
	{
		namespace doubly_linked_list
		{

			template<typename Element> class DoublyLinkedListInterface
			{
			public:

				virtual bool insert(Element element, bool from_beginning = true) = 0;
				virtual bool remove(Element element, bool from_beginning = true) = 0;
				virtual Element find(Element element, bool from_beginning = true) = 0;
				virtual bool isEmpty() = 0;
				virtual bool contains(Element element, bool from_beginning = true) = 0;
				virtual std::string toString(bool from_beginning = true) = 0;

			};

		}
	}
}

#endif // DOUBLY_LINKED_LIST_INTERFACE_H
