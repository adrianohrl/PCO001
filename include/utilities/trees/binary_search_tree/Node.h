/**
 * This header file defines the BinarySearchTreeInterface interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

#include <sstream>
#include <string>

namespace utilities
{
namespace trees
{
namespace binary_search_tree
{

template<typename Key, typename Element> class Node
{
public:
  Node(Node<Key, Element> *left);
  Node(Key key, Element element, Node<Key, Element> *left = NULL, Node<Key, Element> *right = NULL);
  Node(const Node<Key, Element>& node);
  virtual ~Node();

  Node<Key, Element>* insert(Key key, Element element, Node<Key, Element> *parent);
  Node<Key, Element>* remove(Key key, Node<Key, Element> *parent = NULL);
  Element find(Key key);
  Node<Key, Element>* getLeftmost();
  Node<Key, Element>* getRightmost();
  int getHeight();
  int countElements();
  int countElement(Key key);
  int getLevel(Key key);
  bool isProper();
  bool isComplete(unsigned int tree_height, unsigned int current_level = 0);
  bool isFull(unsigned int tree_height, unsigned int current_level = 0);
  bool isUnbalanced();

  Key getKey();
  Element getElement();
  Node<Key, Element>* getLeft();
  Node<Key, Element>* getRight();
  void setLeft(Node<Key, Element> *left);
  void setRight(Node<Key, Element> *right);
  bool hasLeft();
  bool hasRight();
  bool isLeaf();
  std::string toString(); //in-order
  std::string toStringLevel(unsigned int desired_level, unsigned int current_level = 0);
  std::string prettierToString(unsigned int height = 0);
  bool operator==(Node<Key, Element> *node);
  bool operator!=(Node<Key, Element> *node);
  bool operator>(Node<Key, Element> *node);
  bool operator<(Node<Key, Element> *node);

private:
  Key key_;
  Element element_;
  Node<Key, Element> *left_, *right_;

};

template<typename Key, typename Element> Node<Key, Element>::Node(Node<Key, Element> *left)
{
  left_ = left;
  right_ = NULL;
}

template<typename Key, typename Element> Node<Key, Element>::Node(Key key, Element element, Node<Key, Element> *left, Node<Key, Element> *right)
  : key_(key),
    element_(element)
{
  left_ = left;
  right_ = right;
}

template<typename Key, typename Element> Node<Key, Element>::Node(const Node<Key, Element>& node)
  : key_(node.key_),
    element_(node.element_)
{
  left_ = NULL;
  right_ = NULL;
  if (node.left_)
  {
    left_ = new Node<Key, Element>(*node.left_);
  }
  if (node.right_)
  {
    right_ = new Node<Key, Element>(*node.right_);
  }
}

template<typename Key, typename Element> Node<Key, Element>::~Node()
{
  if (hasLeft())
  {
    delete left_;
  }
  if (hasRight())
  {
    delete right_;
  }
}

template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::insert(Key key, Element element, Node<Key, Element> *parent)
{
  if (!parent)
  {
    parent = new Node<Key, Element>(key, element);
  }
  else if (key < parent->key_)
  {
    parent->left_ = insert(key, element, parent->left_);
  }
  else
  {
    parent->right_ = insert(key, element, parent->right_);
  }
  return parent;
}

template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::remove(Key key, Node<Key, Element> *parent)
{
  if (key < key_)
  {
    return left_ ? left_->remove(key, this) : NULL;
  }
  else if (key > key_)
  {
    return right_ ? right_->remove(key, this) : NULL;
  }
  else if (left_ && right_)
  {
    Node<Key, Element> *left_rightmost = left_->getRightmost();
    key_ = left_rightmost->key_;
    element_ = left_rightmost->element_;
    return left_->remove(key_, this);
  }
  else if (parent->left_ == this)
  {
    parent->left_ = left_ ? left_ : right_;
    left_ = NULL; // Testar
    right_ = NULL; // Testar
    return this;
  }
  else if (parent->right_ == this)
  {
    parent->right_ = left_ ? left_ : right_;
    left_ = NULL; // Testar
    right_ = NULL; // Testar
    return this;
  }
  return NULL;
}

template<typename Key, typename Element> Element Node<Key, Element>::find(Key key)
{
  if (key < key_ && hasLeft())
  {
    return left_->find(key);
  }
  else if (key > key_ && hasRight())
  {
    return right_->find(key);
  }
  else if (key == key_)
  {
    return element_;
  }
  return Element();
}

template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getLeftmost()
{
  return left_ ? left_->getLeftmost() : this;
}

template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getRightmost()
{
  return right_ ? right_->getRightmost() : this;
}

template<typename Key, typename Element> int Node<Key, Element>::getHeight()
{
  int leftHeight = hasLeft() ? left_->getHeight() + 1 : 0;
  int rightHeight = hasRight() ? right_->getHeight() + 1 : 0;
  return leftHeight > rightHeight ? leftHeight : rightHeight;
}

template<typename Key, typename Element> int Node<Key, Element>::countElements()
{
  int counter = 1;
  counter += hasLeft() ? left_->countElements() : 0;
  counter += hasRight() ? right_->countElements() : 0;
  return counter;
}

template<typename Key, typename Element> int Node<Key, Element>::countElement(Key key)
{
  int counter = 0;
  if (key < key_ && hasLeft())
  {
    counter += left_->countElement(key);
  }
  else if (hasRight())
  {
    counter += right_->countElement(key);
  }
  return key == key_ ? ++counter : counter;
}

template<typename Key, typename Element> int Node<Key, Element>::getLevel(Key key)
{
  int level = -1;
  if (key < key_ && hasLeft())
  {
    level = left_->getLevel(key);
  }
  else if (key > key_ && hasRight())
  {
    level = right_->getLevel(key);
  }
  else if (key == key_)
  {
    return 0;
  }
  return level != -1 ? level + 1 : -1;
}

template<typename Key, typename Element> bool Node<Key, Element>::isProper()
{
  return isLeaf() || hasLeft() && hasRight() && left_->isProper() && right_->isProper();
}

template<typename Key, typename Element> bool Node<Key, Element>::isComplete(unsigned int tree_height, unsigned int current_level)
{
  return isProper() && (isLeaf() && (current_level == tree_height || current_level == tree_height - 1) ||
                        !isLeaf() && left_->isFull(tree_height, current_level + 1) && right_->isFull(tree_height, current_level + 1));
}

template<typename Key, typename Element> bool Node<Key, Element>::isFull(unsigned int tree_height, unsigned int current_level)
{
  return isLeaf() && current_level == tree_height ||
      !isLeaf() && hasLeft() && hasRight() && left_->isComplete(tree_height, current_level + 1) && right_->isComplete(tree_height, current_level + 1);
}

template<typename Key, typename Element> bool Node<Key, Element>::isUnbalanced()
{
  int leftDepth = hasLeft() ? left_->getHeight() + 1 : 0;
  int rightDepth = hasRight() ? right_->getHeight() + 1 : 0;
  return hasLeft() && left_->isUnbalanced() ||
      hasRight() && right_->isUnbalanced() ||
      leftDepth - rightDepth < -1 ||
      leftDepth - rightDepth > 1;
}

template<typename Key, typename Element> Key Node<Key, Element>::getKey()
{
  return key_;
}

template<typename Key, typename Element> Element Node<Key, Element>::getElement()
{
  return element_;
}

template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getLeft()
{
  return left_;
}

template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getRight()
{
  return right_;
}

template<typename Key, typename Element> void Node<Key, Element>::setLeft(Node<Key, Element> *left)
{
  left_ = left;
}

template<typename Key, typename Element> void Node<Key, Element>::setRight(Node<Key, Element> *right)
{
  right_ = right;
}

template<typename Key, typename Element> bool Node<Key, Element>::hasLeft()
{
  return left_;
}

template<typename Key, typename Element> bool Node<Key, Element>::hasRight()
{
  return right_;
}

template<typename Key, typename Element> bool Node<Key, Element>::isLeaf()
{
  return !left_ && !right_;
}

template<typename Key, typename Element> std::string Node<Key, Element>::toString()
{
  std::stringstream ss;
  if (hasLeft())
  {
    ss << left_->toString() << ",";
  }
  ss << "(" << key_ << ") " << element_;
  if (hasRight())
  {
    ss << "," << right_->toString();
  }
  return ss.str();
}

template<typename Key, typename Element> std::string Node<Key, Element>::toStringLevel(unsigned int desired_level, unsigned int current_level)
{
  if (current_level > desired_level)
  {
    return "";
  }
  std::stringstream ss;
  if (current_level == desired_level)
  {
    if (current_level > 0)
    {
      ss << ",";
    }
    ss << element_;
    return ss.str();
  }
  if (hasLeft())
  {
    ss << left_->toStringLevel(desired_level, current_level + 1);
  }
  if (hasRight())
  {
    ss << right_->toStringLevel(desired_level, current_level + 1);
  }
  return ss.str();
}

template<typename Key, typename Element> std::string Node<Key, Element>::prettierToString(unsigned int height)
{
  std::stringstream ss;
  if (hasRight())
  {
    ss << right_->prettierToString(height + 1);
  }
  for (int i = 0; i < height; i++)
  {
    ss << "     ";
  }
  ss << key_ << "\n";
  if (hasLeft())
  {
    ss << left_->prettierToString(height + 1);
  }
  return ss.str();
}

template<typename Key, typename Element> bool Node<Key, Element>::operator==(Node<Key, Element> *node)
{
  return key_ == node->key_;
}

template<typename Key, typename Element> bool Node<Key, Element>::operator!=(Node<Key, Element> *node)
{
  return key_ != node->key_;
}

template<typename Key, typename Element> bool Node<Key, Element>::operator>(Node<Key, Element> *node)
{
  return key_ > node->key_;
}

template<typename Key, typename Element> bool Node<Key, Element>::operator<(Node<Key, Element> *node)
{
  return key_ < node->key_;
}

}
}
}

#endif // BINARY_SEARCH_TREE_NODE_H
