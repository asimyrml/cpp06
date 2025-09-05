#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>

// -------------------- Private CTOR/DTOR --------------------
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

// -------------------- Helpers --------------------
bool ScalarConverter::isSpecialLiteral(const std::string &input)
{
    return (input == "nan" || input == "nanf" ||
            input == "+inf" || input == "-inf" ||
            input == "+inff" || input == "-inff");
}

void ScalarConverter::validateInput(const std::string &input)
{
    if (isSpecialLiteral(input) || input.length() == 1)
        return;

    const std::string allowed = "0123456789f.+-";
    for (size_t i = 0; i < input.length(); i++)
    {
        if (allowed.find(input[i]) == std::string::npos)
            throw std::invalid_argument("Error: invalid characters in input");
    }
}

// -------------------- Conversion Helpers --------------------
bool parseInt(const std::string &s, int &out)
{
    std::istringstream iss(s);
    iss >> out;
    return !iss.fail() && iss.eof();
}

bool parseFloat(const std::string &s, float &out)
{
    char *end;
    out = static_cast<float>(std::strtod(s.c_str(), &end));
    return (*end == '\0');
}

bool parseDouble(const std::string &s, double &out)
{
    char *end;
    out = std::strtod(s.c_str(), &end);
    return (*end == '\0');
}

// -------------------- Printers --------------------
void ScalarConverter::printChar(const std::string &input)
{
    std::cout << "char: ";
    if (isSpecialLiteral(input))
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        std::cout << "'" << input[0] << "'" << std::endl;
        return;
    }

    int val;
    if (parseInt(input, val))
    {
        if (val < 32 || val > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printInt(const std::string &input)
{
    std::cout << "int: ";
    if (isSpecialLiteral(input))
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    int val;
    if (parseInt(input, val))
        std::cout << val << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printFloat(const std::string &input)
{
    std::cout << "float: ";
    if (input == "nan" || input == "nanf")
        std::cout << "nanf" << std::endl;
    else if (input == "+inf" || input == "+inff")
        std::cout << "+inff" << std::endl;
    else if (input == "-inf" || input == "-inff")
        std::cout << "-inff" << std::endl;
    else
    {
        float val;
        if (parseFloat(input, val))
        {
            if (val == static_cast<int>(val))
                std::cout << val << ".0f" << std::endl;
            else
                std::cout << val << "f" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
}

void ScalarConverter::printDouble(const std::string &input)
{
    std::cout << "double: ";
    if (input == "nan" || input == "nanf")
        std::cout << "nan" << std::endl;
    else if (input == "+inf" || input == "+inff")
        std::cout << "+inf" << std::endl;
    else if (input == "-inf" || input == "-inff")
        std::cout << "-inf" << std::endl;
    else
    {
        double val;
        if (parseDouble(input, val))
        {
            if (val == static_cast<int>(val))
                std::cout << val << ".0" << std::endl;
            else
                std::cout << val << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
}

// -------------------- Public --------------------
void ScalarConverter::convert(const std::string &input)
{
    try {
        validateInput(input);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    printChar(input);
    printInt(input);
    printFloat(input);
    printDouble(input);
}
