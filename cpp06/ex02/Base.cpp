/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:28:18 by miparis           #+#    #+#             */
/*   Updated: 2026/06/30 12:28:29 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base:: ~Base(){}

Base* generate(void)
{
	int	_random = std::rand() %3;

	if (_random == 0)
	{
		std::cout <<  GREEN << "A generated" << NC << std::endl;
		return (new A());
	}
	if (_random == 1)
	{
		std::cout <<  BLUE << "B generated" << NC << std::endl;
		return (new B());
	}
	else if (_random == 2)
	{
		std::cout << PURPLE << "C generated" << NC << std::endl;
		return (new C());
	}
	return (NULL);
}
void identify(Base* p)
{
	if (dynamic_cast <A*>(p) != NULL)
		std::cout <<  GREEN << "A" << NC << std::endl;
	if (dynamic_cast <B*>(p) != NULL)
		std::cout <<  BLUE << "B" << NC << std::endl;
	if (dynamic_cast <C*>(p) != NULL)
		std::cout <<  PURPLE << "C" << NC << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout <<  GREEN << "A" << NC << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout <<  BLUE << "B" << NC << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout <<  PURPLE << "C" << NC << std::endl;
		return ;
	}
	catch(const std::exception& e){}	
}