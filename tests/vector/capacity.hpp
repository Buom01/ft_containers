/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/09/20 22:24:59 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_CAPACITY_HPP
# define TESTS_VECTOR_CAPACITY_HPP

template <class container>
int	vector_capacity_maxsize(container &vector)
{
	typename container::size_type maxsize1	= vector.max_size();

	vector.insert(vector.end(), 100u, 1);

	if (vector.max_size() != maxsize1)
		return (1);

	if (maxsize1 < 128)
		return (2);
	
	return (0);
}

template <class container>
int	vector_capacity_reservecapacity(container &vector)
{
	vector.capacity();

	if (vector.size() != 0 || !vector.empty())
		return (1);

	vector.push_back(0);

	if (vector.capacity() < 1 || vector.size() != 1 || vector.empty())
		return (2);

	vector.insert(vector.end(), 100u, 1);

	if (vector.capacity() < 101 || vector.size() != 101 || vector.empty())
		return (3);

	vector.reserve(100);

	if (vector.capacity() < 101 || vector.size() != 101 || vector.empty())
		return (4);

	vector.reserve(200);

	if (vector.capacity() < 200 || vector.size() != 101 || vector.empty())
		return (5);

	return (0);
}

#endif

