/**
 * This source file implements a main function in order to test the
 * functionalities of the created BinarySearchTree class.
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

int main()
{
  utilities::trees::binary_search_tree::IntegerBinarySearchTree tree;
  /**************************************************************************************/
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


  /**************************************************************************************/
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

  /**************************************************************************************/
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

  /**************************************************************************************/
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

  /**************************************************************************************/
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
  std::cout << "Sum of leaf elements: " << tree.sumLeaves() << std::endl;
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
  }
	return EXIT_SUCCESS;
}
