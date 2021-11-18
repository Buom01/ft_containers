/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/11/18 13:33:32 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_ACCESS_HPP
# define TESTS_MAP_ACCESS_HPP

template <class container>
int	map_access_1(container &map)
{
	if (map.begin() != map.end())
		return (1);

	return (0);
}

template <class container>
int	map_access_2(container &map)
{
	if (map.rbegin() != map.rend())
		return (1);

	return (0);
}

template <class container, class pair>
int	map_access_3(container &map)
{
	typename container::iterator	it;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	it = map.begin();

	if (map.front() != 0)
		return (1);
	if (map.back() != 4)
		return (2);

	return (0);
}

template <class container>
int	map_access_4(container &map)
{
	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	if (map.at(0) != map[0] || map[0] != 0)
		return (1);

	if (map.at(1) != map[1] || map[1] != 1)
		return (2);

	if (map.at(2) != map[2] || map[2] != 2)
		return (3);

	if (map.at(3) != map[3] || map[3] != 3)
		return (4);

	if (map.at(4) != map[4] || map[4] != 4)
		return (5);

	return (0);
}

template <class container>
int	map_access_5(container &map)
{
	const E	*const_data;
	E		*data			= map.data();

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	data		= map.data();
	const_data	= map.data();

	if (*data != 0)
		return (1);

	*data = 9;

	if (*(++data) != 1)
		return (2);

	if (*(++data) != 2)
		return (3);

	if (*(++data) != 3)
		return (4);

	if (*(++data) != 4)
		return (5);


	if (const_data[0] != 9)
		return (6);

	if (const_data[1] != 1)
		return (7);

	if (const_data[2] != 2)
		return (8);

	if (const_data[3] != 3)
		return (9);

	if (const_data[4] != 4)
		return (10);

	return (0);
}

#endif

