/**
 * This source file implements the HighwayMap class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework9/highway_map.h"

namespace homeworks
{

  namespace homework9
  {

    HighwayMap::HighwayMap(std::string file_name)
      : map_(NULL)
    {
      if (!exists(file_name))
      {
        throw utilities::Exception("Inexistent file!!!");
      }
      import(file_name);
      if (!map_)
      {
				throw utilities::Exception("The highway map must NOT be null!!!");
      }
    }

    HighwayMap::~HighwayMap()
    {
      if (map_)
      {
        delete map_;
      }
    }

    void HighwayMap::import(std::string file_name)
    {
      std::ifstream file;
      file.open(file_name.c_str(), std::ifstream::in);
      if (!file.is_open())
      {
        file.close();
        throw utilities::Exception("Inexistent file path!!!");
      }
      std::string str_line("");
      while (str_line.empty() && file.good())
      {
        std::getline(file, str_line);
      }
      if (str_line.empty())
      {
        file.close();
        throw utilities::Exception("Empty file!!!");
      }
      std::vector<Highway> highways;
			std::set<City> cities;
      while (file.good())
      {
        if (!str_line.empty())
        {
          if (str_line.find(',') == std::string::npos)
          {
            while (!str_line.empty() && str_line[0] == ' ')
            {
              str_line.erase(0, 1);
            }
            while (!str_line.empty() && str_line[str_line.size() - 1] == ' ')
            {
              str_line.erase(str_line.size() - 1, std::string::npos);
            }
            if (!str_line.empty())
            {
							cities.insert(City(str_line));
            }
          }
          else
          {
            Highway highway(str_line);
            highways.push_back(highway);
          }
        }
        std::getline(file, str_line);
      }
			file.close();
			buildMap(cities, highways);
		}

		std::list<City> HighwayMap::getItinerary(std::string origin, std::string destiny)
		{
			return getItinerary(City(origin), City(destiny));
		}

		std::list<City> HighwayMap::getItinerary(const City &origin, const City &destiny)
		{
			if (!isRegistered(origin))
			{
				throw utilities::Exception(origin.getName() + " is not registered!!!");
			}
			if (!isRegistered(destiny))
			{
				throw utilities::Exception(destiny.getName() + " is not registered!!!");
			}
			std::list<City> itinerary(map_->getShortestPath(origin, destiny));
			if (itinerary.empty())
			{
				throw utilities::Exception("There isn't a valid path from " + origin.getName() + " to " + destiny.getName() + "!!!");
			}
			return itinerary;
		}

		std::list<City> HighwayMap::getCities() const
		{
			return map_->getVertices();
		}

		std::list<Highway> HighwayMap::getHighways() const
		{
			std::list<Highway> highways;
			std::list<City> cities(map_->getVertices());
			std::list<City>::const_iterator city_it(cities.begin());
			std::list<std::pair<City, double> > connected_cities;
			std::list<std::pair<City, double> >::const_iterator connected_cities_it;
			while (city_it != cities.end())
			{
				connected_cities = map_->getArcs(*city_it);
				connected_cities_it = connected_cities.begin();
				while (connected_cities_it != connected_cities.end())
				{
					highways.push_back(Highway(*city_it, connected_cities_it->first, connected_cities_it->second));
					connected_cities_it++;
				}
				city_it++;
			}
			return highways;
		}

		double HighwayMap::getItineraryTotalDistance(const City &destiny) const
		{
			return map_->getShortestPathTotalWeight(destiny);
		}

		double HighwayMap::getItineraryTotalDistance(std::list<City> itinerary) const
		{
			return map_->getShortestPathTotalWeight(itinerary);
		}

    std::string HighwayMap::str() const
    {
      return map_->str();
		}

    bool HighwayMap::exists(std::string file_name) const
    {
			return true;
		}

		void HighwayMap::buildMap(std::set<City> cities, std::vector<Highway> highways)
		{
			if (map_)
			{
				delete map_;
			}
			map_ = new utilities::graphes::DijkstraAdjacencyList<City>(MAX_NUM_CITIES);
			std::set<City>::iterator it(cities.begin());
			while (it != cities.end())
			{
				map_->insert(*it++);
			}
			for (int i(0); i < highways.size(); i++)
			{
				City origin(highways[i].getOriginCity());
				if (cities.find(origin) == cities.end())
				{
					throw utilities::Exception(origin.getName() + " does NOT exists!!!");
				}
				City destiny(highways[i].getDestinyCity());
				if (cities.find(destiny) == cities.end())
				{
					throw utilities::Exception(destiny.getName() + " does NOT exists!!!");
				}
				double distance(highways[i].getDistance());
				map_->connect(origin, destiny, distance);
				map_->connect(destiny, origin, distance);
			}
		}

		bool HighwayMap::isRegistered(const City &city)
		{
			return map_->hasVertex(city);
		}

	}

}
