/**
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "homeworks/homework9/HighwayMap.h"

#define NUMBER_OF_OPTIONS 16
#define INT_MAX 1
#define INVALID_INTEGER -32768

using namespace homeworks::homework9;

/*void printMenu();
bool process(int option);
int query(int option);*/

int main()
{
  try
  {
    HighwayMap map("../../map.txt");
    std::cout << map.str();
  }
  catch (utilities::Exception& e)
  {
    std::cout << "\nException catched: " << e.what();
  }
  std::cout << "\n";

  /*int option;
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
  }*/
  return EXIT_SUCCESS;
}
/*
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
      std::cout << "\nSomatorio das folhas: " << tree.sumLeaves();
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
  /*std::cout << "Insira um inteiro: ";
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
*/
