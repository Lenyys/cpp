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
        
void PmergeMe::sortDeque1()
{
    sortedDeque.assign(originalVector.begin(), originalVector.end());
    mergeInsertSortDeque(sortedDeque);
}
void PmergeMe::sortVector1()
{
    sortedVector = originalVector;
    mergeInsertSortVector(sortedVector);
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


/////////////////////////////////////////////////////////////////////////////////////
void PmergeMe::sortVector()
{
    sortedVector = originalVector;
    merge_1_part(sortedVector, 2);
    size_t j = 2;
    while (j <= sortedVector.size())
        j = j*2;
    merge_2_part(sortedVector, j/2);
    insort_part(sortedVector, j/2);
}

void PmergeMe::insort_part(std::vector<int>& num, size_t j)
{
    std::vector<int> help, pending, pend;
    for (size_t i= 0; i+2 <= j; i+=2)
    {
        pending.insert(pending.end(), num.begin() + i, num.begin() + i + 1);
        help.insert(help.end(), num.begin() + i + 1, num.begin() + i + 2);
    }
    if (num.size() > j) 
        pend.insert(pend.end(), num.begin() + j, num.end());
    num.clear();
    for (int n = 0; n < 3 && help.size(); n++)
    {
        num.insert(num.end(), help.begin(), help.begin() + 1);
        help.erase(help.begin());
    }
    for (size_t i = 1; i < pending.size()+i; i++)
    {
        int jackob = pow(2,i);
        for(size_t a = jackob; a > 0 && !pending.empty(); a--)
        {
            if (pending.size() < a)
                a = pending.size();
            std::vector<int>::iterator pos = std::lower_bound(num.begin(), num.end(), pending[a-1]);
            num.insert(pos, pending[a-1]);
            pending.erase(pending.begin() + a -1);
        }
        for (int n = 0; n < jackob && help.size(); n++)
        {
            num.insert(num.end(), help.begin(), help.begin() + 1);
            help.erase(help.begin());
        }
    } 
    while(!pend.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(num.begin(), num.end(), pend[0]);
        num.insert(pos, pend[0]);
        pend.erase(pend.begin());
    }
    
}

void PmergeMe::merge_1_part(std::vector<int>& num, size_t j) {
    if (j > num.size()) {
        return;
    }
    std::vector<int> help, pend;
    for (size_t i = 0; i + j <= num.size(); i += j) {
        if (num[i + j / 2 - 1] > num[i + j - 1]) {
            help.insert(help.end(), num.begin() + i + j / 2, num.begin() + i + j);
            help.insert(help.end(), num.begin() + i, num.begin() + i + j / 2);
        } else {
            help.insert(help.end(), num.begin() + i, num.begin() + i + j / 2);
            help.insert(help.end(), num.begin() + i + j / 2, num.begin() + i + j);
        }
    }
    if (num.size() % j != 0) {
        pend.insert(pend.end(), num.begin() + (num.size() - (num.size() % j)), num.end());
    }
    merge_1_part(help, j * 2);
    help.insert(help.end(), pend.begin(), pend.end());
    num = help;  
}

void PmergeMe::merge_2_part(std::vector<int>& num, size_t j) {
    if (j <= 2) 
        return;  
    std::vector<int> help, pend, pending_help;
    std::vector<std::vector<int> > pending;  
    help.insert(help.end(), num.begin(), num.begin() + j);
    for (size_t i = j; i + j <= num.size(); i += j) {
        pending.push_back(std::vector<int>(num.begin() + i , num.begin() + i + j/2));
        help.insert(help.end(), num.begin() + i+ j/2, num.begin() + i + j);
    }
    if (num.size() % j != 0)
        pend.insert(pend.end(), num.begin() + (num.size() - (num.size() % j)), num.end());
    for (size_t i = pending.size() - 1; i != size_t(-1); i-= j/2) {
        if (pending.empty())
            break;
        int k = help.size() - 1;
        while (k > 0 && help[k] > pending.back().back()) {
            k -= j / 2;
        }
        if (k == 0 && help[k] > pending.back().back())
            k = -1;
        pending_help = pending.back();
        pending.pop_back();    
        help.insert(help.begin() + k + 1, pending_help.begin(), pending_help.end());
    }
    merge_2_part(help, j / 2);
    help.insert(help.end(), pend.begin(), pend.end());
    num = help;
}

void PmergeMe::sortDeque()
{
    sortedDeque.assign(originalVector.begin(), originalVector.end());
    merge_1_part_d(sortedDeque, 2);
    size_t j = 2;
    while (j <= sortedDeque.size())
        j = j*2;
    merge_2_part_d(sortedDeque, j/2);
    insort_part_d(sortedDeque, j/2);
}

void PmergeMe::insort_part_d(std::deque<int>& num, size_t j)
{
    std::deque<int> help, pending, pend;
    for (size_t i= 0; i+2 <= j; i+=2)
    {
        pending.insert(pending.end(), num.begin() + i, num.begin() + i + 1);
        help.insert(help.end(), num.begin() + i + 1, num.begin() + i + 2);
    }
    if (num.size() > j) 
        pend.insert(pend.end(), num.begin() + j, num.end());
    num.clear();
    for (int n = 0; n < 3 && help.size(); n++)
    {
        num.insert(num.end(), help.begin(), help.begin() + 1);
        help.erase(help.begin());
    }
    for (size_t i = 1; i < pending.size()+i; i++)
    {
        int jackob = pow(2,i);
        for(size_t a = jackob; a > 0 && !pending.empty(); a--)
        {
            if (pending.size() < a)
                a = pending.size();
            std::deque<int>::iterator pos = std::lower_bound(num.begin(), num.end(), pending[a-1]);
            num.insert(pos, pending[a-1]);
            pending.erase(pending.begin() + a -1);
        }
        for (int n = 0; n < jackob && help.size(); n++)
        {
            num.insert(num.end(), help.begin(), help.begin() + 1);
            help.erase(help.begin());
        }
    } 
    while(!pend.empty())
    {
        std::deque<int>::iterator pos = std::lower_bound(num.begin(), num.end(), pend[0]);
        num.insert(pos, pend[0]);
        pend.erase(pend.begin());
    }
    
}

void PmergeMe::merge_1_part_d(std::deque<int>& num, size_t j) {
    if (j > num.size()) {
        return;
    }
    std::deque<int> help, pend;
    for (size_t i = 0; i + j <= num.size(); i += j) {
        if (num[i + j / 2 - 1] > num[i + j - 1]) {
            help.insert(help.end(), num.begin() + i + j / 2, num.begin() + i + j);
            help.insert(help.end(), num.begin() + i, num.begin() + i + j / 2);
        } else {
            help.insert(help.end(), num.begin() + i, num.begin() + i + j / 2);
            help.insert(help.end(), num.begin() + i + j / 2, num.begin() + i + j);
        }
    }
    if (num.size() % j != 0) {
        pend.insert(pend.end(), num.begin() + (num.size() - (num.size() % j)), num.end());
    }
    merge_1_part_d(help, j * 2);
    help.insert(help.end(), pend.begin(), pend.end());
    num = help;  
}

void PmergeMe::merge_2_part_d(std::deque<int>& num, size_t j) {
    if (j <= 2) 
        return;  
    std::deque<int> help, pend, pending_help;
    std::deque<std::deque<int> > pending;  
    help.insert(help.end(), num.begin(), num.begin() + j);
    for (size_t i = j; i + j <= num.size(); i += j) {
        pending.push_back(std::deque<int>(num.begin() + i , num.begin() + i + j/2));
        help.insert(help.end(), num.begin() + i+ j/2, num.begin() + i + j);
    }
    if (num.size() % j != 0)
        pend.insert(pend.end(), num.begin() + (num.size() - (num.size() % j)), num.end());
    for (size_t i = pending.size() - 1; i != size_t(-1); i-= j/2) {
        if (pending.empty())
            break;
        int k = help.size() - 1;
        while (k > 0 && help[k] > pending.back().back()) {
            k -= j / 2;
        }
        if (k == 0 && help[k] > pending.back().back())
            k = -1;
        pending_help = pending.back();
        pending.pop_back();   
        help.insert(help.begin() + k + 1, pending_help.begin(), pending_help.end());
    }
    merge_2_part_d(help, j / 2);
    help.insert(help.end(), pend.begin(), pend.end());
    num = help;
}