/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:36:56 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/21 08:36:57 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <string>
#include <cstdlib>
#include <cmath>


#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> originalVector;
    std::vector<int> sortedVector;
    std::deque<int> sortedDeque;

    static bool is_sorted(const std::vector<int>& vec);
    static bool is_sorted_d(const std::deque<int>& vec);
    static std::vector<size_t> jacobsthal_sequence(size_t n);
    void mergeInsertionSort(std::vector<int>& vec);
    void mergeInsertionSort_d(std::deque<int> &deq);

public:
    PmergeMe(std::vector<int>& numbers);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortVector();
    void sortDeque();
    void printOriginal() const;
    void printSortedVector() const;
    void printSortedDeque() const;
};

#endif
