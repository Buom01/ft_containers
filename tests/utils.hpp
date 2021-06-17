/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:52:10 by user              #+#    #+#             */
/*   Updated: 2021/06/15 22:05:02 by bastien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "tests.hpp"

namespace ft
{
namespace tests
{


bool	maydo(std::string testname, std::string selection);

template< class iterator >
void	dump(iterator i, iterator end)
{
	size_t	limit	= DUMP_LIMIT;

	std::cout << "[";
	if (i == end)
		std::cout << "]" << std::endl;
	else
	{
		while (i != end && --limit)
		{
			std::cout << *(i++);
			if (i != end)
				std::cout << ", ";
			else
				std::cout << "]" << std::endl;
		}
		if (!limit && i != end)
			std::cout << "...]" << std::endl;
	}
}

template< class iterator_a, class iterator_b >
bool	isequal(iterator_a begin_a, iterator_a end_a,
		iterator_b begin_b, iterator_b end_b)
{
	while (begin_a != end_a && begin_b != end_b)
		if (*(begin_a++) != *(begin_b++))
			return (false);
	if ((begin_a == end_a) != (begin_b == end_b))
		return (false);
	return (true);
}

template< class container_a, class container_b >
bool	exectest(bool (*test_fct_a)(container_a &a),
		bool (*test_fct_b)(container_b &b),
		container_a &a, container_b &b)
{
	bool	ret_a;
	bool	ret_b;

	ret_a = test_fct_a(a);
	ret_b = test_fct_b(b);

	if (!ret_a || !ret_b)
		return (false);
	return (isequal(a.begin(), a.end(), b.begin(), b.end()));
}

template< class container_a, class container_b >
bool	test(bool (*test_fct_a)(container_a &a),
		bool (*test_fct_b)(container_b &b),
		std::string testname, std::string selection)
{
	if (maydo(testname, selection))
	{
		container_a	a;
		container_b	b;

		std::cout << testname << ": ";
		if (exectest(test_fct_a, test_fct_b, a, b))
		{
			std::cout << "OK - ";
			dump(b.begin(), b.end());
		}	
		else
		{
			std::cout << "KO" << std::endl;
			std::cout << ">>>>>>>>" << std::endl;
			dump(a.begin(), a.end());
			std::cout << "--------" << std::endl;
			dump(b.begin(), b.end());
			std::cout << ">>>>>>>>" << std::endl;
			return (false);
		}
	}

	return (true);
}

template <class T>
struct s_pred_val
{
	const T *refval;
	bool	operator() (const T& value)
	{
		return (value == *refval);
	}
	void	set_refval(const T &val)
	{
		refval = &val;
	}
};

template <class T>
struct s_pred_const
{
	bool	ret;
	bool	operator() (const T& value)
	{
		(void)value;

		return (ret);
	}
	void	set_ret(const bool new_ret)
	{
		ret = new_ret;
	}
};

template <class T>
struct s_pred_unique_two
{
	bool	operator() (const T first, const T second)
	{
		T	diff;

		diff = first - second;
		if (diff < 0)
			diff *= -1;
		return (diff <= 1);
	}
};


}
}
