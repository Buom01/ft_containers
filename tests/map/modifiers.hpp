/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/01 00:35:32 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_MODIFIERS_HPP
# define TESTS_MAP_MODIFIERS_HPP

# include <sstream>

template <class container, class pair>
int	map_tricky_insert_1(container &map)
{
	map.insert(pair("c", 0));
	map.insert(pair("b", 1));
	map.insert(pair("a", 2));

	return (0);
}

template <class container, class pair>
int	map_tricky_insert_2(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	return (0);
}

template <class container, class pair>
int	map_tricky_insert_3(container &map)
{
	map.insert(pair("f", 0));
	map.insert(pair("e", 0));
	map.insert(pair("d", 0));
	map.insert(pair("c", 0));
	map.insert(pair("b", 1));
	map.insert(pair("a", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("m", 2));
	map.insert(pair("l", 2));

	return (0);
}

template <class container, class pair>
int	map_tricky_insert_4(container &map)
{
	map.insert(pair("r", 2));
	map.insert(pair("f", 2));
	map.insert(pair("o", 2));
	map.insert(pair("d", 0));
	map.insert(pair("x", 2));
	map.insert(pair("s", 2));
	map.insert(pair("w", 2));
	map.insert(pair("u", 2));
	map.insert(pair("i", 2));
	map.insert(pair("e", 1));
	map.insert(pair("t", 2));
	map.insert(pair("n", 2));
	map.insert(pair("j", 2));
	map.insert(pair("z", 2));
	map.insert(pair("k", 2));
	map.insert(pair("b", 0));
	map.insert(pair("l", 2));
	map.insert(pair("h", 2));
	map.insert(pair("c", 0));
	map.insert(pair("y", 2));
	map.insert(pair("m", 2));
	map.insert(pair("a", 0));
	map.insert(pair("q", 2));
	map.insert(pair("p", 2));
	map.insert(pair("v", 2));
	map.insert(pair("g", 2));

	return (0);
}

template <class container, class pair>
int	map_tricky_insert_5(container &map)
{
	map.insert(pair("b", 0));
	map.insert(pair("q", 2));
	map.insert(pair("m", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("s", 2));
	map.insert(pair("l", 2));
	map.insert(pair("n", 2));
	map.insert(pair("r", 2));
	map.insert(pair("c", 0));
	map.insert(pair("t", 2));
	map.insert(pair("g", 2));
	map.insert(pair("u", 2));
	map.insert(pair("z", 2));
	map.insert(pair("e", 1));
	map.insert(pair("d", 0));
	map.insert(pair("w", 2));
	map.insert(pair("v", 2));
	map.insert(pair("a", 0));
	map.insert(pair("f", 2));
	map.insert(pair("i", 2));
	map.insert(pair("y", 2));
	map.insert(pair("h", 2));
	map.insert(pair("x", 2));

	return (0);
}

template <class container, class pair>
int	map_tricky_insert_6(container &map)
{
	map.insert(pair("h", 2));
	map.insert(pair("p", 2));
	map.insert(pair("v", 2));
	map.insert(pair("c", 0));
	map.insert(pair("s", 2));
	map.insert(pair("m", 2));
	map.insert(pair("f", 2));
	map.insert(pair("z", 2));
	map.insert(pair("o", 2));
	map.insert(pair("g", 2));
	map.insert(pair("n", 2));
	map.insert(pair("w", 2));
	map.insert(pair("i", 2));
	map.insert(pair("r", 2));
	map.insert(pair("y", 2));
	map.insert(pair("t", 2));
	map.insert(pair("b", 0));
	map.insert(pair("k", 2));
	map.insert(pair("d", 0));
	map.insert(pair("x", 2));
	map.insert(pair("l", 2));
	map.insert(pair("j", 2));
	map.insert(pair("q", 2));
	map.insert(pair("e", 1));
	map.insert(pair("u", 2));
	map.insert(pair("a", 0));

	return (0);
}

template <class container, class pair>
int	map_epic_insert_1(container &map)
{
	int	i	= 0;
	std::stringstream	key;

	while (i < 100)
	{
		key << i;
		map.insert(pair(key.str(), i));
		key.str(std::string());
		++i;
	}

	return (0);
}

template <class container, class pair>
int	map_clear(container &map)
{
	map.clear();

	if (map.size() != 0 || !map.empty())
		return (1);

	map.insert(pair("h", 2));
	map.insert(pair("p", 2));


	if (map.size() != 2 || map.empty())
		return (2);

	map.clear();

	if (map.size() != 0 || !map.empty())
		return (3);

	map.insert(pair("v", 2));
	map.insert(pair("v", 2));

	if (map.size() != 1 || map.empty())
		return (4);

	map.clear();
	map.clear();

	if (map.size() != 0 || !map.empty())
		return (5);
	
	return (0);
}

template <class container, class pair>
int	map_swap(container &map)
{
	container						map2;
	container						map3;
	typename container::iterator	first;
	typename container::iterator	second;
	typename container::iterator	third;

	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));

	map2.insert(pair("e", 4));
	map2.insert(pair("f", 5));
	map2.insert(pair("g", 6));

	map3.insert(pair("h", 7));
	map3.insert(pair("i", 8));
	map3.insert(pair("j", 9));

	first = map3.begin();
	second = first;
	++second;
	third = second;
	++third;

	map3.swap(map2);
	map.swap(map2);

	if (map.size() != 3 || map.empty())
		return (1);
	if (first->first == "e")
		return (2);
	if (second->first == "f")
		return (3);
	if (third->first == "g")
		return (4);
	
	return (0);
}

