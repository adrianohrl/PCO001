/**
 * This header file defines the AdjacentMatrix class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <sstream>

#define NUMBER_OF_VERTICES 20

namespace utilities
{

namespace graphes
{

class AdjacencyMatrix
{
public:
  AdjacencyMatrix(const unsigned int number_of_vertices, bool undirected = true);
  virtual ~AdjacencyMatrix();
  bool connect(const unsigned int source, const unsigned int destination);
  bool disconnect(const unsigned int source, const unsigned int destination);
  bool isConvex();
  bool isEulerianGraph();
  std::string toString() const;

private:
  const bool undirected_;
  unsigned int number_of_vertices_;
  unsigned int matrix_[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES];
  bool visited_vertices_[NUMBER_OF_VERTICES];
  void reset();
  void visiteInDepthFirst(const unsigned int vertex);
  bool isConnected(const unsigned int source, const unsigned int destination) const;
  bool isDisconnected(const unsigned int source, const unsigned int destination) const;
  unsigned int getInDegree(const unsigned int vertex) const;
  unsigned int getOutDegree(const unsigned int vertex) const;
  unsigned int getDegree(const unsigned int vertex) const;
};

}

}

#endif // ADJACENCY_MATRIX_H
