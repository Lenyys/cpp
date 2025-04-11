/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:36:23 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/21 08:36:25 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <climits>
#include <ctime>

int main(int argc, char ** argv)
{
    if (argc <= 1)
    {
        std::cerr << "Usage: ./PmergeMe <integers devided by space>" << std::endl;
        return 1;
    }
    std::vector<int> numbers;
    for (int i = 1; i < argc; i++)
    {
        char *end;
        long num = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || num > INT_MAX)
        {
            std::cerr << "Error: not integer in parameters." << std::endl;
            return 1;
        }
        if (num < 0)
        {
            std::cerr << "Error: negative number in parameters" << std::endl;
            return 1;
        }
        numbers.push_back(static_cast<int>(num));
    }

    PmergeMe sorter(numbers);

    std::cout << "Before: ";
    sorter.printOriginal();
    clock_t start = clock();
    sorter.sortVector();
    clock_t end = clock();
    double duration = (double(end-start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "After: ";
    sorter.printSortedVector();
    std::cout << "Time to process vector range of " << argc-1 << " elements: ";
    std::cout <<  duration << " us" << std::endl;
    

    PmergeMe sorterd(numbers);
    start = clock();
    sorterd.sortDeque();
    end = clock();
    duration = (double(end-start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process deque range of " << argc-1 << " elements: ";
    std::cout <<  duration << " us" << std::endl;

    
    return 0;
}

