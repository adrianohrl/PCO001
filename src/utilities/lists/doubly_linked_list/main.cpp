/**
 * This source file implements a main function in order to test the functionalities of the created
 * DisjointSet class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/lists/doubly_linked_list/doubly_linked_list.h"

using typename utilities::lists::doubly_linked_list::DoublyLinkedList;

int main()
{
	DoublyLinkedList<float> list;
	if (list.isEmpty())
	{
		std::cout << std::endl << "The doubly linked list is empty!!!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "The doubly linked list is not empty!!!" << std::endl;
	}
	list.insert(12.5);
	list.insert(320);
	list.insert(413);
	list.insert(197, false);
	list.insert(6.2);
	list.insert(13, false);
	list.insert(504, false);
	std::cout << "Printing the doubly linked list from the beginning: " << list.toString() << std::endl;
	std::cout << "Printing the doubly linked list from the end: " << list.toString(false) << std::endl;
	list.remove(197);
	list.remove(12.5, false);
	list.remove(504);
	list.remove(320, false);
	list.remove(13);
	list.remove(6.2);
	list.remove(413, false);
	std::cout << "Printing the limited stack after all from the beginning: " << list.toString() << std::endl;
	return EXIT_SUCCESS;
}
