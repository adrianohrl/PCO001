/**
 * This header file defines the HighwayMap class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW9_HIGHWAY_MAP_H
#define HW9_HIGHWAY_MAP_H

#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "utilities/graphes/AdjacencyList.h"
#include "homeworks/homework9/Highway.h"
#include "homeworks/homework9/City.h"

namespace homeworks
{
  namespace homework9
	{
    class HighwayMap
		{
		public:
      HighwayMap(std::string file_name);
      virtual ~HighwayMap();
      void import(std::string file_name);
      std::string str() const;
      utilities::graphes::AdjacencyList<City> *getMap() const;
		private:
      utilities::graphes::AdjacencyList<City> *map_;
      bool exists(std::string file_name) const;
		};
	}
}

#endif // HW9_HIGHWAY_MAP_H
