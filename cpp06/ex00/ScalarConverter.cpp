/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:09:29 by miparis           #+#    #+#             */
/*   Updated: 2026/06/12 11:14:21 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& _copy)
{
	*this = _copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& _copy)
{
	if (this != &_copy)
		*this = _copy;
	return (*this);
}

ScalarConverter:: ~ScalarConverter(){}

void	ScalarConverter::convert(const std::string& _literal)
{
	//1º detect the type of the literal passed as a parameter
	type _type = parseLiteral(_literal);
	if (_type == NONE)
	{
		std::cout << RED << "Error: Invalid literal. Cannot convert" << NC << std::endl;
		return ;
	}
	toType(_type, _literal);
}

type	ScalarConverter::parseLiteral(const std::string& _literal)
{
	if (_literal.empty())
		return (NONE);
	
	type _pseudo = searchPseudo(_literal);
	if (_pseudo != NONE)
		return (_pseudo);

	if (isChar(_literal))
		return (CHAR);
	if (isInt(_literal))
		return (INT);
	if (isDouble(_literal))
		return (DOUBLE);
	if (isFloat(_literal))
		return (FLOAT);
	return (NONE);
}

type	 ScalarConverter::searchPseudo(const std::string _literal)
{
	std::string pseudoStrings[8] = { "nan", "+inf", "-inf", "inf", "nanf", "+inff", "-inff", "inff" };
    type  pseudoEnums[8]   = {T_NAN, P_INFF, N_INFF, T_INF, T_NANF, P_INF, N_INF, T_INFF};

	for (int i = 0; i < 8; i++)
	{
		if (_literal == pseudoStrings[i])
			return pseudoEnums[i];
	}
	return (NONE);
}

bool	ScalarConverter:: isChar(const std::string _literal)
{
	if (_literal.length() != 1)
		return (false);
    if (_literal[0] >= '0' && _literal[0] <= '9')
		return (false);
    if (_literal[0] >= 32 && _literal[0] <= 126)
		return (true);
	return (false);
}

bool	ScalarConverter:: isInt(const std::string _literal) 
{
    size_t i = 0;
	int sign = 0; 

	if (_literal[i] == '+' || _literal[i] == '-')
	{
		sign = sign + 1;
		i = i + 1;
	}
	if (i == _literal.length())
		return (false);
	while (i < _literal.length())
	{
		if (_literal[i] <= '0' && _literal[i] >= '9')
			return (false);
		i = i + 1;
	}
	if (sign == 1)
		return (true);
    return (false);
}

bool	ScalarConverter::isDouble(const std::string _literal) 
{
	size_t	i = 0;
	int	point = 0;
	int	digit = 0;
	int sign = 0;

	if (_literal[i] == '+' || _literal[i] == '-')
	{
		sign = sign + 1;
		i = i + 1;
	}    
	while (i <  _literal.length())
	{
		if (_literal[i] == '.')
			point = point + 1;
		if (_literal[i] >= '0' && _literal[i] <= '9')
			digit = digit + 1;
		else
			return (false);
		i++;
	}
	if (point == 1 && digit > 0 && sign == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::isFloat(const std::string _literal) 
{
	int size = _literal.length() -1;
	
	if (_literal[size] != 'f')
		return (false);

	int	i = 0;
	int	point = 0;
	int	digit = 0;
	int sign = 0;
        
	if (_literal[i] == '+' || _literal[i] == '-')
	{
		sign = sign + 1;
		i = i + 1;
	}
    while (i < size)
	{
		if (_literal[i] == '.')
			point = point + 1;
		if (_literal[i] >= '0' && _literal[i] <= '9')
			digit = digit + 1;
		else
			return (false);
		i++;
	}
	if (point == 1 && digit > 0 && sign == 1)
		return (true);
	return (false);
}

void	ScalarConverter::toType(type _type, const std::string _literal) 
{
	if (_type == T_NAN || _type == T_NANF || _type == P_INF || _type == N_INF || _type == N_INFF || _type == P_INFF || _type == T_INF || _type == T_INFF)
	{
		printFromPseudo(_type);
		return;
	}
	if (_type == CHAR)
	{
		printFromChar(_literal[0]);
		return;
	}
	if (_type == INT)
	{
		printFromInt(std::atoi(_literal.c_str()));
		return;
	}
	if (_type == FLOAT)
	{
		printFromFloat(std::strtod(_literal.c_str(), NULL));
		return;
	}
	if (_type == DOUBLE)
	{
		printFromDouble(std::strtod(_literal.c_str(), NULL));
		return;
	}
}

void	ScalarConverter::printFromPseudo(type _type) 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_type == T_NAN || _type == T_NANF)
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (_type == P_INF || _type == P_INFF)
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (_type == N_INF || _type == N_INFF)
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (_type == T_INF || _type == T_INFF)
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
}


void	ScalarConverter::printFromInt(int i) 
{	
	//we first check with the original int to avoid printing overflowed numbers
	if (i < 0 || i > 255)//negative number or non ASCII
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))//non printable char
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char	c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	
	std::cout << "int: " << i << std::endl;

	float	f = static_cast<float>(i);
	std::cout << "float: " << f << ".0f" << std::endl;

	float	d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::printFromChar(char c) 
{
	if (!std::isprint(c))//non printable char
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	int	i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;

	float	f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;

	float	d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::printFromFloat(float f) 
{	
	//we first check with the original int to avoid printing overflowed numbers
	if (f < 0 || f > 255)//negative number or non ASCII
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(f))//non printable char
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		int	c = static_cast<char>(f);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
	{	int	i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	if (f - static_cast<int>(f) == 0.0)
	{
		std::cout << "float: " << f << ".0f\n";
		float	d = static_cast<double>(f);
		std::cout << "double: " << d << ".0\n";
	}
	else
	{
		std::cout << "float: " << f << "f\n";
		float	d = static_cast<double>(f);
		std::cout << "double: " << d << "\n";
	}
}

void	ScalarConverter::printFromDouble(double d)
{	
	//we first check with the original int to avoid printing overflowed numbers
	if (d < 0 || d > 255)//negative number or non ASCII
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(d))//non printable char
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		int	c = static_cast<char>(d);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (d < std::numeric_limits<int>::min() || d < std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
	{	int	i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	if (d - static_cast<int>(d) == 0.0)
	{
		float	f = static_cast<float>(d);
		std::cout << "float: " << f << ".0f\n";
		std::cout << "double: " << d << ".0\n";
	}
	else
	{
		float	f = static_cast<float>(d);
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << d << "\n";
	}
}