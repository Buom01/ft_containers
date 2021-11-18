/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   members.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/11/16 16:04:48 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_MEMBERS_HPP
# define TESTS_VECTOR_MEMBERS_HPP

template <class container>
int	vector_memberstypes_1(container &vector)
{
	static_cast<void>(vector);

	typename container::value_type				T;
	typename container::allocator_type			Allocator;
	typename container::size_type				SizeType;
	typename container::difference_type			DifferenceType;
	typename container::reference				Reference				= T;
	typename container::const_reference			ConstReference			= T;
	typename container::pointer					Pointer;
	typename container::const_pointer			ConstPointer;
	typename container::iterator				Iterator;
	typename container::const_iterator			ConstIterator;
	typename container::reverse_iterator		ReverseIterator;
	typename container::const_reverse_iterator	ConstReverseIterator;

	static_cast<void>(T);
	static_cast<void>(Allocator);
	static_cast<void>(SizeType);
	static_cast<void>(DifferenceType);
	static_cast<void>(Reference);
	static_cast<void>(ConstReference);
	static_cast<void>(Pointer);
	static_cast<void>(ConstPointer);
	static_cast<void>(Iterator);
	static_cast<void>(ConstIterator);
	static_cast<void>(ReverseIterator);
	static_cast<void>(ConstReverseIterator);

	return (0);
}

template <class container>
int	vector_memberstypes_2(container &vector)
{
	static_cast<void>(vector);

	typename container::size_type				SizeType		= 0;
	typename container::difference_type			DifferenceType	= 0;

	if (--SizeType < 0)
		return (1);

	if (--DifferenceType >= 0)
		return (2);

	return (0);
}

template <class container>
int	vector_contructors(container &vector)
{
	typename container::allocator_type	alloc = typename container::allocator_type();

	if (vector.get_allocator() != alloc)
		return (1);

	container	vector2(alloc);
	if (vector2.get_allocator() != alloc)
		return (2);

	container	vector3(static_cast<std::size_t>(5), 1, alloc);
	if (vector3.get_allocator() != alloc)
		return (3);
	if (vector3.size() != 5 || vector3.empty())
		return (4);
	if (vector3[0] != 1 || vector3[4] != 1)
		return (5);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	container	vector5(vector.begin(), vector.end(), alloc);
	if (vector5.get_allocator() != alloc)
		return (6);
	if (vector5.size() != 3 || vector5.empty())
		return (7);
	if (vector5[0] != 1 || vector5[1] != 2 || vector5[2] != 3)
		return (8);

	container	vector6(vector);
	if (vector6.get_allocator() != alloc)
		return (6);
	if (vector6.size() != 3 || vector6.empty())
		return (7);
	if (vector6[0] != 1 || vector6[1] != 2 || vector6[2] != 3)
		return (8);

	return (0);
}

template <class container>
int	vector_equal(container &vector)
{
	container	vector1;
	vector1.push_back(1);
	
	vector = vector1;
	if (vector.size() != 1 || vector.empty())
		return (1);
	if (vector[0] != 1)
		return (2);

	container	vector2;
	vector2.push_back(2);
	vector2.push_back(3);
	vector2.push_back(4);
	
	vector = vector2;

	return (0);
}

template <class container>
int		vector_assign_1(container &vector)
{
	vector.assign(0, 0);
	if (vector.size() != 0 || !vector.empty())
		return (1);

	vector.assign(10, 0);

	return (0);
}

template <class container>
int		vector_assign_2(container &vector)
{
	vector.push_back(2);

	vector.assign(10, 1);

	if (vector.size() != 10 || vector.empty())
		return (1);

	return (0);
}

template <class container>
int		vector_assign_3(container &vector)
{
	vector.push_back(2);

	vector.assign(10, 1);
	if (vector.size() != 10 || vector.empty())
		return (1);

	vector.assign(5, 2);

	if (vector.size() != 5 || vector.empty())
		return (1);

	return (0);
}

template <class container>
int		vector_assign_4(container &vector)
{
	container	vector2;

	vector2.push_back(0);
	vector2.push_back(1);
	vector2.push_back(2);
	vector2.push_back(3);
	vector2.push_back(4);
	
	vector.assign(vector2.begin(), vector2.end());
	if (vector.size() != 5 || vector.empty())
		return (1);

	return (0);
}

template <class container>
int		vector_assign_5(container &vector)
{
	container	vector2;

	vector2.push_back(0);
	vector2.push_back(1);
	vector2.push_back(2);
	vector2.push_back(3);
	vector2.push_back(4);

	vector.push_back(9);
	
	vector.assign(vector2.begin(), vector2.begin());
	if (vector.size() != 0 || !vector.empty())
		return (1);

	return (0);
}

template <class container>
int		vector_assign_6(container &vector)
{
	container	vector2;

	vector.push_back(9);
	
	vector.assign(vector2.begin(), vector2.end());
	if (vector.size() != 0 || !vector.empty())
		return (1);

	return (0);
}

#endif

