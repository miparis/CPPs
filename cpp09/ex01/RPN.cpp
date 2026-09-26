/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:38:32 by miparis           #+#    #+#             */
/*   Updated: 2026/09/26 13:18:39 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//as deque is a container, we dont have to init it dinamically
RPN::RPN() : _size(0)
{
}
RPN::RPN(const RPN &copy)
{
	if (this != &copy)
	{
		this->_values = copy._values;
		this->_size = copy._size;
	}
}
RPN& RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		this->_values = copy._values;
		this->_size = copy._size;
	}
	return (*this);
}

RPN:: ~RPN()
{
}

void RPN::RevertedPolishNotation(const std::string &_input)
{
	//we start parsing the input
    for (size_t i = 0; i < _input.length(); ++i)
	{
        char c = _input[i];

        if (c == ' ')
            continue;
		
		// for every nmb we find,
		// we convert it and put it in the deque ans updating the size of the deque
		if (isdigit(c))
		{
			this->_values.push_back(c - '0');
			this->_size++;
		}

		//when we encounter an operand
		else if (c == '*' || c == '+' || c == '-' || c== '/')
		{
			// if we dont have enough nmbs to operate, its an error
			if (this->_size < 2)
			{
				std::cerr << RED << "Error" << NC << std::endl;
				return ;
			}

			//else we get the right value,
			// (aka the last one) and get it out 
			// and update also the size of the deque
			int r_operand = this->_values.back();
			this->_values.pop_back();
			this->_size--;

			//else we get the left value and repeat the steps
			int l_operand = this->_values.back();
			this->_values.pop_back();
			this->_size--;


			//we start operating
			int result = 0;
            if (c == '+')
				result = (l_operand + r_operand);
            else if (c == '-')
				result = (l_operand - r_operand);
            else if (c == '*')
				result = (l_operand * r_operand);
            else if (c == '/')
			{
                if (r_operand == 0)
				{
                    std::cerr << "Error" << std::endl;
                    return;
                }
                result = (l_operand / r_operand);
            }
			//push the result at the end in the deque and update size
			this->_values.push_back(result);
			this->_size++;
		}
		else //control for other chars
		{
			std::cerr << RED << "Error" << NC << std::endl;
			return ;
		}

	}
	if (this->_size == 1) //print result
		std::cout << BLUE << this->_values.back() << NC << std::endl;
	else
		std::cerr << RED << "Error" << NC << std::endl;
}

