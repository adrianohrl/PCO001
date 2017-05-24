/**
 * This header file defines the ExpressionBinaryTree Operand abstract class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EBT_OPERAND_H
#define EBT_OPERAND_H

#include <sstream>
#include "utilities/trees/expression_binary_tree/node.h"

namespace utilities
{
namespace trees
{
namespace expression_binary_tree
{

template <typename E> class Operand : public Node<double, E>
{
public:
  Operand(const Operand<E>& operand);
  virtual ~Operand();
  virtual std::string str() const;
  virtual bool operator<(const Operand<E>& operand) const;
  virtual bool operator<(const E& operand) const;
  virtual bool operator<=(const Operand<E>& operand) const;
  virtual bool operator<=(const E& operand) const;
  virtual bool operator==(const Operand<E>& operand) const;
  virtual bool operator==(const E& operand) const;
  virtual bool operator!=(const Operand<E>& operand) const;
  virtual bool operator!=(const E& operand) const;
  virtual bool operator>=(const Operand<E>& operand) const;
  virtual bool operator>=(const E& operand) const;
  virtual bool operator>(const Operand<E>& operand) const;
  virtual bool operator>(const E& operand) const;
  virtual double operator+(const Operand<E>& operand) const;
  virtual double operator+(const E& operand) const;
  virtual double operator-(const Operand<E>& operand) const;
  virtual double operator-(const E& operand) const;
  virtual double operator*(const Operand<E>& operand) const;
  virtual double operator*(const E& operand) const;
  virtual double operator/(const Operand<E>& operand) const;
  virtual double operator/(const E& operand) const;

protected:
  Operand(E* operand);
  E* getContent() const;

private:
  E* content_;
};

template <typename E> Operand<E>::Operand(E* content) : content_(content) {}

template <typename E>
Operand<E>::Operand(const Operand<E>& operand)
    : content_(operand.content_)
{
}

template <typename E> Operand<E>::~Operand() {}

template <typename E> std::string Operand<E>::str() const
{
  std::stringstream ss;
  ss << content_;
  return ss.str();
}

template <typename E>
bool Operand<E>::operator<(const Operand<E>& operand) const
{
  return *content_ < *operand.content_;
}

template <typename E> bool Operand<E>::operator<(const E& operand) const
{
  return *content_ < operand;
}

template <typename E>
bool Operand<E>::operator<=(const Operand<E>& operand) const
{
  return *content_ <= *operand.content_;
}

template <typename E> bool Operand<E>::operator<=(const E& operand) const
{
  return *content_ <= operand;
}

template <typename E>
bool Operand<E>::operator==(const Operand<E>& operand) const
{
  return *content_ == *operand.content_;
}

template <typename E> bool Operand<E>::operator==(const E& operand) const
{
  return *content_ == operand;
}

template <typename E>
bool Operand<E>::operator!=(const Operand<E>& operand) const
{
  return *content_ != *operand.content_;
}

template <typename E> bool Operand<E>::operator!=(const E& operand) const
{
  return *content_ != operand;
}

template <typename E>
bool Operand<E>::operator>=(const Operand<E>& operand) const
{
  return *content_ >= *operand.content_;
}

template <typename E> bool Operand<E>::operator>=(const E& operand) const
{
  return *content_ >= operand;
}

template <typename E>
bool Operand<E>::operator>(const Operand<E>& operand) const
{
  return *content_ > *operand.content_;
}

template <typename E> bool Operand<E>::operator>(const E& operand) const
{
  return *content_ > operand;
}

template <typename E>
double Operand<E>::operator+(const Operand<E>& operand) const
{
  return *content_ + *operand.content_;
}

template <typename E> double Operand<E>::operator+(const E& operand) const
{
  return *content_ + operand;
}

template <typename E>
double Operand<E>::operator-(const Operand<E>& operand) const
{
  return *content_ - *operand.content_;
}

template <typename E> double Operand<E>::operator-(const E& operand) const
{
  return *content_ - operand;
}

template <typename E>
double Operand<E>::operator*(const Operand<E>& operand) const
{
  return *content_ * *operand.content_;
}

template <typename E> double Operand<E>::operator*(const E& operand) const
{
  return *content_ * operand;
}

template <typename E>
double Operand<E>::operator/(const Operand<E>& operand) const
{
  return *content_ / *operand.content_;
}

template <typename E> double Operand<E>::operator/(const E& operand) const
{
  return *content_ / operand;
}
}
}
}

#endif // EBT_OPERAND_H
