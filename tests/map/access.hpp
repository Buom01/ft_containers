/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/11/18 14:53:12 by badam            ###   ########.fr       */
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


	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));
	map.insert(pair("e", 4));

	it = map.begin();

	if (map.find("a")->first != "a" || map.find("a")->second != 0)
		return (1);
	if (map.find("e")->first != "e" || map.find("e")->second != 4)
		return (2);

	return (0);
}

template <class container, class pair>
int	map_access_4(container &map)
{
	map.insert(pair("d", 3));
	map.insert(pair("a", 0));
	map.insert(pair("c", 2));
	map.insert(pair("e", 4));
	map.insert(pair("b", 1));

	if (map.at("a") != map["a"] || map["a"] != 0)
		return (1);
	if (map.at("b") != map["b"] || map["b"] != 1)
		return (2);
	if (map.at("c") != map["c"] || map["c"] != 2)
		return (3);
	if (map.at("d") != map["d"] || map["d"] != 3)
		return (4);
	if (map.at("e") != map["e"] || map["e"] != 4)
		return (5);

	return (0);
}

#endif

