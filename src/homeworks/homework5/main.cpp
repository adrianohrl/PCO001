/**
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/trees/binary_search_tree/IntegerBinarySearchTree.h"

#define NUMBER_OF_OPTIONS 16
#define INT_MAX 1
#define INVALID_INTEGER -3000

void printMenu();
bool process(int option);
int query(int option);

static utilities::trees::binary_search_tree::IntegerBinarySearchTree tree;

int main()
{

  int option;
  while (true)
  {
    printMenu();
    std::cin >> option;
    if (option > 0 && option <= NUMBER_OF_OPTIONS)
    {
      std::cout << "\nOption number " << option << " was selected.\n";
      if (!process(option))
      {
        break;
      }
    }
    else
    {
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(INT_MAX);
        std::cout << "\nPlease, enter an integer!!!";
      }
      else
      {
        std::cout << "\nInvalid option: " << option << "!!!";
      }
    }
  }
  /**************************************************************************************
  std::cout << "\n\nEvaluating a proper tree:" << std::endl;
  tree.insert(2);
  tree.insert(1);
  tree.insert(6);
  tree.insert(4);
  tree.insert(3);
  tree.insert(5);
  tree.insert(7); // comment this line to turn it not proper
  std::cout << std::endl << tree.prettierToString() << std::endl;
  std::cout << "It is " << (!tree.isProper() ? "NOT " : "") << "a proper tree!!!" << std::endl;


  /**************************************************************************************
  std::cout << "\n\nEvaluating a complete tree:" << std::endl;
  tree.release();
  tree.insert(6);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(3);
  tree.insert(1);
  tree.insert(10);
  tree.insert(11); // comment this line to turn it not complete
  tree.insert(8);
  tree.insert(7);
  tree.insert(9);
  std::cout << std::endl << tree.prettierToString() << std::endl;
  std::cout << "It is " << (!tree.isComplete() ? "NOT " : "") << "a complete tree!!!" << std::endl;

  /**************************************************************************************
  std::cout << "\n\nEvaluating a full tree:" << std::endl;
  tree.release();
  tree.insert(8);
  tree.insert(4);
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);
  tree.insert(6);
  tree.insert(5);
  tree.insert(7);
  tree.insert(12);
  tree.insert(10);
  tree.insert(9);
  tree.insert(11);
  tree.insert(14);
  tree.insert(13);
  tree.insert(15); // comment this line to turn it not full
  std::cout << std::endl << tree.prettierToString() << std::endl;
  std::cout << "It is " << (!tree.isFull() ? "NOT " : "") << "a full tree!!!" << std::endl;

  /**************************************************************************************
  std::cout << "\n\nEvaluating an unbalanced tree:" << std::endl;
  tree.release();
  tree.insert(6);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(3);
  tree.insert(1);
  tree.insert(10);
  //unbalanced_tree.insert(11); // uncomment this line to turn it balanced
  tree.insert(8);
  tree.insert(7);
  tree.insert(9);
  std::cout << std::endl << tree.prettierToString() << std::endl;
  std::cout << "It is a" << (tree.isUnbalanced() ? "n un" : " ") << "balanced tree!!!" << std::endl;

  /**************************************************************************************
  int n = 20;
  int keys[n] = {15, 9, 6, 9, 7, 24, 20, 18, 6, 3, 13, 2, 9, 9, 4, 17, 6, 20, 1, 2};
  tree.release();
  for (int i = 0; i < n; i++)
  {
    tree.insert(keys[i]);
  }
  std::cout << "\n\nPrinting the integer binary search tree in order: " << tree.toString() << std::endl;
  int key = 100;
  if (tree.findIteratively(key))
  {
    std::cout << "Element found." << std::endl;
  }
  else
  {
    std::cout << "Element, whose key is " << key << ", was NOT found." << std::endl;
  }

  std::cout << std::endl << tree.prettierToString() << std::endl;
  std::cout << "Sum of leaf elements: " << tree.sumLeafs() << std::endl;
  std::cout << "Tree height: " << tree.getHeight() << std::endl;
  std::cout << "Number of elements: " << tree.countElements() << std::endl;
  tree.remove(keys[n - 2]);
  std::cout << std::endl << tree.prettierToString() << std::endl;
  for (int i = 0; i < n; i++)
  {
    std::cout << "Level of " << keys[i] << ": " << tree.getLevel(keys[i]) << std::endl;
    std::cout << "Number of occurrences of " << keys[i] << ": " << tree.countElement(keys[i]) << std::endl;
  }
  std::cout << "Printing level by level: " << tree.toStringLevelByLevel() << std::endl;

  n = 7;
  int indexes[n] = {7, 2, 1, 3, 1, 3, 0};
  for (int i = 0; i < n; i++)
  {
    int index = indexes[i];
    if (tree.remove(keys[index]))
    {
      std::cout << "Removed " << keys[index] << " from the integer binary search tree." << std::endl;
      std::cout << std::endl << tree.prettierToString() << std::endl;
    }
    else
    {
      std::cout << "There is NO key whose value is " << keys[index] << " in the integer binary search tree." << std::endl;
    }
    //std::cout << "Printing the integer binary search tree in order again: " << tree.toString() << std::endl;
  }
  std::cout << "Printing the integer binary search tree in order after all: " << tree.toString() << std::endl;
  key = keys[10];
  if (tree.find(key))
  {
    std::cout << "Element found: " << key << "." << std::endl;
  }
  else
  {
    std::cout << "Element, whose key is " << key << ", was NOT found." << std::endl;
  }*/
  return EXIT_SUCCESS;
}

