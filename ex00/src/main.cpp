/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:01:44 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/17 18:01:48 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
		if (argc != 2) 
		{
			std::cout << "Enter a char/int/float/double literal: " << std::endl;
			return 1;
		}
		ScalarConverter::convert(argv[1]);
		return 0;
}

