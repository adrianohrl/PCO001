/**
 * This header file defines the Highway class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW9_HIGHWAY_H
#define HW9_HIGHWAY_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include "utilities/Exception.h"
#include "homeworks/homework9/City.h"

namespace homeworks
{
  namespace homework9
	{
    class Highway
		{
    public:
      Highway(std::string line);
			Highway(City origin, City destiny, double distance);
			Highway(std::string origin, std::string destiny, std::string distance);
			Highway(const Highway &highway);
      virtual ~Highway();
      City getOriginCity() const;
			City getDestinyCity() const;
			double getDistance() const;
			std::string str() const;
			bool operator<(const Highway &highway) const;
			bool operator<=(const Highway &highway) const;
			bool operator==(const Highway &highway) const;
			bool operator!=(const Highway &highway) const;
			bool operator>=(const Highway &highway) const;
			bool operator>(const Highway &highway) const;
		private:
			City origin_, destiny_;
			double distance_;
      void validate() const;
		};
	}
}

#endif // HW9_HIGHWAY_H
