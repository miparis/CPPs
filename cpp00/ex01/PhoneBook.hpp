/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:26:04 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 16:04:40 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contact_count;

	public:
		PhoneBook() : contact_count(0){} //Default Constructor to  avoid garbage values inside
		void	AddContact();
		bool	CheckIfEmpty(std::string& input);
		void	SearchContact();
};

#endif