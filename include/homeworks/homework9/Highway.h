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

#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "utilities/Exception.h"

namespace homeworks
{
  namespace homework9
	{
    class Highway
		{
    public:
      Highway(std::string line);
      Highway(std::string origin, std::string destiny, int distance) throw();
      Highway(std::string origin, std::string destiny, std::string distance) throw();
      virtual ~Highway();
      std::string getOriginCity() const;
      std::string getDestinyCity() const;
      int getDistance() const;
			std::string str() const;
			bool operator<(const Highway &highway) const;
			bool operator<=(const Highway &highway) const;
			bool operator==(const Highway &highway) const;
			bool operator!=(const Highway &highway) const;
			bool operator>=(const Highway &highway) const;
			bool operator>(const Highway &highway) const;
		private:
      std::string origin_, destiny_;
      int distance_;
      void validate() const;
		};
	}
}

#endif // HW9_HIGHWAY_H
