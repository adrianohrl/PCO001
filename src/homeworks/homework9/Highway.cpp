/**
 * This source file implements the Highway class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework9/Highway.h"

namespace homeworks
{
  namespace homework9
  {
    Highway::Highway(std::string line)
    {
      std::vector<std::string> columns;
      std::size_t index(0), next_index;
      next_index = line.find(',', index);
      while (index < line.size())
      {
        std::string column(line.substr(index, next_index - index));
        while (!column.empty() && column[0] == ' ')
        {
          column.erase(0, 1);
        }
        while (!column.empty() && column[column.size() - 1] == ' ')
        {
          column.erase(column.size() - 1, std::string::npos);
        }
        if (column.empty())
        {
          throw utilities::Exception("Column must not be empty!!!");
        }
        columns.push_back(column);
        index = next_index != std::string::npos ? next_index + 1 : line.size();
        next_index = line.find(',', index);
      }
      if (columns.size() != 3)
      {
        throw utilities::Exception("Lines must have one or three columns only!!!");
      }
      origin_ = columns[0];
      destiny_ = columns[1];
      distance_ = atoi(columns[2].c_str());
      validate();
    }

    Highway::Highway(std::string origin, std::string destiny, int distance) throw()
      : origin_(origin),
        destiny_(destiny),
        distance_(distance)
    {
      validate();
    }

    Highway::Highway(std::string origin, std::string destiny, std::string distance) throw()
      : origin_(origin),
        destiny_(destiny),
        distance_(atoi(distance.c_str()))
    {
      validate();
    }

    Highway::~Highway()
    {}

    std::string Highway::getOriginCity() const
    {
      return origin_;
    }

    std::string Highway::getDestinyCity() const
    {
      return destiny_;
    }

    int Highway::getDistance() const
    {
      return distance_;
    }

    std::string Highway::str() const
    {
      std::stringstream ss;
      ss << "go from " + origin_ + " to " + destiny_ + " for " << distance_ << " [km]";
			return ss.str();
		}

		bool Highway::operator<(const Highway &highway) const
		{
			return distance_ < highway.distance_;
		}

		bool Highway::operator<=(const Highway &highway) const
		{
			return distance_ <= highway.distance_;
		}

		bool Highway::operator==(const Highway &highway) const
		{
			return origin_ == highway.origin_ && destiny_ == highway.destiny_;
		}

		bool Highway::operator!=(const Highway &highway) const
		{
			return !operator==(highway);
		}

		bool Highway::operator>=(const Highway &highway) const
		{
			return distance_ >= highway.distance_;
		}

		bool Highway::operator>(const Highway &highway) const
		{
			return distance_ > highway.distance_;
		}

    void Highway::validate() const
    {
      if (origin_.empty())
      {
        throw utilities::Exception("City names must NOT be empty!!!");
      }
      if (destiny_.empty())
      {
        throw utilities::Exception("City names must NOT be empty!!!");
      }
      if (origin_ == destiny_)
      {
        throw utilities::Exception("The name of cities that are connected by a highway must be different!!!");
      }
      if (distance_ <= 0)
      {
        throw utilities::Exception("Highway distances must be positive!!!");
      }
    }
	}
}
