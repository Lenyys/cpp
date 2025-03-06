/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:33:12 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 06:33:14 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_H
#define SPAN_H

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
private:
    unsigned int _N;
    unsigned int _size;
    std::vector<int> _int_vector;

public:
    Span();
    Span(unsigned int N);
    Span(const Span & other);
    ~Span();

    Span& operator=(const Span & other);

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    void addManyNumbers(const std::vector<int>& numbers);
    
    unsigned int getN() const;
    const std::vector<int>& getVector() const;
    class ContainerFullError: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class NoSpanError: public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream &os, Span &obj);
#endif