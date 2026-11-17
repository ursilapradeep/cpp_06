/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:01:34 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/09 17:01:37 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() : _value(0)
{
}

Data::Data(const Data& other) : _value(other._value)
{
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
        _value = other._value;
    return *this;
}

Data::~Data()
{
}

Data::Data(int value) : _value(value) 
{
}

int Data::getValue() const
{
    return _value;
}
