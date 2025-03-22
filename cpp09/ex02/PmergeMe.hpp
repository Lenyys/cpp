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

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>


class PmergeMe 
{
    private:
        std::vector<int> originalVector;
        std::vector<int> sortedVector;
        std::deque<int> sortedDeque;

        void mergeInsertSortVector(std::vector<int> &vec);
        void mergeInsertSortDeque(std::deque<int> &deq);
    
    public:
        PmergeMe(std::vector<int> & numbers);
        PmergeMe(const PmergeMe & other);
        PmergeMe & operator=(const PmergeMe & other);
        ~PmergeMe();

        void sortVector();
        void sortDeque();

        void printOriginal() const;
        void printSortedVector() const;
        void printSortedDeque() const;
        

};

#endif