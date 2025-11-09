/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:00:47 by miparis           #+#    #+#             */
/*   Updated: 2025/11/09 16:45:08 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Missing arguments. We need: file + string1 + string2" << std::endl;
		return (1);
	}
	else if (argv[2][0] == '\0')
	{
		std::cerr << "String 1 cannot be empty" << std::endl;
		return (1);
	}
	else
	{
		std::ifstream _ogFile(argv[1]);
		std::string _ogFileName = argv[1];
		 //do a control to check if the file passed can be opened
		if (!_ogFile.is_open())
		{
			std::cerr << "Cannot open " << _ogFileName <<std::endl;
			return (1);
		}
		//Preparing new file
		std::string  _fileName = _ogFileName + ".replace";
		std::ofstream _newFile(_fileName.c_str());
		if (!_newFile.is_open())
		{
			std::cerr << "Cannot create newFile... Aborting" << std::endl;
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
	std::cout << "Everything done for you loser :p" << std::endl;
	return (0);
}