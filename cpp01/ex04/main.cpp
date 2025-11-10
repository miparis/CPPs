/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:00:47 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 11:42:52 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

const std::string GREEN  = "\033[0;32m"; // Bold Green
const std::string YELLOW = "\033[0;33m"; // Yellow
const std::string RED    = "\033[0;31m"; // Red
const std::string BLUE   = "\033[0;34m"; // Bold Blue
const std::string PURPLE = "\033[1;35m"; // Bold Purple
const std::string BOLD   = "\033[1m";    // Bold text
const std::string NC     = "\033[0m";    // Reset color

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << BOLD << RED << "Missing arguments. We need: file + string1 + string2" << NC << std::endl;
		return (1);
	}
	else if (argv[2][0] == '\0')
	{
		std::cerr << BOLD << RED << "String 1 cannot be empty" << NC << std::endl;
		return (1);
	}
	else
	{
		std::ifstream _ogFile(argv[1]);
		std::string _ogFileName = argv[1];
		 //do a control to check if the file passed can be opened
		if (!_ogFile.is_open())
		{
			std::cerr << BOLD << RED << "Cannot open " << _ogFileName << NC << std::endl;
			return (1);
		}
		//Preparing new file
		std::string  _fileName = _ogFileName + ".replace";
		std::ofstream _newFile(_fileName.c_str());
		if (!_newFile.is_open())
		{
			std::cerr << BOLD << RED << "Cannot create newFile... Aborting" << NC << std::endl;
			return (1);
		}

		//Replacement flow
		std::string _myText;
		while (std::getline(_ogFile, _myText)) //copy from the ogfile to my newfile
		{
			size_t pos = 0;
			while ((pos = _myText.find(argv[2], pos)) != std::string::npos) //search for all the ocurrences of the string
			{
				_myText.erase(pos, std::string(argv[2]).length());
				_myText.insert(pos, argv[3]);
				pos += std::string(argv[3]).length();
			}
			_newFile << _myText;
			if (!_ogFile.eof())
				_newFile << "\n";
		}
		_ogFile.close();
		_newFile.close();
	}
	std::cout << BOLD << GREEN << "Everything done for you loser :p" << NC << std::endl;
	return (0);
}