/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   members.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 17:44:10 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_MEMBERS_HPP
# define TESTS_SET_MEMBERS_HPP

template <class container>
int	set_memberstypes_1(container &set)
{
	static_cast<void>(set);

	typedef typename container::key_type		Key;
	typedef typename container::value_type		Value;
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
	Value			test_value("TEST1");
	Reference		test_ref(test_value);
	ConstReference	test_cref(test_value);

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

template <class container>
int	set_contructors_1(container &set)
{
	typename container::allocator_type	alloc = typename container::allocator_type();

	if (set.get_allocator() != alloc)
		return (1);

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("c");
	container	set5(set.begin(), set.end());
	if (set5.get_allocator() != alloc)
		return (2);
	if (set5.size() != 3 || set5.empty())
		return (3);

	container	set6(set);
	if (set6.get_allocator() != alloc)
		return (5);
	if (set6.size() != 3 || set6.empty())
		return (6);

	return (0);
}

template <class container>
int	set_contructors_2(container &set)
{
	typename container::allocator_type	alloc = typename container::allocator_type();

	set.insert("a");
	set.insert("bb");
	set.insert("cc");

	container	set5(set.begin(), set.end(), cmpByStringLength());
	if (set5.get_allocator() != alloc)
		return (2);
	if (set5.size() != 2 || set5.empty())
		return (3);

	return (0);
}

template <class container>
int	set_equal(container &set)
{
	set.insert("z");

	container	set0;

	set = set0;

	container	set1;
	set1.insert("a");
	
	set = set1;
	if (set.size() != 1 || set.empty())
		return (1);

	container	set2;
	set2.insert("b");
	set2.insert("c");
	set2.insert("d");
	
	set = set2;

	return (0);
}

#endif