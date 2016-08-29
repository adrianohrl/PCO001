/**
 * This source file implements a main function in order to test the functionalities of the created
 * DisjointSet class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "homeworks/homework1/PhoneBook.h"

#define NUMBER_OF_OPTIONS 6
#define INT_MAX 1

using typename homeworks::homework1::PersonInfo;
using typename homeworks::homework1::PhoneBook;

void printMenu();
bool process(int option);
PersonInfo query(int option);

static PhoneBook phone_book("PCO001");

int main()
{
	int option;
	while (true)
	{
		printMenu();
		std::cin >> option;
		if (option > 0 && option <= NUMBER_OF_OPTIONS)
		{
			std::cout << "\nOption number " << option << " was selected.\n";
			if (!process(option))
			{
				break;
			}
		}
		else
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX);
				std::cout << "\nPlease, enter an integer!!!";
			}
			else
			{
				std::cout << "\nInvalid option: " << option << "!!!";
			}
		}
	}
	return EXIT_SUCCESS;
}


void printMenu()
{
	std::cout << "\n\n*************************************************\n";
	std::cout << "* Enter the desired option number:              *\n";
	std::cout << "* 1) Insert new person info;                    *\n";
	std::cout << "* 2) Find a person info;                        *\n";
	std::cout << "* 3) Remove a person;                           *\n";
	std::cout << "* 4) Print the phone book in ascending order;   *\n";
	std::cout << "* 5) Print the phone book in descending order;  *\n";
	std::cout << "* 6) Quit.                                      *\n";
	std::cout << "*************************************************\n";
	std::cout << "\nOption number: ";
}

bool process(int option)
{
	std::string verb = "";
	bool succeeded = false;
	PersonInfo info;
	if (option > 0 && option < 4)
	{
		info = query(option);
	}
	switch (option)
	{
		case 1:
			verb = "inserted to";
			succeeded = phone_book.insert(info);
			break;
		case 2:
			info = phone_book.find(info);
			if (info.isValid())
			{
				std::cout << "\nFound: "
									<< "\nName: " << info.getName()
									<< "\nPhone Number: " << info.getPhoneNumber()
									<< "\nAdditional: " << info.getAdditional();
			}
			else
			{
				std::cout << "\nNot found!!!";
			}
			break;
		case 3:
			verb = "removed from";
			succeeded = phone_book.remove(info);
			break;
		case 4:
			std::cout << "\nPrinting phone book in ascending order:\n" << phone_book.toString();
			break;
		case 5:
			std::cout << "\nPrinting phone book in ascending order:\n" << phone_book.toString(false);
			break;
		case 6:
			std::cout << "\nQuitting!!!\n";
			return false;
		default:
			std::cout << "\nInvalid option!!!";
	}
	if (verb != "")
	{
		std::cout << "\n" << info.getName()
							<< " was " << (succeeded ? "successfully " : "NOT ")
							<< verb << " the phone book.\n";
	}
	return true;
}

PersonInfo query(int option)
{
	if (option < 1 || option > 3)
	{
		std::cout << "\nInvalid option";
		return PersonInfo();
	}
	std::string name, phone_number = "", additional = "";
	std::cout << "Enter the person info:\n";
	std::cout << "Name: ";
	std::cin.ignore(INT_MAX, '\n');
	std::cin.clear();
	std::getline(std::cin, name);
	if (option == 1)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phone_number);
		std::cout << "Additional: ";
		std::getline(std::cin, additional);
	}
	return PersonInfo(name, phone_number, additional);
}
