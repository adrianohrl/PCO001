/**
 * This header file defines and implements a generic DisjointSet object.
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

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include "utilities/lists/disjoint_set/disjoint_set_interface.h"
#include "utilities/lists/disjoint_set/node.h"
#include "utilities/lists/disjoint_set/expression_parser.h"
#include "utilities/stacks/stack/stack.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

template <typename Element>
class DisjointSet : public DisjointSetInterface<Element>
{
public:
  DisjointSet(const DisjointSet<Element>& ds);
  virtual ~DisjointSet();

  virtual bool insert(Element element);
  virtual bool insert(const char* expression);
  virtual bool remove(Element element);
  virtual bool remove(const char* expression);
  virtual bool find(Element element);
  virtual bool find(const char* expression);
  int calculateHeight();
  int countElements();
  virtual bool isEmpty();
  virtual std::string toString(bool reversed = false) const;
  virtual bool operator==(const DisjointSet& set);
  virtual bool operator!=(const DisjointSet& set);

protected:
  DisjointSet(ExpressionParser<Element>* parser, std::string expression = "");
  virtual bool insert(Node<Element>* node);
  virtual bool remove(Node<Element>* node);
  virtual bool find(Node<Element>* node);
  Node<Element>* getRoot();

private:
  Node<Element>* root_, *node_;
  ExpressionParser<Element>* parser_;
};

template <typename Element>
DisjointSet<Element>::DisjointSet(ExpressionParser<Element>* parser,
                                  std::string expression)
    : node_(NULL), root_(NULL), parser_(parser)
{
  if (expression == "")
  {
    return;
  }
  root_ = parser_->parse(expression);
  node_ = root_;
}

template <typename Element>
DisjointSet<Element>::DisjointSet(const DisjointSet<Element>& set)
    : node_(NULL), root_(NULL), parser_(set.parser_)
{
  if (set.root_)
  {
    root_ = new Node<Element>(*set.root_);
    node_ = root_;
  }
}

template <typename Element> DisjointSet<Element>::~DisjointSet()
{
  if (!isEmpty())
  {
    node_ = NULL;
    delete root_;
    root_ = NULL;
  }
  if (parser_)
  {
    delete parser_;
    parser_ = NULL;
  }
}

template <typename Element> bool DisjointSet<Element>::insert(Element element)
{
  if (isEmpty())
  {
    node_ = new Node<Element>(element);
    root_ = node_;
    return true;
  }
  return node_->insert(element);
}

template <typename Element>
bool DisjointSet<Element>::insert(const char* expression)
{
  if (!parser_->evaluate(std::string(expression)))
  {
    return false;
  }
  return DisjointSet<Element>::insert(parser_->parse(std::string(expression)));
}

template <typename Element>
bool DisjointSet<Element>::insert(Node<Element>* node)
{
  if (!node)
  {
    return false;
  }
  if (isEmpty())
  {
    node_ = node;
    root_ = node_;
    return true;
  }
  return node_->insert(node);
}

template <typename Element> bool DisjointSet<Element>::remove(Element element)
{
  if (isEmpty() || !find(element))
  {
    return false;
  }
  Node<Element>* removed_node = root_->remove(element);
  while (!isEmpty() && removed_node)
  {
    root_ = removed_node->getNext();
    removed_node->setNext(NULL);
    delete removed_node;
    removed_node = root_->remove(element);
  }
  return true;
}

template <typename Element>
bool DisjointSet<Element>::remove(const char* expression)
{
  if (!parser_->evaluate(expression))
  {
    return false;
  }
  return DisjointSet<Element>::remove(parser_->parse(expression));
}

template <typename Element>
bool DisjointSet<Element>::remove(Node<Element>* node)
{
  if (isEmpty() || !find(node))
  {
    return false;
  }
  Node<Element>* removed_node = root_->remove(node);
  if (removed_node)
  {
    root_ = removed_node->getNext();
    removed_node->setNext(NULL);
    delete removed_node;
  }
  return true;
}

template <typename Element> bool DisjointSet<Element>::find(Element element)
{
  return !isEmpty() && root_->find(element);
}

template <typename Element>
bool DisjointSet<Element>::find(const char* expression)
{
  if (!parser_->evaluate(expression))
  {
    return false;
  }
  return DisjointSet<Element>::find(parser_->parse(expression));
}

template <typename Element> bool DisjointSet<Element>::find(Node<Element>* node)
{
  return !isEmpty() && root_->find(node);
}

template <typename Element> int DisjointSet<Element>::calculateHeight()
{
  return !isEmpty() ? root_->calculateHeight() : 0;
}

template <typename Element> int DisjointSet<Element>::countElements()
{
  return !isEmpty() ? root_->countElements() : 0;
}

template <typename Element> Node<Element>* DisjointSet<Element>::getRoot()
{
  return root_;
}

template <typename Element> bool DisjointSet<Element>::isEmpty()
{
  return !root_;
}

template <typename Element>
std::string DisjointSet<Element>::toString(bool reversed) const
{
  return root_ ? "(" + root_->toString(reversed) + ")" : "()";
}

template <typename Element>
bool DisjointSet<Element>::operator==(const DisjointSet& set)
{
  return root_ == set.root_;
}

template <typename Element>
bool DisjointSet<Element>::operator!=(const DisjointSet& set)
{
  return root_ != set.root_;
}
}
}
}

#endif // DISJOINT_SET_H
