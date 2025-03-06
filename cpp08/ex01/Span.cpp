/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:33:25 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 06:33:26 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span(): _N(0), _size(0) {
}

Span::Span(unsigned int N): _N(N), _size(0) {
}

Span::Span(const Span & other): _N(other._N), _size(other._size) {
    this->_int_vector = std::vector<int>(other._int_vector);
}

Span::~Span() {
}

Span& Span::operator=(const Span & other) {
    if (this != &other)
    {
        this->_int_vector = other._int_vector;
        this->_N = other._N;
        this->_size = other._size;
    }
    return *this;
}

 void Span::addNumber(int n) {
    if (this->_size == this->_N) {
        throw Span::ContainerFullError();
    }
    this->_int_vector.push_back(n);
    this->_size++;
}

void Span::addManyNumbers(const std::vector<int>& numbers) {
    size_t curr_vector_size = this->_int_vector.size();
    size_t numbers_size = numbers.size();
    if (curr_vector_size + numbers_size > this-> _N)
    {
        std::cout << "Can't add all numbers because, there is not enought space in Span.";
        std::cout << "reduce the ammount of the numbers to add, or crate a bigger Span" << std::endl;
        return ;
    }
    this->_int_vector.insert(this->_int_vector.end(), numbers.begin(), numbers.end());
    this->_size += numbers_size;
}

int Span::shortestSpan() {
    if (this->_int_vector.size() < 2)
    {
        throw Span::NoSpanError();
    }
    std::sort(this->_int_vector.begin(), this->_int_vector.end());
    int min_span = INT_MAX;
    for (size_t i = 1; i < this->_int_vector.size(); i++)
    {
        int span = this->_int_vector[i] - this->_int_vector[i-1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}


int Span::longestSpan() {
    if (this->_int_vector.size() < 2)
        throw Span::NoSpanError();
    std::sort(this->_int_vector.begin(), this->_int_vector.end());
    int max_span = this->_int_vector[this->_int_vector.size() - 1] - this->_int_vector[0];
    return max_span;
}

const char* Span::ContainerFullError::what() const throw() {
    return "Container is full, you can't add more numbers";
}

const char* Span::NoSpanError::what() const throw() {
    return "In the container is 0 or 1 number, you can't get span";
}

const std::vector<int>& Span::getVector() const {
        return _int_vector;
}
unsigned int Span::getN() const {
    return _N;
}

std::ostream & operator<<(std::ostream &os, Span &src) {
    if (!src.getVector().empty()) {
        os << "[";
        for (size_t i = 0; i < src.getVector().size(); ++i) {
            os << src.getVector()[i];
            if (i < src.getVector().size() - 1) {
                os << ", ";
            }
        }
        os << "]";
    } else {
        os << "Span is empty";
    }
    os << "\nSize: " << src.getVector().size() << ", Capacity: " << src.getN();

    return os;
}