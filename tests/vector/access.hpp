/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/09/24 19:20:28 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_ACCESS_HPP
# define TESTS_VECTOR_ACCESS_HPP

template <class container>
int	vector_access_1(container &vector)
{
	if (vector.begin() != vector.end())
		return (1);

	return (0);
}

template <class container>
int	vector_access_2(container &vector)
{
	if (vector.rbegin() != vector.rend())
		return (1);

	return (0);
}

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
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	if (vector.at(0) != vector[0] || vector[0] != 0)
		return (1);

	if (vector.at(1) != vector[1] || vector[1] != 1)
		return (2);

	if (vector.at(2) != vector[2] || vector[2] != 2)
		return (3);

	if (vector.at(3) != vector[3] || vector[3] != 3)
		return (4);

	if (vector.at(4) != vector[4] || vector[4] != 4)
		return (5);

	return (0);
}

template <class container>
int	vector_access_5(container &vector)
{
	const E	*const_data;
	E		*data			= vector.data();

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	data		= vector.data();
	const_data	= vector.data();

	if (*data != 0)
		return (1);

	*data = 9;

	if (*(++data) != 1)
		return (2);

	if (*(++data) != 2)
		return (3);

	if (*(++data) != 3)
		return (4);

	if (*(++data) != 4)
		return (5);


	if (const_data[0] != 9)
		return (6);

	if (const_data[1] != 1)
		return (7);

	if (const_data[2] != 2)
		return (8);

	if (const_data[3] != 3)
		return (9);

	if (const_data[4] != 4)
		return (10);

	return (0);
}

#endif

