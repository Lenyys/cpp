/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:00:28 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/01 16:00:29 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"
#include <cmath>
#include <cctype>


void uppercase_char(char & c)
{
    c = std::toupper(c);
}

void lowercase_string(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        str[i] = std::tolower(str[i]);
    }
}

void add_2(int & value)
{
    value += 2;
}

void add_double(double & value)
{
    value += 2.1;
}


int main(void)
{
    std::cout << "Test 1: testing integers (printElement)" << std::endl;
    int numbers[] = {1, 4, 5, 2};
    iter(numbers, sizeof(numbers)/sizeof(numbers[0]), printElement<int>);
    std::cout << std::endl;

    std::cout << "Test 2: testing integers (add_2)" << std::endl;
    iter(numbers, sizeof(numbers)/sizeof(numbers[0]), add_2);
    iter(numbers, sizeof(numbers)/sizeof(numbers[0]), printElement<int>);
    std::cout << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "Test 3: testing strings (printElement)" << std::endl;
    std::string strings[] = {"APPLE", "BANANA", "CHERRY"};
    iter(strings, sizeof(strings)/sizeof(strings[0]), printElement<std::string>);
    std::cout << std::endl;

    std::cout << "Test 4: testing strings (lowercase_string)" << std::endl;
    iter(strings, sizeof(strings)/sizeof(strings[0]), lowercase_string);
    iter(strings, sizeof(strings)/sizeof(strings[0]), printElement<std::string>);
    std::cout << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "Test 5: testing char (printElement)" << std::endl;
    char array[] = {'a', 'h', 'o', 'j'};
    iter<char>(array, sizeof(array)/sizeof(array[0]), printElement<char>);
    std::cout << std::endl;

    std::cout << "Test 6: testing char (uppercase_char)" << std::endl;
    iter<char>(array, sizeof(array)/sizeof(array[0]), uppercase_char);
    iter<char>(array, sizeof(array)/sizeof(array[0]), printElement<char>);
    std::cout << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "Test 7: testing double (printElement)" << std::endl;
    double double_numbers[] = {1.2, 4.2, 5.6, 2.8};
    iter(double_numbers, sizeof(double_numbers)/sizeof(double_numbers[0]), printElement<double>);
    std::cout << std::endl;

    std::cout << "Test 8: testing double (add_double)" << std::endl;
    iter(double_numbers, sizeof(double_numbers)/sizeof(double_numbers[0]), add_double);
    iter(double_numbers, sizeof(double_numbers)/sizeof(double_numbers[0]), printElement<double>);
    std::cout << std::endl;

    return 0;
}