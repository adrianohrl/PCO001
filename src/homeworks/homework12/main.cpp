/**
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/exception.h"
#include "utilities/compression/huffman/encoder.h"
#include "utilities/compression/huffman/decoder.h"

#define NUMBER_OF_OPTIONS 8
#define INVALID_INTEGER -32768
#define MAX_NUMBER_OF_ACTIVITIES 1000

using namespace utilities::compression::huffman;

void printMenu();
bool process(int option);
int query(std::string message);
std::string queryString(std::string message);

bool encodeFile(std::string path, std::string name, std::string extension);
bool decodeFile(std::string path, std::string name, std::string extension);
bool showFileContent(std::string path, std::string name, std::string extension);
std::string getWholeFilename(std::string path, std::string name, std::string extension);

int main(int argc, const char** argv)
{
    int option;
    bool keep_going(true);
    while (keep_going)
    {
        printMenu();
        option = query("Option number");
        if (option > 0 && option <= NUMBER_OF_OPTIONS)
        {
            std::cout << "\nOption number " << option << " was selected.\n";
            keep_going = process(option);
        }
        else
        {
            std::cout << "\nInvalid option: " << option << "!!!";
        }
    }
    std::cout << "\nQuitting!!!\n";
    return EXIT_SUCCESS;
}

void printMenu()
{
	std::cout << "\n";
	std::cout << "\n********************************";
	std::cout << "\n* Enter the desired option:    *";
    std::cout << "\n* 1) Encode .TXT file;         *";
    std::cout << "\n* 2) Encode file;              *";
    std::cout << "\n* 3) Decode .TXT file;         *";
    std::cout << "\n* 4) Decode file;              *";
    std::cout << "\n* 5) Show .TXT file content;   *";
    std::cout << "\n* 6) Show .HUF file content;   *";
    std::cout << "\n* 7) Show file content;        *";
    std::cout << "\n* 8) Quit.                     *";
	std::cout << "\n********************************";
}

bool process(int option)
{
    if (option >= NUMBER_OF_OPTIONS)
    {
        return false;
    }
    std::string path(queryString("Enter the file path"));
    std::string name(queryString("Enter the file name without its extension"));
    std::string extension(".txt");
    if (option == 2 || option == 4 || option == 7)
    {
        extension = queryString("Enter the file extension");
    }
    else if (option == 6)
    {
        extension = ".huf";
    }
    switch (option)
    {
        case 1:
        case 2:
            encodeFile(path, name, extension);
            break;
        case 3:
        case 4:
            decodeFile(path, name, extension);
            break;
        case 5:
        case 6:
        case 7:
            showFileContent(path, name, extension);
            break;
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
        std::cout << "\nInvalid entry!!!";
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

bool encodeFile(std::string path, std::string name, std::string extension)
{
    try
    {;
        Encoder encoder(Encoder::getEncoder("../PCO001", "map", ".txt"));
        encoder.process();
        std::cout << "\nEncoder imported text size: " << encoder.getImportedTextSizeInBits() << " [bits]";
        std::cout << "\nEncoder exported text size: " << encoder.getExportedTextSizeInBits() << " [bits]";
        std::cout << "\nEncoder compression rate: " << encoder.getConversionRate() * 100 << "%";
    }
    catch (utilities::Exception e)
    {
        std::cout << "\nException catched: " << e.what();
    }
}

bool decodeFile(std::string path, std::string name, std::string extension)
{
    try
    {
        Decoder decoder(Decoder::getDecoder("../PCO001", "map1", ".txt"));
        decoder.process();
        std::cout << "\nDecoder imported text size: " << decoder.getImportedTextSizeInBits() << " [bits]";
        std::cout << "\nDecoder exported text size: " << decoder.getExportedTextSizeInBits() << " [bits]";
        std::cout << "\nDecoder compression rate: " << decoder.getConversionRate() * 100 << "%";
    }
    catch (utilities::Exception e)
    {
        std::cout << "\nException catched: " << e.what();
    }
}

bool showFileContent(std::string path, std::string name, std::string extension)
{
    std::ifstream file;
    file.open(getWholeFilename(path, name, extension).c_str(), std::ifstream::in);
    if (!file.is_open())
    {
      file.close();
      throw utilities::Exception("Inexistent file path!!!");
    }
    std::cout << file.rdbuf();
    file.close();
}

std::string getWholeFilename(std::string path, std::string name, std::string extension)
{
    if (path.empty())
    {
        path = "./";
    }
    if (path.at(path.size() - 1) != '/')
    {
        path += "/";
    }
    if (name.empty())
    {
        throw utilities::Exception("The file name must not be empty!!!");
    }
    if (extension.empty())
    {
        throw utilities::Exception("The file (to be imported) extension must not be empty!!!");
    }
    if (extension.at(0) != '.')
    {
        extension = "." + extension;
    }
    return path + name + extension;
}
