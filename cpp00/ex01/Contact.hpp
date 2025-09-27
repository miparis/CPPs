/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:16:36 by miparis           #+#    #+#             */
/*   Updated: 2025/09/20 18:08:33 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone; //should we put it as a int?
		std::string darkest_secret;

		std::string TruncateField(const std::string& field);
		
	public:
		void AddField(const std::string& field_name, const std::string& value);
		bool HasEmptyFields();
		void DisplaySummary(int index);
		void DisplayFull();
};

#endif