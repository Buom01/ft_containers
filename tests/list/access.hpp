/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 08:47:36 by badam             #+#    #+#             */
/*   Updated: 2021/06/28 15:05:08 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
namespace tests
{


template <class container>
bool	list_access_1(container &list)
{
	if (list.begin() != list.end())
		return (false);

	if (++(list.begin()) != list.end())
		return (false);
	
	if (list.begin() != --(list.end()))
		return (false);

	return (true);
}

template <class container>
bool	list_access_2(container &list)
{
	if (list.rbegin() != list.rend())
		return (false);

	if (++(list.rbegin()) != list.rend())
		return (false);
	
	if (list.rbegin() != --(list.rend()))
		return (false);

	return (true);
}

/*
 * Below depend of `push_back` which is tested later
 */
template <class container>
bool	list_access_3(container &list)
{
	typename container::iterator	it;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	it = list.begin();

	if (list.front() != 0)
		return (false);
	if (list.back() != 4)
		return (false);

	return (true);
}

template <class container>
bool	list_access_4(container &list)
{
	typename container::iterator	it;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	it = list.begin();

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
	if (++it != list.end())
		return (false);

	return (true);
}

template <class container>
bool	list_access_5(container &list)
{
	typename container::reverse_iterator	it;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	it = list.rbegin();

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
	if (++it != list.rend())
		return (false);
	*/
	return (true);
}




}
}
