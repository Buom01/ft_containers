/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/14 15:32:16 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_CAPACITY_HPP
# define TESTS_MAP_CAPACITY_HPP

# include <sstream>

template <class container, class pair>
int	map_capacity(container &map)
{
	typename container::size_type	maxsize1	= map.max_size();
	int								i			= 0;
	std::stringstream				key;

	map.insert(pair("empty1", map.empty()));

	while (i < 10)
	{
		key << i;
		map.insert(pair(key.str(), i));
		key.str(std::string());
		++i;
	}

	if (map.max_size() != maxsize1)
		return (1);

	if (maxsize1 < 128)
		return (2);
	
	map.insert(pair("empty2", map.empty()));
	map.insert(pair("size", map.size()));

	return (0);
}

#endif

