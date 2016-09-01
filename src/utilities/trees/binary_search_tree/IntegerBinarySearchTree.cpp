#include "utilities/trees/binary_search_tree/IntegerBinarySearchTree.h"

namespace utilities
{
namespace trees
{
namespace binary_search_tree
{

bool IntegerBinarySearchTree::insert(int element)
{
  return BinarySearchTree<int, int>::insert(element, element);
}

int IntegerBinarySearchTree::sumLeafs()
{
  return sum(BinarySearchTree<int, int>::getRoot());
}

int IntegerBinarySearchTree::sum(Node<int, int> *node)
{
  int total = 0;
  if (node && node->isLeaf())
  {
    total += node->getElement();
  }
  if (node->hasLeft())
  {
    total += sum(node->getLeft());
  }
  if (node->hasRight())
  {
    total += sum(node->getRight());
  }
  return total;
}

}
}
}