template <class container, class pair>
int	map_erase_1(container &map)
{
	typename container::iterator	pos;

	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));
	map.insert(pair("e", 4));

	map.erase(map.begin(), map.end());
	if (map.size() != 0 || !map.empty() || map.begin() != map.end())
		return (2);

	map.insert(pair("f", 5));
	map.insert(pair("g", 6));

	map.erase(map.begin());
	if (map.size() != 1 || map.empty())
		return (3);
	map.erase(map.begin());
	if (map.size() != 0 || !map.empty() || map.begin() != map.end())
		return (4);

	map.insert(pair("h", 7));
	map.insert(pair("i", 8));

	pos = map.end();
	--pos;

	map.erase(pos);
	if (map.size() != 1 || map.empty())
		return (5);
	map.erase(map.begin());
	if (!map.empty()|| map.begin() != map.end())
		return (6);

	map.insert(pair("j", 7));
	map.insert(pair("k", 8));
	map.insert(pair("l", 9));
	map.insert(pair("m", 10));

	pos = map.end();
	--pos;

	map.erase(pos);
	if (map.size() != 3 || map.empty())
		return (7);
	map.erase(map.begin());
	if (map.size() != 2 || map.empty())
		return (8);

	return (0);
}

template <class container, class pair>
int	map_erase_2(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("a"));
	map.erase(map.find("b"));
	map.erase(map.find("c"));
	map.erase(map.find("d"));
	map.erase(map.find("e"));
	map.erase(map.find("f"));
	map.erase(map.find("g"));
	map.erase(map.find("h"));
	map.erase(map.find("i"));
	map.erase(map.find("j"));
	map.erase(map.find("k"));
	map.erase(map.find("l"));
	map.erase(map.find("m"));
	map.erase(map.find("n"));
	map.erase(map.find("o"));
	map.erase(map.find("p"));
	map.erase(map.find("q"));
	map.erase(map.find("r"));
	map.erase(map.find("s"));
	map.erase(map.find("t"));
	map.erase(map.find("u"));
	map.erase(map.find("v"));
	map.erase(map.find("w"));
	map.erase(map.find("x"));
	map.erase(map.find("y"));
	map.erase(map.find("z"));

	return (0);
}

template <class container, class pair>
int	map_erase_3(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("z"));
	map.erase(map.find("y"));
	map.erase(map.find("x"));
	map.erase(map.find("w"));
	map.erase(map.find("v"));
	map.erase(map.find("u"));
	map.erase(map.find("t"));
	map.erase(map.find("s"));
	map.erase(map.find("r"));
	map.erase(map.find("q"));
	map.erase(map.find("p"));
	map.erase(map.find("o"));
	map.erase(map.find("n"));
	map.erase(map.find("m"));
	map.erase(map.find("l"));
	map.erase(map.find("k"));
	map.erase(map.find("j"));
	map.erase(map.find("i"));
	map.erase(map.find("h"));
	map.erase(map.find("g"));
	map.erase(map.find("f"));
	map.erase(map.find("e"));
	map.erase(map.find("d"));
	map.erase(map.find("c"));
	map.erase(map.find("b"));
	map.erase(map.find("a"));

	return (0);
}

