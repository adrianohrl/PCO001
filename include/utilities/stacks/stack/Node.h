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

#ifndef STACK_NODE_H
#define STACK_NODE_H

#include <sstream>
#include <string>

namespace utilities
{
	namespace stacks
	{
		namespace stack
		{

    template<typename Element> class Node
    {
    public:
      Node(Element element, Node<Element>* previous = NULL);
      Node(const Node<Element>& node);
      virtual ~Node();

      Element getElement();
      Node<Element>* getPrevious();
      void setPreviousToNull();
      bool hasPrevious();
      std::string toString();

    private:
      Element element_;
      Node<Element> *previous_;

    };

    template<typename Element> Node<Element>::Node(Element element, Node<Element>* previous)
      : element_(element)
    {
      previous_ = previous;
    }

    template<typename Element> Node<Element>::Node(const Node<Element>& node)
      : element_(node.element_)
    {
      previous_ = NULL;
      if (node.previous_)
      {
        previous_ = new Node<Element>(*node.previous_);
      }
    }

    template<typename Element> Node<Element>::~Node()
    {
      if (previous_)
      {
        delete previous_;
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

    template<typename Element> void Node<Element>::setPreviousToNull()
    {
      previous_ = NULL;
    }

    template<typename Element> bool Node<Element>::hasPrevious()
    {
      return previous_;
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

#endif // STACK_NODE_H
