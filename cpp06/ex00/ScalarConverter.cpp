/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:33:57 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/25 15:34:01 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
// #include <iomanip>
// std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f"<< std::endl;


void convertFloat(float d, char sign)
{
    if (sign)
    {
        d = d * (-1);
    }
    if (d >= CHAR_MIN && d <= CHAR_MAX && std::isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= CHAR_MIN && d <= CHAR_MAX)
        std::cout << "char: is not displayable" << std::endl;
    else
        std::cout << "char: conversion is impossible." << std::endl;
    if (d >= INT_MIN && d <= (float)INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: conversion is impossible." << std::endl;
    if (std::isinf(d) || std::isnan(d) || (d >= -FLT_MAX && d <= FLT_MAX))
        std::cout << "float: " << static_cast<float>(d) << "f"<< std::endl;
    else
        std::cout << "float: conversion is impossible." << std::endl;
    if (std::isinf(d) || std::isnan(d) || (d >= -DBL_MAX && d <= DBL_MAX))
    {
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    }
    else
        std::cout << "double: conversion is impossible." << std::endl;
    }

void convertDouble(double d, char sign)
{
    if (sign)
    {
        d = d * (-1);
    }
     if (d >= CHAR_MIN && d <= CHAR_MAX && std::isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= CHAR_MIN && d <= CHAR_MAX)
        std::cout << "char: is not displayable" << std::endl;
    else
        std::cout << "char: conversion is impossible." << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: conversion is impossible." << std::endl;
    if (std::isinf(d) || std::isnan(d) || (d >= -FLT_MAX && d <= FLT_MAX))
        std::cout << "float: " << static_cast<float>(d) << "f"<< std::endl;
    else
        std::cout << "float: conversion is impossible." << std::endl;
    if (std::isinf(d) || std::isnan(d) || (d >= -DBL_MAX && d <= DBL_MAX))
    {
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    }
    else
        std::cout << "double: conversion is impossible." << std::endl;
}

void convertInt(int d, char sign)
{
    if (sign)
    {
        d = d * (-1);
    }
    if (d >= CHAR_MIN && d <= CHAR_MAX && std::isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= CHAR_MIN && d <= CHAR_MAX)
        std::cout << "char: is not displayable" << std::endl;
    else
        std::cout << "char: conversion is impossible." << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: conversion is impossible." << std::endl;
    if (std::isinf(d) || std::isnan(d) || (d >= -FLT_MAX && d <= FLT_MAX))
    {   
        std::cout << "float: " << static_cast<float>(d) << "f"<< std::endl;
    }
    else
    {
        std::cout << "float: conversion is impossible." << std::endl;
    }
    if (std::isinf(d) || std::isnan(d) || (d >= -DBL_MAX && d <= DBL_MAX))
    {
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    }
    else
        std::cout << "double: conversion is impossible." << std::endl;
}

void ScalarConverter::convert(std::string& literal) 
{
    bool sign = false;
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" <<std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" <<std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return; 
    }
    if (literal[0] == '-' && std::isdigit(literal[1]))
    {
        literal = literal.substr(1, literal.length());
        sign = true;
    }  
    if ((literal[literal.length() - 1] == 'f' && std::isdigit(literal[0])) ||
        (literal == "-inff") || (literal == "+inff") || (literal == "nanf") || (literal == "inff"))
    {
        literal = literal.substr(0, literal.length() -1);
        char *end;
        float f = strtof(literal.c_str(), &end);
        if (*end != '\0')
        {
            std::cout << "Error: literal seems as a float but cant be converted to float" << std::endl;
            return;
        }
        convertFloat(f, sign);
    }
    else if ((literal.find('.') != std::string::npos) || 
        (literal == "-inf" || literal == "+inf" ||
            literal == "nan" || literal == "inf"))
    {
        char *end;
        double d = strtod(literal.c_str(), &end);
        if (*end != '\0')
        {
            std::cout << "double: conversion is impossible." << std::endl;
            return;
        }
        convertDouble(d, sign);
    }
    else if (std::isdigit(literal[0]))
    {
        char *end;
        int j = 0;
        long int i = strtol(literal.c_str(), &end, 10);
        if (*end != '\0')
        {
            std::cout << "Error: literal seems to be an int but cant be converted to int" << std::endl;
            return;
        }
        if (i >= INT_MIN && i <= INT_MAX)
            j = static_cast<int>(i);
        else 
        {
            std::cout << "Error: literal seems to be an int but cant be converted to int" << std::endl;
            return;
        }
        convertInt(j, sign);
    }
}