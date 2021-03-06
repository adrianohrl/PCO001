#ifndef INTEGER_BINARY_SEARCH_TREE_H
#define INTEGER_BINARY_SEARCH_TREE_H

#include "utilities/trees/binary_search_tree/binary_search_tree.h"

namespace utilities
{
namespace trees
{
namespace binary_search_tree
{

class IntegerBinarySearchTree : public BinarySearchTree<int, int>
{
public:
  int sumLeaves();
  bool insert(int element);

private:
  int sum(Node<int, int>* node);
};

}
}
}

#endif // INTEGER_BINARY_SEARCH_TREE_H
