/**
 * This source file implements the CPM class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "homeworks/homework11/CPM.h"
#include <iostream>

namespace homeworks
{

  namespace homework11
  {

		CPM::CPM(std::string file_name, std::string time_unit)
			: graph_(NULL),
				time_unit_(time_unit)
    {
      if (!exists(file_name))
      {
        throw utilities::Exception("Inexistent file!!!");
      }
      import(file_name);
			if (!graph_)
      {
				throw utilities::Exception("The CPM graph must NOT be null!!!");
      }
    }

    CPM::~CPM()
    {
			if (graph_)
      {
				delete graph_;
			}
		}

		std::list<Activity> CPM::getCriticalPath()
		{
			if (graph_->isEmpty())
			{
				throw utilities::Exception("In order to calculate the critical path, the CPM graph must not be empty!!!");
			}
			if (!graph_->isDirected())
			{
				throw utilities::Exception("In order to calculate the critical path, the CPM graph must be a directed graph!!!");
			}
			if (!graph_->isAcyclic())
			{
				throw utilities::Exception("In order to calculate the critical path, the CPM graph must be an acyclic graph!!!");
			}
			std::queue<Activity> topological_ordering(graph_->getTopologicalOrdering());
			Activity activity(topological_ordering.back());
			while (!topological_ordering.empty())
			{
				Activity *v = graph_->getContentReference(topological_ordering.front());
				topological_ordering.pop();
				std::list<std::pair<Activity, double> > successors(graph_->getArcs(*v));
				std::list<std::pair<Activity, double> >::iterator it(successors.begin());
				while (it != successors.end())
				{
					Activity *w = graph_->getContentReference(it->first);
					w->setDuration(max(w->getDuration(), v->getDuration() + w->getTime()));
					it++;
				}
			}
			std::list<Activity> critical_path;
			activity = *graph_->getContentReference(activity);
			critical_path.insert(critical_path.begin(), activity);
			std::list<std::pair<Activity, double> > predecessors(graph_->getPredecessors(activity));
			while (!predecessors.empty())
			{
				std::list<std::pair<Activity, double> >::iterator it(predecessors.begin());
				while (it != predecessors.end())
				{
					double duration(0);
					if (it->first.getDuration() >= duration)
					{
						activity = it->first;
						duration = activity.getDuration();
					}
					it++;
				}
				predecessors = graph_->getPredecessors(activity);
				critical_path.insert(critical_path.begin(), activity);
			}
			return critical_path;
		}

		double CPM::getTotalDuration()
		{
			return getTotalDuration(getCriticalPath());
		}

		double CPM::getTotalDuration(std::list<Activity> critical_path) const
		{
			std::list<Activity>::const_iterator it(critical_path.begin());
			double duration(0);
			while (it != critical_path.end())
			{
				duration += it->getDuration();
				it++;
			}
			return duration;
		}

    void CPM::import(std::string file_name)
    {
      std::ifstream file;
      file.open(file_name.c_str(), std::ifstream::in);
      if (!file.is_open())
      {
        file.close();
        throw utilities::Exception("Inexistent file path!!!");
      }
			std::string line("");
			while (line.empty() && file.good())
      {
				std::getline(file, line);
      }
			if (line.empty())
      {
        file.close();
        throw utilities::Exception("Empty file!!!");
      }
			std::map<char, Activity> activities;
			std::map<char, std::vector<char> > predecessors;
      while (file.good())
      {
				while (!line.empty() && (line[0] == ' ' || line[0] == '\t'))
				{
					line.erase(0, 1);
				}
				while (!line.empty() && (line[line.size() - 1] == ' ' || line[line.size() - 1] == '\t'))
				{
					line.erase(line.size() - 1, std::string::npos);
				}
				if (!line.empty() && line[0] != '#')
				{
					std::vector<std::string> columns;
					std::size_t index(0), next_index;
					next_index = line.find(',', index);
					while (index < line.size())
					{
						std::string column(line.substr(index, next_index - index));
						while (!column.empty() && (column[0] == ' ' || column[0] == '\t'))
						{
							column.erase(0, 1);
						}
						while (!column.empty() && (column[column.size() - 1] == ' ' || column[column.size() - 1] == '\t'))
						{
							column.erase(column.size() - 1, std::string::npos);
						}
						if (column.empty())
						{
							file.close();
							throw utilities::Exception("Column must not be empty!!!");
						}
						columns.push_back(column);
						index = next_index != std::string::npos ? next_index + 1 : line.size();
						next_index = line.find(',', index);
					}
					if (columns.size() < 4)
					{
						file.close();
						throw utilities::Exception("Lines must have four or more columns!!!");
					}
					char id = columns[0][0];
					std::string name = columns[1];
					double duration = atof(columns[2].c_str());
					activities.insert(std::pair<char, Activity>(id, Activity(id, name, duration)));
					if (columns[3][0] != '-')
					{
						std::vector<char> pred;
						for (int i(3); i < columns.size(); i++)
						{
							pred.push_back(columns[i][0]);
						}
						std::pair<std::map<char, std::vector<char> >::iterator, bool> ret;
						ret = predecessors.insert(std::pair<char, std::vector<char> >(id, pred));
						if (!ret.second)
						{
							file.close();
							throw utilities::Exception("Multiple entries of an existing activity ID!!!");
						}
					}
        }
				std::getline(file, line);
      }
			file.close();
			buildGraph(activities, predecessors);
		}

		Activity CPM::getActivity(char id) const
		{
			return getActivity(Activity(id));
		}

		std::string CPM::getTimeUnit() const
		{
			return time_unit_;
		}

		Activity CPM::getActivity(const Activity &activity) const
		{
			return graph_->getVertex(activity)->getContent();
		}

    std::string CPM::str() const
    {
			std::size_t max_name_size(0);
			std::stringstream ss;
			std::list<Activity> activities(graph_->getVertices());
			std::list<Activity>::const_iterator activities_it(activities.begin());
			std::map<char, std::vector<char> > predecessors;
			while (activities_it != activities.end())
			{
				Activity activity(*activities_it);
				std::stringstream aux;
				aux << activity.getName() << " (" << activity.getDuration() << " [" << time_unit_ << "])";
				std::size_t size(aux.str().size());
				if (size > max_name_size)
				{
					max_name_size = size;
				}
				predecessors.insert(std::pair<char, std::vector<char> >(activity.getId(), std::vector<char>()));
				activities_it++;
			}
			activities_it = activities.begin();
			while (activities_it != activities.end())
			{
				Activity activity(*activities_it);
				std::list<std::pair<Activity, double> > successors(graph_->getArcs(activity));
				std::list<std::pair<Activity, double> >::const_iterator successors_it(successors.begin());
				while (successors_it != successors.end())
				{
					Activity successor(successors_it->first);
					std::map<char, std::vector<char> >::iterator predecessors_it(predecessors.find(successor.getId()));
					predecessors_it->second.push_back(activity.getId());
					successors_it++;
				}
				activities_it++;
			}
			activities_it = activities.begin();
			while (activities_it != activities.end())
			{
				Activity activity(*activities_it);
				std::stringstream aux;
				aux << activity.getName() << " (" << activity.getDuration() << " [" << time_unit_ << "])";
				while (aux.str().size() < max_name_size)
				{
					aux << " ";
				}
				ss << "\n" << activity.getId() << "\t" << aux.str() << "\t";
				std::vector<char> activity_predecessors(predecessors.find(activity.getId())->second);
				if (activity_predecessors.empty())
				{
					ss << "-";
				}
				else
				{
					ss << activity_predecessors[0];
					for (int i(1); i < activity_predecessors.size(); i++)
					{
						ss << ", " << activity_predecessors[i];
					}
				}
				activities_it++;
			}
			return ss.str();
		}

    bool CPM::exists(std::string file_name) const
    {
			return true;
		}

		void CPM::buildGraph(std::map<char, Activity> activities, std::map<char, std::vector<char> > predecessors)
		{
			if (graph_)
			{
				delete graph_;
			}
			graph_ = new utilities::graphes::AdjacencyList<Activity>(MAX_NUM_ACTIVITIES, true);
			std::map<char, Activity>::iterator activities_it(activities.begin());
			while (activities_it != activities.end())
			{
				graph_->insert(activities_it->second);
				activities_it++;
			}
			std::map<char, std::vector<char> >::iterator predecessors_it(predecessors.begin());
			while (predecessors_it != predecessors.end())
			{
				std::vector<char> pred(predecessors_it->second);
				for (int i(0); i < pred.size(); i++)
				{
					std::map<char, Activity>::iterator origin(activities.find(pred[i]));
					if (origin == activities.end())
					{
						std::stringstream msg;
						msg << "There is no activity whose ID is " << origin->first << "!!!";
						throw utilities::Exception(msg.str());
					}
					std::map<char, Activity>::iterator destiny(activities.find(predecessors_it->first));
					if (destiny == activities.end())
					{
						std::stringstream msg;
						msg << "There is no activity whose ID is " << destiny->first << "!!!";
						throw utilities::Exception(msg.str());
					}
					graph_->connect(origin->second, destiny->second);
				}
				predecessors_it++;
			}

		}

		bool CPM::isRegistered(const Activity &activity)
		{
			return graph_->hasVertex(activity);
		}

		double CPM::max(double d1, double d2) const
		{
			return d1 > d2 ? d1 : d2;
		}

	}

}
