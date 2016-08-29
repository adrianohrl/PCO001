/**
 * This header file defines the features of a generic DoubleStack object,
 * which is based on DoubleStackInterface interface.
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

#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H

#include <iostream>
#include "utilities/stacks/double_stack/Node.h"
#include "utilities/stacks/double_stack/DoubleStackInterface.h"

namespace utilities
{
	namespace stacks
	{
		namespace double_stack
		{

			template<typename Element> class DoubleStack : public DoubleStackInterface<Element>
			{
			public:
				DoubleStack(const unsigned int max_size);
				virtual ~DoubleStack();

				virtual bool pushToA(Element element);
				virtual bool pushToB(Element element);
				virtual Element popFromA();
				virtual Element popFromB();
				virtual Element topOfA();
				virtual Element topOfB();
				virtual bool isAEmpty();
				virtual bool isBEmpty();
				virtual std::string toStringA();
				virtual std::string toStringB();
				virtual std::string toStringAInOrder();
				virtual std::string toStringBInOrder();

			private:
				const unsigned int max_size_;
				int top_A_, top_B_;
				Node<Element> *vector_;

				bool isFull();
				std::string toString(int index);

			};

			template<typename Element> DoubleStack<Element>::DoubleStack(const unsigned int max_size)
				: max_size_(max_size)
			{
				top_A_ = -1;
				top_B_ = max_size_;
				vector_ = new Node<Element>[max_size_];
			}

			template<typename Element> DoubleStack<Element>::~DoubleStack()
			{
				delete[] vector_;
			}

			template<typename Element> bool DoubleStack<Element>::pushToA(Element element)
			{
				if (isFull())
				{
					return false;
				}
				vector_[top_A_].set(element, top_A_++);
				return true;
			}

			template<typename Element> bool DoubleStack<Element>::pushToB(Element element)
			{
				if (isFull())
				{
					return false;
				}
				vector_[top_B_].set(element, top_B_--);
				return true;
			}

			template<typename Element> Element DoubleStack<Element>::popFromA()
			{
				Element element;
				if (!isAEmpty())
				{
					element = vector_[top_A_].getElement();
					top_A_ = vector_[top_A_].getPrevious();
				}
				return element;
			}

			template<typename Element> Element DoubleStack<Element>::popFromB()
			{
				Element element;
				if (!isBEmpty())
				{
					element = vector_[top_B_].getElement();
					top_B_ = vector_[top_B_].getPrevious();
				}
				return element;
			}

			template<typename Element> Element DoubleStack<Element>::topOfA()
			{
				Element element;
				if (!isAEmpty())
				{
					element = vector_[top_A_].getElement();
				}
				return element;
			}

			template<typename Element> Element DoubleStack<Element>::topOfB()
			{
				Element element;
				if (!isBEmpty())
				{
					element = vector_[top_B_].getElement();
				}
				return element;
			}

			template<typename Element> bool DoubleStack<Element>::isAEmpty()
			{
				return top_A_ == -1;
			}

			template<typename Element> bool DoubleStack<Element>::isBEmpty()
			{
				return top_B_ == max_size_;
			}

			template<typename Element> bool DoubleStack<Element>::isFull()
			{
				return top_B_ - top_A_ == 1;
			}

			template<typename Element> std::string DoubleStack<Element>::toString(int index)
			{
				std::string str = "";
				while (index != -1 && index != max_size_)
				{
					str += vector_[index].toString();
					index = vector_[index].getPrevious();
					if (index != -1 && index != max_size_)
					{
						str += ",";
					}
				}
				return str;
			}

			template<typename Element> std::string DoubleStack<Element>::toStringA()
			{
				return "(" + (!isAEmpty() ? toString(top_A_) : "") + ")";
			}

			template<typename Element> std::string DoubleStack<Element>::toStringB()
			{
				return "(" + (!isBEmpty() ? toString(top_B_) : "") + ")";
			}

			template<typename Element> std::string DoubleStack<Element>::toStringAInOrder()
			{
				std::stringstream ss ;
				ss << "(";
				int top = top_A_;
				while (!isAEmpty())
				{
					pushToB(popFromA());
				}
				while (top != top_A_)
				{
					ss << topOfB();
					pushToA(popFromB());
					ss << (top != top_A_ ? "," : "");
				}
				ss << ")";
				return ss.str();
			}

			template<typename Element> std::string DoubleStack<Element>::toStringBInOrder()
			{
				std::stringstream ss ;
				ss << "(";
				int top = top_B_;
				while (!isBEmpty())
				{
					pushToA(popFromB());
				}
				while (top != top_B_)
				{
					ss << topOfA();
					pushToB(popFromA());
					ss << (top != top_B_ ? "," : "");
				}
				ss << ")";
				return ss.str();
			}

		}
	}
}

#endif // DOUBLE_STACK_H
