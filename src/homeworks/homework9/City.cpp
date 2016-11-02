/**
 * This source file implements the City class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework9/City.h"

namespace homeworks
{

  namespace homework9
  {

    City::City(std::string name)
      : name_(name)
    {
      if (name_.empty())
      {
        throw utilities::Exception("City name must not be empty!!!");
      }
    }

    City::~City()
    {}

    std::string City::getName() const
    {
      return name_;
    }

    std::string City::str() const
    {
			return "Name: " + name_;
		}

		bool City::operator<(const City &city) const
		{
			return name_ < city.name_;
		}

		bool City::operator<=(const City &city) const
		{
			return name_ <= city.name_;
		}

		bool City::operator==(const City &city) const
		{
			return name_ == city.name_;
		}

		bool City::operator!=(const City &city) const
		{
			return !operator==(city);
		}

		bool City::operator>(const City &city) const
		{
			return name_ > city.name_;
		}

		bool City::operator>=(const City &city) const
		{
			return name_ >= city.name_;
		}

    std::ostream &operator<<(std::ostream &os, const City &city)
    {
      os << city.str();
      return os;
    }

	}

}
