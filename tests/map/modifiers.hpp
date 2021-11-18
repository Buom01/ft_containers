/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/28 23:49:03 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_MODIFIERS_HPP
# define TESTS_MAP_MODIFIERS_HPP

template <class container>
int	map_push_back(container &map)
{
	map.push_back(1);
	map.push_back(2);

	if (map.size() != 2 || map.empty())
		return (1);
	
	return (0);
}

template <class container>
int	map_pop_back(container &map)
{
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);

	map.pop_back();
	map.pop_back();
	map.pop_back();

	map.push_back(7);
	map.push_back(8);
	map.push_back(9);

	map.pop_back();

	if (map.size() != 2 || map.empty())
		return (1);
	
	return (0);
}

template <class container>
int	map_clear(container &map)
{
	map.clear();

	if (map.size() != 0 || !map.empty())
		return (1);

	map.push_back(3);
	map.push_back(4);


	if (map.size() != 2 || map.empty())
		return (2);

	map.clear();

	if (map.size() != 0 || !map.empty())
		return (3);

	map.push_back(1);

	if (map.size() != 1 || map.empty())
		return (4);

	map.clear();
	map.clear();

	if (map.size() != 0 || !map.empty())
		return (5);
	
	return (0);
}

template <class container>
int	map_swap(container &map)
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

	map3.swap(map2);
	map.swap(map2);

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
int	map_erase(container &map)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	ret = map.erase(map.begin(), map.end());
	if (ret != map.end())
		return (1);
	if (map.size() != 0 || !map.empty())
		return (2);

	map.push_back(5);
	map.push_back(6);

	ret = map.erase(map.begin());
	if (ret != map.begin() || map.size() != 1 || map.empty())
		return (3);
	ret = map.erase(map.begin());
	if (ret != map.begin() || map.size() != 0 || !map.empty())
		return (4);

	map.push_back(7);
	map.push_back(8);

	pos = map.end();
	--pos;

	ret = map.erase(pos);
	if (ret != map.end() || map.size() != 1 || map.empty())
		return (5);
	ret = map.erase(map.begin());
	if (ret != map.begin() || !map.empty())
		return (6);

	map.push_back(9);
	map.push_back(10);
	map.push_back(11);
	map.push_back(12);

	pos = map.end();
	--pos;

	ret = map.erase(pos);
	if (ret != map.end() || map.size() != 3 || map.empty())
		return (7);
	ret = map.erase(map.begin());
	if (ret != map.begin() || map.size() != 2 || map.empty())
		return (8);

	return (0);
}

template <class container>
int	map_insert_1(container &map)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	ret = map.insert(map.begin(), 2);
	if (ret != map.begin() || map.size() != 1 || map.empty())
		return (1);

	ret = map.insert(map.end(), 4);
	std::advance(pos = map.end(), -1);
	if (ret != pos || map.size() != 2 || map.empty())
		return (2);
		
	ret = map.insert(pos, 3);
	std::advance(pos = map.begin(), 1);
	if (ret != pos || map.size() != 3 || map.empty())
		return (3);


	ret = map.insert(map.end(), 7);
	std::advance(pos = map.end(), -1);
	if (ret != pos || map.size() != 4 || map.empty())
		return (4);

	ret = map.insert(pos, 6);
	std::advance(pos = map.end(), -2);
	if (ret != pos || map.size() != 5 || map.empty())
		return (5);

	ret = map.insert(pos, 5);
	std::advance(pos = map.end(), -3);
	if (ret != pos || map.size() != 6 || map.empty())
		return (6);


	ret = map.insert(map.begin(), 0);
	if (ret != map.begin() || map.size() != 7 || map.empty())
		return (7);

	std::advance(pos = map.begin(), 1);
	ret = map.insert(pos, 1);
	std::advance(pos = map.begin(), 1);
	if (ret != pos || map.size() != 8 || map.empty())
		return (8);
		
	ret = map.insert(map.end(), 8);
	std::advance(pos = map.end(), -1);
	if (ret != pos || map.size() != 9 || map.empty())
		return (9);

	return (0);
}

template <class container>
int		map_insert_2(container &map)
{
	typename container::iterator	pos;

	map.insert(map.end(), 0, 0);
	if (map.size() != 0 || !map.empty())
		return (1);

	map.insert(map.begin(), 0, 0);
	if (map.size() != 0 || !map.empty())
		return (2);

	map.insert(map.end(), 1, 1);
	if (map.size() != 1 || map.empty())
		return (3);

	map.insert(map.end(), 2, 3);
	if (map.size() != 3 || map.empty())
		return (4);

	map.insert(map.begin(), 3, 0);
	if (map.size() != 6 || map.empty())
		return (5);

	std::advance(pos = map.end(), -2);
	map.insert(pos, 4, 2);
	if (map.size() != 10 || map.empty())
		return (6);

	return (0);
}

template <class container>
int		map_insert_3(container &map)
{
	typename container::iterator	pos;
	container						map1;
	container						map2;
	container						map3;

	map1.push_back(1);
	map1.push_back(2);
	map1.push_back(3);
	map2.push_back(4);
	map2.push_back(5);
	map2.push_back(6);
	map3.push_back(7);
	map3.push_back(8);
	map3.push_back(9);

	map.insert(map.end(), map3.begin(), map3.end());
	if (map.size() != 3 || map.empty())
		return (1);

	map.insert(map.begin(), map1.begin(), map1.end());
	if (map.size() != 6 || map.empty())
		return (2);

	std::advance(pos = map.begin(), 3);
	map.insert(pos, map2.begin(), map2.end());
	if (map.size() != 9 || map.empty())
		return (3);

	return (0);
}

template <class container>
int		map_resize_1(container &map)
{
	map.resize(0);
	if (map.size() != 0 || !map.empty())
		return (1);
	
	return (0);
}

template <class container>
int		map_resize_2(container &map)
{
	map.push_back(1);
	map.resize(7);
	map.push_back(2);

	if (map.size() != 8 || map.empty())
		return (1);
	
	return (0);
}

template <class container>
int		map_resize_3(container &map)
{
	map.resize(1);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);

	map.resize(10, 4);
	map.resize(5);
	map.resize(7, 5);
	map.resize(6);
	map.resize(7, 6);
	map.resize(7, 10);

	map.push_back(7);

	if (map.size() != 8 || map.empty())
		return (1);
	
	return (0);
}

template <class container>
int		map_resize_4(container &map)
{
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);

	map.resize(0);

	if (map.size() != 0 || !map.empty())
		return (1);
	
	return (0);
}

template <class container>
int		map_resize_5(container &map)
{
	map.resize(0);
	map.resize(1);
	map.resize(100);
	map.resize(1000);
	map.resize(0);

	if (map.size() != 0 || !map.empty())
		return (1);
	
	return (0);
}

#endif

