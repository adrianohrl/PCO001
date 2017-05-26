/**
 * This header file defines the available person info.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef QUEUE_INVERTER_H
#define QUEUE_INVERTER_H

#include "utilities/queues/queue/queue.h"
#include "utilities/stacks/stack/stack.h"

namespace utilities
{
	namespace queues
	{
		namespace queue
		{

			template<typename Element> class QueueInverter
			{
			public:
				static Queue<Element> invert(Queue<Element> input);

			private:
				QueueInverter();

			};

			template<typename Element> Queue<Element> QueueInverter<Element>::invert(Queue<Element> input)
			{
				Queue<Element> output;
				stacks::stack::Stack<Element> stack;
				while (!input.isEmpty())
				{
					stack.push(input.remove());
				}
				while (!stack.isEmpty())
				{
					output.insert(stack.pop());
				}
				return output;
			}

		}
	}
}

#endif // QUEUE_INVERTER_H
