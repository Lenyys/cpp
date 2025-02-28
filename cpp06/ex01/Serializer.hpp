/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:41:18 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/28 07:41:20 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>
#include <iostream>
#include <stdint.h>

struct Data {
    std::string data;
};

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &other);
    ~Serializer();
    Serializer& operator=(const Serializer &other);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif