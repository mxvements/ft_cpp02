/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:31:34 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/10 21:17:43 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){};

Fixed::~Fixed(void){};

Fixed::Fixed(Fixed &fixedP)
{
	fixedP._int_p = this->_int_p;
};

Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_int_p = fixed._int_p;		
	return *this;
}

int Fixed::getRawBits(void) const
{
	//TODO
	return 0;
}

void Fixed::setRawBits(int const raw)
{
	//TODO
	(void)raw;
}
