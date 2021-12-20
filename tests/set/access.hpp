/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 17:48:38 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_ACCESS_HPP
# define TESTS_SET_ACCESS_HPP

template <class container>
int	set_access_1(container &set)
{
	if (set.begin() != set.end())
		return (1);

	return (0);
}

template <class container>
int	set_access_2(container &set)
{
	if (set.rbegin() != set.rend())
		return (1);

	return (0);
}

template <class container>
int	set_access_3(container &set)
{
	typename container::iterator	it;

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");

	it = set.begin();

	if (*it != "a")
		return (1);
	if (*(++it) != "b")
		return (2);
	if (*(++it) != "c")
		return (3);
	if (*(++it) != "d")
		return (4);
	if (*(++it) != "e")
		return (5);

	return (0);
}

template <class container>
int	set_access_4(container &set)
{
	typename container::reverse_iterator	it;

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");

	it = set.rbegin();

	if (*it != "e")
		return (1);
	if (*(++it) != "d")
		return (2);
	if (*(++it) != "c")
		return (3);
	if (*(++it) != "b")
		return (4);
	if (*(++it) != "a")
		return (5);

	return (0);
}

#endif

