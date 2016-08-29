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

#ifndef STACK_H
#define STACK_H

#include "utilities/stacks/stack/Node.h"
#include "utilities/stacks/stack/StackInterface.h"

namespace utilities
{
	namespace stacks
	{
		namespace stack
		{

			template<typename Element> class Stack : public StackInterface<Element>
			{
			public:
				Stack(const int max_size = -1);
				virtual ~Stack();

				virtual bool push(Element element);
				virtual Element pop();
				virtual Element top();
				virtual bool isEmpty();
				virtual std::string toString();

			private:
				unsigned int size_;
				const int max_size_;
				Node<Element> *top_;

				bool isFull();

			};

			template<typename Element> Stack<Element>::Stack(const int max_size)
				: max_size_(max_size)
			{
				size_ = 0;
				top_ = NULL;
			}

			template<typename Element> Stack<Element>::~Stack()
			{
				if (!isEmpty())
				{
					delete top_;
				}
			}

			template<typename Element> bool Stack<Element>::push(Element element)
			{
				if (isFull())
				{
					return false;
				}
				top_ = new Node<Element>(element, top_);
				++size_;
				return true;
			}

			template<typename Element> Element Stack<Element>::pop()
			{
				Element element;
				if (!isEmpty())
				{
					Node<Element> *top = top_;
					top_ = top->getPrevious();
					element = top->getElement();
					top->setPreviousToNull();
					delete top;
					--size_;
				}
				return element;
			}

			template<typename Element> Element Stack<Element>::top()
			{
				Element element;
				if (!isEmpty())
				{
					element = top_->getElement();
				}
				return element;
			}

			template<typename Element> bool Stack<Element>::isEmpty()
			{
				return !top_;
			}

			template<typename Element> bool Stack<Element>::isFull()
			{
				return max_size_ != -1 && size_ == max_size_;
			}

			template<typename Element> std::string Stack<Element>::toString()
			{
				std::string str = "(";
				if (!isEmpty())
				{
					Node<Element>* node = top_;
					str += node->toString();
					while (node->hasPrevious())
					{
						node = node->getPrevious();
						str += "," + node->toString();
					}
				}
				return str + ")";
			}

		}
	}
}

#endif // STACK_H
