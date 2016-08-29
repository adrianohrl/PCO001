/**
 * This source file implements a main function in order to test the
 * functionalities of the created BinaryTree class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/trees/binary_tree/BinaryTree.h"

int main()
{
	utilities::trees::binary_tree::BinaryTree<int, std::string> tree;
	if (tree.isEmpty())
	{
		std::cout << "The binary tree is empty!!!" << std::endl;
	}
	else
	{
		std::cout << "The binary tree is NOT empty!!!" << std::endl;
	}
	int n = 11;
	int keys[n] = {15, 6, 7, 18, 3, 13, 2, 9, 4, 17, 20};
	std::string elements[n] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th"};
	for (int i = 0; i < n; i++)
	{
		tree.insert(keys[i], elements[i]);
	}
	std::cout << "Printing the binary tree in order: " << tree.toString() << std::endl;

  n = 7;
  int indexes[n] = {7, 2, 1, 3, 1, 3, 0};
	for (int i = 0; i < n; i++)
	{
    int index = indexes[i];
    if (tree.remove(keys[index]))
		{
      std::cout << "Removed (" << keys[index] << ") " << elements[index] << " from the binary tree." << std::endl;
		}
		else
		{
      std::cout << "There is NO key whose value is " << keys[index] << " in the binary tree." << std::endl;
		}
    std::cout << "Printing the binary tree in order again: " << tree.toString() << std::endl;
	}
	std::cout << "Printing the binary tree in order after all: " << tree.toString() << std::endl;
	int key = keys[10];
	std::string element = tree.find(key);
	if (element != "")
	{
		std::cout << "Element found: " << element << " (whose key is " << key << ")." << std::endl;
	}
	else
	{
		std::cout << "Element, whose key is " << key << ", was NOT found." << std::endl;
	}
	return EXIT_SUCCESS;
}
