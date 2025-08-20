/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:36:05 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/21 07:36:06 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"expression\" " << std::endl;
        return 0; 
    }
    RPN calculator;
    calculator.doTheMath(argv[1]);

    return 0;
}
