/**
 * This source file implements the HighwayMap class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework9/HighwayMap.h"

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
        throw utilities::Exception("the highway map must NOT be null!!!");
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

    std::string HighwayMap::str() const
    {
      return map_->str();
    }

		utilities::graphes::AdjacencyList<City> *HighwayMap::getMap() const
    {
      return map_;
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
				double distance(highways[i].getDistance());
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
				map_->connect(origin, destiny, distance);
				map_->connect(destiny, origin, distance);
			}
		}

	}

}
