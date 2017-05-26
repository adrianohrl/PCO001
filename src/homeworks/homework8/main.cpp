/**
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/graphes/adjacency_matrix.h"

#define NUMBER_OF_OPTIONS 7
#define INT_MAX 1
#define INVALID_INTEGER -32768
#define MAX_NUMBER_OF_VERTICES 20
#define NUMBER_OF_ATTEMPTS 3

using utilities::graphes::AdjacencyMatrix;

void printMenu();
bool process(AdjacencyMatrix **graph, int option);
int query(std::string message);

bool create(utilities::graphes::AdjacencyMatrix **graph);
bool connect(AdjacencyMatrix *graph);
bool disconnect(utilities::graphes::AdjacencyMatrix *graph);

int main()
{
  AdjacencyMatrix *graph = NULL;
  int option;
  while (true)
  {
    printMenu();
    option = query("Numero da opcao");
    if (option > 0 && option <= NUMBER_OF_OPTIONS)
    {
      std::cout << "\nA opcao " << option << " foi selecionada.\n";
      if (!process(&graph, option))
      {
        break;
      }
    }
    else
    {
      std::cout << "\nOpcao invalida: " << option << "!!!";
    }
  }
  if (graph)
  {
    delete graph;
    graph = NULL;
  }
  return EXIT_SUCCESS;
}

void printMenu()
{
	std::cout << "\n";
  std::cout << "\n*********************************************";
  std::cout << "\n* Entre o numero da opcao desejada:         *";
  std::cout << "\n* 1) Criar novo grafo;                      *";
  std::cout << "\n* 2) Conectar vertices;                     *";
  std::cout << "\n* 3) Desconectar vertices;                  *";
  std::cout << "\n* 4) Verificar se grafo eh conexo;          *";
  std::cout << "\n* 5) Verificar se o grafo eh euleriano;     *";
  std::cout << "\n* 6) Mostrar matriz de adjacencia do grafo; *";
  std::cout << "\n* 7) Sair.                                  *";
  std::cout << "\n*********************************************";
}

bool process(utilities::graphes::AdjacencyMatrix **graph, int option)
{
  if (option != 1 && option != NUMBER_OF_OPTIONS && !*graph)
  {
    std::cout << "\nO grafo deve ser criado antes que qualquer outra opcao possa ser utilizada!!!";
    return true;
  }
  switch (option)
  {
    case 1:
      std::cout << "\nCriando novo grafo:";
      if (!create(graph))
      {
        std::cout << "\nFalha ao criar um novo grafo.";
      }
      break;
    case 2:
      std::cout << "\nConectando vertices no grafo:";
      while (connect(*graph));
      break;
    case 3:
      std::cout << "\nDesconectando vertices no grafo:";
      while (disconnect(*graph));
      break;
    case 4:
      std::cout << "\nVerificando se grafo eh conexo:";
      std::cout << "\nO grafo ";
      if (*graph && !(*graph)->isConvex())
      {
        std::cout << "NAO ";
      }
      std::cout << "eh conexo!!!";
      break;
    case 5:
      std::cout << "\nVerificando se o grafo eh euleriano:";
      std::cout << "\nO grafo ";
      if (*graph && !(*graph)->isEulerianGraph())
      {
        std::cout << "NAO";
      }
      std::cout << " eh euleriano!!!";
      break;
    case 6:
      std::cout << "\nMostrando matriz de adjacencia do grafo:";
      std::cout << (*graph)->toString() << "\n";
      break;
    case 7:
      std::cout << "\nSaindo!!!";
      return false;
    default:
      std::cout << "\nInvalid option!!!";
  }
  return true;
}

int query(std::string message)
{
  int number(INVALID_INTEGER);
  std::cout << "\n" + message + ": ";
  std::cin >> number;
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(INT_MAX);
    std::cout << "\nEntrada invalida!!!";
    return INVALID_INTEGER;
  }
  return number;
}

bool create(AdjacencyMatrix **graph)
{
  int counter(0);
  int number_of_vertices(0);
  while (number_of_vertices == 0)
  {
    number_of_vertices = query("\nEntre o numero de vertices no grafo");
    if (number_of_vertices < 0 || number_of_vertices > MAX_NUMBER_OF_VERTICES)
    {
      counter++;
      std::cout << "O numero de vertices no grafo deve ser positivo e no maximo " << MAX_NUMBER_OF_VERTICES << ".";
      number_of_vertices = 0;
    }
    if (counter > NUMBER_OF_ATTEMPTS)
    {
      std::cout << "\nNumero maximo de tentativas excedido!!!";
      return false;
    }
  }
  if (*graph)
  {
    delete *graph;
    *graph = NULL;
  }
  *graph = new AdjacencyMatrix(number_of_vertices);
  return true;
}

bool connect(utilities::graphes::AdjacencyMatrix *graph)
{
  if (!graph)
  {
    return false;
  }
  int counter(0);
  int source(MAX_NUMBER_OF_VERTICES);
  while (source == MAX_NUMBER_OF_VERTICES)
  {
    source = query("\nEntre o numero do vertice de origem do arco (entre -1 para cancelar)");
    if (source == -1)
    {
      std::cout << "\nAbortando conexao de vertices!!!";
      return false;
    }
    if (source < 0 || source >= MAX_NUMBER_OF_VERTICES)
    {
      counter++;
      std::cout << "\nO numero do vertice deve ser positivo e no maximo " << MAX_NUMBER_OF_VERTICES << ".";
      source = MAX_NUMBER_OF_VERTICES;
    }
  }
  counter = 0;
  int destination(MAX_NUMBER_OF_VERTICES);
  while (destination == MAX_NUMBER_OF_VERTICES)
  {
    destination = query("Entre o numero do vertice de destino do arco (entre -1 para cancelar)");
    if (destination == -1)
    {
      std::cout << "\nAbortando conexao de vertices!!!";
      return false;
    }
    if (destination < 0 || destination >= MAX_NUMBER_OF_VERTICES)
    {
      counter++;
      std::cout << "\nO numero do vertice deve ser positivo e no maximo " << MAX_NUMBER_OF_VERTICES << ".";
      destination = MAX_NUMBER_OF_VERTICES;
    }
  }
  return graph->connect(source, destination);
}

bool disconnect(AdjacencyMatrix *graph)
{
  if (!graph)
  {
    return false;
  }
  int counter(0);
  int source(MAX_NUMBER_OF_VERTICES);
  while (source == MAX_NUMBER_OF_VERTICES)
  {
    source = query("\nEntre o numero do vertice de origem do arco (entre -1 para cancelar)");
    if (source == -1)
    {
      std::cout << "\nAbortando conexao de vertices!!!";
      return false;
    }
    if (source < 0 || source >= MAX_NUMBER_OF_VERTICES)
    {
      counter++;
      std::cout << "\nO numero do vertice deve ser positivo e no maximo " << MAX_NUMBER_OF_VERTICES << ".";
      source = MAX_NUMBER_OF_VERTICES;
    }
  }
  counter = 0;
  int destination(MAX_NUMBER_OF_VERTICES);
  while (destination == MAX_NUMBER_OF_VERTICES)
  {
    destination = query("\nEntre o numero do vertice de destino do arco (entre -1 para cancelar)");
    if (destination == -1)
    {
      std::cout << "\nAbortando conexao de vertices!!!";
      return false;
    }
    if (destination < 0 || destination >= MAX_NUMBER_OF_VERTICES)
    {
      counter++;
      std::cout << "\nO numero do vertice deve ser positivo e no maximo " << MAX_NUMBER_OF_VERTICES << ".";
      destination = MAX_NUMBER_OF_VERTICES;
    }
  }
  return graph->disconnect(source, destination);
}
