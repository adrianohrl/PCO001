/**
 * This source file implements the Activity class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework11/activity.h"

namespace homeworks
{

  namespace homework11
	{

		Activity::Activity(char id)
			: id_(id)
		{}

		Activity::Activity(char id, std::string name, double time, std::string description)
			: id_(id),
				name_(name),
				time_(time),
				description_(description),
				duration_(0.0)
		{
			if (name_.empty())
			{
				throw utilities::Exception("Activity name must not be empty!!!");
			}
			if (time_ < 0)
			{
				throw utilities::Exception("Activity time must not be negative!!!");
			}
		}

		Activity::Activity(const Activity &activity)
			: id_(activity.id_),
				name_(activity.name_),
				time_(activity.time_),
				description_(activity.description_),
				duration_(activity.duration_)
		{}

		Activity::~Activity()
		{}

		char Activity::getId() const
		{
			return id_;
		}

		std::string Activity::getName() const
		{
			return name_;
		}

		double Activity::getTime() const
		{
			return time_;
		}

		std::string Activity::getDescription() const
		{
			return description_;
		}

		double Activity::getDuration() const
		{
			return duration_;
		}

		void Activity::setDescription(const std::string &description)
		{
			description_ = description;
		}

		void Activity::setDuration(double duration)
		{
			duration_ = duration;
		}

		std::string Activity::str() const
		{
			std::stringstream ss;
			ss << id_ << ":\tname=" << name_ << ",\ttime=" << time_ << ",\tduration=" << duration_;
			return ss.str();
		}

		void Activity::operator=(const Activity &activity)
		{
			if (activity.name_.empty())
			{
				throw utilities::Exception("Activity name must not be empty!!!");
			}
			id_ = activity.id_;
			name_ = activity.name_;
			time_ = activity.time_;
			description_ = activity.description_;
			duration_ = activity.duration_;
		}

		bool Activity::operator<(const Activity &activity) const
		{
			return id_ < activity.id_;
		}

		bool Activity::operator<=(const Activity &activity) const
		{
			return id_ <= activity.id_;
		}

		bool Activity::operator==(const Activity &activity) const
		{
			return id_ == activity.id_;
		}

		bool Activity::operator!=(const Activity &activity) const
		{
			return !operator==(activity);
		}

		bool Activity::operator>(const Activity &activity) const
		{
			return id_ > activity.id_;
		}

		bool Activity::operator>=(const Activity &activity) const
		{
			return id_ >= activity.id_;
		}

		std::ostream &operator<<(std::ostream &os, const Activity &activity)
    {
      os << activity.str();
      return os;
    }

	}

}
