/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:07:23 by miparis           #+#    #+#             */
/*   Updated: 2025/09/20 17:37:54 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>


int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *str_pointer = &str;
	std::string	&str_ref = str;

	std::cout << "--- Printing addresses ---" << std::endl;
	std::cout << "Str memory address is " << &str << std::endl;
	std::cout << "Str_pointer memory address is " << &str_pointer << std::endl;
	std::cout << "Str_ref memory address is " << &str_ref  << std::endl;
	std::cout << std::endl;
	std::cout << "--- Printing content ---" << std::endl;
	std::cout << "Str memory content is: " << str << std::endl;
	std::cout << "Str_pointer memory content is: " << *str_pointer << std::endl;
	std::cout << "Str_ref memory content is: " << str_ref  << std::endl;
	
	return (0);
}