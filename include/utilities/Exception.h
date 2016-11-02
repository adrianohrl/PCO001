/**
 * This header file defines the Exception class.
 *
 * Author: Adriano Henrique Rossette Leite (2016101518)
 * Subject: Algoritmos e Estruturas de Dados (PCO001)
 * Institution: Universidade Federal de Itajubá
 * E-mail: adrianohrl@unifei.edu.br
 * Version: 1.0.0
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>

namespace utilities
{

class Exception : public std::exception
{
public:
  Exception(std::string message);
  Exception(const char* message);
  virtual const char* what() const throw();
private:
  const char* message_;
};

}


#endif // EXCEPTION_H
