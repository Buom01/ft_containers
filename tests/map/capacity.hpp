/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/28 23:49:03 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_CAPACITY_HPP
# define TESTS_MAP_CAPACITY_HPP

template <class container>
int	map_capacity_maxsize(container &map)
{
	typename container::size_type maxsize1	= map.max_size();

	map.insert(map.end(), 100, 1);

	if (map.max_size() != maxsize1)
		return (1);

	if (maxsize1 < 128)
		return (2);
	
	return (0);
}

template <class container>
int	map_capacity_reservecapacity(container &map)
{
	map.capacity();

	if (map.size() != 0 || !map.empty())
		return (1);

	map.push_back(0);

	if (map.capacity() < 1 || map.size() != 1 || map.empty())
		return (2);

	map.insert(map.end(), 100, 1);

	if (map.capacity() < 101 || map.size() != 101 || map.empty())
		return (3);

	map.reserve(100);

	if (map.capacity() < 101 || map.size() != 101 || map.empty())
		return (4);

	map.reserve(200);

	if (map.capacity() < 200 || map.size() != 101 || map.empty())
		return (5);

	return (0);
}

#endif

