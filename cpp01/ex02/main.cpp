/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:07:23 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 11:29:23 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

const std::string GREEN  = "\033[0;32m"; // Bold Green
const std::string YELLOW = "\033[0;33m"; // Yellow
const std::string RED    = "\033[0;31m"; // Red
const std::string BLUE   = "\033[0;34m"; // Bold Blue
const std::string PURPLE = "\033[1;35m"; // Bold Purple
const std::string BOLD   = "\033[1m";    // Bold text
const std::string NC     = "\033[0m";    // Reset color

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str; //Here we store the address where str is
	std::string	&stringREF = str; //Different name for the same str

	std::cout << BOLD << PURPLE << "--- Printing addresses ---" << NC << std::endl;
	std::cout << BLUE << "Str memory address is " << &str << NC << std::endl;
	std::cout << YELLOW << "Str_pointer memory address is " << stringPTR << NC << std::endl;
	std::cout << GREEN << "Str_ref memory address is " << &stringREF  << NC << std::endl;

	std::cout << std::endl;
	
	std::cout << BOLD << PURPLE << "--- Printing content ---" << NC << std::endl;
	std::cout << BLUE << "Str memory content is: " << str << NC << std::endl;
	std::cout << YELLOW << "Str_pointer memory content is: " << *stringPTR << NC << std::endl;
	std::cout << GREEN << "Str_ref memory content is: " << stringREF  << NC << std::endl;
	
	return (0);
}