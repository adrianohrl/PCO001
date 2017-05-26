/**
 * This header file defines and implements a generic DisjointSet Node object.
 *
 * OBS.: The class implementation is stated in this file because it make its
 *usage
 * easier (due to the template use).
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DISJOINT_SET_NODE_H
#define DISJOINT_SET_NODE_H

#include <sstream>
#include <string>
#include <iostream>

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

namespace tags
{

enum TagEnum
{
  ELEMENT,
  SUBSET
};
}

typedef typename tags::TagEnum TagEnum;

template <typename Element> class Node
{
public:
  Node(Element element, Node<Element>* next = NULL);
  Node(Node<Element>* next = NULL, Node<Element>* subset = NULL);
  Node(const Node<Element>& node);
  virtual ~Node();

  bool insert(Element element);
  bool insert(Node<Element>* node);
  Node<Element>* remove(Element element, Node<Element>* previous = NULL);
  Node<Element>* remove(Node<Element>* node, Node<Element>* previous = NULL);
  bool find(Element element);
  bool find(Node<Element>* node);
  int calculateHeight();
  int countElements();

  Element getElement();
  Node<Element>* getSubset();
  Node<Element>* getNext();
  void setNone();
  void setElement(Element element);
  void setSubset(Node<Element>* subset);
  void setNext(Node<Element>* node);
  bool isElement() const;
  bool isSubset() const;
  bool hasNext() const;
  std::string toString(bool reversed = false) const;
  bool operator==(const Node<Element>& node);
  bool operator!=(const Node<Element>& node);

private:
  TagEnum tag_;
  union
  {
    Element* element_;
    Node<Element>* subset_;
  };
  Node<Element>* next_;

  Node<Element>* getRightmost();
};

template <typename Element>
Node<Element>::Node(Element element, Node<Element>* next)
{
  tag_ = tags::ELEMENT;
  element_ = new Element(element);
  next_ = next;
}

template <typename Element>
Node<Element>::Node(Node<Element>* next, Node<Element>* subset)
{
  tag_ = tags::SUBSET;
  subset_ = subset;
  next_ = next;
}

template <typename Element> Node<Element>::Node(const Node<Element>& node)
{
  tag_ = node.tag_;
  element_ = NULL;
  subset_ = NULL;
  next_ = NULL;
  if (isElement() && node.element_)
  {
    element_ = new Element(*node.element_);
  }
  else if (isSubset() && node.subset_)
  {
    subset_ = new Node<Element>(*node.subset_);
  }
  if (node.next_)
  {
    next_ = new Node<Element>(*node.next_);
  }
}

template <typename Element> Node<Element>::~Node()
{
  if (next_)
  {
    delete next_;
  }
  if (tag_ == tags::SUBSET)
  {
    delete subset_;
  }
  else
  {
    delete element_;
  }
}

template <typename Element> bool Node<Element>::insert(Element element)
{
  return insert(new Node<Element>(element));
}

template <typename Element> bool Node<Element>::insert(Node<Element>* node)
{
  if (!node)
  {
    return false;
  }
  if (next_)
  {
    Node<Element>* rightmost = node->getRightmost();
    rightmost->next_ = next_;
  }
  next_ = node;
  return true;
}

template <typename Element>
Node<Element>* Node<Element>::remove(Element element, Node<Element>* previous)
{
  Node<Element>* removed_node;
  if (hasNext())
  {
    removed_node = next_->remove(element, this);
    if (removed_node)
    {
      delete removed_node;
    }
  }
  if (isSubset())
  {
    removed_node = subset_->remove(element, this);
    if (removed_node)
    {
      delete removed_node;
    }
  }
  if (isElement() && *element_ == element || isSubset() && !subset_)
  {
    if (previous)
    {
      if (previous->isSubset() && this == previous->subset_)
      {
        previous->subset_ = next_;
      }
      else
      {
        previous->next_ = next_;
      }
      next_ = NULL;
    }
    return this;
  }
  return NULL;
}

// testar essa funcao
template <typename Element>
Node<Element>* Node<Element>::remove(Node<Element>* node,
                                     Node<Element>* previous)
{
  Node<Element>* removed_node;
  if (hasNext())
  {
    removed_node = next_->remove(node, this);
    if (removed_node)
    {
      delete removed_node;
    }
  }
  if (isSubset())
  {
    removed_node = subset_->remove(node, this);
    if (removed_node)
    {
      delete removed_node;
    }
  }
  if (*this == *node || isSubset() && !subset_) ///// talvez isso vai dar pau
  {
    if (previous)
    {
      if (previous->isSubset() && this == previous->subset_)
      {
        previous->subset_ = next_;
      }
      else
      {
        previous->next_ = next_;
      }
      next_ = NULL;
    }
    return this;
  }
  return NULL;
}

template <typename Element> bool Node<Element>::find(Element element)
{
  return isElement() && *element_ == element ||
         isSubset() && subset_->find(element) ||
         hasNext() && next_->find(element);
}

template <typename Element> bool Node<Element>::find(Node<Element>* node)
{
  return node && *this == *node || isSubset() && subset_->find(node) ||
         hasNext() && next_->find(node);
}

template <typename Element> Node<Element>* Node<Element>::getRightmost()
{
  if (!next_)
  {
    return this;
  }
  return next_->getRightmost();
}

template <typename Element> int Node<Element>::calculateHeight()
{
  int height = 1;
  if (isSubset())
  {
    height += subset_->calculateHeight();
  }
  if (hasNext())
  {
    int next_height = next_->calculateHeight();
    if (next_height > height)
    {
      height = next_height;
    }
  }
  return height;
}

template <typename Element> int Node<Element>::countElements()
{
  int counter = 0;
  if (isElement())
  {
    counter++;
  }
  else if (isSubset())
  {
    counter += subset_->countElements();
  }
  if (hasNext())
  {
    counter += next_->countElements();
  }
  return counter;
}

template <typename Element> Element Node<Element>::getElement()
{
  return *element_;
}

template <typename Element> Node<Element>* Node<Element>::getSubset()
{
  return subset_;
}

template <typename Element> Node<Element>* Node<Element>::getNext()
{
  return next_;
}

template <typename Element> void Node<Element>::setElement(Element element)
{
  tag_ = tags::ELEMENT;
  element_ = new Element(element);
}

template <typename Element> void Node<Element>::setSubset(Node<Element>* subset)
{
  tag_ = tags::SUBSET;
  subset_ = subset;
}

template <typename Element> void Node<Element>::setNext(Node<Element>* node)
{
  next_ = node;
}

template <typename Element> bool Node<Element>::isElement() const
{
  return tag_ == tags::ELEMENT;
}

template <typename Element> bool Node<Element>::isSubset() const
{
  return tag_ == tags::SUBSET;
}

template <typename Element> bool Node<Element>::hasNext() const
{
  return next_;
}

template <typename Element>
std::string Node<Element>::toString(bool reversed) const
{
  std::stringstream ss;
  if (reversed && hasNext())
  {
    ss << next_->toString(reversed) << ",";
  }
  if (isElement() && element_)
  {
    ss << *element_;
  }
  else if (isSubset())
  {
    ss << "(" << (subset_ ? subset_->toString(reversed) : "") << ")";
  }
  if (!reversed && hasNext())
  {
    ss << "," << next_->toString(reversed);
  }
  return ss.str();
}

template <typename Element>
bool Node<Element>::operator==(const Node<Element>& node)
{
  return tag_ == node.tag_ &&
         (node.isElement() && *element_ == *node.element_ ||
          node.isSubset() && *subset_ == *node.subset_) &&
         (!node.hasNext() || hasNext() && *next_ == *node.next_);
}

template <typename Element>
bool Node<Element>::operator!=(const Node<Element>& node)
{
  return !operator==(node);
}
}
}
}

#endif // DISJOINT_SET_NODE_H
