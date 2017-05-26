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

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include <sstream>
#include <string>

namespace utilities
{
	namespace queues
	{
		namespace queue
		{

    template<typename Element> class Node
    {
    public:
      Node(Element element);
      Node(const Node<Element>& node);
      virtual ~Node();

      Element getElement();
      Node<Element>* getNext();
      void setNext(Node<Element> *next);
      bool hasNext();
      std::string toString();

    private:
      Element element_;
      Node<Element> *next_;

    };

    template<typename Element> Node<Element>::Node(Element element)
      : element_(element)
    {
      next_ = NULL;
    }

    template<typename Element> Node<Element>::Node(const Node<Element>& node)
      : element_(node.element_)
    {
      next_ = NULL;
      if (node.next_)
      {
        next_ = new Node<Element>(*node.next_);
      }
    }

    template<typename Element> Node<Element>::~Node()
    {
      if (next_)
      {
        delete next_;
      }
    }

    template<typename Element> Element Node<Element>::getElement()
    {
      return element_;
    }

    template<typename Element> Node<Element>* Node<Element>::getNext()
    {
      return next_;
    }

    template<typename Element> void Node<Element>::setNext(Node<Element> *next)
    {
      next_ = next;
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

#endif // QUEUE_NODE_H
