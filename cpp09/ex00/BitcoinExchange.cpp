/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:38:45 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/08 11:38:47 by lmaresov         ###   ########.fr       */
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
    std::getline(file, line);
    while(std::getline(file, line))
    {
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
                std::cerr << "Error: too large a number." << std::endl;
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