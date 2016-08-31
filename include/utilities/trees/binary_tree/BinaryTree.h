/**
 * This header file defines the BinaryTreeInterface interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "utilities/trees/binary_tree/Node.h"
#include "utilities/trees/binary_tree/BinaryTreeInterface.h"

namespace utilities
{
	namespace trees
	{
		namespace binary_tree
		{

    template<typename Key, typename Element> class BinaryTree : public BinaryTreeInterface<Key, Element>
    {
    public:
      BinaryTree();
      BinaryTree(const BinaryTree& tree);
      virtual ~BinaryTree();

      virtual bool insert(Key key, Element element);
      virtual bool remove(Key key);
      virtual Element find(Key key);
      bool isEmpty();
      virtual std::string toString(); //in-order

    private:
      Node<Key, Element> *root_;

    };

    template<typename Key, typename Element> BinaryTree<Key, Element>::BinaryTree()
    {
      root_ = NULL;
    }

    template<typename Key, typename Element> BinaryTree<Key, Element>::BinaryTree(const BinaryTree& tree)
    {
      root_ = NULL;
      if (tree.root_)
      {
        root_ = new Node<Key, Element>(*tree.root_);
      }
    }

    template<typename Key, typename Element> BinaryTree<Key, Element>::~BinaryTree()
    {
      if (!isEmpty())
      {
        delete root_;
      }
    }

    template<typename Key, typename Element> bool BinaryTree<Key, Element>::insert(Key key, Element element)
    {
      if (isEmpty())
      {
        root_ = new Node<Key, Element>(key, element);
      }
      else
      {
        root_ = root_->insert(key, element, root_);
      }
      return root_;
    }

    template<typename Key, typename Element> bool BinaryTree<Key, Element>::remove(Key key)
    {
      if (isEmpty())
      {
        return false;
      }
      Node<Key, Element> *removed_node;
      if (root_->getKey() == key)
      {
        Node<Key, Element> aux(root_);
        removed_node = root_->remove(key, &aux);
        root_ = aux.getLeft();
      }
      else
      {
        removed_node = root_->remove(key);
      }
      if (!removed_node)
      {
        return false;
      }
      //removed_node->setLeft(NULL);
      //removed_node->setRight(NULL);
      delete removed_node;
      return true;
    }

    template<typename Key, typename Element> Element BinaryTree<Key, Element>::find(Key key)
    {
      return !isEmpty() ? root_->find(key) : Element();
    }

    template<typename Key, typename Element> bool BinaryTree<Key, Element>::isEmpty()
    {
      return !root_;
    }

    template<typename Key, typename Element> std::string BinaryTree<Key, Element>::toString()
    {
      return "(" + root_->toString() + ")";
    }

		}
	}
}

#endif // BINARY_TREE_H
