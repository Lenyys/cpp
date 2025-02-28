/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:03:06 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/28 08:03:08 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef A_H
#define A_H

#include "Base.hpp"

class A: public Base
{

};

std::ostream& operator<<(std::ostream& os, const A&) {
    os << "instance of class A"; 
    return os;
}

#endif