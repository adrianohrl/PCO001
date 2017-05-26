/**
 * This source file implements a main function in order to test the
 * functionalities of the created Huffman Encoder and Decoder classes.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <iostream>
#include "utilities/compression/huffman/decoder.h"
#include "utilities/compression/huffman/encoder.h"

using namespace utilities::compression::huffman;

int main()
{
    std::cout << "\nTesting Huffman classes:\n";
    Encoder encoder(Encoder::getEncoder("../PCO001", "map1", ".txt"));
    encoder.process();
    std::cout << "\nEncoder imported text size: " << encoder.getImportedTextSizeInBits() << " [bits]";
    std::cout << "\nEncoder exported text size: " << encoder.getExportedTextSizeInBits() << " [bits]";
    try
    {
        std::cout << "\nEncoder compression rate: " << encoder.getConversionRate() * 100 << "%";
    }
    catch (utilities::Exception e)
    {
        std::cout << "\nException catched: " << e.what();
    }
    Decoder decoder(Decoder::getDecoder("../PCO001", "map2", ".txt"));
    decoder.process();
    std::cout << "\nDecoder imported text size: " << decoder.getImportedTextSizeInBits() << " [bits]";
    std::cout << "\nDecoder exported text size: " << decoder.getExportedTextSizeInBits() << " [bits]";
    try
    {
        std::cout << "\nDecoder compression rate: " << decoder.getConversionRate();
    }
    catch (utilities::Exception e)
    {
        std::cout << "\nException catched: " << e.what();
    }
    std::cout << "\n\n;";
    return EXIT_SUCCESS;
}