template <class container, class pair>
int	map_erase_4(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("n"));
	map.erase(map.find("x"));
	map.erase(map.find("u"));
	map.erase(map.find("s"));
	map.erase(map.find("l"));
	map.erase(map.find("o"));
	map.erase(map.find("m"));
	map.erase(map.find("d"));
	map.erase(map.find("b"));
	map.erase(map.find("v"));
	map.erase(map.find("c"));
	map.erase(map.find("g"));
	map.erase(map.find("h"));
	map.erase(map.find("j"));
	map.erase(map.find("r"));
	map.erase(map.find("z"));
	map.erase(map.find("t"));
	map.erase(map.find("f"));
	map.erase(map.find("p"));
	map.erase(map.find("k"));
	map.erase(map.find("q"));

	return (0);
}

template <class container, class pair>
int	map_erase_5(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("r"));
	map.erase(map.find("l"));
	map.erase(map.find("m"));
	map.erase(map.find("a"));
	map.erase(map.find("h"));
	map.erase(map.find("q"));
	map.erase(map.find("b"));
	map.erase(map.find("o"));
	map.erase(map.find("k"));
	map.erase(map.find("y"));
	map.erase(map.find("w"));
	map.erase(map.find("c"));
	map.erase(map.find("u"));
	map.erase(map.find("x"));
	map.erase(map.find("n"));
	map.erase(map.find("v"));
	map.erase(map.find("p"));
	map.erase(map.find("j"));
	map.erase(map.find("f"));
	map.erase(map.find("g"));
	map.erase(map.find("e"));

	return (0);
}

template <class container, class pair>
int	map_erase_6(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("p"));
	map.erase(map.find("l"));
	map.erase(map.find("e"));
	map.erase(map.find("d"));
	map.erase(map.find("k"));
	map.erase(map.find("a"));
	map.erase(map.find("w"));
	map.erase(map.find("v"));
	map.erase(map.find("t"));
	map.erase(map.find("g"));
	map.erase(map.find("i"));
	map.erase(map.find("m"));
	map.erase(map.find("c"));
	map.erase(map.find("z"));
	map.erase(map.find("s"));
	map.erase(map.find("o"));
	map.erase(map.find("u"));
	map.erase(map.find("r"));
	map.erase(map.find("y"));
	map.erase(map.find("f"));
	map.erase(map.find("n"));

	return (0);
}

template <class container, class pair>
int	map_erase_7(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("m"));
	map.erase(map.find("n"));
	map.erase(map.find("v"));
	map.erase(map.find("l"));
	map.erase(map.find("u"));
	map.erase(map.find("i"));
	map.erase(map.find("q"));
	map.erase(map.find("r"));
	map.erase(map.find("o"));
	map.erase(map.find("z"));
	map.erase(map.find("f"));

	return (0);
}

template <class container, class pair>
int	map_erase_8(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("m"));
	map.erase(map.find("n"));
	map.erase(map.find("v"));
	map.erase(map.find("l"));
	map.erase(map.find("u"));
	map.erase(map.find("i"));
	map.erase(map.find("q"));
	map.erase(map.find("r"));

	return (0);
}

template <class container, class pair>
int	map_erase_9(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));
	map.insert(pair("d", 0));
	map.insert(pair("e", 1));
	map.insert(pair("f", 2));
	map.insert(pair("g", 2));
	map.insert(pair("h", 2));
	map.insert(pair("i", 2));
	map.insert(pair("j", 2));
	map.insert(pair("k", 2));
	map.insert(pair("l", 2));
	map.insert(pair("m", 2));
	map.insert(pair("n", 2));
	map.insert(pair("o", 2));
	map.insert(pair("p", 2));
	map.insert(pair("q", 2));
	map.insert(pair("r", 2));
	map.insert(pair("s", 2));
	map.insert(pair("t", 2));
	map.insert(pair("u", 2));
	map.insert(pair("v", 2));
	map.insert(pair("w", 2));
	map.insert(pair("x", 2));
	map.insert(pair("y", 2));
	map.insert(pair("z", 2));

	map.erase(map.find("y"));
	map.erase(map.find("x"));
	map.erase(map.find("w"));
	map.erase(map.find("v"));
	map.erase(map.find("u"));
	map.erase(map.find("t"));
	map.erase(map.find("s"));
	map.erase(map.find("r"));
	map.erase(map.find("q"));
	map.erase(map.find("p"));
	map.erase(map.find("o"));
	map.erase(map.find("n"));
	map.erase(map.find("m"));
	map.erase(map.find("l"));
	map.erase(map.find("k"));
	map.erase(map.find("j"));
	map.erase(map.find("i"));
	map.erase(map.find("h"));
	map.erase(map.find("g"));
	map.erase(map.find("f"));
	map.erase(map.find("e"));
	map.erase(map.find("d"));
	map.erase(map.find("c"));
	map.erase(map.find("b"));

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

