/**
 * This header file defines the BinarySearchTreeInterface interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "utilities/trees/binary_search_tree/node.h"
#include "utilities/trees/binary_search_tree/binary_search_tree_interface.h"

namespace utilities
{
namespace trees
{
namespace binary_search_tree
{

namespace classifications
{

enum TreeClassificationEnum
{
  FULL,
  COMPLETE,
  UNBALANCED
};

}

typedef typename classifications::TreeClassificationEnum TreeClassificationEnum;

template<typename Key, typename Element> class BinarySearchTree : public BinarySearchTreeInterface<Key, Element>
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& tree);
  virtual ~BinarySearchTree();

  virtual bool insert(Key key, Element element);
  virtual bool insert(BinarySearchTree<Key, Element>* tree);
  virtual bool remove(Key key);
  virtual Element find(Key key);
  virtual void release();
  Element findIteratively(Key key);
  int getHeight();
  int countElements();
  int countElement(Key key);
  int getLevel(Key key);
  TreeClassificationEnum classify();
  bool isProper();
  bool isComplete();
  bool isFull();
  bool isUnbalanced();
  bool isEmpty();
  virtual std::string toString(); //in-order
  std::string toStringLevelByLevel();
  std::string prettierToString();
  bool operator<(const BinarySearchTree<Key, Element> &tree) const;
  bool operator<=(const BinarySearchTree<Key, Element> &tree) const;
  bool operator==(const BinarySearchTree<Key, Element> &tree) const;
  bool operator!=(const BinarySearchTree<Key, Element> &tree) const;
  bool operator>=(const BinarySearchTree<Key, Element> &tree) const;
  bool operator>(const BinarySearchTree<Key, Element> &tree) const;

//protected:
  Node<Key, Element>* getRoot();

private:
  Node<Key, Element> *root_;

};

template<typename Key, typename Element> BinarySearchTree<Key, Element>::BinarySearchTree()
{
  root_ = NULL;
}

template<typename Key, typename Element> BinarySearchTree<Key, Element>::BinarySearchTree(const BinarySearchTree& tree)
{
  root_ = NULL;
  if (tree.root_)
  {
    root_ = new Node<Key, Element>(*tree.root_);
  }
}

template<typename Key, typename Element> BinarySearchTree<Key, Element>::~BinarySearchTree()
{
  if (!isEmpty())
  {
    delete root_;
  }
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::insert(Key key, Element element)
{
  if (isEmpty())
  {
    root_ = new Node<Key, Element>(key, element);
  }
  else
  {
    root_ = root_->insert(key, element, root_);
  }
  return root_;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::insert(BinarySearchTree<Key, Element> *tree)
{
    if (isEmpty())
    {
        root_ = new Node<Key, Element>(*tree->root_);
    }
    else
    {
        root_ = root_->insert(tree->root_, root_);
    }
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::remove(Key key)
{
  if (isEmpty())
  {
    return false;
  }
  Node<Key, Element> *removed_node;
  if (root_->getKey() == key)
  {
    Node<Key, Element> aux(*root_);
    removed_node = root_->remove(key, &aux);
  }
  else
  {
    removed_node = root_->remove(key);
  }
  if (!removed_node)
  {
    return false;
  }
  //removed_node->setLeft(NULL);
  //removed_node->setRight(NULL);
  delete removed_node;
  return true;
}

template<typename Key, typename Element> Element BinarySearchTree<Key, Element>::find(Key key)
{
  return !isEmpty() ? root_->find(key) : Element();
}

template<typename Key, typename Element> void BinarySearchTree<Key, Element>::release()
{
  if (root_)
  {
    delete root_;
    root_ = NULL;
  }
}

template<typename Key, typename Element> Element BinarySearchTree<Key, Element>::findIteratively(Key key)
{
  if (isEmpty())
  {
    return Element();
  }
  Node<Key, Element> *node = root_;
  while (node->hasLeft() && key < node->getKey())
  {
    node = node->getLeft();
  }
  while (node->hasRight() && key > node->getKey())
  {
    node = node->getRight();
  }
  if (key == node->getKey())
  {
    return node->getElement();
  }
  return Element();
}

template<typename Key, typename Element> int BinarySearchTree<Key, Element>::getHeight()
{
  return root_->getHeight();
}

template<typename Key, typename Element> int BinarySearchTree<Key, Element>::countElements()
{
  return root_->countElements();
}

template<typename Key, typename Element> int BinarySearchTree<Key, Element>::countElement(Key key)
{
  return root_->countElement(key);
}

template<typename Key, typename Element> int BinarySearchTree<Key, Element>::getLevel(Key key)
{
  return root_->getLevel(key);
}

template<typename Key, typename Element> TreeClassificationEnum BinarySearchTree<Key, Element>::classify()
{
  TreeClassificationEnum classification;
  if (isFull())
  {
    classification = classifications::FULL;
  }
  else if (isComplete())
  {
    classification = classifications::COMPLETE;
  }
  else if (isUnbalanced())
  {
    classification = classifications::UNBALANCED;
  }
  return classification;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::isProper()
{
  return root_->isProper();
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::isFull()
{
  return isProper() && root_->isFull(getHeight());
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::isComplete()
{
  return root_->isComplete(getHeight());
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::isUnbalanced()
{
  return root_->isUnbalanced();
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::isEmpty()
{
  return !root_;
}

template<typename Key, typename Element> std::string BinarySearchTree<Key, Element>::toString()
{
  return !isEmpty() ? "(" + root_->toString() + ")" : "";
}

template<typename Key, typename Element> std::string BinarySearchTree<Key, Element>::toStringLevelByLevel()
{
  std::stringstream ss;
  int height = getHeight();
  for (int level = 0; level <= height; level++)
  {
    ss << root_->toStringLevel(level);
  }
  return "(" + ss.str() + ")";
}

template<typename Key, typename Element> std::string BinarySearchTree<Key, Element>::prettierToString()
{
    return root_->prettierToString();
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::operator<(const BinarySearchTree<Key, Element> &tree) const
{
    return root_ < tree.root_;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::operator<=(const BinarySearchTree<Key, Element> &tree) const
{
    return root_ <= tree.root_;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::operator==(const BinarySearchTree<Key, Element> &tree) const
{
    return root_ == tree.root_;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::operator!=(const BinarySearchTree<Key, Element> &tree) const
{
    return root_ != tree.root_;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::operator>=(const BinarySearchTree<Key, Element> &tree) const
{
    return root_ >= tree.root_;
}

template<typename Key, typename Element> bool BinarySearchTree<Key, Element>::operator>(const BinarySearchTree<Key, Element> &tree) const
{
    return root_ > tree.root_;
}

template<typename Key, typename Element> Node<Key, Element>* BinarySearchTree<Key, Element>::getRoot()
{
  return root_;
}

}
}
}

#endif // BINARY_SEARCH_TREE_H
