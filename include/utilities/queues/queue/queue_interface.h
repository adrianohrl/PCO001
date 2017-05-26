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

#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

#include <string>

namespace utilities
{
	namespace queues
	{
		namespace queue
		{

			template<typename Element> class QueueInterface
			{
			public:

				virtual bool insert(Element element) = 0;
				virtual Element remove() = 0;
				virtual int size() = 0;
				virtual bool isEmpty() = 0;
				virtual std::string toString() = 0;

			};

		}
	}
}

#endif // QUEUE_INTERFACE_H
