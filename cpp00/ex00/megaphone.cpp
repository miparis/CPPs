/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:01:37 by miparis           #+#    #+#             */
/*   Updated: 2025/09/20 18:09:45 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Megaphone
{
	public:
	std:: string input;
	std:: string return_input;

	std::string ConcatInput(char **argv);
	void Capitalize(std::string &input);
	void phraseReturn(char **argv);
};

std::string Megaphone:: ConcatInput(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (i == 1)
			input = argv[i];
		else
			input = input + argv[i];
		i++;
	}
	return (input);
}

void Megaphone::Capitalize(std::string &input)
{
	for (int i = 0; i < input.length(); i++)
		input[i] = toupper(input[i]);
}

void Megaphone:: phraseReturn(char **argv)
{
	ConcatInput(argv);
	Capitalize(input);
}

int main(int argc, char **argv)
{
	Megaphone	phrase;

	if (argc < 2)
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		phrase.phraseReturn(argv);
	std:: cout << std::endl;
	return (0);
}