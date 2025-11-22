/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:03:20 by miparis           #+#    #+#             */
/*   Updated: 2025/11/22 18:58:10 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return (0);
}
//
//
//int main( void )
//{
//	// -------------------------------------------------------------------------
//	// 1. ARITHMETIC OPERATORS (+, -, *, /)
//	// -------------------------------------------------------------------------
//	std::cout << BOLD << "--- TEST: ARITHMETIC OPERATORS ---" << NC << std::endl;
//
//	Fixed a(10.5f);
//	Fixed b(5);
//	Fixed c(20.75f);
//	Fixed d(0.5f);
//	Fixed e(3.0f);
//
//	// Test + (10.5 + 5 = 15.5)
//	std::cout << "1. a(10.5f) + b(5): " << YELLOW << (a + b) << NC << " (Expected: 15.5)" << std::endl;
//
//	// Test - (20.75 - 0.5 = 20.25)
//	std::cout << "2. c(20.75f) - d(0.5f): " << YELLOW << (c - d) << NC << " (Expected: 20.25)" << std::endl;
//
//	// Test * (10.0 * 0.5 = 5.0) - Crucial for scaling check
//	std::cout << "3. a(10.5f) * d(0.5f): " << YELLOW << (a * d) << NC << " (Expected: 5.25)" << std::endl;
//
//	// Test / (10.0 / 3.0 = ~3.33984...)
//	std::cout << "4. a(10.5f) / e(3.0f): " << YELLOW << (a / e) << NC << " (Expected: ~3.5)" << std::endl;
//	
//	// -------------------------------------------------------------------------
//	// 2. COMPARISON OPERATORS (>, <, ==, !=, >=, <=)
//	// -------------------------------------------------------------------------
//	std::cout << BOLD << "\n--- TEST: COMPARISON OPERATORS ---" << NC << std::endl;
//
//	Fixed f(10);
//	Fixed g(10.0039f); // 10 + 1/256 (smallest fractional unit)
//	Fixed h(10);
//
//	std::cout << "f = 10.0, g = 10.0039, h = 10.0" << std::endl;
//
//	// Test >
//	std::cout << "1. f > g: " << (f > g ? GREEN : RED) << (f > g) << NC << " (Expected: 0)" << std::endl;
//	// Test <
//	std::cout << "2. f < g: " << (f < g ? GREEN : RED) << (f < g) << NC << " (Expected: 1)" << std::endl;
//	// Test ==
//	std::cout << "3. f == h: " << (f == h ? GREEN : RED) << (f == h) << NC << " (Expected: 1)" << std::endl;
//	// Test !=
//	std::cout << "4. f != h: " << (f != h ? GREEN : RED) << (f != h) << NC << " (Expected: 0)" << std::endl;
//	// Test >=
//	std::cout << "5. g >= h: " << (g >= h ? GREEN : RED) << (g >= h) << NC << " (Expected: 1)" << std::endl;
//
//	// -------------------------------------------------------------------------
//	// 3. INCREMENT/DECREMENT OPERATORS
//	// -------------------------------------------------------------------------
//	std::cout << BOLD << "\n--- TEST: INCREMENT/DECREMENT OPERATORS ---" << NC << std::endl;
//
//	Fixed i(42); // Start at 42.0
//
//	// Test Pre-Increment (++i)
//	std::cout << "1. i before (++i): " << i << std::endl; // 42.0
//	std::cout << "   Result of ++i: " << YELLOW << ++i << NC << " (Expected: 42.0039...)" << std::endl; // 42 + 1/256
//	std::cout << "   i after ++i: " << i << std::endl; // 42.0039...
//
//	// Test Post-Increment (i++)
//	std::cout << "2. i before (i++): " << i << std::endl; // 42.0039...
//	std::cout << "   Result of i++: " << YELLOW << i++ << NC << " (Expected: 42.0039...)" << std::endl; // Original value returned
//	std::cout << "   i after i++: " << i << std::endl; // 42.0078...
//
//	// Test Pre-Decrement (--i)
//	std::cout << "3. i before (--i): " << i << std::endl; // 42.0078...
//	std::cout << "   Result of --i: " << YELLOW << --i << NC << " (Expected: 42.0039...)" << std::endl; // 42 + 1/256
//	std::cout << "   i after --i: " << i << std::endl; // 42.0039...
//
//	// Test Post-Decrement (i--)
//	std::cout << "4. i before (i--): " << i << std::endl; // 42.0039...
//	std::cout << "   Result of i--: " << YELLOW << i-- << NC << " (Expected: 42.0039...)" << std::endl; // Original value returned
//	std::cout << "   i after i--: " << i << std::endl; // 42.0
//
//	// -------------------------------------------------------------------------
//	// 4. STATIC FUNCTIONS (min/max)
//	// -------------------------------------------------------------------------
//	std::cout << BOLD << "\n--- TEST: STATIC MIN/MAX FUNCTIONS ---" << NC << std::endl;
//	
//	Fixed j(50.5f);
//	Fixed k(100.1f);
//	
//	// Mutable Test (min)
//	std::cout << "1. Min (mutable, j=50.5, k=100.1): " << YELLOW << Fixed::min(j, k) << NC << " (Expected: 50.5)" << std::endl;
//
//	// Mutable Test (max)
//	std::cout << "2. Max (mutable, j=50.5, k=100.1): " << YELLOW << Fixed::max(j, k) << NC << " (Expected: 100.1)" << std::endl;
//
//	// Const Test (max) - Requires const objects
//	const Fixed l(20.2f);
//	const Fixed m(20.3f);
//	std::cout << "3. Max (const, l=20.2, m=20.3): " << YELLOW << Fixed::max(l, m) << NC << " (Expected: 20.3)" << std::endl;
//
//	// Test min/max on equality
//	Fixed n(12.3f);
//	Fixed o(12.3f);
//	std::cout << "4. Min (equal, n=12.3, o=12.3): " << YELLOW << Fixed::min(n, o) << NC << " (Expected: 12.3)" << std::endl;
//
//
//	// -------------------------------------------------------------------------
//	// 5. EDGE CASE (DIVISION BY ZERO)
//	// -------------------------------------------------------------------------	
//	std::cout << BOLD << "\n--- ALL TESTS COMPLETE ---" << NC << std::endl;
//	return (0);
//}//