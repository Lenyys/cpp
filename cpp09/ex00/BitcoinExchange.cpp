/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:38:45 by lmaresov          #+#    #+#             */
/*   Updated: 2025/08/14 12:51:23 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
    loadDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
{
    exchangeRates = other.exchangeRates;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other)
{
    if (this != &other)
    {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){ }

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: opening file failed." << std::endl;
        exit(1);
    }
    std::string line, date;
    double rate;
    while (std::getline(file, line))
    {
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream stream(line);
        if (stream >> date >> rate)
        {
            exchangeRates[date] = rate;
        }
    }
}

double BitcoinExchange::getClosestRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator iter = exchangeRates.lower_bound(date);
    if (iter == exchangeRates.end() || iter->first != date)
    {
        if (iter == exchangeRates.begin())
            return -1;
        iter--;
    }
    return iter->second;
}

void BitcoinExchange::processFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: opening file failed." << std::endl;
        return ;
    }
    std::string line, date;
    double value;
    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty input file." << std::endl;
        return ;
    }
    while(std::getline(file, line))
    {   
        if (line.find('|') == std::string::npos)
        {
            std::cerr << "Error: invalid input." << std::endl;
                continue;
        }
        std::replace(line.begin(), line.end(), '|', ' ');
        std::istringstream stream(line);
        if (stream >> date >> value)
        {
            if (value < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            else if(value > 1000)
            {
                std::cerr << "Error: too large number." << std::endl;
                continue;
            }
            else if(!isValidDate(date))
            {
                std::cerr << "Error: invalid date." << std::endl;
                continue;
            }
            double rate = getClosestRate(date);
            if (rate == -1)
            {
                std::cerr << "Error: no rate found for " << date << std::endl;
                continue;
            }
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        else
        {
            std::cerr << "Error: bad input -> " << line << std::endl;
        }
    }
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    int year = atoi(date.substr(0,4).c_str());
    int month = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8,2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month -1])
        return false;
    return true;
}