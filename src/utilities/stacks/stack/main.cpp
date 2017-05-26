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
#include "utilities/stacks/stack/stack.h"

using typename utilities::stacks::stack::Stack;

int main()
{
	int i = 9;
	Stack<int> limited_stack(6);
	if (limited_stack.isEmpty())
	{
		std::cout << std::endl << "The limited stack is empty!!!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "The limited stack is not empty!!!" << std::endl;
	}
	while (limited_stack.push(++i))
	{
			std::cout << "limited stack top: " << limited_stack.top() << std::endl;
	}
	std::cout << "Unable to push " << i << " to the limited stack." << std::endl;
	std::cout << "Printing the limited stack: " << limited_stack.toString() << std::endl;
	while (!limited_stack.isEmpty())
	{
		std::cout << "Popped " << limited_stack.pop() << " from the limited stack." << std::endl;
	}
	std::cout << "Printing the limited stack after all: " << limited_stack.toString() << std::endl;

	std::cout << std::endl << "----------------" << std::endl;
	Stack<std::string> unlimited_stack;
	if (unlimited_stack.isEmpty())
	{
		std::cout << std::endl << "The stack is empty!!!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "The stack is not empty!!!" << std::endl;
	}
	unlimited_stack.push("1st in");
	unlimited_stack.push("2nd in");
	unlimited_stack.push("3rd in");
	unlimited_stack.push("4th in");
	unlimited_stack.push("5th in");
	unlimited_stack.push("6th in");
	unlimited_stack.push("7th in");
	unlimited_stack.push("8th in");
	unlimited_stack.push("9th in");
	unlimited_stack.push("10th in");
	std::cout << "Printing the unlimited stack: " << unlimited_stack.toString() << std::endl;
	while (!unlimited_stack.isEmpty())
	{
		std::cout << "Popped " << unlimited_stack.pop() << " from the unlimited stack." << std::endl;
	}
	std::cout << "Printing the unlimited stack after all: " << unlimited_stack.toString() << std::endl;

	return EXIT_SUCCESS;
}
