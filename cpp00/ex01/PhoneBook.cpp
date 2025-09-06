/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:15:32 by miparis           #+#    #+#             */
/*   Updated: 2025/08/26 10:20:47 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::AddContact()
{
	std::string first_name, last_name, nickname, phone, darkest_secret;
	std::string input;
	int			indexToAdd;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (CheckIfEmpty(input) == true)
		return;
	first_name = input;

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (CheckIfEmpty(input) == true)
		return;
	last_name = input;

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (CheckIfEmpty(input) == true)
		return;
	nickname = input;

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (CheckIfEmpty(input) == true)
		return;
	phone = input;

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (CheckIfEmpty(input) == true)
		return;
	darkest_secret = input;

	indexToAdd = contact_count;
	if (contact_count == 8)
	{
		std::cout << "Phonebook is full. Replacing the oldest contact..." << std::endl;
		for (int i = 0; i < 7; ++i)
		{
			contacts[i] = contacts[i + 1];
		}
		indexToAdd = 7;
	}
	else
		contact_count++;
	contacts[indexToAdd].AddField("first name", first_name);
	contacts[indexToAdd].AddField("last name", last_name);
	contacts[indexToAdd].AddField("nickname", nickname);
	contacts[indexToAdd].AddField("phone number", phone);
	contacts[indexToAdd].AddField("darkest secret", darkest_secret);
}

bool	PhoneBook::CheckIfEmpty(std::string& input)
{
	if (input.empty())
	{
		std::cout << "Field cannot be empty. Aborting add..." << std::endl;
		return (true);
	}
	return (false);
}

void PhoneBook::SearchContact()
{
	if (contact_count == 0)
	{
		std::cout << "Phonebook is empty. No contacts to display." << std::endl;
		return;
	}

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < contact_count; ++i)
		contacts[i].DisplaySummary(i + 1);

	std::cout << "Enter the index of the contact you wish to display: ";
	int index;
	std::cin >> index;

	if (std::cin.fail() || index < 1 || index > contact_count)
	{
		//Clears the error flags of the stream. When an input operation fails (
		std::cin.clear();
		std::cout << "Invalid index. Please enter a number between 1 and " << contact_count << "." << std::endl;
	}
	else
		contacts[index - 1].DisplayFull();
	//Prevents getline from reading the leftover newline character
	std::cin.ignore(256, '\n');
}