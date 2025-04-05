/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:38:38 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/08 11:38:40 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>


class  BitcoinExchange 
{
    private:
        std::map<std::string, double> exchangeRates;

    public:
        BitcoinExchange(const std::string & filename);
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange & operator=(const BitcoinExchange & other);
        ~BitcoinExchange();
        
        void loadDatabase(const std::string &filename);
        double getClosestRate(const std::string &date) const;
        void processFile(const std::string &filename);
        bool isLeapYear(int year);
        bool isValidDate(const std::string& date);
};

#endif