/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:26:33 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 16:38:55 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_OPERATIONS_HPP
# define TESTS_MAP_OPERATIONS_HPP


template <class container, class pair>
int	map_find(container &map)
{
    container   map2;
    
    map2.insert(pair("p", 5));
	map2.insert(pair("s", 9));
	map2.insert(pair("x", 21));
	map2.insert(pair("o", 24));
	map2.insert(pair("u", 8));
	map2.insert(pair("b", 6));
	map2.insert(pair("w", 3));
	map2.insert(pair("e", 15));
	map2.insert(pair("q", 10));
	map2.insert(pair("r", 17));
	map2.insert(pair("y", 23));
	map2.insert(pair("i", 12));
	map2.insert(pair("z", 20));
	map2.insert(pair("n", 14));
	map2.insert(pair("m", 26));
	map2.insert(pair("t", 11));
	map2.insert(pair("d", 22));
	map2.insert(pair("k", 16));
	map2.insert(pair("a", 19));
	map2.insert(pair("h", 2));
	map2.insert(pair("l", 13));
	map2.insert(pair("v", 7));
	map2.insert(pair("g", 1));
	map2.insert(pair("f", 18));
	map2.insert(pair("j", 25));
	map2.insert(pair("c", 4));


    map.insert(*map2.find("a"));
    map.insert(*map2.find("b"));
    map.insert(*map2.find("c"));
    map.insert(*map2.find("d"));
    map.insert(*map2.find("e"));
    map.insert(*map2.find("f"));
    map.insert(*map2.find("g"));
    map.insert(*map2.find("h"));
    map.insert(*map2.find("i"));
    map.insert(*map2.find("j"));
    map.insert(*map2.find("k"));
    map.insert(*map2.find("l"));
    map.insert(*map2.find("m"));
    map.insert(*map2.find("n"));
    map.insert(*map2.find("o"));
    map.insert(*map2.find("p"));
    map.insert(*map2.find("q"));
    map.insert(*map2.find("r"));

    map.insert(*map2.find("z"));
    map.insert(*map2.find("y"));
    map.insert(*map2.find("x"));

	return (0);
}

template <class container, class pair>
int	map_count(container &map)
{
    container   map2;
    
    map2.insert(pair("b", 0));
    map2.insert(pair("b", 1));
    map2.insert(pair("b", 2));
    map2.insert(pair("b", 3));
    map2.insert(pair("c", 3));
    map2.insert(pair("d", 3));
    map2.insert(pair("e", 3));
    map2.insert(pair("e", 3));


    map.insert(pair("a", map2.count("a")));
    map.insert(pair("b", map2.count("b")));
    map.insert(pair("c", map2.count("c")));
    map.insert(pair("d", map2.count("d")));
    map.insert(pair("e", map2.count("e")));
    map.insert(pair("f", map2.count("f")));

	return (0);
}


template <class container, class pair>
static void    insert_lowerbound(std::string key, container &map, container &map2)
{
    typename container::iterator  it  = map2.lower_bound(key);
    
    if (it != map2.end())
        map.insert(pair(key, it->second));
    else
        map.insert(pair(key, 0));
}

template <class container, class pair>
int	map_lowerbound(container &map)
{
    container   map2;
    
    map2.insert(pair("p", 5));
	map2.insert(pair("s", 9));
	map2.insert(pair("x", 21));
	map2.insert(pair("o", 24));
	map2.insert(pair("u", 8));
	map2.insert(pair("b", 6));
	map2.insert(pair("w", 3));
	map2.insert(pair("e", 15));
	map2.insert(pair("q", 10));


    insert_lowerbound<container, pair>("a", map, map2);
    insert_lowerbound<container, pair>("b", map, map2);
    insert_lowerbound<container, pair>("c", map, map2);
    insert_lowerbound<container, pair>("d", map, map2);
    insert_lowerbound<container, pair>("e", map, map2);
    insert_lowerbound<container, pair>("f", map, map2);
    insert_lowerbound<container, pair>("g", map, map2);
    insert_lowerbound<container, pair>("h", map, map2);
    insert_lowerbound<container, pair>("i", map, map2);
    insert_lowerbound<container, pair>("j", map, map2);
    insert_lowerbound<container, pair>("k", map, map2);
    insert_lowerbound<container, pair>("l", map, map2);
    insert_lowerbound<container, pair>("m", map, map2);
    insert_lowerbound<container, pair>("n", map, map2);
    insert_lowerbound<container, pair>("o", map, map2);
    insert_lowerbound<container, pair>("p", map, map2);
    insert_lowerbound<container, pair>("q", map, map2);
    insert_lowerbound<container, pair>("r", map, map2);
    insert_lowerbound<container, pair>("s", map, map2);
    insert_lowerbound<container, pair>("t", map, map2);
    insert_lowerbound<container, pair>("u", map, map2);
    insert_lowerbound<container, pair>("v", map, map2);
    insert_lowerbound<container, pair>("w", map, map2);
    insert_lowerbound<container, pair>("x", map, map2);
    insert_lowerbound<container, pair>("y", map, map2);
    insert_lowerbound<container, pair>("z", map, map2);

	return (0);
}


