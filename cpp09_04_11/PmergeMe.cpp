/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:36:49 by lmaresov          #+#    #+#             */
/*   Updated: 2025/06/08 18:07:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int>& numbers) : originalVector(numbers) {}

PmergeMe::PmergeMe(const PmergeMe& other) : originalVector(other.originalVector) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
        originalVector = other.originalVector;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printOriginal() const {
    for (size_t i = 0; i < originalVector.size(); i++)
        std::cout << originalVector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printSortedVector() const {
    for (size_t i = 0; i < sortedVector.size(); i++)
        std::cout << sortedVector[i] << " ";
    std::cout << std::endl;
    // std::cout << "is sorted: " << (is_sorted(sortedVector) ? "YES" : "NO") << std::endl;
}

void PmergeMe::printSortedDeque() const {
    for (size_t i = 0; i < sortedDeque.size(); i++)
        std::cout << sortedDeque[i] << " ";
    std::cout << std::endl;
    std::cout << "is sorted: " << (is_sorted_d(sortedDeque) ? "YES" : "NO") << std::endl;
}

bool PmergeMe::is_sorted_d(const std::deque<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1])
            return false;
    }
    return true;
}

bool PmergeMe::is_sorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1])
            return false;
    }
    return true;
}

// Jacobsthal sequence: 1, 3, 5, 11, 21, ...
std::vector<size_t> PmergeMe::jacobsthal_sequence(size_t n) {
    std::vector<size_t> seq;
    size_t a = 1, b = 3;
    seq.push_back(a);
    while (b < n) {
        seq.push_back(b);
        size_t next = b + 2 * a;
        a = b;
        b = next;
    }
    return seq;
}

void PmergeMe::mergeInsertSortNested(std::vector<std::vector<int>> &nest_vec, int num)
{
    if (nest_vec.size() <= 1) return ;

    std::vector<std::vector<int>> pairs;
    std::vector<std::vector<int>> pending_chain;
    std::vector<std::vector<int>> main_chain;
    for (size_t i = 0; i + 1 < nest_vec.size(); i += 2) {
        std::vector<int> pair;
        if (nest_vec[i].back() > nest_vec[i + 1].back())
        {
            pair.insert(pair.end(), nest_vec[i].begin(), nest_vec[i].end());
            pair.insert(pair.end(), nest_vec[i + 1].begin(),nest_vec[i + 1].end()); 
        }
        else
        {
            pair.insert(pair.end(), nest_vec[i + 1].begin(),nest_vec[i + 1].end());
            pair.insert(pair.end(), nest_vec[i].begin(), nest_vec[i].end());
        }
        pairs.push_back(pair);
    }
    std::vector<int> lone = {};
    if (nest_vec.size() % 2 == 1) {
        lone = nest_vec.back(); 
    }
    
    mergeInsertSortNested(pairs, num*2);
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::vector<int> pending(pairs[i].begin(), pairs[i].begin() + num);
        std::vector<int> main(pairs[i].begin() + num, pairs[i].end());
        pending_chain.push_back(pending);
        main_chain.push_back(main);  
    }
    if (lone.size())
    {
        pending_chain.push_back(lone);
    }
    std::vector<size_t> jac_seq = jacobsthal_sequence(pending_chain.size());
    std::vector<bool> inserted(pending_chain.size(), false);
    for (size_t i = 0; i < jac_seq.size(); ++i) 
    {
        if (jac_seq[i] < pending_chain.size()) {
            std::vector<int> val = pending_chain[jac_seq[i]];
            std::vector<std::vector<int>>::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), val.back(),
                            [](const std::vector<int>& vec, int target) {
                                return vec.back() < target; }
                            );
            main_chain.insert(pos, val);
            inserted[jac_seq[i]] = true;
        }
    }
    for (size_t i = 0; i < pending_chain.size(); ++i) {
        if (!inserted[i]) {
            std::vector<int> val = pending_chain[i];
            std::vector<std::vector<int>>::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), val.back(),
                            [](const std::vector<int>& vec, int target) {
                                return vec.back() < target; }
                            );
            main_chain.insert(pos, val);
        }
    }
    nest_vec = main_chain;
    return;
}

void PmergeMe::mergeInsertionSort(std::vector<int>& vec) {

    std::vector<std::vector<int>> pairs;
    for (size_t i = 0; i < vec.size(); i++) {
        std::vector<int> pair;
        pair.push_back(vec[i]);
        pairs.push_back(pair);
    }
    mergeInsertSortNested(pairs, 1); 
    std::vector<int> help;
    for (size_t i = 0; i < vec.size(); i++) {
        help.push_back(pairs[i][0]);
    } 
    vec = help;
}

void PmergeMe::sortVector() {
    sortedVector = originalVector;
    mergeInsertionSort(sortedVector);
}

// void PmergeMe::mergeInsertionSort(std::vector<int>& vec) {
    

//     std::vector<std::vector<int>> pairs;
//     for (size_t i = 0; i + 1 < vec.size(); i += 2) {
//         std::vector<int> pair;
//         if (vec[i] > vec[i + 1])
//             pair = {vec[i], vec[i + 1]};
//         else
//             pair = {vec[i + 1], vec[i]};
//         pairs.push_back(pair);
//     }
//     int lone = -1;
//     if (vec.size() % 2 == 1) {
//         lone = vec.back(); 
//     }
//     mergeInsertSortNested(pairs, 2); 
//     std::vector<int> pending;
//     std::vector<int> main_chain;
//     for (size_t i = 0; i < pairs.size(); i++)
//     {
//         pending.push_back(pairs[i][0]);
//         main_chain.push_back(pairs[i][1]);
//     }
//     if (lone != -1)
//         pending.push_back(lone);
    
//     std::vector<bool> inserted(pending.size(), false);
//     std::vector<size_t> jac_seq = jacobsthal_sequence(pending.size());
//     for (size_t i = 0; i < jac_seq.size(); ++i) 
//     {
//         if (jac_seq[i] < pending.size()) {
//             int val = pending[jac_seq[i]];
//             std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
//             main_chain.insert(pos, val);
//             inserted[jac_seq[i]] = true;
//         }
//     }

//     // Insert remaining values
//     for (size_t i = 0; i < pending.size(); ++i) {
//         if (!inserted[i]) {
//             int val = pending[i];
//             std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
//             main_chain.insert(pos, val);
//         }
//     }
//     vec = main_chain;
// }


#include <deque>
#include <algorithm>
#include <vector>

void PmergeMe::mergeInsertSortNested(std::deque<std::deque<int>>& nest_deque, int num)
{
    if (nest_deque.size() <= 1) return;

    std::deque<std::deque<int>> pairs;
    std::deque<std::deque<int>> pending_chain;
    std::deque<std::deque<int>> main_chain;

    for (size_t i = 0; i + 1 < nest_deque.size(); i += 2) {
        std::deque<int> pair;
        if (nest_deque[i].back() > nest_deque[i + 1].back()) {
            pair.insert(pair.end(), nest_deque[i].begin(), nest_deque[i].end());
            pair.insert(pair.end(), nest_deque[i + 1].begin(), nest_deque[i + 1].end());
        } else {
            pair.insert(pair.end(), nest_deque[i + 1].begin(), nest_deque[i + 1].end());
            pair.insert(pair.end(), nest_deque[i].begin(), nest_deque[i].end());
        }
        pairs.push_back(pair);
    }

    std::deque<int> lone = {};
    if (nest_deque.size() % 2 == 1) {
        lone = nest_deque.back();
    }

    mergeInsertSortNested(pairs, num * 2);

    for (size_t i = 0; i < pairs.size(); i++) {
        std::deque<int> pending(pairs[i].begin(), pairs[i].begin() + num);
        std::deque<int> main(pairs[i].begin() + num, pairs[i].end());
        pending_chain.push_back(pending);
        main_chain.push_back(main);
    }

    if (!lone.empty()) {
        pending_chain.push_back(lone);
    }

    std::vector<size_t> jac_seq = jacobsthal_sequence(pending_chain.size());
    std::vector<bool> inserted(pending_chain.size(), false);

    for (size_t i = 0; i < jac_seq.size(); ++i) {
        if (jac_seq[i] < pending_chain.size()) {
            std::deque<int> val = pending_chain[jac_seq[i]];
            auto pos = std::lower_bound(
                main_chain.begin(), main_chain.end(), val.back(),
                [](const std::deque<int>& dq, int target) {
                    return dq.back() < target;
                }
            );
            main_chain.insert(pos, val);
            inserted[jac_seq[i]] = true;
        }
    }

    for (size_t i = 0; i < pending_chain.size(); ++i) {
        if (!inserted[i]) {
            std::deque<int> val = pending_chain[i];
            auto pos = std::lower_bound(
                main_chain.begin(), main_chain.end(), val.back(),
                [](const std::deque<int>& dq, int target) {
                    return dq.back() < target;
                }
            );
            main_chain.insert(pos, val);
        }
    }
    nest_deque = main_chain;
}

void PmergeMe::sortDeque() {
    sortedDeque.assign(originalVector.begin(), originalVector.end());
    mergeInsertionSort_d(sortedDeque);
}