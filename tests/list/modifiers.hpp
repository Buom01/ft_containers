/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:24:18 by user              #+#    #+#             */
/*   Updated: 2021/09/21 15:29:03 by badam            ###   ########.fr       */
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

	return (list.size() == 4);
}

template <class container>
bool	list_pop_frontback(container &list)
{
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.pop_front();
	list.pop_front();
	list.pop_front();

	list.push_back(4);
	list.push_back(5);
	list.push_back(6);

	list.pop_back();
	list.pop_back();
	list.pop_back();

	list.push_back(7);
	list.push_back(8);
	list.push_back(9);

	list.pop_back();
	list.pop_front();

	return (list.size() == 1);
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

	return (list.size() == 0);
}

template <class container>
bool	list_swap(container &list)
{
	container						list2;
	container						list3;
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
bool	list_erase(container &list)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	ret = list.erase(list.begin(), list.end());
	if (ret != list.end() || list.size() != 0)
		return (false);

	list.push_back(5);
	list.push_back(6);

	ret = list.erase(list.begin());
	if (ret != list.begin() || list.size() != 1)
		return (false);
	ret = list.erase(list.begin());
	if (ret != list.begin() || list.size() != 0)
		return (false);

	list.push_back(7);
	list.push_back(8);

	pos = list.end();
	--pos;

	ret = list.erase(pos);
	if (ret != list.end() || list.size() != 1)
		return (false);
	ret = list.erase(list.begin());
	if (ret != list.begin() || !list.empty())
		return (false);

	list.push_back(9);
	list.push_back(10);
	list.push_back(11);
	list.push_back(12);

	pos = list.end();
	--pos;

	ret = list.erase(pos);
	if (ret != list.end() || list.size() != 3)
		return (false);
	ret = list.erase(list.begin());
	if (ret != list.begin() || list.size() != 2)
		return (false);

	return (true);
}

template <class container>
bool	list_insert_1(container &list)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	ret = list.insert(list.begin(), 2);
	if (ret != list.begin() || list.size() != 1)
		return (false);
	ret = list.insert(list.end(), 4);
	pos = list.end();
	--pos;
	if (ret != pos || list.size() != 2)
		return (false);
	ret = list.insert(pos, 3);
	--pos;
	if (ret != pos || list.size() != 3)
		return (false);


	ret = list.insert(list.end(), 7);
	pos = list.end();
	--pos;
	if (ret != pos || list.size() != 4)
		return (false);
	ret = list.insert(pos, 6);
	--pos;
	if (ret != pos || list.size() != 5)
		return (false);
	ret = list.insert(pos, 5);
	--pos;
	if (ret != pos || list.size() != 6)
		return (false);

	ret = list.insert(list.begin(), 0);
	if (ret != list.begin() || list.size() != 7)
		return (false);
	pos = list.begin();
	++pos;
	ret = list.insert(pos, 1);
	--pos;
	if (ret != pos || list.size() != 8)
		return (false);
	ret = list.insert(list.end(), 8);
	pos = list.end();
	--pos;
	if (ret != pos || list.size() != 9)
		return (false);

	return (true);
}

template <class container>
bool	list_insert_2(container &list)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	list.insert(list.end(), 0, 0);
	if (list.size() != 0)
		return (false);
	list.insert(list.begin(), 0, 0);
	if (list.size() != 0)
		return (false);
	list.insert(list.end(), 1, 1);
	if (list.size() != 1)
		return (false);
	list.insert(list.end(), 2, 3);
	if (list.size() != 3)
		return (false);
	list.insert(list.begin(), 3, 0);
	if (list.size() != 6)
		return (false);

	pos = list.end();
	--pos;
	--pos;
	list.insert(pos, 4, 2);
	if (list.size() != 10)
		return (false);

	return (true);
}

template <class container>
bool	list_insert_3(container &list)
{
	typename container::iterator	pos;
	container						list1;
	container						list2;
	container						list3;

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list2.push_back(4);
	list2.push_back(5);
	list2.push_back(6);
	list3.push_back(7);
	list3.push_back(8);
	list3.push_back(9);

	list.insert(list.end(), list3.begin(), list3.end());
	if (list.size() != 3)
		return (false);
	list.insert(list.begin(), list1.begin(), list1.end());
	if (list.size() != 6)
		return (false);
	pos = list.begin();
	++pos;
	++pos;
	++pos;
	list.insert(pos, list2.begin(), list2.end());
	if (list.size() != 9)
		return (false);

	return (true);
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

template <class container>
bool	list_assign_1(container &list)
{
	list.assign(0, 0);
	if (list.size() != 0)
		return (false);

	list.assign(10, 0);
	return (true);
}

template <class container>
bool	list_assign_2(container &list)
{
	list.push_back(2);

	list.assign(10, 1);
	return (true);
}

template <class container>
bool	list_assign_3(container &list)
{
	list.push_back(2);

	list.assign(10, 1);
	list.assign(5, 2);
	return (true);
}

template <class container>
bool	list_assign_4(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);
	
	list.assign(list2.begin(), list2.end());
	return (true);
}

template <class container>
bool	list_assign_5(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.push_back(9);
	
	list.assign(list2.begin(), list2.begin());
	return (true);
}

template <class container>
bool	list_assign_6(container &list)
{
	container	list2;

	list.push_back(9);
	
	list.assign(list2.begin(), list2.end());
	return (true);
}

}
}
