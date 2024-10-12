/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:19:37 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/12 20:32:58 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Point
{
	private:
		int _coords[3];
	
	public:
		Point(void);
		Point(int coords[3]);
		~Point(void);
		void setCoords(int coords[3]);
		int *getCoords(void);
} ;

#endif