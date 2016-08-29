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
#include "utilities/lists/disjoint_set/StringDisjointSet.h"

using typename utilities::lists::disjoint_set::StringDisjointSet;

int main()
{
  std::cout << std::endl << "Testing StringDisjointSet class:" << std::endl;
	std::string input_str = "(ae,(b32,(c4,d),145,2vtrr,(e4dr,fs23,((((gs23es)),(h23se),i)),jws,k23e),(s2el)))";
  std::cout << "Trying to build: " << input_str << std::endl;
  StringDisjointSet sds;
  sds.insert(input_str);
  std::cout << "sds = " << sds.toString() << std::endl;
	return EXIT_SUCCESS;
}
