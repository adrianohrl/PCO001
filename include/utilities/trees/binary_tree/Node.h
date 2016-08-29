/**
 * This header file defines the BinaryTreeInterface interface.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <sstream>
#include <string>

namespace utilities
{
	namespace trees
	{
		namespace binary_tree
		{

			template<typename Key, typename Element> class Node
			{
			public:
        Node(Node<Key, Element> *left);
				Node(Key key, Element element, Node<Key, Element> *left = NULL, Node<Key, Element> *right = NULL);
				virtual ~Node();

				Node<Key, Element>* insert(Key key, Element element, Node<Key, Element> *parent);
        Node<Key, Element>* remove(Key key, Node<Key, Element> *parent = NULL);
				Element find(Key key);
        Node<Key, Element>* getLeftmost();
        Node<Key, Element>* getRightmost();

				Key getKey();
				Element getElement();
				Node<Key, Element>* getLeft();
				Node<Key, Element>* getRight();
				void setLeft(Node<Key, Element> *left);
				void setRight(Node<Key, Element> *right);
				bool hasLeft();
				bool hasRight();
				bool isLeaf();
				std::string toString(); //in-order
				bool operator==(Node<Key, Element> *node);
				bool operator!=(Node<Key, Element> *node);
				bool operator>(Node<Key, Element> *node);
				bool operator<(Node<Key, Element> *node);

			private:
				Key key_;
				Element element_;
				Node<Key, Element> *left_, *right_;

      };

    template<typename Key, typename Element> Node<Key, Element>::Node(Node<Key, Element> *left)
    {
      left_ = left;
      right_ = NULL;
    }

    template<typename Key, typename Element> Node<Key, Element>::Node(Key key, Element element, Node<Key, Element> *left, Node<Key, Element> *right)
      : key_(key),
        element_(element)
    {
      left_ = left;
      right_ = right;
    }

			template<typename Key, typename Element> Node<Key, Element>::~Node()
			{
        if (hasLeft())
				{
					delete left_;
				}
				if (hasRight())
				{
					delete right_;
        }
			}

			template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::insert(Key key, Element element, Node<Key, Element> *parent)
			{
				if (!parent)
				{
					parent = new Node<Key, Element>(key, element);
				}
				else if (key < parent->key_)
				{
					parent->left_ = insert(key, element, parent->left_);
				}
				else
				{
					parent->right_ = insert(key, element, parent->right_);
				}
				return parent;
			}

			template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::remove(Key key, Node<Key, Element> *parent)
      {
        if (key < key_)
				{
          return left_ ? left_->remove(key, this) : NULL;
				}
        else if (key > key_)
				{
          return right_ ? right_->remove(key, this) : NULL;
				}
        else if (left_ && right_)
				{
          Node<Key, Element> *left_rightmost = left_->getRightmost();
          key_ = left_rightmost->key_;
          element_ = left_rightmost->element_;
          return left_->remove(key_, this);
        }
        else if (parent->left_ == this)
        {
          parent->left_ = left_ ? left_ : right_;
          return this;
        }
        else if (parent->right_ == this)
        {
          parent->right_ = left_ ? left_ : right_;
          return this;
        }
				return NULL;
			}

			template<typename Key, typename Element> Element Node<Key, Element>::find(Key key)
			{
				if (key < key_ && hasLeft())
				{
					return left_->find(key);
				}
				else if (key > key_ && hasRight())
				{
					return right_->find(key);
				}
				else if (key == key_)
				{
					return element_;
				}
				return Element();
      }

    template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getLeftmost()
    {
      return left_ ? left_->getLeftmost() : this;
    }

    template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getRightmost()
    {
      return right_ ? right_->getRightmost() : this;
    }

			template<typename Key, typename Element> Key Node<Key, Element>::getKey()
			{
				return key_;
			}

			template<typename Key, typename Element> Element Node<Key, Element>::getElement()
			{
				return element_;
			}

			template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getLeft()
			{
				return left_;
			}

			template<typename Key, typename Element> Node<Key, Element>* Node<Key, Element>::getRight()
			{
				return right_;
			}

			template<typename Key, typename Element> void Node<Key, Element>::setLeft(Node<Key, Element> *left)
			{
				left_ = left;
			}

			template<typename Key, typename Element> void Node<Key, Element>::setRight(Node<Key, Element> *right)
			{
				right_ = right;
			}

			template<typename Key, typename Element> bool Node<Key, Element>::hasLeft()
			{
				return left_;
			}

			template<typename Key, typename Element> bool Node<Key, Element>::hasRight()
			{
				return right_;
			}

			template<typename Key, typename Element> bool Node<Key, Element>::isLeaf()
			{
				return !left_ && !right_;
			}

			template<typename Key, typename Element> std::string Node<Key, Element>::toString()
			{
				std::stringstream ss;
				if (hasLeft())
				{
					ss << left_->toString() << ",";
				}
				ss << "(" << key_ << ") " << element_;
				if (hasRight())
				{
					ss << "," << right_->toString();
				}
				return ss.str();
			}

			template<typename Key, typename Element> bool Node<Key, Element>::operator==(Node<Key, Element> *node)
			{
				return key_ == node->key_;
			}

			template<typename Key, typename Element> bool Node<Key, Element>::operator!=(Node<Key, Element> *node)
			{
				return key_ != node->key_;
			}

			template<typename Key, typename Element> bool Node<Key, Element>::operator>(Node<Key, Element> *node)
			{
				return key_ > node->key_;
			}

			template<typename Key, typename Element> bool Node<Key, Element>::operator<(Node<Key, Element> *node)
			{
				return key_ < node->key_;
			}

		}
	}
}

#endif // BINARY_TREE_NODE_H
