/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 10:30:41 by miparis           #+#    #+#             */
/*   Updated: 2026/06/15 10:50:48 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& _copy)
{
	*this = _copy;
}
Serializer& Serializer::operator=(const Serializer& _copy)
{
	if (this != &_copy)
			*this = _copy;
	return (*this);
}

Serializer:: ~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{	
	return (reinterpret_cast<Data*>(raw));
}