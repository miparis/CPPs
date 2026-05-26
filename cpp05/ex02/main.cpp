/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:05 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:35:36 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL)); //-> for rand() in robotomy

	/*										SHRUBERRY TESTS					*/
	std::cout << BLUE << "\n--- Test 1: Problem signing and executing ---" << NC << std::endl;
	try
	{
		Bureaucrat b_pro("Hermes Conrad", 150);
		ShrubberyCreationForm f_easy("Home");
		
		std::cout << b_pro;
		std::cout << f_easy;
		
		b_pro.signForm(f_easy); //not enough grade to sign
		f_easy.execute(b_pro);// Shouldnt get here
		std::cout << f_easy;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n--- Test 2: Shruberry working---" << NC << std::endl;
	try
	{
		Bureaucrat b_boss("Boss", 100);
		ShrubberyCreationForm f_top_secret("Top Secret Document");
		
		std::cout <<  b_boss;
		std::cout << f_top_secret;
		
		b_boss.signForm(f_top_secret);
		std::cout <<  b_boss;
		std::cout << f_top_secret;

		f_top_secret.execute(b_boss);// Should work
		std::cout << f_top_secret; // State 'signed: true'
	} 
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	/*										ROBOTOMY TESTS					*/
	std::cout << BLUE << "\n--- Test 3: Robotomy done ---" << NC << std::endl;
	try
	{
	
		Bureaucrat b_dr("Dr.Who", 40);
		RobotomyRequestForm f_easy("Frankeinstein");
		
		std::cout << b_dr;
		std::cout << f_easy;
		
		b_dr.signForm(f_easy);
		std::cout << f_easy;
		b_dr.executeForm(f_easy);
		b_dr.executeForm(f_easy);
		b_dr.executeForm(f_easy);
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n--- Test 4: Robotomy failed ---" << NC << std::endl;
	try
	{
		Bureaucrat b_pro("Hermes Conrad", 150);
		RobotomyRequestForm f_easy("Home");
		
		std::cout << b_pro;
		std::cout << f_easy;
		
		b_pro.signForm(f_easy); //not enough grade to sign
		f_easy.execute(b_pro);// Shouldnt get here
		std::cout << f_easy;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	/*										PRESIDENTIAL PARDON TESTS					*/
	std::cout << BLUE << "\n--- Test 5: PRESIDENTIAL PARDON done ---" << NC << std::endl;
	try
	{
	
		Bureaucrat b_dr("Sanchez", 5);
		PresidentialPardonForm f_easy("Trump");
		
		std::cout << b_dr;
		std::cout << f_easy;
		
		b_dr.signForm(f_easy);
		std::cout << f_easy;
		b_dr.executeForm(f_easy);
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n--- Test 6: PRESIDENTIAL PARDON failed ---" << NC << std::endl;
	try
	{
		Bureaucrat b_pro("Trump", 150);
		PresidentialPardonForm f_easy("Sanchez");
		
		std::cout << b_pro;
		std::cout << f_easy;
		
		b_pro.signForm(f_easy); //not enough grade to sign
		f_easy.execute(b_pro);// Shouldnt get here
		std::cout << f_easy;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	return 0;
}
