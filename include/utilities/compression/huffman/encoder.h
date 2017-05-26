/**
 * This header file defines the Compression Encoder class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef HUFFMAN_ENCODER_H
#define HUFFMAN_ENCODER_H

#include <queue>
#include <map>
#include "utilities/compression/converter.h"
#include "utilities/trees/binary_search_tree/node.h"

namespace utilities
{

namespace compression
{

namespace huffman
{

class Comparison
{
  public:
    bool operator()(utilities::trees::binary_search_tree::Node<long, unsigned char> node1, utilities::trees::binary_search_tree::Node<long, unsigned char> node2)
    {
        return node1.getKey() > node2.getKey();
    }
};

class Encoder : public Converter
{
public:
    Encoder(const Encoder &encoder);
    virtual ~Encoder();
    static Encoder getEncoder(std::string path, std::string file_name, std::string in_extension);
    static void encode(std::string path, std::string file_name, std::string in_extension);
protected:
    Encoder(std::string path, std::string file_name, std::string in_extension);
    virtual void convert();
private:
    std::map<unsigned char, long> counters_;
    std::map<unsigned char, std::string> letters_map_;
    void countLetterFrequency();
    void increment(unsigned char c);
    void mapLetters();
    void mapLetters(utilities::trees::binary_search_tree::Node<long, unsigned char> tree, std::string code = "");
};

}

}

}

#endif // HUFFMAN_ENCODER_H
