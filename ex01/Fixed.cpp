/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:31:34 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/12 18:16:53 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>

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
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};

Fixed::Fixed(const int int_nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = int_nbr * (1 << Fixed::_fract_bits);
}

Fixed::Fixed(const float float_nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = (float_nbr * (1 << Fixed::_fract_bits));
}

/**
 * Copy assignment overload
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

/**
 * Insertion assignment overload
 * 
 * Example with 42.42
 * 		when storing raw_bits
 * 		42.42 * (1 << 8) = 42.42 * 256 = 10859
 * 		
 * 		when calculating the ouput
 * 		int part	-> 10859 >> 8 = 42
 * 		float part	-> 10859 << 255 = 107
 * 						107 / 256 = 0.412
 */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	int integer_part = fixed.getRawBits() >> Fixed::_fract_bits;
	float fractional_part = fixed.getRawBits() & ((1 << Fixed::_fract_bits) - 1);
	float floatFractional = fractional_part / (1 << Fixed::_fract_bits);
	os << integer_part + floatFractional;
	return (os);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

float Fixed::toFloat(void) const
{
	return ((this->_raw_bits / (float)(1 << Fixed::_fract_bits)));
}

int Fixed::toInt(void) const
{
	return ((int)(this->_raw_bits >> Fixed::_fract_bits));
}