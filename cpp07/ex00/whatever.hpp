/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:54:47 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/01 15:54:49 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_H
#define WHATEVER_H

#include <string>
#include <iostream>

template<typename T>
void    swap(T &a, T &b)
{
    T   tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template<typename T>
T   max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

#endif