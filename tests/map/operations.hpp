/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:26:33 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 16:15:06 by badam            ###   ########.fr       */
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
    insert_lowerbound<container, pair>("z", map, map2);

	return (0);
}

#endif