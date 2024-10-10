/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:31 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/10 21:19:38 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * $> ./a.out 
 * Default constructor called
 * Copy constructor called
 * Copy assignment operator called // <-- This line may be missing depending on your implementation
 * getRawBits member function called
 * Default constructor called
 * Copy assignment operator called
 * getRawBits member function called
 * getRawBits member function called
 * 0
 * getRawBits member function called
 * 0
 * getRawBits member function called
 * 0
 * Destructor called
 * Destructor called
 * Destruct
 */
int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}