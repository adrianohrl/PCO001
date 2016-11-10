/**
 * This header file defines the CPM class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HW11_CPM_H
#define HW11_CPM_H

#define MAX_NUM_ACTIVITIES 50000

#include <cstdlib>
#include <fstream>
#include <map>
#include <vector>
#include "utilities/graphes/AdjacencyList.h"
#include "homeworks/homework11/Activity.h"

namespace homeworks
{
	namespace homework11
	{
    class CPM
		{
		public:
			CPM(std::string file_name, std::string time_unit);
      virtual ~CPM();
			std::list<Activity> getCriticalPath();
			double getTotalDuration();
			double getTotalDuration(std::list<Activity> critical_path) const;
			void import(std::string file_name);
			Activity getActivity(char id) const;
			std::string getTimeUnit() const;
			std::string str() const;
		private:
			utilities::graphes::AdjacencyList<Activity> *graph_;
			std::string time_unit_;
      bool exists(std::string file_name) const;
			void buildGraph(std::map<char, Activity> activities, std::map<char, std::vector<char> > predecessors);
			bool isRegistered(const Activity &activity);
			Activity getActivity(const Activity &activity) const;
			double max(double d1, double d2) const;
		};
	}
}

#endif // HW11_CPM_H
