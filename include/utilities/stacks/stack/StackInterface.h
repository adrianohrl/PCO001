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

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include <string>

namespace utilities
{
	namespace stacks
	{
		namespace stack
		{

			template<typename Element> class StackInterface
			{
			public:
				virtual bool push(Element element) = 0;
				virtual Element pop() = 0;
				virtual Element top() = 0;
				virtual bool isEmpty() = 0;
				virtual std::string toString() = 0;

			};

		}
	}
}

#endif // STACK_INTERFACE_H
