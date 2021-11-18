/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   members.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/11/16 18:29:54 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_MEMBERS_HPP
# define TESTS_MAP_MEMBERS_HPP

template <class container>
int	map_memberstypes_1(container &map)
{
	static_cast<void>(map);

	typedef typename container::key_type		Key;
	typedef typename container::mapped_type		T;
	typedef typename container::value_type		PAIR;
	typename container::key_compare				Compare;
	typename container::allocator_type			Allocator;
	typename container::size_type				SizeType		= 0;
	typename container::difference_type			DifferenceType	= 0;
	typedef typename container::reference		Reference;
	typedef typename container::const_reference	ConstReference;
	typename container::pointer					Pointer;
	typename container::const_pointer			ConstPointer;
	typename container::iterator				Iterator;
	typename container::const_iterator			ConstIterator;
	typename container::reverse_iterator		ReverseIterator;
	typename container::const_reverse_iterator	ConstReverseIterator;

	Key				test_key("TEST");
	T				test_val(1);
	PAIR			test_pair(test_key, test_val);
	Reference		test_ref(test_pair);
	ConstReference	test_cref(test_pair);

	static_cast<void>(Compare);
	static_cast<void>(Allocator);
	static_cast<void>(SizeType);
	static_cast<void>(DifferenceType);
	static_cast<void>(test_ref);
	static_cast<void>(test_cref);
	static_cast<void>(Pointer);
	static_cast<void>(ConstPointer);
	static_cast<void>(Iterator);
	static_cast<void>(ConstIterator);
	static_cast<void>(ReverseIterator);
	static_cast<void>(ConstReverseIterator);

	if (--SizeType < 0)
		return (1);

	if (--DifferenceType >= 0)
		return (2);

	return (0);
}

template <class container, class pair>
int	map_contructors_1(container &map)
{
	typename container::allocator_type	alloc = typename container::allocator_type();

	if (map.get_allocator() != alloc)
		return (1);

	map.insert(pair("a", 1));
	map.insert(pair("b", 2));
	map.insert(pair("c", 3));
	container	map5(map.begin(), map.end());
	if (map5.get_allocator() != alloc)
		return (2);
	if (map5.size() != 3 || map5.empty())
		return (3);
	if (map5["a"] != 1 || map5["b"] != 2 || map5["c"] != 3)
		return (4);

	container	map6(map);
	if (map6.get_allocator() != alloc)
		return (5);
	if (map6.size() != 3 || map6.empty())
		return (6);
	if (map6["a"] != 1 || map6["b"] != 2 || map6["c"] != 3)
		return (7);

	return (0);
}

template <class container, class pair>
int	map_contructors_2(container &map)
{
	typename container::allocator_type	alloc = typename container::allocator_type();

	map.insert(pair("a", 1));
	map.insert(pair("bb", 2));
	map.insert(pair("cc", 3));

	// if (map.find("dd") == map.end())
	// 	return (1);

	container	map5(map.begin(), map.end(), cmpByStringLength());
	if (map5.get_allocator() != alloc)
		return (2);
	if (map5.size() != 2 || map5.empty())
		return (3);
	if (map5["a"] != 1 || map5["bb"] != 2)
		return (4);

	return (0);
}

template <class container, class pair>
int	map_equal(container &map)
{
	map.insert(pair("z", 0));

	container	map0;

	map = map0;

	container	map1;
	map1.insert(pair("a", 1));
	
	map = map1;
	if (map.size() != 1 || map.empty())
		return (1);
	if (map["a"] != 1)
		return (2);

	container	map2;
	map2.insert(pair("b", 2));
	map2.insert(pair("c", 3));
	map2.insert(pair("d", 4));
	
	map = map2;

	return (0);
}

#endif