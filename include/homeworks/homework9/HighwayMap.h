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

#define MAX_NUM_CITIES 50000

#include <fstream>
#include <set>
#include "utilities/graphes/DijkstraAdjacencyList.h"
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
			std::list<City> getItinerary(std::string origin, std::string destiny);
			std::list<City> getItinerary(const City &origin, const City &destiny);
			std::list<City> getCities() const;
			std::list<Highway> getHighways() const;
			double getItineraryTotalDistance(const City &destiny) const;
			double getItineraryTotalDistance(std::list<City> itinerary) const;
			std::string str() const;
		private:
			utilities::graphes::DijkstraAdjacencyList<City> *map_;
      bool exists(std::string file_name) const;
			void buildMap(std::set<City> cities, std::vector<Highway> highways);
			bool isRegistered(const City &city);
		};
	}
}

#endif // HW9_HIGHWAY_MAP_H
