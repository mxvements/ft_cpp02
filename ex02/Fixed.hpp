/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:52 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/16 20:17:38 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <iomanip>


/**
 * 
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
		
		bool operator!=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);
		bool operator>=(const Fixed &Fixed);
		bool operator>(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		bool operator<(const Fixed &fixed);

		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);

		Fixed &operator++(); //pre increment
		Fixed &operator++(int); //post increment, dummy iny param
		Fixed &operator--();
		Fixed &operator --(int);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static Fixed &max(const Fixed &f1, const Fixed &f2);

} ;

#endif