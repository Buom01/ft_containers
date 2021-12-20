/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 18:07:55 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_ITERATOR_HPP
# define TESTS_SET_ITERATOR_HPP

template <class container, class iterator>
int	set_iterator_1(container &set)
{
	iterator	it;

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");

	it = set.begin();

	if (*it != "a")
		return (1);
	if (*(++it) != "b")
		return (2);
	if (*(++it) != "c")
		return (3);
	if (*(++it) != "d")
		return (4);
	if (*(--it) != "c")
		return (5);
	if (*(it++) != "c")
		return (6);
	if (*(++it) != "e")
		return (7);
	if (++it != set.end())
		return (8);

	return (0);
}

template <class container, class iterator>
int	set_iterator_2(container &set)
{
	iterator	it;

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");

	it = set.begin();

	std::advance(it, 4);

	if (*it != "e")
		return (1);
	if (*(--it) != "d")
		return (2);
	if (*(--it) != "c")
		return (3);
	if (*(--it) != "b")
		return (4);
	if (*(++it) != "c")
		return (5);
	if (*(it--) != "c")
		return (6);
	if (*(--it) != "a")
		return (7);
	if (it != set.begin())
		return (8);
	return (0);
}

template <class container, class iterator>
int	set_reverse_iterator_1(container &set)
{
	iterator	it;

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");

	it = set.rbegin();
	if (*it != "e")
		return (1);
	if (*(++it) != "d")
		return (2);
	if (*(++it) != "c")
		return (3);
	if (*(++it) != "b")
		return (4);
	if (*(--it) != "c")
		return (5);
	if (*(it++) != "c")
		return (6);
	if (*(++it) != "a")
		return (7);

	if (++it != set.rend())
		return (8);
	return (0);
}

template <class container, class iterator>
int	set_reverse_iterator_2(container &set)
{
	iterator	it;

	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");

	it = set.rbegin();

	std::advance(it, 4);
	
	if (*it != "a")
		return (1);
	if (*(--it) != "b")
		return (2);
	if (*(--it) != "c")
		return (3);
	if (*(--it) != "d")
		return (4);
	if (*(++it) != "c")
		return (5);
	if (*(it--) != "c")
		return (6);
	if (*(--it) != "e")
		return (7);
	if (it != set.rbegin())
		return (8);
	return (0);
}

template <class container, class iterator_a, class iterator_b, class iterator_c>
int	set_iterator_contructor_eq_deref(container &set)
{
	set.insert("a");
	set.insert("b");

	iterator_a	a;
	a = set.begin();
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

	return (0);
}

template <class container, class iterator_a, class iterator_b, class iterator_c>
int	set_iterator_contructor_eq_deref_reverse(container &set)
{
	set.insert("a");
	set.insert("b");

	iterator_a	a;
	a = set.rbegin();
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

	return (0);
}

template <class container, class reverse_iterator, class iterator>
int	set_reverse_iterator_operator_equal_with_iterator(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");

	iterator			it(set.begin());
	reverse_iterator	rit(it);

	set.insert(set_concat_pair("d", rit.base() == it));
	set.insert(set_concat_pair("e", (++rit).base() == it));
	set.insert(set_concat_pair("f", rit == --rit));

	return (0);
}

#endif