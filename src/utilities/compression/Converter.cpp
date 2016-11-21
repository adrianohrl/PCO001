/**
 * This source file implements the Compression Converter class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <iostream>
#include "utilities/compression/Converter.h"

namespace utilities
{

namespace compression
{

Converter::Converter(std::string path, std::string file_name, std::string in_extension, std::string out_extension)
    : imported_file_name_(""),
      exported_file_name_("")
{
    if (path.empty())
    {
        path = "./";
    }
    if (path.at(path.size() - 1) != '/')
    {
        path += "/";
    }
    if (file_name.empty())
    {
        throw Exception("The file name must not be empty!!!");
    }
    if (in_extension.empty())
    {
        throw Exception("The file (to be imported) extension must not be empty!!!");
    }
    if (in_extension.at(0) != '.')
    {
        in_extension = "." + in_extension;
    }
    if (out_extension.empty())
    {
        throw Exception("The file (to be exported) extension must not be empty!!!");
    }
    if (out_extension.at(0) != '.')
    {
        out_extension = "." + out_extension;
    }
    imported_file_name_ = path + file_name + in_extension;
    exported_file_name_ = path + file_name + out_extension;
}

Converter::Converter(const Converter &converter)
    : imported_file_name_(converter.imported_file_name_),
      exported_file_name_(converter.exported_file_name_)
{
    imported_file_content_ << converter.imported_file_content_.rdbuf();
    exported_file_content_ << converter.exported_file_content_.rdbuf();
}

Converter::~Converter()
{}

long Converter::getImportedTextSizeInBits()
{
    return imported_file_content_.str().length() * 8;
}

long Converter::getExportedTextSizeInBits()
{
    return exported_file_content_.str().length() * 8;
}

float Converter::getConversionRate()
{
    long imported_text_size(getImportedTextSizeInBits());
    long exported_text_size(getExportedTextSizeInBits());
    if (imported_text_size == 0)
    {
        throw Exception("Imported file is empty!!!");
    }
    if (exported_text_size == 0)
    {
        throw Exception("Exported file is empty!!!");
    }
    return (float) exported_text_size / (float) imported_text_size;
}

void Converter::process()
{
    importFile();
    convert();
    exportFile();
}

bool Converter::exists() const
{
    return true;
}

void Converter::importFile()
{
    if (!exists())
    {
        throw Exception("The file to be imported does not exist!!!");
    }
    std::ifstream file;
    file.open(imported_file_name_.c_str(), std::ifstream::in);
    if (!file.is_open())
    {
      file.close();
      throw Exception("Inexistent file path!!!");
    }
    imported_file_content_ << file.rdbuf();
    file.close();
}

void Converter::exportFile() const
{
    std::ofstream file;
    file.open(exported_file_name_.c_str(), std::ofstream::out | std::ofstream::binary);
    if (!file.is_open())
    {
      file.close();
      throw Exception("Inexistent file path!!!");
    }
    file << exported_file_content_.rdbuf();
    file.close();
}

std::string Converter::getImportedText() const
{
    return imported_file_content_.str();
}

std::vector<bool> Converter::getBits(char c) const
{
    std::string str;
    while (c != 0)
    {
        str = (c % 2 == 0 ? "0" : "1") + str;
        c /= 2;
    }
    while (str.size() < 8)
    {
        str = "0" + str;
    }
    return getBits(str.c_str());
}

std::vector<bool> Converter::getBits(long n) const
{
    std::string str;
    while (n != 0)
    {
        str = (n % 2 == 0 ? "0" : "1") + str;
        n /= 2;
    }
    while (str.size() < 32)
    {
        str = "0" + str;
    }
    return getBits(str.c_str());
}

std::vector<bool> Converter::getBits(const char *str) const
{
    std::vector<bool> bits;
    for (int i(0); str[i] != '\0'; i++)
    {
        bits.push_back(str[i] == '0' ? 0 : 1);
    }
    return bits;
}

std::vector<bool> Converter::getBits(std::string str) const
{
    std::vector<bool> bits;
    for (int i(0); i < str.size(); i++)
    {
        unsigned char c(str[i]);
        for (int j(7); j >= 0; j--)
        {
            bits.push_back((c >> j) & 1);
        }
    }
    return bits;
}

unsigned char Converter::getChar(std::vector<bool> bits) const
{
    unsigned char c;
    for (int i(bits.size() - 1); i >= 0; i--)
    {
        if (bits[i])
        {
            c += 1 << (7 - i);
        }
    }
    return c;
}

long Converter::getLong(std::vector<bool> bits) const
{
    long n(0);
    for (int i(bits.size() - 1); i >= 0; i--)
    {
        if (bits[i])
        {
            n += 1 << (31 - i);
        }
    }
    return n;
}

std::string Converter::getString(std::vector<bool> bits) const
{
    std::string str;
    for (int i(0); i < bits.size(); i++)
    {
        str += bits[i] ? "1" : "0";
    }
    return str;
}

void Converter::append(std::vector<bool> bits)
{
    for (int i(0); i < bits.size(); i += 8)
    {
        std::vector<bool> letter(bits.begin() + i, bits.begin() + i + 8);
        unsigned char c(getChar(letter));
        exported_file_content_ << c;
    }
}

void Converter::append(unsigned char c)
{
    exported_file_content_ << c;
}

}

}
