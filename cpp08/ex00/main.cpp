/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 05:40:29 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 05:40:31 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"

int main(void) 
{
    std::vector<int> vector_int;
    std::list<int> list_int;
    std::deque<int> deque_int;
    std::list<int>::const_iterator list_iter;
    std::vector<int>::const_iterator vector_iter;
    std::deque<int>::const_iterator deque_iter;

    for (int i = 0; i <= 5; i++)
    {
        list_int.push_back(i);
        vector_int.push_back(i);
        deque_int.push_back(i);
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "value is in container" << std::endl;
    
    try {
        list_iter = easyfind(list_int, 2);
        std::cout << "found value in list: " << *list_iter << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        vector_iter = easyfind(vector_int, 2);
        std::cout << "found value in vector: " << *vector_iter << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        deque_iter = easyfind(deque_int, 2);
        std::cout << "found value in deque: " << *deque_iter << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "value is not in container" << std::endl;
    
    try {
        list_iter = easyfind(list_int, 10);
        std::cout << "found value in list: " << *list_iter << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        vector_iter = easyfind(vector_int, 20);
        std::cout << "found value in vector: " << *vector_iter << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        deque_iter = easyfind(deque_int, -2);
        std::cout << "found value in deque: " << *deque_iter << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return(0);
}