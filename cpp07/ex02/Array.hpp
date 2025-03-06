/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:01:20 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/01 16:01:22 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
private:
    T * _data;
    unsigned int _size;
public:
    Array(): _data(NULL), _size(0) {}
    Array(unsigned int n): _data(new T[n]()), _size(n) {}
    Array(const Array &other): _data(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }  
    }
    ~Array() {
        delete[] _data;
    }
    Array& operator=(const Array &other) {
        if (this != &other) 
        {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    T& operator[] (unsigned int index) 
    {
        if (index >= _size)
            throw std::out_of_range("index out of bounds");
        return _data[index]; 
    }

    unsigned int size( void) const
    {
        return _size;
    }
};

template<typename T>
std::ostream & operator<<(std::ostream &os, Array<T> &src) {
    os << "[";
    for (unsigned int i = 0; i < src.size(); i++) {
        os << src[i];
        if (i < src.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return (os);
}

template<>
std::ostream& operator<<(std::ostream& os, Array<std::string>& src) {
    os << "[";
    for (unsigned int i = 0; i < src.size(); i++) {
        os << "\"" << src[i] << "\"";  
        if (i < src.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

#endif
