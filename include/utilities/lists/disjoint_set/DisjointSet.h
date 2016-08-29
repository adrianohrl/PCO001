/**
 * This header file defines and implements a generic DisjointSet object.
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

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include "utilities/lists/disjoint_set/DisjointSetInterface.h"
#include "utilities/lists/disjoint_set/Node.h"
#include "utilities/stacks/stack/Stack.h"

namespace utilities
{
	namespace lists
	{
		namespace disjoint_set
		{

    template<typename Element> class DisjointSet : public DisjointSetInterface<Element>
    {
    public:
      DisjointSet();
      DisjointSet(const DisjointSet<Element>& ds);
      virtual ~DisjointSet();

      virtual bool insert(Element element);
      virtual bool remove(Element element);
      virtual bool find(Element element);
      virtual bool isEmpty();
      virtual std::string toString(bool reversed = false) const;
      virtual bool operator==(const DisjointSet& set);
      virtual bool operator!=(const DisjointSet& set);

      static bool evaluate(std::string expression);

    protected:
      virtual bool insert(Node<Element> *node);
      virtual bool remove(Node<Element> *node);
      virtual bool find(Node<Element> *node);

      static std::string getNext(std::string expression);

    private:
      Node<Element> *root_, *node_;

    };

    template<typename Element> DisjointSet<Element>::DisjointSet()
    {
      node_ = NULL;
      root_ = NULL;
    }

    template<typename Element> DisjointSet<Element>::DisjointSet(const DisjointSet<Element>& set)
    {
      node_ = NULL;
      root_ = NULL;
      if (set.root_)
      {
        root_ = new Node<Element>(*set.root_);
        node_ = root_;
      }
    }

    template<typename Element> DisjointSet<Element>::~DisjointSet()
    {
      if (!isEmpty())
      {
        node_ = NULL;
        delete root_;
      }
    }

    template<typename Element> bool DisjointSet<Element>::insert(Element element)
    {
      if (isEmpty())
      {
        node_ = new Node<Element>(element);
        root_ = node_;
        return true;
      }
      return node_->insert(element);
    }

    template<typename Element> bool DisjointSet<Element>::insert(Node<Element> *node)
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

    template<typename Element> bool DisjointSet<Element>::remove(Element element)
    {
      if (isEmpty())
      {
        return false;
      }
      Node<Element> *removed_node = root_->remove(element);
      if (removed_node)
      {
        delete removed_node;
        return true;
      }
      return false;
    }

    template<typename Element> bool DisjointSet<Element>::remove(Node<Element> *node)
    {
      if (isEmpty())
      {
        return false;
      }
      Node<Element> *removed_node = root_->remove(node);
      if (removed_node)
      {
        delete removed_node;
        return true;
      }
      return false;
    }

    template<typename Element> bool DisjointSet<Element>::find(Element element)
    {
      if (isEmpty())
      {
        return false;
      }
      return root_->find(element);
    }

    template<typename Element> bool DisjointSet<Element>::find(Node<Element> *node)
    {
      if (isEmpty())
      {
        return false;
      }
      return root_->find(node);
    }

    template<typename Element> bool DisjointSet<Element>::isEmpty()
    {
      return !root_;
    }

    template<typename Element> std::string DisjointSet<Element>::toString(bool reversed) const
    {
      return root_ ? "(" + root_->toString(reversed) + ")" : "()";
    }

    template<typename Element> bool DisjointSet<Element>::operator==(const DisjointSet& set)
    {
      return root_ == set.root_; //toString() == set.toString();
    }

    template<typename Element> bool DisjointSet<Element>::operator!=(const DisjointSet& set)
    {
      return root_ != set.root_; //toString() != set.toString();
    }

    template<typename Element> bool DisjointSet<Element>::evaluate(std::string expression)
    {
      if (expression == "" || expression.at(0) != '(')
      {
        return false;
      }
      stacks::stack::Stack<char> evaluator;
      evaluator.push(expression.at(0));
      for (std::string::iterator it = expression.begin() + 1; it != expression.end(); ++it)
      {
        if (evaluator.top() == ')' && *it != ',' && *it != ')')
        {
          return false;
        }
        if (*it == ')')
        {
          do
          {
            if (evaluator.isEmpty())
            {
              return false;
            }
          } while (evaluator.pop() != '(');
        }
        evaluator.push(*it);
      }
      if (evaluator.top() == ')')
      {
        evaluator.pop();
      }
      return evaluator.isEmpty();
    }

    template<typename Element> std::string DisjointSet<Element>::getNext(std::string expression)
    {
      int counter = 0;
      std::string output = "";
      for (std::string::iterator it = expression.begin(); it != expression.end(); ++it)
      {
        if (*it == ',' && counter == 0)
        {
          return output;
        }
        output += *it;
        if (*it == '(')
        {
          counter++;
        }
        else if (*it == ')')
        {
          if (counter == 0)
          {
            return "";
          }
          counter--;
        }
      }
      return output;
    }

		}
	}
}

#endif // DISJOINT_SET_H
