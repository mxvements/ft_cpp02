/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:52 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/10 21:11:07 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <iomanip>

/**
 * Copy constructor:
 * 		- creates a new obj from an existing obj
 * 		- creates mem space for the new obj
 * 		- overloaded constructor
 * 		- cpp compiler implicity provides a copy constructor if none is provided
 * 		in the class
 * 		- syntax:
 * 			className(const className &obj) { - body - }
 * 
 * Copy assignment:
 * 		- operator called when an already initialized obj is assignated new
 * 		values from an existing obj
 * 		- does not create new mem space. However, if the class involves dynamic mem,
 * 		it must release the existing mem and then allocate new memory as needed
 * 		- bitwise operator
 * 		- a bitwise copy gets created
 * 		- syntax
 * 			className obj1, obj2; -> both initialized
 * 			obj2 = obj1;
 */

class Fixed
{
	private:
		int 				_int_p;
		static const int	_fract_p; //belongs to the class

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed &fixedP); //copy constructor, copies to referenced using 'this' ptr
		Fixed& operator=(const Fixed &fixed); //copy assignment operator overload
		int getRawBits(void) const;
		void setRawBits(int const raw);
} ;

#endif