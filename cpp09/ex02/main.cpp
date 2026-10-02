/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:47:30 by miparis           #+#    #+#             */
/*   Updated: 2026/10/02 11:05:05 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << BOLD << RED << "Error: no arguments provided." << NC << std::endl;
		return (1);
	}

	PmergeMe _sorter;
	if (!_sorter.validateArgs(argc, argv))
		return (1);
	_sorter.executeSorts(argc, argv);

	return (0);
}