void printMenu()
{
  std::cout << "\n\n******************************************************************\n";
  std::cout << "* Entre o numero da opcao desejada:                                *\n";
  std::cout << "* 1) Insercao de elemento;                                         *\n";
  std::cout << "* 2) Remocao de elemento;                                          *\n";
  std::cout << "* 3) Impressao dos elementos (percurso in-ordem);                  *\n";
  std::cout << "* 4) Busca binaria iterativa;                                      *\n";
  std::cout << "* 5) Busca binaria recursiva;                                      *\n";
  std::cout << "* 6) Obtencao da altura da arvore;                                 *\n";
  std::cout << "* 7) Obtencao do numero de elementos da arvore;                    *\n";
  std::cout << "* 8) Somatorio dos elementos folha da arvore;                      *\n";
  std::cout << "* 9) Obtencao do nivel de um no arbitrario da arvore;              *\n";
  std::cout << "* 10) Classificacao da arvore: cheia, completa ou desbalanceada;   *\n";
  std::cout << "* 11) Classificacao da arvore: estritamente binaria ou nao;        *\n";
  std::cout << "* 12) Contar ocorrencias de um dado elemento;                      *\n";
  std::cout << "* 13) Imprimir elementos da arvore por nivel;                      *\n";
  std::cout << "* 14) Imprimir arvode (no formato de arvore);                      *\n";
  std::cout << "* 15) Destruicao da arvore;                                        *\n";
  std::cout << "* 16) Sair.                                                        *\n";
  std::cout << "********************************************************************\n";
  std::cout << "\nOption number: ";
}

bool process(int option)
{
  int number = INVALID_INTEGER;
  bool succeeded = true;
  if (option > 0 && option != 3 && option < 6 || option == 9 || option == 12)
  {
    number = query(option);
    if (number == INVALID_INTEGER)
    {
      return false;
    }
  }
  switch (option)
  {
    case 1:
      succeeded = tree.insert(number);
      break;
    case 2:
      succeeded = tree.remove(number);
      break;
    case 3:
      std::cout << "\n" << tree.toString() << "\n";
      break;
    case 4:
      number = tree.findIteratively(number);
      break;
    case 5:
      number = tree.find(number);
      break;
    case 6:
      std::cout << "\nAltura: " << tree.getHeight();
      break;
    case 7:
      std::cout << "\nNumero total de elementos: " << tree.countElements();
      break;
    case 8:
      std::cout << "\nSomatorio das folhas: " << tree.sumLeafs();
      break;
    case 9:
      std::cout << "\nNivel do elemento " <<  number << ": " << tree.getLevel(number);
      break;
    case 10:
      std::cout << "\nEsta arvore eh: " << (tree.isFull() ? "cheia" : (tree.isComplete() ? "completa" : (tree.isUnbalanced() ? "desbalanceada" : "ERRO")));
      break;
    case 11:
      std::cout << "\nEssa arvore " << (tree.isProper() ? "" : "nao") <<" eh estritamente binaria";
      break;
    case 12:
      std::cout << "\nO elemento " <<  number << " ocorreu: " << tree.countElement(number) << " vezes";
      break;
    case 13:
      std::cout << "\n" << tree.toStringLevelByLevel();
      break;
    case 14:
      std::cout << "\n" << tree.prettierToString();
      break;
    case 15:
      tree.release();
      break;
    default:
      std::cout << "\nInvalid option!!!";
  }
  return succeeded;
}

int query(int option)
{
  int number = INVALID_INTEGER;
  /*if (option < 1 || option == 3 || option > 5)
  {
    std::cout << "\nInvalid option";
    return number;
  }*/
  std::string name, phone_number = "", additional = "";
  std::cout << "Insira um inteiro: ";
  std::cin >> number;
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(INT_MAX);
    std::cout << "\nEntrada invalid";
    return INVALID_INTEGER;
  }
  return number;
}
