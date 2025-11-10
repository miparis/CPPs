/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:54:42 by miparis           #+#    #+#             */
/*   Updated: 2025/11/09 18:30:04 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>

const std::string GREEN  = "\033[0;32m"; // Bold Green
const std::string YELLOW = "\033[0;33m"; // Yellow
const std::string RED    = "\033[0;31m"; // Red
const std::string BLUE   = "\033[0;34m"; // Bold Blue
const std::string PURPLE = "\033[1;35m"; // Bold Purple
const std::string BOLD   = "\033[1m";    // Bold text
const std::string NC     = "\033[0m";    // Reset color

class Harl
{
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	std::map<std::string, void(Harl::*)()>messages;

	public:
	Harl();
	void complain( std::string level );
};

#endif