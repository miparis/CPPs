/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:05 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:40:07 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	/* 							VALID CREATION FORM										 */	
	std::cout << GREEN << "--- Test 1: Normal Form Creation ---" << NC << std::endl;
	try {
		Form f1("Tax Return", 50, 25, false);
		std::cout << f1;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/* 							ERROR WITH GRADES INVALID								 */	
	std::cout << RED << "\n--- Test 2: Form Constructor Errors ---" << NC << std::endl;
	try {
		std::cout << "Trying to create form with grade 0..." << std::endl;
		Form f_high("Impossible", 0, 50, false);
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to create form with grade 151..." << std::endl;
		Form f_low("Trash", 151, 50, false);
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	/* 						SUCCESFULL SIGN 									 */	
	std::cout << BLUE << "\n--- Test 3: Successful Signing ---" << NC << std::endl;
	try {
		Bureaucrat b_pro("Hermes Conrad", 10);
		Form f_easy("Coffee Request", 20, 150, false);
		
		std::cout << b_pro;
		std::cout << f_easy;
		
		b_pro.signForm(f_easy); // Should work
		std::cout << f_easy;    // State 'signed: true'
	} catch (std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	/* 							FAILED SIGN 									 */	
	std::cout << YELLOW << "\n--- Test 4: Failed Signing (Grade too low) ---" << NC << std::endl;
	try {
		Bureaucrat b_intern("Intern", 140);
		Form f_top_secret("Top Secret Document", 1, 1, false);
		
		std::cout << b_intern;
		std::cout << f_top_secret;
		
		b_intern.signForm(f_top_secret); // Should catch the error internally
		std::cout << f_top_secret;       // State 'signed: false'
	} catch (std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	/* 							SUCCESFULL BESIGNED USE									 */
	std::cout << PURPLE << "\n--- Test 5: Manual signing attempt ---" << NC << std::endl;
	try {
		Bureaucrat b_medium("Middle Manager", 75);
		Form f_medium("Budget Approval", 70, 70, false);

		std::cout << "Trying manual signature..." << std::endl;
		f_medium.beSigned(b_medium); // Should trow exception
	} catch (std::exception &e) {
		std::cerr << "Manual catch: " << e.what() << std::endl;
	}

	return 0;
}
