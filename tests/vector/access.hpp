/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/09/07 14:41:46 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ACCESS_HPP
# define VECTOR_ACCESS_HPP

template <class container>
int	vector_access_1(container &vector)
{
	if (vector.begin() != vector.end())
		return (1);

	if (++(vector.begin()) != ++(vector.end()))
		return (2);
	
	if (--(vector.begin()) != --(vector.end()))
		return (3);

	return (0);
}

template <class container>
int	vector_access_2(container &vector)
{
	if (vector.rbegin() != vector.rend())
		return (1);

	if (++(vector.rbegin()) != ++(vector.rend()))
		return (2);
	
	if (--(vector.rbegin()) != --(vector.rend()))
		return (3);

	return (0);
}

/*
 * Below depend of `push_back` which is tested later
 */
template <class container>
int	vector_access_3(container &vector)
{
	typename container::iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.begin();

	if (vector.front() != 0)
		return (1);
	if (vector.back() != 4)
		return (2);

	return (0);
}

template <class container>
int	vector_access_4(container &vector)
{
	typename container::iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.begin();

	if (*it != 0)
		return (1);
	if (*(++it) != 1)
		return (2);
	if (*(++it) != 2)
		return (3);
	if (*(++it) != 3)
		return (4);
	if (*(--it) != 2)
		return (5);
	if (*(++it) != 3)
		return (6);
	if (*(++it) != 4)
		return (7);
	if (++it != vector.end())
		return (8);

	return (0);
}

template <class container>
int	vector_access_5(container &vector)
{
	typename container::reverse_iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.rbegin();

	if (*it != 4)
		return (1);
	if (*(++it) != 3)
		return (2);
	if (*(++it) != 2)
		return (3);
	if (*(++it) != 1)
		return (4);
	if (*(--it) != 2)
		return (5);
	if (*(++it) != 1)
		return (6);
	if (*(++it) != 0)
		return (7);
	if (++it != vector.rend())
		return (8);
	return (0);
}

#endif

