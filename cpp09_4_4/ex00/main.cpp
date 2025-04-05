/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:42:51 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/08 11:42:52 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc input.txt" << std::endl;
        return (0);
    }
    std::string filename = argv[1];

    BitcoinExchange bitcoin("data.csv");
    bitcoin.processFile(filename);

    return 0;
}