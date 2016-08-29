/**
 * This source file implements specific parse and evaluation operations
 * for a Disjoint Set of String objects.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework1/PhoneBook.h"

namespace homeworks
{
	namespace homework1
	{

		PhoneBook::PhoneBook(std::string name)
		{
			name_ = name;
		}

		PhoneBook::~PhoneBook()
		{
		}

		bool PhoneBook::insert(std::string name, std::string phone_number, std::string additional)
		{
			return insert(PersonInfo(name, phone_number,additional));
		}

		bool PhoneBook::insert(PersonInfo info)
		{
			if (!info.isValid())
			{
				return false;
			}
			char first_char = info.getName().at(0);
			if ((first_char >= 'A' && first_char <= 'M') || (first_char >= 'a' && first_char <= 'm'))
			{
				return !list_.contains(info) && list_.insert(info);
			}
			else if ((first_char >= 'N' && first_char <= 'Z') || (first_char >= 'n' && first_char <= 'z'))
			{
				return !list_.contains(info, false) && list_.insert(info, false);
			}
			return false;
		}

		PersonInfo PhoneBook::find(std::string name)
		{
			return find(PersonInfo(name, ""));
		}

		PersonInfo PhoneBook::find(PersonInfo info)
		{
			return list_.find(info);
		}

		bool PhoneBook::remove(std::string name)
		{
			return remove(PersonInfo(name, ""));
		}

		bool PhoneBook::remove(PersonInfo info)
		{
			return list_.remove(info);
		}

		std::string PhoneBook::toString(bool from_beginning)
		{
			std::string str = list_.toString(from_beginning);
			str = str.substr(1, str.length() - 2);
			for (std::string::iterator it = str.begin(); it != str.end(); it++)
			{
				if (*it == ',')
				{
					str.replace(it, it + 1, "\n");
				}
			}
			return name_ + "'s phone book: \n" + str;
		}

	}
}
