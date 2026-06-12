/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:50:30 by miparis           #+#    #+#             */
/*   Updated: 2026/06/12 10:04:40 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./ScalarConverter <input>" << NC <<std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}