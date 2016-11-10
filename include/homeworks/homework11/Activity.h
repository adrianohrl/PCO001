/**
 * This header file defines the Activity class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW11_ACTIVITY_H
#define HW11_ACTIVITY_H

#include <sstream>
#include "utilities/Exception.h"

namespace homeworks
{
	namespace homework11
	{
    class Activity
		{
		public:
			Activity(char id);
			Activity(char id, std::string name, double time, std::string description = "");
			Activity(const Activity &activity);
			virtual ~Activity();
			char getId() const;
			std::string getName() const;
			double getTime() const;
			std::string getDescription() const;
			double getDuration() const;
			void setDescription(const std::string &description);
			void setDuration(double duration);
      std::string str() const;
			void operator=(const Activity &activity);
			bool operator<(const Activity &activity) const;
			bool operator<=(const Activity &activity) const;
			bool operator==(const Activity &activity) const;
			bool operator!=(const Activity &activity) const;
			bool operator>=(const Activity &activity) const;
			bool operator>(const Activity &activity) const;
			friend std::ostream &operator<<(std::ostream &os, const Activity &activity);
		private:
			char id_;
			std::string name_;
			double time_;
			std::string description_;
			double duration_;
		};
	}
}

#endif // HW11_HIGHWAY_H
