/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:02:11 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/17 18:02:14 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>

// Parse special floating-point literals such as nan and infinity.
static bool parsePseudoLiteral(const std::string &literal, double &value)
{
	if (literal == "nan" || literal == "nanf")
	{
		value = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	if (literal == "+inf" || literal == "inf"
		|| literal == "+inff" || literal == "inff")
	{
		value = std::numeric_limits<double>::infinity();
		return true;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		value = -std::numeric_limits<double>::infinity();
		return true;
	}
	return false;
}

// Parse a single non-digit character literal and convert it to double.
static bool parseCharacterLiteral(const std::string &literal, double &value)
{
	if (literal.size() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		value = static_cast<double>(literal[0]);
		return true;
	}
	return false;
}

// Parse decimal input, allowing the optional f suffix for float literals.
static bool parseNumericLiteral(const std::string &literal, double &value)
{
	char *end;
	const char *input = literal.c_str();

	value = std::strtod(input, &end);
	if (end == input)
		return false;
	if (*end == 'f' && *(end + 1) == '\0')
		return true;
	return *end == '\0';
}

bool ScalarConverter::parseValue(const std::string &literal, double &value)
{
	if (parsePseudoLiteral(literal, value))
		return true;
	if (parseCharacterLiteral(literal, value))
		return true;
	return parseNumericLiteral(literal, value);
}
