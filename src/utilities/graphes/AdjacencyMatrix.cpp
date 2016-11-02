/**
 * This source file implements the AdjacentMatrix class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/graphes/AdjacencyMatrix.h"

namespace utilities
{

namespace graphes
{

AdjacencyMatrix::AdjacencyMatrix(const unsigned int number_of_vertices, bool undirected)
  : number_of_vertices_(number_of_vertices),
    undirected_(undirected)
{
  if (number_of_vertices > NUMBER_OF_VERTICES)
  {
    number_of_vertices_ = 0;
  }
  for (int i(0); i < number_of_vertices_; i++)
  {
    visited_vertices_[i] = false;
    for (int j(0); j < number_of_vertices_; j++)
    {
      matrix_[i][j] = 0;
    }
  }
}

AdjacencyMatrix::~AdjacencyMatrix()
{}

bool AdjacencyMatrix::connect(const unsigned int source, const unsigned int destination)
{
  if (source >= number_of_vertices_ || destination >= number_of_vertices_)
  {
    return false;
  }
  matrix_[source][destination] = 1;
  if (undirected_)
  {
    matrix_[destination][source] = 1;
  }
  return true;
}

bool AdjacencyMatrix::disconnect(const unsigned int source, const unsigned int destination)
{
  if (source >= number_of_vertices_ || destination >= number_of_vertices_)
  {
    return false;
  }
  matrix_[source][destination] = 0;
  if (undirected_)
  {
    matrix_[destination][source] = 0;
  }
  return true;
}

bool AdjacencyMatrix::isConvex()
{
  reset();
  visiteInDepthFirst(0);
  for (int i(0); i < number_of_vertices_; i++)
  {
    if (!visited_vertices_[i])
    {
      return false;
    }
  }
  return true;
}

bool AdjacencyMatrix::isEulerianGraph()
{
  if (!isConvex())
  {
    return false;
  }
  bool condition1(false), condition2(false);
  int in_degree, out_degree, difference;
  for (int v(0); v < number_of_vertices_; v++)
  {
    in_degree = getInDegree(v);
    out_degree = getOutDegree(v);
    difference = out_degree - in_degree;
    if (difference != 0 || in_degree == 0 || in_degree % 2 != 0)
    {
      return false;
    }
  }
  return true;
}

std::string AdjacencyMatrix::toString() const
{
  std::stringstream ss;
  for (int i(0); i < number_of_vertices_; i++)
  {
    ss << "\n";
    for (int j(0); j < number_of_vertices_; j++)
    {
      ss << matrix_[i][j] << "\t";
    }
  }
  return ss.str();
}

void AdjacencyMatrix::reset()
{
  for (int i(0); i < number_of_vertices_; i++)
  {
    visited_vertices_[i] = false;
  }
}

void AdjacencyMatrix::visiteInDepthFirst(const unsigned int vertex)
{
  for (int i(0); i < number_of_vertices_; i++)
  {
    if (isConnected(vertex, i) && !visited_vertices_[i])
    {
      visited_vertices_[i] = true;
      visiteInDepthFirst(i);
    }
  }
}

bool AdjacencyMatrix::isConnected(const unsigned int source, const unsigned int destination) const
{
  return source < number_of_vertices_ &&
      destination < number_of_vertices_ &&
      matrix_[source][destination] == 1;
}

bool AdjacencyMatrix::isDisconnected(const unsigned int source, const unsigned int destination) const
{
  return source < number_of_vertices_ &&
      destination < number_of_vertices_ &&
      matrix_[source][destination] == 0;
}

unsigned int AdjacencyMatrix::getInDegree(const unsigned int vertex) const
{
  int counter(0);
  for (int i(0); i < number_of_vertices_; i++)
  {
    if (matrix_[vertex][i] == 1)
    {
      counter++;
    }
  }
  return counter;
}

unsigned int AdjacencyMatrix::getOutDegree(const unsigned int vertex) const
{
  int counter(0);
  for (int i(0); i < number_of_vertices_; i++)
  {
    if (matrix_[i][vertex] == 1)
    {
      counter++;
    }
  }
  return counter;
}

unsigned int AdjacencyMatrix::getDegree(const unsigned int vertex) const
{
  return getInDegree(vertex);
}

}

}

