/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:24:18 by user              #+#    #+#             */
/*   Updated: 2021/05/18 17:24:03 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
namespace tests
{


template <class container>
bool	list_push_frontback(container &list)
{
	list.push_front(2);
	list.push_front(1);
	list.push_back(3);
	list.push_back(4);

	return (true);
}

template <class container>
bool	list_pushpop_frontback(container &list)
{
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_back(3);
	list.push_back(4);
	list.push_back(4);

	list.pop_front();
	list.pop_back();

	return (true);
}

template <class container>
bool	list_clear(container &list)
{
	list.clear();

	list.push_back(3);
	list.push_back(4);

	list.clear();

	list.push_front(1);

	list.clear();
	list.clear();

	return (true);
}

template <class container>
bool	list_swap(container &list)
{
	container			list2;
	container			list3;
	typename container::iterator	first;
	typename container::iterator	second;
	typename container::iterator	third;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list2.push_back(4);
	list2.push_back(5);
	list2.push_back(6);

	list3.push_back(7);
	list3.push_back(8);
	list3.push_back(9);

	first = list3.begin();
	second = first;
	++second;
	third = second;
	++third;

	list3.swap(list2);
	list.swap(list2);

	return (
		list.size() == 3
		&& *first == 7
		&& *second == 8
		&& *third == 9
	);
}

template <class container>
bool	list_resize(container &list)
{
	list.resize(1);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.resize(10, 4);
	list.resize(5);
	list.resize(7, 5);
	list.resize(6);
	list.resize(7, 6);
	list.resize(7, 10);

	list.push_back(7);

	return (list.size() == 8);
}

}
}
