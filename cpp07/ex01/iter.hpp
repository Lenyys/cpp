/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:00:38 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/01 16:00:39 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_H
#define ITER_H

#include <cstddef>
#include <string>
#include <iostream>


template<typename T, typename F>
void iter(T *adress, size_t length, F fnc)
{
    for(size_t i = 0; i < length; i++)
    {
        fnc(adress[i]);
    }
}

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

#endif