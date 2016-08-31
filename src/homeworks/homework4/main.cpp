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
#include "homeworks/homework4/IntegerDisjointSets.h"
#include "utilities/queues/queue/Queue.h"

using typename homeworks::homework4::IntegerDisjointSets;
using typename homeworks::homework4::IntegerDisjointSetEnum;
using typename utilities::queues::queue::Queue;

std::string report(IntegerDisjointSets sets, Queue<std::string> expression_queue);
std::string report(IntegerDisjointSets sets, Queue<std::string> expression_queue, IntegerDisjointSetEnum set);

int main()
{
  Queue<IntegerDisjointSets> set_queue;
  set_queue.insert(IntegerDisjointSets("(1,(2,0),0,0,(2,3),0,(((0,0)),0))", "((1),(2,(0,(0,3,0),0),4),0,5,6)")); // not equals
  set_queue.insert(IntegerDisjointSets("(1,0,((10,(0,0)),0))", "(1,0,(((0,0),0),0))")); // not equals
  set_queue.insert(IntegerDisjointSets("(0,(0,(0,3,0),0,4,0),0,5)", "(1,2,3,(4,(5,((6)))))")); // equals
  set_queue.insert(IntegerDisjointSets("(0,((2,3),3),0,4)", "(1,2,3,(4,(5,((6)))))")); // equals
  set_queue.insert(IntegerDisjointSets("(((2,3),1),0,4)", "(1,2,3,(4,(5,((6,((2,3),1))))))")); // equals
  set_queue.insert(IntegerDisjointSets("((1,2,3))", "((1,2,3))")); // not equals
  set_queue.insert(IntegerDisjointSets("(1,(2),3)", "(1,(2),3,(2,3),((1)))")); // equals
  Queue<std::string> expression_queue;
  expression_queue.insert("((2,3),1)");
  expression_queue.insert("(2,3)");
  expression_queue.insert("1");
  expression_queue.insert("(0)");
  while (!set_queue.isEmpty())
  {
    std::cout << std::endl << report(set_queue.remove(), expression_queue) << std::endl;
    std::cout << std::endl << "--------------------------------" << std::endl;
  }
	return EXIT_SUCCESS;
}

std::string report(IntegerDisjointSets sets, Queue<std::string> expression_queue)
{
  std::stringstream ss;
  ss << report(sets, expression_queue, homeworks::homework4::sets::A);
  ss << report(sets, expression_queue, homeworks::homework4::sets::B);
  if (sets.compareDisjointSets())
  {
    ss << "\nThe disjoint set A is equal to the B one.\n";
  }
  else
  {
    ss << "\nThe disjoint set A is NOT equal to the B one.\n";
  }
  return ss.str();
}

std::string report(IntegerDisjointSets sets, Queue<std::string> expression_queue, IntegerDisjointSetEnum set)
{
  std::stringstream ss;
  ss << "\nDisjoin Set " << (set == 0 ? "A" : "B") << ": " << sets.toString(set) << "\n";
  ss << "\n\tSum of elements: " << sets.sumNodes(set) << "\n";
  ss << "\n\tHeight: " << sets.calculateHeight(set) << "\n";
  ss << "\n\tNumber of elements: " << sets.countElements(set) << "\n";
  ss << "\n\tReversed: " << sets.toStringReversed(set) << "\n";
  if (sets.removeZeros(set))
  {
    ss << "\n\tRemoved found zeros: " << sets.toString(set) << "\n";
  }
  else
  {
    ss << "\n\tNone zero was found!!!";
  }
  ss << "\n\tFinding elements and subsets:\n";
  while (!expression_queue.isEmpty())
  {
    std::string expression(expression_queue.remove());
    ss << "\n\t\t" << expression << ": " << (!sets.find(set, expression) ? "NOT " : "") << "found!!!";
  }
  return ss.str() + "\n";
}
