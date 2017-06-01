/**
 * This header file defines the features of a StringDisjointSet object,
 * which is based on DisjointSet class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef STRING_DISJOINT_SET_H
#define STRING_DISJOINT_SET_H

#include "utilities/lists/disjoint_set/disjoint_set.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

class StringDisjointSet : public DisjointSet<std::string>
{
public:
  StringDisjointSet(std::string expression = "");
  StringDisjointSet(std::string valid_characters, std::string separators,
                    std::string opening_bounds = "",
                    std::string closing_bounds = "", std::string spacers = "",
                    std::string expression = "");
  StringDisjointSet(
      std::string valid_characters, std::list<std::string> separators,
      std::list<std::string> opening_bounds = std::list<std::string>(),
      std::list<std::string> closing_bounds = std::list<std::string>(),
      std::list<std::string> spacers = std::list<std::string>(),
      std::string expression = "");
  StringDisjointSet(const StringDisjointSet& set);
  virtual ~StringDisjointSet();
};
}
}
}

#endif // STRING_DISJOINT_SET_H
