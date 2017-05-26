/**
 * This source file implements the Exception class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#include "utilities/exception.h"

namespace utilities
{

Exception::Exception(std::string message) : message_(message.c_str()) {}

Exception::Exception(const char* message) : message_(message) {}

const char* Exception::what() const throw() { return message_; }
}
