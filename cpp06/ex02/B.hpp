/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:03:16 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/28 08:03:18 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef B_H
#define B_H

#include "Base.hpp"

class B: public Base
{

};

std::ostream& operator<<(std::ostream& os, const B&) {
    os << "instance of class B"; 
    return os;
}

#endif
