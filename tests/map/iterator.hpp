/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/28 23:49:03 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_ITERATOR_HPP
# define TESTS_MAP_ITERATOR_HPP

template <class container, class iterator>
int	map_iterator_1(container &map)
{
	iterator	it;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	it = map.begin();

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
	if (*(it++) != 2)
		return (6);
	if (*(++it) != 4)
		return (7);
	if (++it != map.end())
		return (8);

	return (0);
}

template <class container, class iterator>
int	map_iterator_2(container &map)
{
	iterator	it;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	it = map.begin();

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
	if (*(it--) != 2)
		return (6);
	if (*(--it) != 0)
		return (7);

	return (0);
}

template <class container, class iterator>
int	map_reverse_iterator_1(container &map)
{
	iterator	it;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	it = map.rbegin();

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
	if (*(it++) != 2)
		return (6);
	if (*(++it) != 0)
		return (7);
	if (++it != map.rend())
		return (8);
	return (0);
}

template <class container, class iterator>
int	map_reverse_iterator_2(container &map)
{
	iterator	it;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);

	it = map.rbegin();

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
	if (*(it--) != 2)
		return (6);
	if (*(--it) != 4)
		return (7);
	return (0);
}

template <class container, class iterator_a, class iterator_b, class iterator_c>
int	map_iterator_contructor_eq_deref(container &map)
{
	map.push_back(0);
	map.push_back(1);

	iterator_a	a;
	a = map.begin();
	iterator_b	b(a);
	iterator_c	c;
	c = b;

	if (a != c || a != b || b != c)
		return (1);
	
	if (!(a == c) || !(a == b) || !(b == c))
		return (2);

	++a;

	if (a == c || a == b || b != c)
		return (3);
	
	if (!(a != c) || !(a != b) || !(b == c))
		return (4);

	++b;

	if (a == c || a != b || b == c)
		return (5);
	
	if (!(a != c) || !(a == b) || !(b != c))
		return (6);
	
	++a;
	++c;
	++c;

	if (a != c || a == b || b == c)
		return (7);
	
	if (!(a == c) || !(a != b) || !(b != c))
		return (8);

	*b = 2;

	return (0);
}

