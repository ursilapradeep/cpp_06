/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:45:06 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/05 15:22:49 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cctype>
#include <iomanip>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}


static bool isIntegerValue(double value)
{
	return value == value
		&& value != std::numeric_limits<double>::infinity()
		&& value != -std::numeric_limits<double>::infinity()
		&& value == static_cast<long long>(value);
}

static bool isFiniteValue(double value)
{
	return value == value
		&& value != std::numeric_limits<double>::infinity()
		&& value != -std::numeric_limits<double>::infinity();
}

static bool isNaNValue(double value)
{
	return value != value;
}

static bool isInfiniteValue(double value)
{
	return value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity();
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (!isFiniteValue(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "impossible";
	}
	else
	{
		char c = static_cast<char>(value);
		if (std::isprint(static_cast<unsigned char>(c)))
		{
			std::cout << "'" << c << "'";
		}
		else
		{
			std::cout << "Non displayable";
		}
	}
	std::cout << '\n';
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (!isFiniteValue(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << static_cast<int>(value);
	}
	std::cout << '\n';
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (isNaNValue(value))
		std::cout << "nanf";
	else if (isInfiniteValue(value))
	{
		if (value < 0)
			std::cout << "-inff";
		else
			std::cout << "+inff";
	}
	else if (isIntegerValue(value))
		std::cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(value) << 'f';
	else
		std::cout << static_cast<float>(value) << 'f';
	std::cout << '\n';
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (isNaNValue(value))
		std::cout << "nan";
	else if (isInfiniteValue(value))
	{
		if (value < 0)
			std::cout << "-inf";
		else
			std::cout << "+inf";
	}
	else if (isIntegerValue(value))
		std::cout << std::fixed << std::setprecision(1) << value;
	else
		std::cout << value;
	std::cout << '\n';
}

static void printAllTypes(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::convert(const std::string &literal)
{
	double value;

	if (!parseValue(literal, value))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}
	printAllTypes(value);
}

