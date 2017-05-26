/**
 * This header file defines the features of a generic doubly linked
 * list object, which is based on DoublyLinkedListInterface interface.
 *
 * OBS.: The class implementation is stated in this file because it
 * make its usage easier (due to the template use).
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "utilities/lists/doubly_linked_list/doubly_linked_list_interface.h"
#include "utilities/lists/doubly_linked_list/node.h"

namespace utilities
{
	namespace lists
	{
		namespace doubly_linked_list
		{

    template<typename Element> class DoublyLinkedList : public DoublyLinkedListInterface<Element>
    {
    public:
			DoublyLinkedList();
			DoublyLinkedList(const DoublyLinkedList& list);
      virtual ~DoublyLinkedList();
			virtual void clear();
      virtual bool insert(Element element, bool from_beginning = true);
      virtual bool remove(Element element, bool from_beginning = true);
      virtual Element find(Element element, bool from_beginning = true);
      virtual bool isEmpty();
      virtual bool contains(Element element, bool from_beginning = true);
      virtual std::string toString(bool from_beginning = true);

    private:
      Node<Element> *first_, *last_;

    };

    template<typename Element> DoublyLinkedList<Element>::DoublyLinkedList()
				: first_(NULL),
					last_(NULL)
		{}

    template<typename Element> DoublyLinkedList<Element>::DoublyLinkedList(const DoublyLinkedList& list)
				: first_(NULL),
					last_(NULL)
		{
      if (list.first_)
      {
        first_ = new Node<Element>(*list.first_);
        Node<Element> *node = first_;
        while (node->hasNext())
        {
          node = node->getNext();
        }
        last_ = node;
      }
    }

    template<typename Element> DoublyLinkedList<Element>::~DoublyLinkedList()
    {
      if (!isEmpty())
      {
        last_ = NULL;
				delete first_;
				first_ = NULL;
			}
		}

		template<typename Element> void DoublyLinkedList<Element>::clear()
		{
				if (!isEmpty())
				{
					last_ = NULL;
					delete first_;
					first_ = NULL;
				}
		}

    template<typename Element> bool DoublyLinkedList<Element>::insert(Element element, bool from_beginning)
    {
      if (isEmpty())
      {
        first_ = new Node<Element>(element);
        last_ = first_;
        return true;
      }
      Node<Element> *node;
      if (from_beginning)
      {
        node = first_;
        while (node->getElement() < element && node->hasNext())
        {
          node = node->getNext();
        }
      }
      else
      {
        node = last_;
        while (node->getElement() > element && node->hasPrevious())
        {
          node = node->getPrevious();
        }
      }
      if (node->getElement() > element)
      {
        node = new Node<Element>(element, node->getPrevious(), node);
      }
      else
      {
        node = new Node<Element>(element, node, node->getNext());
      }
      if (node->hasPrevious())
      {
        node->getPrevious()->setNext(node);
      }
      else
      {
        first_ = node;
      }
      if (node->hasNext())
      {
        node->getNext()->setPrevious(node);
      }
      else
      {
        last_ = node;
      }
      return true;
    }

    template<typename Element> bool DoublyLinkedList<Element>::remove(Element element, bool from_beginning)
    {
      if (isEmpty())
      {
        return false;
      }
      Node<Element> *node;
      if (from_beginning)
      {
        node = first_;
        while (node && node->getElement() != element)
        {
          node = node->getNext();
        }
      }
      else
      {
        node = last_;
        while (node && node->getElement() != element)
        {
          node = node->getPrevious();
        }
      }
      if (!node)
      {
        return false;
      }
      if (node->hasPrevious())
      {
        node->getPrevious()->setNext(node->getNext());
      }
      else
      {
        first_ = node->getNext();
      }
      if (node->hasNext())
      {
        node->getNext()->setPrevious(node->getPrevious());
      }
      else
      {
        last_ = node->getPrevious();
      }
      node->setPrevious();
      node->setNext();
      delete node;
      return true;
    }

    template<typename Element> Element DoublyLinkedList<Element>::find(Element element, bool from_beginning)
    {
      if (isEmpty())
      {
        return element;
      }
      Node<Element> *node;
      if (from_beginning)
      {
        node = first_;
        while (node && node->getElement() != element)
        {
          node = node->getNext();
        }
      }
      else
      {
        node = last_;
        while (node && node->getElement() != element)
        {
          node = node->getPrevious();
        }
      }
      return node ? node->getElement() : element;
    }

    template<typename Element> bool DoublyLinkedList<Element>::isEmpty()
    {
      return !first_;
    }

    template<typename Element> bool DoublyLinkedList<Element>::contains(Element element, bool from_beginning)
    {
      if (isEmpty())
      {
        return false;
      }
      Node<Element> *node;
      if (from_beginning)
      {
        node = first_;
        while (node && node->getElement() != element)
        {
          node = node->getNext();
        }
      }
      else
      {
        node = last_;
        while (node && node->getElement() != element)
        {
          node = node->getPrevious();
        }
      }
      return node;
    }

    template<typename Element> std::string DoublyLinkedList<Element>::toString(bool from_beginning)
    {
      std::string str = "(";
      Node<Element> *node;
      if (!isEmpty())
      {
        if (from_beginning)
        {
          node = first_;
          str += node->toString();
          while (node->hasNext())
          {
            node = node->getNext();
            str += "," + node->toString();
          }
        }
        else
        {
          node = last_;
          str += node->toString();
          while (node->hasPrevious())
          {
            node = node->getPrevious();
            str += "," + node->toString();
          }
        }
      }
      return str + ")";
    }

		}
	}
}

#endif // DOUBLY_LINKED_LIST_H
