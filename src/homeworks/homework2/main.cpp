/**
 * This source file implements a main function in order to test
 * the functionalities of the created DoubleStack class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/stacks/double_stack/DoubleStack.h"

using typename utilities::stacks::double_stack::DoubleStack;

int main()
{
	DoubleStack<int> stack(10);
	int i = 1;
	while (stack.pushToA(i++) &&
				 stack.pushToB(i++) &&
				 stack.pushToA(i++) &&
				 stack.pushToB(i++) &&
				 stack.pushToA(i++));
	std::cout << "Printing stack A: " << stack.toStringA() << std::endl;
	std::cout << "Printing stack B: " << stack.toStringB() << std::endl;
	while (!stack.isAEmpty())
	{
		std::cout << "Popped " << stack.popFromA() << " from the stack A." << std::endl;
	}
	while (!stack.isBEmpty())
	{
		std::cout << "Popped " << stack.popFromB() << " from the stack B." << std::endl;
	}
	if (stack.isAEmpty() && stack.isBEmpty())
	{
		std::cout << "Both stacks are empty!!" << std::endl;
	}
	else
	{
		std::cout << "They are NOT empty!!" << std::endl;
	}
	stack.pushToA(1);
	stack.pushToA(2);
	stack.pushToA(3);
	stack.pushToA(4);
	stack.pushToA(5);
	stack.pushToA(6);
	stack.pushToB(100);
	stack.pushToB(75);
	stack.pushToB(50);
	stack.pushToB(25);
	std::cout << "Printing stack A inverted: " << stack.toStringAInOrder() << std::endl;
	std::cout << "Printing stack A after all: " << stack.toStringA() << std::endl;
	std::cout << "Printing stack B after all: " << stack.toStringB() << std::endl;
	std::cout << "Printing stack B inverted: " << stack.toStringBInOrder() << std::endl;
	std::cout << "Printing stack B after all: " << stack.toStringB() << std::endl;
	std::cout << "Printing stack A after all: " << stack.toStringA() << std::endl;
	return EXIT_SUCCESS;
}
