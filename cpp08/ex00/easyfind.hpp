/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 05:40:44 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 05:40:46 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_H
#define EASYFIND_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <list>
#include <vector>
#include <deque>


// class NotFoundError: public std::exception
// {
//     private:
//         std::string _message;

//     public:
//         NotFoundError(const std::string message): _message(message) {}
//         virtual const char * what() const throw() {
//             return _message.c_str();
//         }
//         virtual ~NotFoundError() throw() {}
// };

class NotFoundError: public std::exception
{
    public:
        virtual const char * what() const throw() {
            return "Second parametr not found in container";
        }
};

template<typename T>
typename T::const_iterator easyfind(const T& integers, const int n)
{
    typename T::const_iterator iter;

    iter = std::find(integers.begin(), integers.end(), n);
    if (iter == integers.end()) {
        throw NotFoundError();
    }
    return iter;
};

#endif