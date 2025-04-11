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

void PmergeMe::mergeInsertionSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    std::vector<int> main_chain;
    std::vector<int> pending;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        if (a > b) std::swap(a, b);
        main_chain.push_back(b);
        pending.push_back(a);
    }

    if (vec.size() % 2 == 1)
        pending.push_back(vec.back());

    mergeInsertionSort(main_chain);

    std::vector<size_t> jac_seq = jacobsthal_sequence(pending.size());
    //
    // std::cout << "jac_seq: ";
    // for (size_t i = 0; i < jac_seq.size(); i++)
    // {
    //     std::cout << jac_seq[i] << " " ;
    // }
    // std::cout << std::endl;
    //

    std::vector<bool> inserted(pending.size(), false);
    for (size_t i = 0; i < jac_seq.size(); ++i) 
    {
        if (jac_seq[i] < pending.size()) {
            int val = pending[jac_seq[i]];
            std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
            inserted[jac_seq[i]] = true;
        }
    }

    // Insert remaining values
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            int val = pending[i];
            std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
        }
    }

    vec = main_chain;
}

void PmergeMe::sortVector() {
    sortedVector = originalVector;
    mergeInsertionSort(sortedVector);
}


void PmergeMe::mergeInsertionSort_d(std::deque<int>& vec) {
    if (vec.size() <= 1) return;

    std::deque<int> main_chain;
    std::deque<int> pending;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        if (a > b) std::swap(a, b);
        main_chain.push_back(b);
        pending.push_back(a);
    }

    if (vec.size() % 2 == 1)
        pending.push_back(vec.back());

    mergeInsertionSort_d(main_chain);

    std::vector<size_t> jac_seq = jacobsthal_sequence(pending.size());
    //
    // std::cout << "jac_seq: ";
    // for (size_t i = 0; i < jac_seq.size(); i++)
    // {
    //     std::cout << jac_seq[i] << " " ;
    // }
    // std::cout << std::endl;
    //

    std::vector<bool> inserted(pending.size(), false);
    for (size_t i = 0; i < jac_seq.size(); ++i) 
    {
        if (jac_seq[i] < pending.size()) {
            int val = pending[jac_seq[i]];
            std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
            inserted[jac_seq[i]] = true;
        }
    }

    // Insert remaining values
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            int val = pending[i];
            std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
        }
    }

    vec = main_chain;
}

void PmergeMe::sortDeque() {
    sortedDeque.assign(originalVector.begin(), originalVector.end());
    mergeInsertionSort_d(sortedDeque);
}
