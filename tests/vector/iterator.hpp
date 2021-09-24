/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/09/24 19:13:43 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_ITERATOR_HPP
# define TESTS_VECTOR_ITERATOR_HPP

template <class container, class iterator>
int	vector_iterator_1(container &vector)
{
	iterator	it;

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

template <class container, class iterator>
int	vector_iterator_2(container &vector)
{
	iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.begin();

	std::advance(it, 4);

	if (*it != 4)
		return (1);
	if (*(--it) != 3)
		return (2);
	if (*(--it) != 2)
		return (3);
	if (*(--it) != 1)
		return (4);
	if (*(++it) != 2)
		return (5);
	if (*(--it) != 1)
		return (6);
	if (*(--it) != 0)
		return (7);

	return (0);
}

template <class container, class iterator>
int	vector_reverse_iterator_1(container &vector)
{
	iterator	it;

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

template <class container, class iterator>
int	vector_reverse_iterator_2(container &vector)
{
	iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.rbegin();

	std::advance(it, 4);

	if (*it != 0)
		return (1);
	if (*(--it) != 1)
		return (2);
	if (*(--it) != 2)
		return (3);
	if (*(--it) != 3)
		return (4);
	if (*(++it) != 2)
		return (5);
	if (*(--it) != 3)
		return (6);
	if (*(--it) != 4)
		return (7);
	return (0);
}

#endif