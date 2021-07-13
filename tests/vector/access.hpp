/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/07/13 14:10:48 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS_HPP
# define ACCESS_HPP

namespace ft
{
namespace tests
{
namespace vector
{


template <class container>
bool	vector_access_1(container &vector)
{
	if (vector.begin() != vector.end())
		return (false);

	if (++(vector.begin()) != vector.end())
		return (false);
	
	if (vector.begin() != --(vector.end()))
		return (false);

	return (true);
}

template <class container>
bool	vector_access_2(container &vector)
{
	if (vector.rbegin() != vector.rend())
		return (false);

	if (++(vector.rbegin()) != vector.rend())
		return (false);
	
	if (vector.rbegin() != --(vector.rend()))
		return (false);

	return (true);
}

/*
 * Below depend of `push_back` which is tested later
 */
template <class container>
bool	vector_access_3(container &vector)
{
	typename container::iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.begin();

	if (vector.front() != 0)
		return (false);
	if (vector.back() != 4)
		return (false);

	return (true);
}

template <class container>
bool	vector_access_4(container &vector)
{
	typename container::iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.begin();

	if (*it != 0)
		return (false);
	if (*(++it) != 1)
		return (false);
	if (*(++it) != 2)
		return (false);
	if (*(++it) != 3)
		return (false);
	if (*(--it) != 2)
		return (false);
	if (*(++it) != 3)
		return (false);
	if (*(++it) != 4)
		return (false);
	if (++it != vector.end())
		return (false);

	return (true);
}

template <class container>
bool	vector_access_5(container &vector)
{
	typename container::reverse_iterator	it;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	it = vector.rbegin();

	if (*it != 4)
		return (false);
	if (*(++it) != 3)
		return (false);
	if (*(++it) != 2)
		return (false);
	if (*(++it) != 1)
		return (false);
	if (*(--it) != 2)
		return (false);
	if (*(++it) != 1)
		return (false);
	if (*(++it) != 0)
		return (false);
	/*
	if (++it != vector.rend())
		return (false);
	*/
	return (true);
}


}
}
}
#endif

