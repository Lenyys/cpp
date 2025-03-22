/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:36:49 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/21 08:36:50 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(std::vector<int> & numbers): originalVector(numbers) {}

        
PmergeMe::PmergeMe(const PmergeMe & other): originalVector(other.originalVector) {}

        
PmergeMe & PmergeMe::operator=(const PmergeMe & other)
{
    if (this != &other)
        originalVector = other.originalVector;
    return *this;
}
        
PmergeMe::~PmergeMe() {}

        
void PmergeMe::printOriginal() const
{
    for (size_t i = 0; i < originalVector.size(); i++)
    {
        std::cout << originalVector[i] << " ";
    }
    std:: cout << std::endl;
}

        
void PmergeMe::printSortedVector() const
{
    for (size_t i = 0; i < sortedVector.size(); i++)
    {
        std::cout << sortedVector[i] << " ";
    }
    std:: cout << std::endl;
}   

void PmergeMe::printSortedDeque() const
{
    for (size_t i = 0; i < sortedDeque.size(); i++)
    {
        std::cout << sortedDeque[i] << " ";
    }
    std:: cout << std::endl;
}   

void PmergeMe::sortVector()
{
    sortedVector = originalVector;
    mergeInsertSortVector(sortedVector);
}
        
void PmergeMe::sortDeque()
{
    sortedDeque.assign(originalVector.begin(), originalVector.end());
    mergeInsertSortDeque(sortedDeque);
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &vec)
{
    if (vec.size() < 2)
        return;
    std::vector<int> main, pending;
    for (size_t i = 0; i+1 < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        main.push_back(vec[i + 1]);
        pending.push_back(vec[i]);
    }
    if (vec.size() % 2 == 1)
    {
        pending.push_back(vec.back());
    }
    mergeInsertSortVector(main);
    vec.clear();
    vec.insert(vec.end(), main.begin(), main.end());
    for (size_t i = 0; i < pending.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), pending[i]);
        vec.insert(pos, pending[i]);
    }
}
        
void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq)
{
    if (deq.size() < 2)
        return;
    std::deque<int> main, pending;
    for (size_t i = 0; i+1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]);
        main.push_back(deq[i + 1]);
        pending.push_back(deq[i]);
    }
    if (deq.size() % 2 == 1)
    {
        pending.push_back(deq.back());
    }
    mergeInsertSortDeque(main);
    deq.clear();
    deq.insert(deq.end(), main.begin(), main.end());
    for (size_t i = 0; i < pending.size(); i++)
    {
        std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), pending[i]);
        deq.insert(pos, pending[i]);
    }
}