/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/05 16:40:19 by badam            ###   ########.fr       */
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
	if (*(it++) != 2)
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
	if (*(it--) != 2)
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
	if (*(it++) != 2)
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
	if (*(it--) != 2)
		return (6);
	if (*(--it) != 4)
		return (7);
	return (0);
}

template <class container, class iterator_a, class iterator_b, class iterator_c>
int	vector_iterator_contructor_eq_deref(container &vector)
{
	vector.push_back(0);
	vector.push_back(1);

	iterator_a	a;
	a = vector.begin();
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
int	vector_iterator_contructor_eq_deref_reverse(container &vector)
{
	vector.push_back(0);
	vector.push_back(1);

	iterator_a	a;
	a = vector.rbegin();
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
int	vector_iterator_operator_diff_1(container &vector)
{
	iterator_a	it;
	iterator_b	ite;

	it	= vector.begin();
	ite	= vector.end();

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= vector.end();

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= vector.end();

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= vector.end();

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= vector.end();

	vector.push_back(ite - it);
	
	it	= ++(vector.begin());
	ite	= vector.end();

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= ++(vector.begin());

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= ++(++(vector.begin()));

	vector.push_back(ite - it);
	
	it	= vector.begin();
	ite	= ++(++(++(vector.begin())));

	vector.push_back(ite - it);
	
	it	= ++(vector.begin());
	ite	= ++(vector.begin());

	vector.push_back(ite - it);

	it	= ++(vector.begin());
	ite	= ++(++(vector.begin()));

	vector.push_back(ite - it);

	it	= ++(vector.begin());
	ite	= ++(++(++(vector.begin())));

	vector.push_back(ite - it);

	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	vector_iterator_operator_diff_reverse_1(container &vector)
{
	iterator_a	it;
	iterator_b	ite;

	it	= vector.rbegin();
	ite	= vector.rend();

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= vector.rend();

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= vector.rend();

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= vector.rend();

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= vector.rend();

	vector.push_back(ite - it);
	
	it	= ++(vector.rbegin());
	ite	= vector.rend();

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= ++(vector.rbegin());

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= ++(++(vector.rbegin()));

	vector.push_back(ite - it);
	
	it	= vector.rbegin();
	ite	= ++(++(++(vector.rbegin())));

	vector.push_back(ite - it);
	
	it	= ++(vector.rbegin());
	ite	= ++(vector.rbegin());

	vector.push_back(ite - it);

	it	= ++(vector.rbegin());
	ite	= ++(++(vector.rbegin()));

	vector.push_back(ite - it);

	it	= ++(vector.rbegin());
	ite	= ++(++(++(vector.rbegin())));

	vector.push_back(ite - it);

	return (0);
}

template <class container, class iterator>
int	vector_iterator_operator_sum_diff_1(container &vector)
{
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);
	vector.push_back(7);

	iterator	it = vector.begin();

	it = it + 7;
	it = 3 + it;
	it = it - 4;

	E	val = *it;
	vector.push_back(val);
	
	return (0);
}

template <class container, class iterator>
int	vector_reverse_iterator_operator_sum_diff_1(container &vector)
{
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);
	vector.push_back(7);

	iterator	it = vector.rbegin();

	it = it + 7;
	it = 3 + it;
	it = it - 4;

	E	val = *it;
	vector.push_back(val);

	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	vector_iterator_operator_compare_1(container &vector)
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
		vector.push_back(ita < itb);
		vector.push_back(ita > itb);
		vector.push_back(ita <= itb);
		vector.push_back(ita >= itb);
		
		++ita;
		++i;
	}

	return (0);
}

template <class container, class iterator_a, class iterator_b>
int	vector_reverse_iterator_operator_compare_1(container &vector)
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
		vector.push_back(ita < itb);
		vector.push_back(ita > itb);
		vector.push_back(ita <= itb);
		vector.push_back(ita >= itb);
		
		++ita;
		++i;
	}

	return (0);
}

template <class container, class iterator>
int	vector_iterator_operator_equal_add_del_1(container &vector)
{
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	iterator	it = vector.begin();

	it += 8;
	it -= 4;
	E	intermeditate = *it;
	it -= 3;
	E	final = *it;


	vector.push_back(intermeditate);
	vector.push_back(final);

	return (0);
}

template <class container, class iterator>
int	vector_reverse_iterator_operator_equal_add_del_1(container &vector)
{
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	iterator	it = vector.rbegin();

	it += 8;
	it -= 4;
	E	intermeditate = *it;
	it -= 3;
	E	final = *it;


	vector.push_back(intermeditate);
	vector.push_back(final);

	return (0);
}

template <class container, class iterator>
int	vector_iterator_operator_brackets_1(container &vector)
{
	container	a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	iterator	it = a.begin();

	vector.push_back(it[0]);
	vector.push_back(it[1]);
	vector.push_back(it[2]);
	vector.push_back(it[3]);
	vector.push_back(it[4]);

	return (0);
}

template <class container, class iterator>
int	vector_reverse_iterator_operator_brackets_1(container &vector)
{
	container	a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	iterator	it = a.rbegin();

	vector.push_back(it[0]);
	vector.push_back(it[1]);
	vector.push_back(it[2]);
	vector.push_back(it[3]);
	vector.push_back(it[4]);

	return (0);
}

#endif