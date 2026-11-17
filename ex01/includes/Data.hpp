/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:00:15 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/09 17:00:45 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
    int _value;
public:
    Data();
    Data(const Data&other);
    Data &operator=(const Data&other);
    ~Data();
    Data(int value);
    int getValue() const;
};

#endif