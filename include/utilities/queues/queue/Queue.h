/**
 * This header file defines the features of a generic Stack object,
 * which is based on StackInterface interface.
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

#ifndef QUEUE_H
#define QUEUE_H

#include "utilities/queues/queue/Node.h"
#include "utilities/queues/queue/QueueInterface.h"

namespace utilities
{
	namespace queues
	{
		namespace queue
		{

    template<typename Element> class Queue : public QueueInterface<Element>
    {
    public:
      Queue(const int max_size = -1);
      Queue(const Queue<Element>& queue);
      virtual ~Queue();

      virtual bool insert(Element element);
      virtual Element remove();
      virtual int size();
      virtual bool isEmpty();
      virtual std::string toString();

    private:
      int size_;
      const int max_size_;
      Node<Element> *first_, *last_;

      bool isFull();

    };

    template<typename Element> Queue<Element>::Queue(const int max_size)
      : max_size_(max_size)
    {
      size_ = 0;
      first_ = NULL;
      last_ = NULL;
    }

    template<typename Element> Queue<Element>::Queue(const Queue<Element>& queue)
      : max_size_(queue.max_size_)
    {
      size_ = queue.size_;
      first_ = NULL;
      last_ = NULL;
      if (queue.first_)
      {
        first_ = new Node<Element>(*queue.first_);
        Node<Element> *node = first_;
        while (node->hasNext())
        {
          node = node->getNext();
        }
        last_ = node;
      }

    }

    template<typename Element> Queue<Element>::~Queue()
    {
      if (!isEmpty())
      {
        last_ = NULL;
        delete first_;
      }
    }

    template<typename Element> bool Queue<Element>::insert(Element element)
    {
      if (isFull())
      {
        return false;
      }
      Node<Element>* last = new Node<Element>(element);
      if (isEmpty())
      {
        first_ = last;
      }
      else
      {
        last_->setNext(last);
      }
      last_ = last;
      ++size_;
      return true;
    }

    template<typename Element> Element Queue<Element>::remove()
    {
      Element element;
      if (!isEmpty())
      {
        Node<Element> *first = first_;
        first_ = first->getNext();
        element = first->getElement();
        first->setNext(NULL);
        delete first;
        --size_;
      }
      return element;
    }

    template<typename Element> int Queue<Element>::size()
    {
      return size_;
    }

    template<typename Element> bool Queue<Element>::isEmpty()
    {
      return !first_;
    }

    template<typename Element> bool Queue<Element>::isFull()
    {
      return max_size_ != -1 && size_ == max_size_;
    }

    template<typename Element> std::string Queue<Element>::toString()
    {
      std::string str = "(";
      Node<Element>* node;
      if (!isEmpty())
      {
        node = first_;
        str += node->toString();
        while (node->hasNext())
        {
          node = node->getNext();
          str += "," + node->toString();
        }
      }
      return str + ")";
    }

		}
	}
}

#endif // QUEUE_H
