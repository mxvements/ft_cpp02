/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:52 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/12 15:24:25 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <iomanip>


/**
 * << overload
 * 
 * we need to declare it as a 'friend' function because it is treated as a non-member
 * function in terms on how cpp handles access control, it doesnt have access to
 * the private or protected members of the class unless it is explicitly declared
 * as a friend
 */
class Fixed
{
	private:
		int 				_raw_bits;
		static const int	_fract_bits = 8; //belongs to the class

	public:
		Fixed(void);
		~Fixed(void);
		
		Fixed(const int int_nbr); //converts it to the fixed-point value
		Fixed(const float float_nbr); //converts it to the fixed-point value
		Fixed(const Fixed &fixedP); //copy constructor, copies to referenced using 'this' ptr
		
		Fixed &operator=(const Fixed &fixed); //copy assignment operator overload
		friend std::ostream &operator<<(std::ostream& os, const Fixed &fixed);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
} ;

#endif