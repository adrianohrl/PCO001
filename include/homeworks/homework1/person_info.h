/**
 * This header file defines the available person info.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW1_PERSON_INFO_H
#define HW1_PERSON_INFO_H

#include <string>

namespace homeworks
{
	namespace homework1
	{
		class PersonInfo
		{
		public:
			PersonInfo();
			PersonInfo(std::string name, std::string phone_number, std::string additional = "");
			virtual ~PersonInfo();

			std::string getName() const;
			std::string getPhoneNumber() const;
			std::string getAdditional() const;
			void setPhoneNumber(std::string phone_number);
			void setAdditional(std::string additional);
			bool isValid();
			std::string toString() const;

			void operator=(const PersonInfo& info);
			bool operator==(const PersonInfo& info);
			bool operator!=(const PersonInfo& info);
			bool operator<(const PersonInfo& info);
			bool operator>(const PersonInfo& info);
			friend std::ostream& operator<<(std::ostream& os, const PersonInfo& info);

		private:
			std::string name_, phone_number_, additional_;

		};
	}
}

#endif // HW1_PERSON_INFO_H