template <class container, class iterator_a, class iterator_b, class iterator_c>
int	map_iterator_contructor_eq_deref_reverse(container &map)
{
	map.push_back(0);
	map.push_back(1);

	iterator_a	a;
	a = map.rbegin();
	iterator_b	b(a);
	iterator_c	c;
	c = b;

	if (a != c || a != b || b != c)
		return (1);
	
	if (!(a == c) || !(a == b) || !(b == c))
		return (2);

	++a;

	if (a == c || a == b || b != c)
		return (3);
	
	if (!(a != c) || !(a != b) || !(b == c))
		return (4);

	++b;

	if (a == c || a != b || b == c)
		return (5);
	
	if (!(a != c) || !(a == b) || !(b != c))
		return (6);
	
	++a;
	++c;
	++c;

	if (a != c || a == b || b == c)
		return (7);
	
	if (!(a == c) || !(a != b) || !(b != c))
		return (8);

	*b = 2;

	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	map_iterator_operator_diff_1(container &map)
{
	iterator_a	it;
	iterator_b	ite;

	it	= map.begin();
	ite	= map.end();

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= map.end();

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= map.end();

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= map.end();

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= map.end();

	map.push_back(ite - it);
	
	it	= ++(map.begin());
	ite	= map.end();

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= ++(map.begin());

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= ++(++(map.begin()));

	map.push_back(ite - it);
	
	it	= map.begin();
	ite	= ++(++(++(map.begin())));

	map.push_back(ite - it);
	
	it	= ++(map.begin());
	ite	= ++(map.begin());

	map.push_back(ite - it);

	it	= ++(map.begin());
	ite	= ++(++(map.begin()));

	map.push_back(ite - it);

	it	= ++(map.begin());
	ite	= ++(++(++(map.begin())));

	map.push_back(ite - it);

	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	map_iterator_operator_diff_reverse_1(container &map)
{
	iterator_a	it;
	iterator_b	ite;

	it	= map.rbegin();
	ite	= map.rend();

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= map.rend();

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= map.rend();

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= map.rend();

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= map.rend();

	map.push_back(ite - it);
	
	it	= ++(map.rbegin());
	ite	= map.rend();

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= ++(map.rbegin());

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= ++(++(map.rbegin()));

	map.push_back(ite - it);
	
	it	= map.rbegin();
	ite	= ++(++(++(map.rbegin())));

	map.push_back(ite - it);
	
	it	= ++(map.rbegin());
	ite	= ++(map.rbegin());

	map.push_back(ite - it);

	it	= ++(map.rbegin());
	ite	= ++(++(map.rbegin()));

	map.push_back(ite - it);

	it	= ++(map.rbegin());
	ite	= ++(++(++(map.rbegin())));

	map.push_back(ite - it);

	return (0);
}

template <class container, class iterator>
int	map_iterator_operator_sum_diff_1(container &map)
{
	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);
	map.push_back(5);
	map.push_back(6);
	map.push_back(7);

	iterator	it = map.begin();

	it = it + 7;
	it = 3 + it;
	it = it - 4;

	E	val = *it;
	map.push_back(val);
	
	return (0);
}

template <class container, class iterator>
int	map_reverse_iterator_operator_sum_diff_1(container &map)
{
	iterator	it;
	E			val;
	E			bval;

	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);
	map.push_back(5);
	map.push_back(6);
	map.push_back(7);

	it = map.rbegin();
	it = it + 7;
	it = 3 + it;
	it = it - 4;

	val = *it;
	bval = *(it.base());
	
	map.push_back(val);
	map.push_back(bval);
	
	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	map_iterator_operator_compare_1(container &map)
{
	container	a;
	int			i	= 0;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);

	iterator_a	ita	= a.begin();
	iterator_b	itb	= a.begin();

	++itb;

	while (i <= 3)
	{
		map.push_back(ita < itb);
		map.push_back(ita > itb);
		map.push_back(ita <= itb);
		map.push_back(ita >= itb);
		
		++ita;
		++i;
	}

	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	map_reverse_iterator_operator_compare_1(container &map)
{
	container	a;
	int			i	= 0;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);

	iterator_a	ita	= a.rbegin();
	iterator_b	itb	= a.rbegin();

	++itb;

	while (i <= 3)
	{
		map.push_back(ita < itb);
		map.push_back(ita > itb);
		map.push_back(ita <= itb);
		map.push_back(ita >= itb);
		
		++ita;
		++i;
	}

	return (0);
}

template <class container, class iterator>
int	map_iterator_operator_equal_add_del_1(container &map)
{
	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);
	map.push_back(5);

	iterator	it = map.begin();

	it += 8;
	it -= 4;
	E	intermeditate = *it;
	it -= 3;
	E	final = *it;


	map.push_back(intermeditate);
	map.push_back(final);

	return (0);
}

template <class container, class iterator>
int	map_reverse_iterator_operator_equal_add_del_1(container &map)
{
	map.push_back(0);
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);
	map.push_back(4);
	map.push_back(5);

	iterator	it = map.rbegin();

	it += 8;
	it -= 4;
	E	intermeditate = *it;
	it -= 3;
	E	final = *it;


	map.push_back(intermeditate);
	map.push_back(final);

	return (0);
}

template <class container, class reverse_iterator, class iterator>
int	map_reverse_iterator_operator_equal_with_iterator(container &map)
{
	map.push_back(1);
	map.push_back(2);
	map.push_back(3);

	iterator			it(map.begin());
	reverse_iterator	rit(it);

	map.push_back(rit.base() == it);
	map.push_back((++rit).base() == it);
	map.push_back(rit == --rit);

	return (0);
}

template <class container, class iterator>
int	map_iterator_operator_brackets_1(container &map)
{
	container	a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	iterator	it = a.begin();

	map.push_back(it[0]);
	map.push_back(it[1]);
	map.push_back(it[2]);
	map.push_back(it[3]);
	map.push_back(it[4]);

	return (0);
}

template <class container, class iterator>
int	map_reverse_iterator_operator_brackets_1(container &map)
{
	container	a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	iterator	it = a.rbegin();

	map.push_back(it[0]);
	map.push_back(it[1]);
	map.push_back(it[2]);
	map.push_back(it[3]);
	map.push_back(it[4]);

	return (0);
}

#endif