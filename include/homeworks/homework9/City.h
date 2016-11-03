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

#include <string>
#include "utilities/Exception.h"

namespace homeworks
{
  namespace homework9
	{
    class City
		{
    public:
			City();
      City(std::string name);
			City(const City &city);
      virtual ~City();
      std::string getName() const;
      std::string str() const;
			void operator=(const City &city);
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
