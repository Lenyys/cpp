/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:36:49 by lmaresov          #+#    #+#             */
/*   Updated: 2025/08/16 14:55:05 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    for (size_t i = 0; i < originalVector.size() && i < 10; i++)
        std::cout << originalVector[i] << " ";
    if (originalVector.size() > 10) {
        std::cout << "[...]"; 
    }
    std::cout << std::endl;
}

void PmergeMe::printSortedVector() const {
    for (size_t i = 0; i < sortedVector.size() && i < 10; i++)
        std::cout << sortedVector[i] << " ";
    if (sortedVector.size() > 10) {
        std::cout << "[...]"; 
    }
    std::cout << std::endl;
    std::cout << "is sorted: " << (is_sorted(sortedVector) ? "YES" : "NO") << std::endl;
}

void PmergeMe::printSortedDeque() const {
    for (size_t i = 0; i < sortedDeque.size() && i < 10; i++)
        std::cout << sortedDeque[i] << " ";
    if (sortedDeque.size() > 10) {
        std::cout << "[...]";
    }
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
    if (n <= 1)
    {
        seq.push_back(0);
        return seq;
    }
        
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

static bool compareVecBack(const std::vector<int>& vec, const std::vector<int>& target) {
    return vec.back() < target.back();
}

void PmergeMe::mergeInsertSortNested(std::vector<std::vector<int> > &nest_vec, int num)
{
    if (nest_vec.size() <= 1) return ;

    std::vector<std::vector<int> > pairs;
    std::vector<std::vector<int> > pending_chain;
    std::vector<std::vector<int> > main_chain;
    for (size_t i = 0; i + 1 < nest_vec.size(); i += 2) {
        std::vector<int> pair;
        if (nest_vec[i].back() > nest_vec[i + 1].back())
        {
            pair.insert(pair.end(), nest_vec[i + 1].begin(),nest_vec[i + 1].end());
            pair.insert(pair.end(), nest_vec[i].begin(), nest_vec[i].end()); 
        }
        else
        {
            pair.insert(pair.end(), nest_vec[i].begin(), nest_vec[i].end());
            pair.insert(pair.end(), nest_vec[i + 1].begin(),nest_vec[i + 1].end());
            
        }
        pairs.push_back(pair);
        
    }
    std::vector<int> lone;
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
    std::vector<size_t> jac_seq = jacobsthal_sequence(pending_chain.size());
    size_t jac_seq_prev = 0;
    size_t j = 0;
    for (size_t i = 0; i < jac_seq.size(); ++i) 
    {
        if (jac_seq[i] < pending_chain.size()) {
            std::vector<int> val = pending_chain[jac_seq[i]];
            std::vector<std::vector<int> >::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), val,
                            compareVecBack);
            main_chain.insert(pos, val);
            j++;
            if (jac_seq[0] > 0){
            size_t in = jac_seq[i];
            for (; in >= 1 && in-1 > jac_seq_prev; --in) {
                std::vector<int> val = pending_chain[in-1];
                std::vector<std::vector<int> >::iterator pos_in = std::lower_bound(
                                main_chain.begin(), main_chain.begin() + jac_seq[i] + j, val,
                                compareVecBack);
                j++;
                main_chain.insert(pos_in, val);
            }
            if (in == 1)
            {
                std::vector<int> val = pending_chain[in-1];
                std::vector<std::vector<int> >::iterator pos_in = std::lower_bound(
                                main_chain.begin(), main_chain.begin() + jac_seq[i]+j++, val,
                                compareVecBack);
                main_chain.insert(pos_in, val);
                j++;
            }        
        }
            jac_seq_prev = jac_seq[i];
        } 
        if (jac_seq.back() && jac_seq_prev == jac_seq.back() && pending_chain.size() > jac_seq_prev){ 
            for (size_t i = jac_seq_prev+1; i < pending_chain.size(); ++i) {
            std::vector<int> val = pending_chain[i];
            std::vector<std::vector<int> >::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), val,
                            compareVecBack);
            main_chain.insert(pos, val);
            }
        }
    }
    if (lone.size())
    {
        pending_chain.push_back(lone);
        std::vector<std::vector<int> >::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), lone,
                            compareVecBack);
        main_chain.insert(pos, lone);
    }
    nest_vec = main_chain;
    return;
}

void PmergeMe::mergeInsertionSort(std::vector<int>& vec) {

    std::vector<std::vector<int> > pairs;
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

static bool compareDequeBack(const std::deque<int>& dq, const std::deque<int>&  target) {
    return dq.back() < target.back();
}

void PmergeMe::mergeInsertSortNested_d(std::deque<std::deque<int> >& nest_deque, int num)
{
    if (nest_deque.size() <= 1) return;
    std::deque<std::deque<int> > pairs;
    std::deque<std::deque<int> > pending_chain;
    std::deque<std::deque<int> > main_chain;
    for (size_t i = 0; i + 1 < nest_deque.size(); i += 2) {
        std::deque<int> pair;
        if (nest_deque[i].back() > nest_deque[i + 1].back()) {
            pair.insert(pair.end(), nest_deque[i + 1].begin(), nest_deque[i + 1].end());
            pair.insert(pair.end(), nest_deque[i].begin(), nest_deque[i].end());
        } else {
            pair.insert(pair.end(), nest_deque[i].begin(), nest_deque[i].end());
            pair.insert(pair.end(), nest_deque[i + 1].begin(), nest_deque[i + 1].end());
        }
        pairs.push_back(pair);
    }
    std::deque<int> lone;
    if (nest_deque.size() % 2 == 1) {
        lone = nest_deque.back();
    }
    mergeInsertSortNested_d(pairs, num * 2);
    for (size_t i = 0; i < pairs.size(); i++) {
        std::deque<int> pending(pairs[i].begin(), pairs[i].begin() + num);
        std::deque<int> main(pairs[i].begin() + num, pairs[i].end());
        pending_chain.push_back(pending);
        main_chain.push_back(main);
    }
    std::vector<size_t> jac_seq = jacobsthal_sequence(pending_chain.size());
    size_t jac_seq_prev = 0;
    size_t j = 0;
    for (size_t i = 0; i < jac_seq.size(); ++i) {
        if (jac_seq[i] < pending_chain.size()) {
            std::deque<int> val = pending_chain[jac_seq[i]];
            std::deque<std::deque<int> >::iterator pos = std::lower_bound(
                main_chain.begin(), main_chain.end(), val,
                compareDequeBack);
            main_chain.insert(pos, val);
            j++;
            if (jac_seq[0] > 0){
            size_t in = jac_seq[i];
            for (; in >= 1 && in-1 > jac_seq_prev; --in) {
                std::deque<int> val = pending_chain[in-1];
                std::deque<std::deque<int> >::iterator pos_in = std::lower_bound(
                                main_chain.begin(), main_chain.begin() + jac_seq[i] + j, val,
                                compareDequeBack);
                j++;
                main_chain.insert(pos_in, val);
            }
            if (in == 1)
            {
                std::deque<int> val = pending_chain[in-1];
                std::deque<std::deque<int> >::iterator pos_in = std::lower_bound(
                                main_chain.begin(), main_chain.begin() + jac_seq[i]+j++, val,
                                compareDequeBack);
                main_chain.insert(pos_in, val);
                j++;
            }        
        }
            jac_seq_prev = jac_seq[i];
        } 
        if (jac_seq.back() && jac_seq_prev == jac_seq.back() && pending_chain.size() > jac_seq_prev){ 
            for (size_t i = jac_seq_prev+1; i < pending_chain.size(); ++i) {
            std::deque<int> val = pending_chain[i];
            std::deque<std::deque<int> >::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), val,
                            compareDequeBack);
            main_chain.insert(pos, val);
            }
        }
    }
    if (lone.size())
    {
        pending_chain.push_back(lone);
        std::deque<std::deque<int> >::iterator pos = std::lower_bound(
                            main_chain.begin(), main_chain.end(), lone,
                            compareDequeBack);
        main_chain.insert(pos, lone);
    }
    nest_deque = main_chain;
    return;
}

void PmergeMe::mergeInsertionSort_d(std::deque<int>& deq) {

    std::deque<std::deque<int> > pairs;
    for (size_t i = 0; i < deq.size(); i++) {
        std::deque<int> pair;
        pair.push_back(deq[i]);
        pairs.push_back(pair);
    }
    mergeInsertSortNested_d(pairs, 1); 
    std::deque<int> help;
    for (size_t i = 0; i < deq.size(); i++) {
        help.push_back(pairs[i][0]);
    } 
    deq = help;
}

void PmergeMe::sortDeque() {
    sortedDeque.assign(originalVector.begin(), originalVector.end());
    mergeInsertionSort_d(sortedDeque);
}