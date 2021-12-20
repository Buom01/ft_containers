/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 17:17:06 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_ITERATOR_HPP
# define TESTS_MAP_ITERATOR_HPP

template <class container, class pair, class iterator>
int	map_iterator_1(container &map)
{
	iterator	it;

	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));
	map.insert(pair("e", 4));

	it = map.begin();

	if (it->first != "a")
		return (1);
	if ((++it)->first != "b")
		return (2);
	if ((++it)->first != "c")
		return (3);
	if ((++it)->first != "d")
		return (4);
	if ((--it)->first != "c")
		return (5);
	if ((it++)->first != "c")
		return (6);
	if ((++it)->first != "e")
		return (7);
	if (++it != map.end())
		return (8);

	return (0);
}

template <class container, class pair, class iterator>
int	map_iterator_2(container &map)
{
	iterator	it;


	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));
	map.insert(pair("e", 4));

	it = map.begin();

	std::advance(it, 4);

	if (it->first != "e")
		return (1);
	if ((--it)->first != "d")
		return (2);
	if ((--it)->first != "c")
		return (3);
	if ((--it)->first != "b")
		return (4);
	if ((++it)->first != "c")
		return (5);
	if ((it--)->first != "c")
		return (6);
	if ((--it)->first != "a")
		return (7);
	if (it != map.begin())
		return (8);
	return (0);
}

template <class container, class pair, class iterator>
int	map_reverse_iterator_1(container &map)
{
	iterator	it;

	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));
	map.insert(pair("e", 4));


	it = map.rbegin();

	if (it->first != "e")
		return (1);
	if ((++it)->first != "d")
		return (2);
	if ((++it)->first != "c")
		return (3);
	if ((++it)->first != "b")
		return (4);
	if ((--it)->first != "c")
		return (5);
	if ((it++)->first != "c")
		return (6);
	if ((++it)->first != "a")
		return (7);
	if (++it != map.rend())
		return (8);
	return (0);
}

template <class container, class pair, class iterator>
int	map_reverse_iterator_2(container &map)
{
	iterator	it;

	map.insert(pair("a", 0));
	map.insert(pair("b", 1));
	map.insert(pair("c", 2));
	map.insert(pair("d", 3));
	map.insert(pair("e", 4));

	it = map.rbegin();

	std::advance(it, 4);

	if (it->first != "a")
		return (1);
	if ((--it)->first != "b")
		return (2);
	if ((--it)->first != "c")
		return (3);
	if ((--it)->first != "d")
		return (4);
	if ((++it)->first != "c")
		return (5);
	if ((it--)->first != "c")
		return (6);
	if ((--it)->first != "e")
		return (7);
	if (it != map.rbegin())
		return (8);
	return (0);
}

template <class container, class pair, class iterator_a, class iterator_b, class iterator_c>
int	map_iterator_contructor_eq_deref(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 1));

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

	b->second = 2;

	return (0);
}

template <class container, class pair, class iterator_a, class iterator_b, class iterator_c>
int	map_iterator_contructor_eq_deref_reverse(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 1));

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

	b->second = 2;

	return (0);
}

template <class container, class pair, class reverse_iterator, class iterator>
int	map_reverse_iterator_operator_equal_with_iterator(container &map)
{
	map.insert(pair("a", 0));
	map.insert(pair("b", 0));
	map.insert(pair("c", 0));

	iterator			it(map.begin());
	reverse_iterator	rit(it);

	map.insert(pair("d", rit.base() == it));
	map.insert(pair("e", (++rit).base() == it));
	map.insert(pair("f", rit == --rit));

	return (0);
}

#endif