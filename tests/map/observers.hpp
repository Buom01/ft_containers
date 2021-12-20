/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:34:18 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 14:25:18 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_OBSERVERS_HPP
# define TESTS_MAP_OBSERVERS_HPP

template <class container, class pair>
int	map_keycomp_a(container &map)
{
	map.insert(pair("a", map.key_comp()("ac", "ab")));
	map.insert(pair("b-", map.key_comp()("ab", "ab")));
	map.insert(pair("c--", map.key_comp()("aa", "ab")));
	map.insert(pair("d---", map.key_comp()("ab", "ac")));
	map.insert(pair("e----", map.key_comp()("ab", "ab")));
	map.insert(pair("f-----", map.key_comp()("ab", "aa")));

	return (0);
}

template <class container, class pair>
int	map_keycomp_b(container &map)
{
	map.insert(pair("e", map.key_comp()("aaaaa", "e")));
	map.insert(pair("dd", map.key_comp()("bbbb", "dd")));
	map.insert(pair("ccc", map.key_comp()("ccc", "ccc")));
	map.insert(pair("bbbb", map.key_comp()("dd", "bbbb")));
	map.insert(pair("aaaaa", map.key_comp()("e", "aaaaa")));

	return (0);
}

template <class container, class pair>
int	map_valuecomp_a(container &map)
{
	map.insert(pair("a", map.value_comp()(pair("ac", "ab"), pair("ac", "ab")) ? "1" : "0" ));


	map.insert(pair("b-", map.value_comp()(pair("ab", "ab"), pair("ab", "ab")) ? "1" : "0" ));
	map.insert(pair("c--", map.value_comp()(pair("aa", "ab"), pair("aa", "ab")) ? "1" : "0" ));
	map.insert(pair("d---", map.value_comp()(pair("aa", "aa"), pair("aa", "aa")) ? "1" : "0" ));
	map.insert(pair("e----", map.value_comp()(pair("ab", "ac"), pair("ab", "ac")) ? "1" : "0" ));
	map.insert(pair("f-----", map.value_comp()(pair("ab", "ab"), pair("ab", "ab")) ? "1" : "0" ));
	map.insert(pair("g------", map.value_comp()(pair("ab", "aa"), pair("ab", "aa")) ? "1" : "0" ));

	return (0);
}

template <class container, class pair>
int	map_valuecomp_b(container &map)
{
	map.insert(pair("e", map.value_comp()(pair("aaaaa", "e"), pair("aaaaa", "e")) ? "1" : "0" ));
	map.insert(pair("dd", map.value_comp()(pair("bbbb", "dd"), pair("bbbb", "dd")) ? "1" : "0" ));
	map.insert(pair("ccc", map.value_comp()(pair("ccc", "ccc"), pair("ccc", "ccc")) ? "1" : "0" ));
	map.insert(pair("bbbb", map.value_comp()(pair("dd", "bbbb"), pair("dd", "bbbb")) ? "1" : "0" ));
	map.insert(pair("aaaaa", map.value_comp()(pair("e", "aaaaa"), pair("e", "aaaaa")) ? "1" : "0" ));

	return (0);
}

#endif