/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:33:02 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 06:33:04 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "testing addNumber()" << std::endl;
    std::cout << "---------------------" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try 
    {
        sp.addNumber(5);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "testing addManyNumbers()" << std::endl;
    std::cout << "-------------------------" << std::endl;
    Span big_span = Span(10000);
    std::vector<int> vector_int;
    for (int i = 0; i < 10000; i++)
    {
        vector_int.push_back(i);
    }
    big_span.addManyNumbers(vector_int);
    try 
    {
        big_span.addNumber(-2);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // std::cout << big_span << std::endl;
    std::cout << "testing copy and assignment" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    Span span = Span(5);
    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);
    Span copy_span(span);
    Span new_span;
    std::cout << span << std::endl;
    std::cout << "sp adress: " << &span << std::endl;
    std::cout << copy_span << std::endl;
    std::cout << "copy_span adress: " << &copy_span << std::endl;
    new_span = copy_span;
    std::cout << new_span << std::endl;
    std::cout << "new_span adress: " << &new_span << std::endl;
    return (0);
}