/**
 * This header file defines and implements a generic DoubleStack Node object.
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

#ifndef DOUBLE_STACK_NODE_H
#define DOUBLE_STACK_NODE_H

#include <sstream>
#include <string>

namespace utilities
{
	namespace stacks
	{
		namespace double_stack
		{

    template<typename Element> class Node
    {
    public:
      Node();
      Node(Element element, int previous);
      Node(const Node<Element>& node);
      virtual ~Node();

      Element getElement();
      int getPrevious();
      void set(Element element, int previous);
      std::string toString();
      void operator=(Node<Element> *node);

    private:
      Element element_;
      int previous_;

    };

    template<typename Element> Node<Element>::Node()
    {
      previous_ = -100;
    }

    template<typename Element> Node<Element>::Node(Element element, int previous)
      : element_(element)
    {
      previous_ = previous;
    }

    template<typename Element> Node<Element>::Node(const Node<Element>& node)
      : element_(node.element_)
    {
      previous_ = node.previous_;
    }

    template<typename Element> Node<Element>::~Node()
    {
    }

    template<typename Element> Element Node<Element>::getElement()
    {
      return element_;
    }

    template<typename Element> int Node<Element>::getPrevious()
    {
      return previous_;
    }

    template<typename Element> void Node<Element>::set(Element element, int previous)
    {
      element_ = element;
      previous_ = previous;
    }

    template<typename Element> std::string Node<Element>::toString()
    {
      std::stringstream ss;
      ss << element_;
      return ss.str();
    }

    template<typename Element> void Node<Element>::operator=(Node<Element> *node)
    {
      element_ = node->element_;
      previous_ = node->previous_;
    }

		}
	}
}

#endif // DOUBLE_STACK_NODE_H
