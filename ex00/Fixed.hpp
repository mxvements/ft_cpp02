/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:52 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/12 18:18:24 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Fixed
{
	private:
		int 				_raw_bits;
		static const int	_fract_bits = 8; //belongs to the class

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed &fixedP); //copy constructor, copies to referenced using 'this' ptr
		Fixed& operator=(const Fixed &fixed); //copy assignment operator overload
		int getRawBits(void) const;
		void setRawBits(int const raw);
} ;

#endif