template <class container, class pair>
static void    insert_upperbound(std::string key, container &map, container &map2)
{
    typename container::iterator  it  = map2.upper_bound(key);
    
    if (it != map2.end())
        map.insert(pair(key, it->second));
    else
        map.insert(pair(key, 0));
}

template <class container, class pair>
int	map_upperbound(container &map)
{
    container   map2;
    
    map2.insert(pair("p", 5));
	map2.insert(pair("s", 9));
	map2.insert(pair("x", 21));
	map2.insert(pair("o", 24));
	map2.insert(pair("u", 8));
	map2.insert(pair("b", 6));
	map2.insert(pair("w", 3));
	map2.insert(pair("e", 15));
	map2.insert(pair("q", 10));


    insert_upperbound<container, pair>("a", map, map2);
    insert_upperbound<container, pair>("b", map, map2);
    insert_upperbound<container, pair>("c", map, map2);
    insert_upperbound<container, pair>("d", map, map2);
    insert_upperbound<container, pair>("e", map, map2);
    insert_upperbound<container, pair>("f", map, map2);
    insert_upperbound<container, pair>("g", map, map2);
    insert_upperbound<container, pair>("h", map, map2);
    insert_upperbound<container, pair>("i", map, map2);
    insert_upperbound<container, pair>("j", map, map2);
    insert_upperbound<container, pair>("k", map, map2);
    insert_upperbound<container, pair>("l", map, map2);
    insert_upperbound<container, pair>("m", map, map2);
    insert_upperbound<container, pair>("n", map, map2);
    insert_upperbound<container, pair>("o", map, map2);
    insert_upperbound<container, pair>("p", map, map2);
    insert_upperbound<container, pair>("q", map, map2);
    insert_upperbound<container, pair>("r", map, map2);
    insert_upperbound<container, pair>("s", map, map2);
    insert_upperbound<container, pair>("t", map, map2);
    insert_upperbound<container, pair>("u", map, map2);
    insert_upperbound<container, pair>("v", map, map2);
    insert_upperbound<container, pair>("w", map, map2);
    insert_upperbound<container, pair>("x", map, map2);
    insert_upperbound<container, pair>("y", map, map2);
    insert_upperbound<container, pair>("z", map, map2);

	return (0);
}


template <class container, class pair>
static void    insert_equalrange(std::string key, container &map, container &map2)
{
    if (map2.equal_range(key).first != map2.end())
        map.insert(pair(key + "_low", map2.equal_range(key).first->second));
    else
        map.insert(pair(key + "_low", 0));

    if (map2.equal_range(key).second != map2.end())
        map.insert(pair(key + "_upp", map2.equal_range(key).second->second));
    else
        map.insert(pair(key + "_upp", 0));
}

template <class container, class pair>
int	map_equalrange(container &map)
{
    container   map2;
    
    map2.insert(pair("p", 5));
	map2.insert(pair("s", 9));
	map2.insert(pair("x", 21));
	map2.insert(pair("o", 24));
	map2.insert(pair("u", 8));
	map2.insert(pair("b", 6));
	map2.insert(pair("w", 3));
	map2.insert(pair("e", 15));
	map2.insert(pair("q", 10));


    insert_equalrange<container, pair>("a", map, map2);
    insert_equalrange<container, pair>("b", map, map2);
    insert_equalrange<container, pair>("c", map, map2);
    insert_equalrange<container, pair>("d", map, map2);
    insert_equalrange<container, pair>("e", map, map2);
    insert_equalrange<container, pair>("f", map, map2);
    insert_equalrange<container, pair>("g", map, map2);
    insert_equalrange<container, pair>("h", map, map2);
    insert_equalrange<container, pair>("i", map, map2);
    insert_equalrange<container, pair>("j", map, map2);
    insert_equalrange<container, pair>("k", map, map2);
    insert_equalrange<container, pair>("l", map, map2);
    insert_equalrange<container, pair>("m", map, map2);
    insert_equalrange<container, pair>("n", map, map2);
    insert_equalrange<container, pair>("o", map, map2);
    insert_equalrange<container, pair>("p", map, map2);
    insert_equalrange<container, pair>("q", map, map2);
    insert_equalrange<container, pair>("r", map, map2);
    insert_equalrange<container, pair>("s", map, map2);
    insert_equalrange<container, pair>("t", map, map2);
    insert_equalrange<container, pair>("u", map, map2);
    insert_equalrange<container, pair>("v", map, map2);
    insert_equalrange<container, pair>("w", map, map2);
    insert_equalrange<container, pair>("x", map, map2);
    insert_equalrange<container, pair>("y", map, map2);
    insert_equalrange<container, pair>("z", map, map2);

	return (0);
}

#endif