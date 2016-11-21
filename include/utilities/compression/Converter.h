/**
 * This header file defines the Compression Converter class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef COMPRESSION_CONVERTER_H
#define COMPRESSION_CONVERTER_H

#include <vector>
#include <sstream>
#include <fstream>
#include "utilities/Exception.h"

namespace utilities
{

namespace compression
{

class Converter
{
public:
    Converter(const Converter &converter);
    virtual ~Converter();
    long getImportedTextSizeInBits();
    long getExportedTextSizeInBits();
    float getConversionRate();
    virtual void process();
protected:
    Converter(std::string path, std::string file_name, std::string in_extension, std::string out_extension);
    virtual void importFile();
    virtual void convert() = 0;
    virtual void exportFile() const;
    std::string getImportedText() const;
    std::vector<bool> getBits(char c) const;
    std::vector<bool> getBits(long n) const;
    std::vector<bool> getBits(const char *str) const;
    std::vector<bool> getBits(std::string str) const;
    unsigned char getChar(std::vector<bool> bits) const;
    long getLong(std::vector<bool> bits) const;
    std::string getString(std::vector<bool> bits) const;
    void append(std::vector<bool> bits);
    void append(unsigned char c);
private:
    std::string imported_file_name_;
    std::stringstream imported_file_content_;
    std::string exported_file_name_;
    std::stringstream exported_file_content_;
    bool exists() const;
};

}

}

#endif // COMPRESSION_CONVERTER_H
