/**
 * This header file defines the Compression Decoder class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include <map>
#include "utilities/compression/Converter.h"

namespace utilities
{

namespace compression
{

namespace huffman
{

class Decoder : public Converter
{
public:
    Decoder(const Decoder &decoder);
    virtual ~Decoder();
    static Decoder getDecoder(std::string path, std::string file_name, std::string out_extension);
    static void decode(std::string path, std::string file_name, std::string out_extension);
protected:
    Decoder(std::string path, std::string file_name, std::string out_extension);
    virtual void convert();
private:
    std::map<std::string, unsigned char> codes_map_;
    long mapLetters();
};

}

}

}

#endif // HUFFMAN_DECODER_H
