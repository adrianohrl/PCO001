/**
 * This source file implements specific parse and evaluation operations
 * for a Disjoint Set of String objects.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/lists/disjoint_set/string_expression_parser.h"

namespace utilities
{
namespace lists
{
namespace disjoint_set
{

StringDisjointSet::StringDisjointSet(std::string expression)
    : DisjointSet<std::string>::DisjointSet(new StringExpressionParser(),
                                            expression)
{
}

StringDisjointSet::StringDisjointSet(std::string valid_characters,
                                     std::string separators,
                                     std::string opening_bounds,
                                     std::string closing_bounds,
                                     std::string expression)
    : DisjointSet<std::string>::DisjointSet(
          new StringExpressionParser(valid_characters, separators,
                                     opening_bounds, closing_bounds),
          expression)
{
}

StringDisjointSet::StringDisjointSet(std::string valid_characters,
                                     std::list<std::string> separators,
                                     std::list<std::string> opening_bounds,
                                     std::list<std::string> closing_bounds,
                                     std::string expression)
    : DisjointSet<std::string>::DisjointSet(
          new StringExpressionParser(valid_characters, separators,
                                     opening_bounds, closing_bounds),
          expression)
{
}

StringDisjointSet::StringDisjointSet(const StringDisjointSet& set)
    : DisjointSet(set)
{
}

StringDisjointSet::~StringDisjointSet() {}
}
}
}
