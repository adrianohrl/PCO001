/**
 * This source file implements a main function in order to test the functionalities of the created
 * AdjacentMatrix graph class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/graphes/AdjacencyMatrix.h"

using typename utilities::graphes::AdjacencyMatrix;

int main()
{
  std::cout << std::endl << "Testing AdjacencyMatrix class:" << std::endl;
  AdjacencyMatrix graph(4);
  std::cout << std::endl << "Initializing the graph:" << graph.toString() << std::endl;
  graph.connect(0, 1);
  graph.connect(1, 2);
  graph.connect(2, 3);
  graph.connect(3, 0);
  std::cout << std::endl << "Graph after connections:" << graph.toString() << std::endl;
  std::cout << std::endl << "The given graph is ";
  if (graph.isConvex())
  {
    std::cout << "convex!!!" << std::endl;
    std::cout << std::endl << "The given graph is an " << (graph.isEulerianGraph() ? "" : "NOT ") << "eulerian graph!!!" << std::endl;
  }
  else
  {
    std::cout << "NOT convex!!!" << std::endl;
  }
	return EXIT_SUCCESS;
}
