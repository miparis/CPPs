/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:01:53 by miparis           #+#    #+#             */
/*   Updated: 2026/06/12 10:28:45 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <cctype>
#include <cstdlib>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	
	P_INFF,
	N_INFF,
	T_INFF,
	T_NANF,
	N_INF,
	T_INF, 
	P_INF,
	T_NAN,

	NONE
};



class ScalarConverter
{
	private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& _copy);
	ScalarConverter& operator=(const ScalarConverter& _copy);
	virtual ~ScalarConverter();

	static type	parseLiteral(const std::string& _literal);
	static type	searchPseudo(const std::string _literal);

	static bool	isChar(const std::string _literal);
	static bool	isInt(const std::string _literal);
	static bool	isDouble(const std::string _literal);
	static bool	isFloat(const std::string _literal);
	static void	toType(type _type, const std::string _literal);

	static void	printFromInt(int i);
	static void	printFromChar(char c);
	static void	printFromFloat(float f);
	static void	printFromDouble(double d);
	static void	printFromPseudo(type _type);

	public:
	static void	convert(const std::string& _literal);

};

