/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:00:47 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 19:37:54 by miparis          ###   ########.fr       */
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
	else
	{
		std::string _myText;
		std::ifstream _ogFile(argv[1]); //do a control to check if the file passed can be opened
		if (!_ogFile.is_open())
		{
			std::cerr << "Cannot open file passed" << std::endl;
			return (1);
		}
		std::ofstream _newFile("newFile.txt");
		if (!_newFile.is_open())
		{
			std::cerr << "Cannot create newFile" << std::endl;
			return (1);
		}
		while (std::getline(_ogFile, _myText)) //copy from the ogfile to my newfile
		{
			_newFile << _myText << "\n";
		}
		_ogFile.close();
		_newFile.close();
	}
	return (0);
}