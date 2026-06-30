/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 10:38:09 by miparis           #+#    #+#             */
/*   Updated: 2026/06/30 12:18:32 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	//Original values
    Data _originalData;
    _originalData._value = 84;
    _originalData._name = "Miranda";

    std::cout << BLUE << "--- ORIGINAL ---" << std::endl << GREEN << "Address: " << &_originalData << std::endl << "ID: " << _originalData._value << " | Name: " << _originalData._name << NC << std::endl;

	// Serializer (Pointer to uniptr)
    uintptr_t raw = Serializer::serialize(&_originalData);
    
    std::cout << YELLOW << std::endl << "--- SERIALIZED ---" << NC << std::endl;
	 std::cout << GREEN << "Result uintptr_t address: " << &raw << NC << std::endl;
    std::cout << GREEN << "Result uintptr_t value: " << raw << NC << std::endl;

    // Deserializer (Uniptr a to Pointer)
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << PURPLE << std::endl << "--- DESERIALIZED ---" << NC << std::endl;
    std::cout << GREEN << "Address: " << deserializedData << std::endl;
    std::cout << "ID: " << deserializedData->_value<< " | Name: " << deserializedData->_name << NC << std::endl;

    //Checking values
    if (&_originalData == deserializedData)
        std::cout << "\nSUCCESS: The pointers match perfectly!" << std::endl;
    else
        std::cout << "\nFAIL: The pointers are different." << std::endl;

    return 0;
}