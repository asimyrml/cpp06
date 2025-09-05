#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
private:
    // Non-instantiable
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    // Helpers
    static bool isSpecialLiteral(const std::string &input);
    static void validateInput(const std::string &input);

    static void printChar(const std::string &input);
    static void printInt(const std::string &input);
    static void printFloat(const std::string &input);
    static void printDouble(const std::string &input);

public:
    static void convert(const std::string &input);
};

#endif
