/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:40:46 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/28 07:40:49 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int main (void)
{
    Data* data = new Data;
    Data * new_data;
    uintptr_t raw;

    
    data->data = "Hello, how are you? and what is that?";
    std::cout << "data to serialize: " << data->data << std::endl;
    raw = Serializer::serialize(data);
    std::cout << "serialized data: " << raw << std::endl;
    new_data = Serializer::deserialize(raw);
    std::cout << "deserialized data: " << new_data->data << std::endl;
    delete data;
    return 0;
}