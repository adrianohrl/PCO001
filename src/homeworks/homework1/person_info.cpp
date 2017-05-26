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

#include "homeworks/homework1/person_info.h"

namespace homeworks
{
	namespace homework1
	{

		PersonInfo::PersonInfo()
		{
			name_ = "";
			phone_number_ = "";
			additional_ = "";
		}

		PersonInfo::PersonInfo(std::string name, std::string phone_number, std::string additional)
		{
			name_ = name;
			phone_number_ = phone_number;
			additional_ = additional;
		}

		PersonInfo::~PersonInfo()
		{
		}

		std::string PersonInfo::getName() const
		{
			return name_;
		}

		std::string PersonInfo::getPhoneNumber() const
		{
			return phone_number_;
		}

		std::string PersonInfo::getAdditional() const
		{
			return additional_;
		}

		void PersonInfo::setPhoneNumber(std::string phone_number)
		{
			phone_number_ = phone_number;
		}

		void PersonInfo::setAdditional(std::string additional)
		{
			additional_ = additional;
		}

		bool PersonInfo::isValid()
		{
			return name_ != "" && phone_number_ != "";
		}

		std::string PersonInfo::toString() const
		{
			return name_ + " \t\t\t " + phone_number_;
		}

		void PersonInfo::operator=(const PersonInfo& info)
		{
			name_ = info.name_;
			phone_number_ = info.phone_number_;
			additional_ = info.additional_;
		}

		bool PersonInfo::operator==(const PersonInfo& info)
		{
			return name_ == info.name_;
		}

		bool PersonInfo::operator!=(const PersonInfo& info)
		{
			return name_ != info.name_;
		}

		bool PersonInfo::operator<(const PersonInfo& info)
		{
			return name_.compare(info.name_) < 0;
		}

		bool PersonInfo::operator>(const PersonInfo& info)
		{
			return name_.compare(info.name_) > 0;
		}

    std::ostream& operator<<(std::ostream& os, const PersonInfo& info)
		{
			os << info.toString();
			return os;
		}

	}
}
