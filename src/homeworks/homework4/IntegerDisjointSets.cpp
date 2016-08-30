/**
 * This source file implements specific parse and evaluation operations
 * for two Disjoint Set of integer numbers.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework4/IntegerDisjointSets.h"

namespace homeworks
{
  namespace homework4
  {

  IntegerDisjointSets::IntegerDisjointSets()
  {
    set_A_ = NULL;
    set_B_ = NULL;
  }

  IntegerDisjointSets::IntegerDisjointSets(std::string expression_A, std::string expression_B)
  {
    set_A_ = NULL;
    set_B_ = NULL;
    setDisjointSetA(expression_A);
    setDisjointSetB(expression_B);
  }

  IntegerDisjointSets::IntegerDisjointSets(const IntegerDisjointSets& sets)
  {
    set_A_ = NULL;
    set_B_ = NULL;
    if (sets.set_A_)
    {
      set_A_ = new utilities::lists::disjoint_set::IntegerDisjointSet(*sets.set_A_);
    }
    if (sets.set_B_)
    {
      set_B_ = new utilities::lists::disjoint_set::IntegerDisjointSet(*sets.set_B_);
    }
  }

  IntegerDisjointSets::~IntegerDisjointSets()
  {
    if (set_A_)
    {
      delete set_A_;
      set_A_ = NULL;
    }
    if (set_B_)
    {
      delete set_B_;
      set_B_ = NULL;
    }
  }

  bool IntegerDisjointSets::insert(IntegerDisjointSetEnum set, int element)
  {
    if (set == sets::A)
    {
      return set_A_->insert(element);
    }
    return set_B_->insert(element);
  }

  bool IntegerDisjointSets::insert(IntegerDisjointSetEnum set, std::string expression)
  {
    if (set == sets::A)
    {
      return set_A_->insert(expression);
    }
    return set_B_->insert(expression);
  }

  bool IntegerDisjointSets::removeZeros(IntegerDisjointSetEnum set)
  {
    return remove(set);
  }

  bool IntegerDisjointSets::remove(IntegerDisjointSetEnum set, int element)
  {
    if (set == sets::A)
    {
      return set_A_->remove(element);
    }
    return set_B_->remove(element);
  }

  bool IntegerDisjointSets::remove(IntegerDisjointSetEnum set, std::string expression)
  {
    if (set == sets::A)
    {
      return set_A_->remove(expression);
    }
    return set_B_->remove(expression);
  }

  bool IntegerDisjointSets::find(IntegerDisjointSetEnum set, int element)
  {
    if (set == sets::A)
    {
      return set_A_->find(element);
    }
    return set_B_->find(element);
  }

  bool IntegerDisjointSets::find(IntegerDisjointSetEnum set, std::string expression)
  {
    if (set == sets::A)
    {
      return set_A_->find(expression);
    }
    return set_B_->find(expression);
  }

  int IntegerDisjointSets::sumNodes(IntegerDisjointSetEnum set)
  {
    if (set == sets::A)
    {
      return set_A_->sumNodes();
    }
    return set_B_->sumNodes();
  }

  int IntegerDisjointSets::calculateHeight(IntegerDisjointSetEnum set)
  {
    if (set == sets::A)
    {
      return set_A_->calculateHeight();
    }
    return set_B_->calculateHeight();
  }
  int IntegerDisjointSets::countElements(IntegerDisjointSetEnum set)
  {
    if (set == sets::A)
    {
      return set_A_->countElements();
    }
    return set_B_->countElements();
  }

  bool IntegerDisjointSets::compareDisjointSets()
  {
    return set_A_ == set_B_;
  }

  std::string IntegerDisjointSets::toString(IntegerDisjointSetEnum set) const
  {
    if (set == sets::A)
    {
      return set_A_->toString();
    }
    return set_B_->toString();
  }

  std::string IntegerDisjointSets::toStringReversed(IntegerDisjointSetEnum set)
  {
    if (set == sets::A)
    {
      return set_A_->toString(true);
    }
    return set_B_->toString(true);
  }

  bool IntegerDisjointSets::setDisjointSetA(std::string expression)
  {
    if (!utilities::lists::disjoint_set::IntegerDisjointSet::evaluate(expression))
    {
      return false;
    }
    if (set_A_)
    {
      delete set_A_;
    }
    set_A_ = new utilities::lists::disjoint_set::IntegerDisjointSet();
    set_A_->insert(expression);
  }

  bool IntegerDisjointSets::setDisjointSetB(std::string expression)
  {
    if (!utilities::lists::disjoint_set::IntegerDisjointSet::evaluate(expression))
    {
      return false;
    }
    if (set_B_)
    {
      delete set_B_;
    }
    set_B_ = new utilities::lists::disjoint_set::IntegerDisjointSet();
    set_B_->insert(expression);
  }

  std::ostream& operator<<(std::ostream& os, const IntegerDisjointSets& sets)
  {
    os << "A = " << sets.toString(sets::A) << " and B = " << sets.toString(sets::B);
    return os;
  }

  void IntegerDisjointSets::operator=(const IntegerDisjointSets& sets)
  {
    if (set_A_)
    {
      delete set_A_;
    }
    if (set_B_)
    {
      delete set_B_;
    }
    set_A_ = NULL;
    set_B_ = NULL;
    if (sets.set_A_)
    {
      set_A_ = new utilities::lists::disjoint_set::IntegerDisjointSet(*sets.set_A_);
    }
    if (sets.set_B_)
    {
      set_B_ = new utilities::lists::disjoint_set::IntegerDisjointSet(*sets.set_B_);
    }
  }

  }
}
