/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:07:15 by miparis           #+#    #+#             */
/*   Updated: 2026/09/26 13:08:25 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	RPN _test;
	
	if (argc != 2)
	{
		std::cerr << RED << "Error" << NC << std::endl;
		return (1);
	}
	_test.RevertedPolishNotation(argv[1]);
	return (0);
}