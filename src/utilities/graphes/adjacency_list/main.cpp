/**
 * This source file implements a main function in order to test the functionalities of the created
 * DijkstraAdjacencyList graph class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/graphes/dijkstra_adjacency_list.h"

using typename utilities::graphes::DijkstraAdjacencyList;

int main()
{
	std::cout << "Testing DijkstraAdjacencyList class:\n";
	DijkstraAdjacencyList<char> graph(11);
	graph.insert('A'); // 0
	graph.insert('B'); // 1
	graph.insert('C'); // 2
	graph.insert('D'); // 3
	graph.insert('E'); // 4
	graph.insert('F'); // 5
	graph.insert('G'); // 6
	graph.insert('H'); // 7
	graph.insert('I'); // 8
	graph.insert('J'); // 9
	graph.insert('K'); // 10
	std::cout << "\nInitializing the graph:\n\n" + graph.str() + "\n";

	graph.connect('A', 'B', 8);
	graph.connect('A', 'C', 5);
	graph.connect('A', 'D', 7);
	graph.connect('B', 'E', 6);
	graph.connect('B', 'F', 2);
	graph.connect('C', 'E', 4);
	graph.connect('C', 'F', 5);
	graph.connect('D', 'F', 4);
	graph.connect('D', 'G', 2);
	graph.connect('E', 'H', 4);
	graph.connect('F', 'H', 4);
	graph.connect('F', 'I', 2);
	graph.connect('F', 'J', 4);
	graph.connect('G', 'I', 2);
	graph.connect('G', 'J', 4);
	graph.connect('H', 'K', 4);
	graph.connect('I', 'K', 5);
	graph.connect('J', 'K', 4);
	std::cout << "\nInitialized graph:\n\n" + graph.str() + "\n\n";

	std::list<std::pair<char, char> > goals;
	goals.push_back(std::pair<char, char>('A', 'K')); // proposed homework
	goals.push_back(std::pair<char, char>('B', 'H'));
	goals.push_back(std::pair<char, char>('B', 'G'));
	goals.push_back(std::pair<char, char>('J', 'A'));
	std::list<std::pair<char, char> >::iterator goals_it(goals.begin());
	std::list<char> path;
	std::list<char>::iterator path_it;
	int counter;
	char origin, destiny;
	while (goals_it != goals.end())
	{
		origin = goals_it->first;
		destiny = goals_it->second;
		goals_it++;
		path = graph.getShortestPath(origin, destiny);
		if (path.empty())
		{
			std::cout << "\nThere is no path from " << origin << " to " << destiny << "!!!\n";
			continue;
		}
		counter = 1;
		path_it = path.begin();
		std::cout << "\nPath from " << origin << " to " << destiny << ":";
		while (path_it != path.end())
		{
			std::cout << "\n\t" << counter++ << ": " << *path_it++;
		}
		std::cout << "\n";
	}
	return EXIT_SUCCESS;
}
