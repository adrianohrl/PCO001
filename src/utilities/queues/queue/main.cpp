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
#include "utilities/queues/queue/Queue.h"

using typename utilities::queues::queue::Queue;

int main()
{
	Queue<int> queue;
	if (queue.isEmpty())
	{
		std::cout << "The queue is empty!!!" << std::endl;
	}
	else
	{
		std::cout << "The queue is NOT empty!!!" << std::endl;
	}
	queue.insert(12);
	queue.insert(320);
	queue.insert(413);
	queue.insert(197);
	queue.insert(26);
	std::cout << "Printing the queue (whose size is " << queue.size() << "): " << queue.toString() << std::endl;
	while (!queue.isEmpty())
	{
		int element = queue.remove();
		std::cout << "Removed " << element << " from the queue (whose size is " << queue.size() << ")." << std::endl;
	}
	return EXIT_SUCCESS;
}
