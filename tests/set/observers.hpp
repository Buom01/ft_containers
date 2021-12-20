/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:34:18 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 18:15:43 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_OBSERVERS_HPP
# define TESTS_SET_OBSERVERS_HPP

template <class container>
int	set_keycomp_a(container &set)
{
	set.insert(set_concat_pair("a", set.key_comp()("ac", "ab")));
	set.insert(set_concat_pair("b-", set.key_comp()("ab", "ab")));
	set.insert(set_concat_pair("c--", set.key_comp()("aa", "ab")));
	set.insert(set_concat_pair("d---", set.key_comp()("ab", "ac")));
	set.insert(set_concat_pair("e----", set.key_comp()("ab", "ab")));
	set.insert(set_concat_pair("f-----", set.key_comp()("ab", "aa")));

	return (0);
}

template <class container>
int	set_keycomp_b(container &set)
{
	set.insert(set_concat_pair("e", set.key_comp()("aaaaa", "e")));
	set.insert(set_concat_pair("dd", set.key_comp()("bbbb", "dd")));
	set.insert(set_concat_pair("ccc", set.key_comp()("ccc", "ccc")));
	set.insert(set_concat_pair("bbbb", set.key_comp()("dd", "bbbb")));
	set.insert(set_concat_pair("aaaaa", set.key_comp()("e", "aaaaa")));

	return (0);
}

template <class container>
int	set_valuecomp_a(container &set)
{
	set.insert(set_concat_pair("a", set.value_comp()(set_concat_pair("ac", "ab"), set_concat_pair("ac", "ab")) ? "1" : "0" ));


	set.insert(set_concat_pair("b-", set.value_comp()(set_concat_pair("ab", "ab"), set_concat_pair("ab", "ab")) ? "1" : "0" ));
	set.insert(set_concat_pair("c--", set.value_comp()(set_concat_pair("aa", "ab"), set_concat_pair("aa", "ab")) ? "1" : "0" ));
	set.insert(set_concat_pair("d---", set.value_comp()(set_concat_pair("aa", "aa"), set_concat_pair("aa", "aa")) ? "1" : "0" ));
	set.insert(set_concat_pair("e----", set.value_comp()(set_concat_pair("ab", "ac"), set_concat_pair("ab", "ac")) ? "1" : "0" ));
	set.insert(set_concat_pair("f-----", set.value_comp()(set_concat_pair("ab", "ab"), set_concat_pair("ab", "ab")) ? "1" : "0" ));
	set.insert(set_concat_pair("g------", set.value_comp()(set_concat_pair("ab", "aa"), set_concat_pair("ab", "aa")) ? "1" : "0" ));

	return (0);
}

template <class container>
int	set_valuecomp_b(container &set)
{
	set.insert(set_concat_pair("e", set.value_comp()(set_concat_pair("aaaaa", "e"), set_concat_pair("aaaaa", "e")) ? "1" : "0" ));
	set.insert(set_concat_pair("dd", set.value_comp()(set_concat_pair("bbbb", "dd"), set_concat_pair("bbbb", "dd")) ? "1" : "0" ));
	set.insert(set_concat_pair("ccc", set.value_comp()(set_concat_pair("ccc", "ccc"), set_concat_pair("ccc", "ccc")) ? "1" : "0" ));
	set.insert(set_concat_pair("bbbb", set.value_comp()(set_concat_pair("dd", "bbbb"), set_concat_pair("dd", "bbbb")) ? "1" : "0" ));
	set.insert(set_concat_pair("aaaaa", set.value_comp()(set_concat_pair("e", "aaaaa"), set_concat_pair("e", "aaaaa")) ? "1" : "0" ));

	return (0);
}

#endif