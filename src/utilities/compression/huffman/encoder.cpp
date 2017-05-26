/**
 * This source file implements the Compression Encoder class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/compression/huffman/encoder.h"
#include <iostream>

using namespace utilities::trees::binary_search_tree;

namespace utilities
{

namespace compression
{

namespace huffman
{

Encoder::Encoder(std::string path, std::string file_name, std::string in_extension)
    : Converter(path, file_name, in_extension, ".huf")
{}

Encoder::Encoder(const Encoder &encoder)
    : Converter(encoder),
      counters_(encoder.counters_)
{}

Encoder::~Encoder()
{}

Encoder Encoder::getEncoder(std::string path, std::string file_name, std::string in_extension)
{
    return Encoder(path, file_name, in_extension);
}

void Encoder::convert()
{
    countLetterFrequency();
    mapLetters();
    std::vector<bool> bits(Converter::getBits((long) letters_map_.size()));
    std::map<unsigned char, std::string>::iterator it(letters_map_.begin());
    std::vector<bool> letter, size, code;
    while (it != letters_map_.end())
    {
        letter = Converter::getBits((char) it->first);
        bits.insert(bits.end(), letter.begin(), letter.end());
        size = Converter::getBits((char) it->second.size());
        bits.insert(bits.end(), size.begin(), size.end());
        code = Converter::getBits(it->second.c_str());
        bits.insert(bits.end(), code.begin(), code.end());
        it++;
    }
    std::string content(Converter::getImportedText());
    for (int i(0); i < content.size(); i++)
    {
        unsigned char c(content.at(i));
        std::vector<bool> code(Converter::getBits(letters_map_[c].c_str()));
        bits.insert(bits.end(), code.begin(), code.end());
    }
    std::cout << "\nBits Enconder:\n";
    for (int i(0); i < bits.size(); i++)
    {
        std::cout << (bits[i] ? "1" : "0");
    }
    std::cout << "\n\n";
    Converter::append(bits);
}

void Encoder::countLetterFrequency()
{
    std::string text(Converter::getImportedText());
    for (int i(0); i < text.size(); i++)
    {
        increment(text.at(i));
    }
}

void Encoder::increment(unsigned char c)
{
    if (counters_.find(c) == counters_.end())
    {
        counters_.insert(std::pair<unsigned char, long>(c, 1));
    }
    else
    {
        counters_[c]++;
    }
}

void Encoder::mapLetters()
{
    std::map<unsigned char, long>::iterator it(counters_.begin());
    std::priority_queue<Node<long, unsigned char>, std::vector<Node<long, unsigned char> >, Comparison> tree_queue;
    while (it != counters_.end())
    {
        Node<long, unsigned char> tree(it->second, it->first);
        tree_queue.push(tree);
        it++;
    }
    while (tree_queue.size() != 1)
    {
        Node<long, unsigned char> *subtree1 = new Node<long, unsigned char>(tree_queue.top());
        tree_queue.pop();
        Node<long, unsigned char> *subtree2 = new Node<long, unsigned char>(tree_queue.top());
        tree_queue.pop();
        Node<long, unsigned char> tree(subtree1->getKey() + subtree2->getKey(), '\0', subtree1, subtree2);
        tree_queue.push(tree);
    }    
    mapLetters(tree_queue.top());
    tree_queue.pop();
}

void Encoder::mapLetters(utilities::trees::binary_search_tree::Node<long, unsigned char> tree, std::string code)
{
    if (tree.isLeaf())
    {
        letters_map_[tree.getElement()] = code;
        return;
    }
    if (tree.hasLeft())
    {
        mapLetters(*tree.getLeft(), code + "0");
    }
    if (tree.hasRight())
    {
        mapLetters(*tree.getRight(), code + "1");
    }
}

void Encoder::encode(std::string path, std::string file_name, std::string in_extension)
{
    Encoder encoder(path, file_name, in_extension);
    encoder.process();
}

}

}

}

