/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:31:34 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/12 14:46:56 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):_raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(void){ std::cout << "Destructor called" << std::endl; };

/**
 * Copy constructor
 * Fixed b(a);
 * 
 * copies a into b
 * this references b, which is the object initializing
 */
Fixed::Fixed(Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};
/**
 * Copy assignment
 * c = b, both already initialized
 * 
 * this references c
 * sets c with the data from b (&fixed from the function below)
 * 
 */
Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_raw_bits = fixed.getRawBits();		
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}
