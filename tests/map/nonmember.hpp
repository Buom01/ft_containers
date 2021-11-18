/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonmember.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/28 23:49:03 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_NONMEMBER_HPP
# define TESTS_MAP_NONMEMBER_HPP

template <class container>
int	_map_nm_swap(container &map, void (*swap)(container &lhs, container &rhs))
{
	container						map2;
	container						map3;
	typename container::iterator	first;
	typename container::iterator	second;
	typename container::iterator	third;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);

	map2.push_back(4);
	map2.push_back(5);
	map2.push_back(6);

	map3.push_back(7);
	map3.push_back(8);
	map3.push_back(9);

	first = map3.begin();
	second = first;
	++second;
	third = second;
	++third;

	swap(map3, map2);
	swap(map, map2);

	if (map.size() != 3 || map.empty())
		return (1);
	if (*first == 4)
		return (2);
	if (*second == 5)
		return (3);
	if (*third == 6)
		return (4);
	
	return (0);
}

template <class container>
int	map_nm_std_swap(container &map)
{
	return (_map_nm_swap(map, std::swap));
}

template <class container>
int	map_nm_ft_swap(container &map)
{
	return (_map_nm_swap(map, ft::swap));
}


template <class container>
int	map_nm_equal_not_equal(container &map)
{
	container	map1;

	if (!(map == map1))
		return (1);
	if (map != map1)
		return (2);

	map.push_back(1);

	if (map == map1)
		return (3);
	if (!(map != map1))
		return (4);

	map1.push_back(1);

	if (!(map == map1))
		return (5);
	if (map != map1)
		return (6);

	map1.push_back(2);

	if (map == map1)
		return (7);
	if (!(map != map1))
		return (8);

	map.push_back(2);

	if (!(map == map1))
		return (9);
	if (map != map1)
		return (10);



	map1.push_back(3);

	if (map == map1)
		return (11);
	if (!(map != map1))
		return (12);

	map.push_back(3);

	if (!(map == map1))
		return (13);
	if (map != map1)
		return (14);

	map.push_back(4);

	if (map == map1)
		return (15);
	if (!(map != map1))
		return (16);

	map1.push_back(4);

	if (!(map == map1))
		return (17);
	if (map != map1)
		return (18);

	
	map.clear();
	map1.clear();

	if (!(map == map1))
		return (19);
	if (map != map1)
		return (20);

	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map1.push_back(0);
	map1.push_back(2);
	map1.push_back(3);

	if (map == map1)
		return (21);
	if (!(map != map1))
		return (22);

	map.clear();
	map1.clear();

	if (!(map == map1))
		return (23);
	if (map != map1)
		return (24);

	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map1.push_back(1);
	map1.push_back(2);
	map1.push_back(4);

	if (map == map1)
		return (25);
	if (!(map != map1))
		return (26);

	map.clear();
	map1.clear();

	if (!(map == map1))
		return (27);
	if (map != map1)
		return (28);


	return (0);
}

template <class container>
void	_map_nm_dump_compare(container &out, container first, container second)
{
	out.push_back(first == second);
	out.push_back(first >= second);
	out.push_back(first <= second);
	out.push_back(first != second);
	out.push_back(first > second);
	out.push_back(first < second);
	out.push_back(2);
}

template <class container>
int	map_nm_compare(container &map)
{
	{
		container first;
		container second;
		
		_map_nm_dump_compare(map, first, second);

		first.push_back(1);
		_map_nm_dump_compare(map, first, second);
		
		second.push_back(2);
		_map_nm_dump_compare(map, first, second);
		
		first.push_back(3);
		_map_nm_dump_compare(map, first, second);
		
		second.push_back(4);
		_map_nm_dump_compare(map, first, second);
		
		second.push_back(5);
		_map_nm_dump_compare(map, first, second);
	}

	{
		container first;
		container second;
		
		_map_nm_dump_compare(map, second, first);

		first.push_back(1);
		_map_nm_dump_compare(map, second, first);
		
		second.push_back(2);
		_map_nm_dump_compare(map, second, first);
		
		first.push_back(3);
		_map_nm_dump_compare(map, second, first);
		
		second.push_back(4);
		_map_nm_dump_compare(map, second, first);
		
		second.push_back(5);
		_map_nm_dump_compare(map, second, first);
	}

	return (0);
}

#endif