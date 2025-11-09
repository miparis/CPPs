/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:57:19 by miparis           #+#    #+#             */
/*   Updated: 2025/11/09 18:38:55 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl()
{
	messages["INFO"] =&Harl::info;
	messages["WARNING"] =&Harl::warning;
	messages["DEBUG"] =&Harl::debug;
	messages["ERROR"] =&Harl::error;
}
void Harl::complain( std::string level )
{
	std::map<std::string, void (Harl::*)()>::iterator it = messages.find(level) ;
	
	if (it != messages.end())
	{
		void (Harl::*func)() = it->second;
		(this->*func)();
	}
	else
	{
		std::cout << BOLD << PURPLE << "Be clear! I can:"  << std::endl;
		std::cout << "- INFO"  << std::endl;
		std::cout << "- DEBUG"  << std::endl;
		std::cout << "- WARNING"  << std::endl;
		std::cout << "- ERROR"  << std::endl;
		std::cout << "- EXIT(please)" << std::endl << NC;
	}
}
void  Harl::debug( void )
{
	std::cout << BLUE << "Processing..." << std::endl << "Found 10902 problems with you" << std::endl;
}
void  Harl::info( void )
{
	std::cout <<  GREEN << "Random fact:" << std::endl << "Miranda is always hungry" << std::endl;
}
void  Harl::warning( void )
{
	std::cout << YELLOW << "This is a warning for you checky f*/'er!" << std::endl;
}
void  Harl::error( void )
{
	std::cout << RED << "All of your brains are gone: Aborting ..." << std::endl;
}
