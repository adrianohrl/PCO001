/**
 * This header file defines and implements a generic Stack Node object.
 *
 * OBS.: The class implementation is stated in this file because it make its usage
 * easier (due to the template use).
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H

#include <sstream>
#include <string>

namespace utilities
{
	namespace lists
	{
		namespace doubly_linked_list
		{

    template<typename Element> class Node
    {
    public:
      Node(Element element, Node<Element>* previous = NULL, Node<Element>* next = NULL);
      Node(const Node<Element>& node);
      virtual ~Node();

      Element getElement();
      Node<Element>* getPrevious();
      Node<Element>* getNext();
      void setPrevious(Node<Element>* previous = NULL);
      void setNext(Node<Element>* next = NULL);
      bool hasPrevious();
      bool hasNext();
      std::string toString();

    private:
      Element element_;
      Node<Element> *previous_, *next_;

    };

    template<typename Element> Node<Element>::Node(Element element, Node<Element>* previous, Node<Element>* next)
      : element_(element)
    {
      previous_ = previous;
      next_ = next;
    }

    template<typename Element> Node<Element>::Node(const Node<Element>& node)
      : element_(node.element_)
    {
      previous_ = NULL;
      next_ = NULL;
      if (node.next_)
      {
        next_ = new Node<Element>(*node.next_);
        next_->previous_ = this;
      }
    }

    template<typename Element> Node<Element>::~Node()
    {
      previous_ = NULL;
      if (next_)
      {
        delete next_;
      }
    }

    template<typename Element> Element Node<Element>::getElement()
    {
      return element_;
    }

    template<typename Element> Node<Element>* Node<Element>::getPrevious()
    {
      return previous_;
    }

    template<typename Element> Node<Element>* Node<Element>::getNext()
    {
      return next_;
    }

    template<typename Element> void Node<Element>::setPrevious(Node<Element>* previous)
    {
      previous_ = previous;
    }

    template<typename Element> void Node<Element>::setNext(Node<Element>* next)
    {
      next_ = next;
    }

    template<typename Element> bool Node<Element>::hasPrevious()
    {
      return previous_;
    }

    template<typename Element> bool Node<Element>::hasNext()
    {
      return next_;
    }

    template<typename Element> std::string Node<Element>::toString()
    {
      std::stringstream ss;
      ss << element_;
      return ss.str();
    }

		}
	}
}

#endif // DOUBLY_LINKED_LIST_NODE_H
