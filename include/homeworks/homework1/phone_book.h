/**
 * This header file defines the features of a generic Stack object,
 * which is based on DisjointSet class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW1_PHONE_BOOK_H
#define HW1_PHONE_BOOK_H

#include "homeworks/homework1/person_info.h"
#include "utilities/lists/doubly_linked_list/doubly_linked_list.h"

namespace homeworks
{
	namespace homework1
	{

		class PhoneBook
		{
		public:
			PhoneBook(std::string name = "");
			virtual ~PhoneBook();

			bool insert(std::string name, std::string phone_number, std::string additional = "");
			bool insert(PersonInfo info);
			PersonInfo find(std::string name);
			PersonInfo find(PersonInfo info);
			bool remove(std::string name);
			bool remove(PersonInfo info);
			std::string toString(bool from_beginning = true);

		private:
			std::string name_;
			utilities::lists::doubly_linked_list::DoublyLinkedList<PersonInfo> list_;

		};
	}
}

#endif // HW1_PHONE_BOOK_H
