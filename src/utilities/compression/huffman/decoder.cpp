/**
 * This source file implements the Compression Decoder class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include<iostream>
#include "utilities/compression/huffman/decoder.h"

namespace utilities
{

namespace compression
{

namespace huffman
{

Decoder::Decoder(std::string path, std::string file_name, std::string out_extension)
    : Converter(path, file_name, ".huf", out_extension)
{}

Decoder::Decoder(const Decoder &decoder)
    : Converter(decoder),
      codes_map_(decoder.codes_map_)
{}

Decoder::~Decoder()
{}

Decoder Decoder::getDecoder(std::string path, std::string file_name, std::string out_extension)
{
    return Decoder(path, file_name, out_extension);
}

void Decoder::convert()
{
    long index(mapLetters());
    std::vector<bool> bits(Converter::getBits(Converter::getImportedText()));
    std::string content(Converter::getString(std::vector<bool>(bits.begin() + index, bits.end())));
    std::string code;
    std::map<std::string, unsigned char>::iterator it;
    for (int i(0); i < content.size(); i++)
    {
        code += content[i];
        it = codes_map_.find(code);
        if (it != codes_map_.end())
        {
            char c(it->second);
            Converter::append(c);
            code = "";
        }
    }
}

long Decoder::mapLetters()
{
    long index(32);
    std::vector<bool> bits(Converter::getBits(Converter::getImportedText()));
    long letters(Converter::getLong(std::vector<bool>(bits.begin(), bits.begin() + index)));
    for (int i(0); i < letters; i++)
    {
        unsigned char c(Converter::getChar(std::vector<bool>(bits.begin() + index, bits.begin() + index + 8)));
        index += 8;
        char size(Converter::getChar(std::vector<bool>(bits.begin() + index, bits.begin() + index + 8)));
        index += 8;
        std::string code(Converter::getString(std::vector<bool>(bits.begin() + index, bits.begin() + index + size)));
        index += size;
        codes_map_[code] = c;
    }
    return index;
}

void Decoder::decode(std::string path, std::string file_name, std::string out_extension)
{
    Decoder decoder(path, file_name, out_extension);
    decoder.process();
}

}

}

}

