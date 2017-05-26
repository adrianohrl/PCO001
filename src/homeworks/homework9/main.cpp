/**
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "homeworks/homework9/highway_map.h"

#define NUMBER_OF_OPTIONS 6
#define INVALID_INTEGER -32768

using namespace homeworks::homework9;

void printMenu();
bool process(HighwayMap **map, int option);
int query(std::string message);
std::string queryString(std::string message);

void importMap(HighwayMap **map);
void showMap(HighwayMap *map);
void showItinerary(HighwayMap *map);
void showCities(HighwayMap *map);
void showHighways(HighwayMap *map);
void printItinerary(std::list<City> itinerary, double distance);

int main()
{
	HighwayMap *map = NULL;
	int option;
	bool keep_going(true);
	while (keep_going)
  {
    printMenu();
		option = query("Option number");
    if (option > 0 && option <= NUMBER_OF_OPTIONS)
    {
      std::cout << "\nOption number " << option << " was selected.\n";
			keep_going = process(&map, option);
		}
    else
    {
			std::cout << "\nInvalid option: " << option << "!!!";
    }
	}
	std::cout << "\nQuitting!!!\n";
	if (map)
	{
		delete map;
	}
	return EXIT_SUCCESS;
}

void printMenu()
{
	std::cout << "\n";
	std::cout << "\n********************************";
	std::cout << "\n* Enter the desired option:    *";
	std::cout << "\n* 1) Import new map;           *";
	std::cout << "\n* 2) Show map;                 *";
	std::cout << "\n* 3) Show itinerary;           *";
	std::cout << "\n* 4) Show registered cities;   *";
	std::cout << "\n* 5) Show registered highways; *";
	std::cout << "\n* 6) Quit.                     *";
	std::cout << "\n********************************";
}

bool process(HighwayMap **map, int option)
{
	if (option != 1 && option != NUMBER_OF_OPTIONS && !*map)
	{
		std::cout << "\nThe map must be built, at first!!!";
		return true;
	}
  switch (option)
  {
    case 1:
			importMap(map);
			break;
		case 2:
			showMap(*map);
			break;
		case 3:
			showItinerary(*map);
			break;
		case 4:
			showCities(*map);
			break;
		case 5:
			showHighways(*map);
			break;
		case 6:
			return false;
    default:
      std::cout << "\nInvalid option!!!";
  }
	return true;
}

int query(std::string message)
{
	int number(INVALID_INTEGER);
	std::cout << "\n" + message + ": ";
	std::cin >> number;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1, '\n');
		std::cout << "\nEntrada invalida!!!";
		return INVALID_INTEGER;
	}
	return number;
}

std::string queryString(std::string message)
{
	std::string str("");
	std::cout << "\n" + message + "\n(please, use ' ' before the entry if needed): ";
	std::cin.clear();
	std::cin.ignore(1, '\n');
	std::getline(std::cin, str);
	return std::cin.fail() ? "" : str;
}

void importMap(HighwayMap **map)
{
	std::string file_name = queryString("Enter the map file name");
	if (*map)
	{
		delete *map;
		*map = NULL;
	}
	try
	{
		*map = new HighwayMap(file_name);
	}
	catch (const utilities::Exception &e)
	{
		std::cout << "\nException catched: " << e.what();
	}
}

void showMap(HighwayMap *map)
{
	showCities(map);
	showHighways(map);
}

void showCities(HighwayMap *map)
{
	std::cout << "\nCities: ";
	std::list<City> cities(map->getCities());
	std::list<City>::iterator it(cities.begin());
	while (it != cities.end())
	{
		std::cout << "\n\t" << *it++;
	}
}

void showHighways(HighwayMap *map)
{
	std::cout << "\nHighways: ";
	std::list<Highway> highways(map->getHighways());
	std::list<Highway>::iterator it(highways.begin());
	while (it != highways.end())
	{
		std::cout << "\n\t" << *it++;
	}
}

void showItinerary(HighwayMap *map)
{
	try
	{
		City origin(queryString("Enter the origin city name"));
		City destiny(queryString("Enter the destiny city name"));
		std::list<City> itinerary(map->getItinerary(origin, destiny));
		double distance(map->getItineraryTotalDistance(itinerary.back()));
		printItinerary(itinerary, distance);
	}
	catch (const utilities::Exception &e)
	{
		std::cout << "\nException catched: " << e.what();
	}
}

void printItinerary(std::list<City> itinerary, double distance)
{
	std::list<City>::const_iterator it(itinerary.begin());
	std::cout << "\nGoing from " << itinerary.front() << " to " << itinerary.back() << ":";
	int counter(1);
	while (*it != itinerary.back())
	{
		std::cout << "\n\t" << counter++ << ") go from " << it->getName() << " to ";
		it++;
		std::cout << it->getName() << ";";
	}
	std::cout << "\nTotal distance: " << distance << "[km].";
}
