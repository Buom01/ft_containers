/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/11/23 20:21:05 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_CAPACITY_HPP
# define TESTS_MAP_CAPACITY_HPP

# include <sstream>

template <class container, class pair>
int	map_capacity_maxsize(container &map)
{
	typename container::size_type	maxsize1	= map.max_size();
	int								i			= 0;
	std::stringstream				key;


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
	
	return (0);
}

#endif

