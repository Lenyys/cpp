/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:42:51 by lmaresov          #+#    #+#             */
/*   Updated: 2025/08/16 14:29:56 by lmaresov         ###   ########.fr       */
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

    BitcoinExchange bitcoin("data2.csv");
    bitcoin.processFile(filename);

    return 0;
}