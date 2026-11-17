/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:01:45 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/09 17:01:50 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main()
{
    Data data(55799);

    std::cout << "Original Data value: "<< data.getValue() << std::endl;
    std::cout << "Original address: " << &data << std::endl;
    uintptr_t ptr = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(ptr); 
    std::cout << "Deserialized address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data value: "<< deserializedData->getValue() << std::endl;
    return 0;
}