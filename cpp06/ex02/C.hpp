/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:03:26 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/28 08:03:28 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef C_H
#define C_H

#include "Base.hpp"

class C: public Base
{

};

std::ostream& operator<<(std::ostream& os, const C&) {
    os << "instance of class C"; 
    return os;
}

#endif