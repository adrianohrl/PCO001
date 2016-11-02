/**
 * This header file defines the City class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW9_CITY_H
#define HW9_CITY_H

#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "utilities/Exception.h"

namespace homeworks
{
  namespace homework9
	{
    class City
		{
    public:
      City(std::string name);
      virtual ~City();
      std::string getName() const;
      std::string str() const;
			bool operator<(const City &city) const;
			bool operator<=(const City &city) const;
			bool operator==(const City &city) const;
			bool operator!=(const City &city) const;
			bool operator>=(const City &city) const;
			bool operator>(const City &city) const;
      friend std::ostream &operator<<(std::ostream &os, const City &city);
		private:
      std::string name_;
		};
	}
}

#endif // HW9_HIGHWAY_H
