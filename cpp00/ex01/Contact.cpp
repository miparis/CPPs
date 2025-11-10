/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:16:16 by miparis           #+#    #+#             */
/*   Updated: 2025/08/26 10:08:59 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::TruncateField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return (field);
}

void Contact::AddField(const std::string& field_name, const std::string& value)
{
	if (field_name == "first name")
		first_name = value;
	else if (field_name == "last name")
		last_name = value;
	else if (field_name == "nickname")
		nickname = value;
	else if (field_name == "phone number")
		phone = value;
	else if (field_name == "darkest secret")
		darkest_secret = value;
}

bool Contact::HasEmptyFields()
{
	return (first_name.empty() || last_name.empty() || nickname.empty() || phone.empty() || darkest_secret.empty());
}

void Contact::DisplaySummary(int index)
{
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << TruncateField(first_name) << "|";
	std::cout << std::setw(10) << std::right << TruncateField(last_name) << "|";
	std::cout << std::setw(10) << std::right << TruncateField(nickname) << std::endl;
}

void Contact::DisplayFull()
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
