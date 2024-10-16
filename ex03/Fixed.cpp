/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:31:34 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/16 20:07:18 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>

Fixed::Fixed(void):_raw_bits(0){};

Fixed::~Fixed(void){};

/**
 * Copy constructor
 * Fixed b(a);
 *
 * copies a into b
 * this references b, which is the object initializing
 */
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
};

Fixed::Fixed(const int int_nbr)
{
	this->_raw_bits = int_nbr * (1 << Fixed::_fract_bits);
}

Fixed::Fixed(const float float_nbr)
{
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
	if (this != &fixed)
		this->_raw_bits = fixed.getRawBits();
	return *this;
}

//  operator overloads

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

bool Fixed::operator!=(const Fixed &fixed)
{
	if (this->getRawBits() != fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &fixed)
{
	if (this->getRawBits() != fixed.getRawBits())
		return (0);
	return (1);
}

bool Fixed::operator>=(const Fixed &fixed)
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator>(const Fixed &fixed)
{
	if (this->getRawBits() > fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &fixed)
{
	if (this->getRawBits() <= fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &fixed)
{
	if (this->getRawBits() < fixed.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	float added_float = this->toFloat() + fixed.toFloat();
	return (Fixed(added_float));
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	float substracted_float = this->toFloat() - fixed.toFloat();
	return (Fixed(substracted_float));
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	float mult_float = this->toFloat() * fixed.toFloat();
	return (Fixed(mult_float));
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	float div_float = this->toFloat() / fixed.toFloat();
	return (Fixed(div_float));
}

//Prefix
Fixed &Fixed::operator++()
{
	int val = this->getRawBits() + 1;
	this->setRawBits(val);
	return (*this);
}

//Postfix
Fixed &Fixed::operator++(int)
{
	Fixed *tmp = new Fixed(*this);  //created a copy, return this
	int val = this->getRawBits() + 1;
	this->setRawBits(val);
	return (*tmp);
}

//Prefix
Fixed &Fixed::operator--()
{
	int val = this->getRawBits() - 1;
	this->setRawBits(val);
	return (*this);
}

//Postfix
Fixed &Fixed::operator --(int)
{
	Fixed *tmp = new Fixed(*this); //created a copy, return this
	int val = this->getRawBits() - 1;
	this->setRawBits(val);
	return (*tmp);
}

// member functs

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

//statics

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	Fixed *min = new Fixed();
	if (f1.getRawBits() <= f2.getRawBits())
	{
		*min = f1;
	} else {
		*min = f2;
	}
	return (*min);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	Fixed *max = new Fixed();
	if (f1.getRawBits() >= f2.getRawBits())
	{
		*max = f1;
	} else {
		*max = f2;
	}
	return (*max);
}
