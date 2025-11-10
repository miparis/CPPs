/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:00:47 by miparis           #+#    #+#             */
/*   Updated: 2025/11/09 18:37:16 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string _message;
	Harl _h;
	
	while (true)
	{
		std::cout << BOLD << PURPLE << "What do you want?" << std::endl  << NC;
		std::getline(std::cin, _message);
		if (_message == "EXIT")
        {
            std::cout << BOLD << GREEN << "Finally you leaving!" << NC << std::endl;
            break;
        }
		_h.complain(_message);
	}
	return (0);
}