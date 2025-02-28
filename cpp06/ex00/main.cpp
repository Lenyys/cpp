/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:34:28 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/25 15:34:29 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
    
    if (argc != 2)
    {
        std::cout << "run program as ./convert <param>" << std::endl;
        return 0;
    }
    std::string literal = argv[1];
    ScalarConverter::convert(literal);

// tests for int main(void)

    // std::string int_number;
    // std::string float_number;
    // std::string double_number;
    // std::string char_literal;
    
    // int_number = "98";
    // std::cout << "convert int " << int_number << std::endl;
    // ScalarConverter::convert(int_number);
    // std::cout << "________________________" << std::endl;
    // int_number = "4";
    // std::cout << "convert int " << int_number << std::endl;
    // ScalarConverter::convert(int_number);
    // std::cout << "________________________" << std::endl;
    // int_number = "-42";
    // std::cout << "convert int " << int_number << std::endl;
    // ScalarConverter::convert(int_number);
    // std::cout << "------------------------------------------" << std::endl;
    

    // float_number = "99.9999f";
    // std::cout << "convert float " << float_number << std::endl;
    // ScalarConverter::convert(float_number);
    // std::cout << "________________________" << std::endl;
    // float_number = "0.0f";
    // std::cout << "convert float " << float_number << std::endl;
    // ScalarConverter::convert(float_number);
    // std::cout << "________________________" << std::endl;
    // float_number = "-4.2f";
    // std::cout << "convert float " << float_number << std::endl;
    // ScalarConverter::convert(float_number);
    // std::cout << "________________________" << std::endl;
    // float_number = "-inff";
    // std::cout << "convert float " << float_number << std::endl;
    // ScalarConverter::convert(float_number);
    // std::cout << "________________________" << std::endl;
    // float_number = "+inff";
    // std::cout << "convert float " << float_number << std::endl;
    // ScalarConverter::convert(float_number);
    // std::cout << "________________________" << std::endl;
    // float_number = "nanf";
    // std::cout << "convert float " << float_number << std::endl;
    // ScalarConverter::convert(float_number);
    // std::cout << "------------------------------------------" << std::endl;
    

    // double_number = "100.2";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // double_number = "0.0";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // double_number = "4.2";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // double_number = "-4.2";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // double_number = "-inf";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // double_number = "+inf";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // double_number = "nan";
    // std::cout << "convert double " << double_number << std::endl;
    // ScalarConverter::convert(double_number);
    // std::cout << "________________________" << std::endl;
    // std::cout << "------------------------------------------" << std::endl;
    

    // char_literal = "a";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;
    // char_literal = "A";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;
    // char_literal = "z";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;
    // char_literal = "Z";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;
    // char_literal = "*";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;
    // char_literal = " ";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;
    // char_literal = ".";
    // std::cout << "convert char " << char_literal << std::endl;
    // ScalarConverter::convert(char_literal);
    // std::cout << "________________________" << std::endl;

    return 0;
}