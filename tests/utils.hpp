/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:52:10 by user              #+#    #+#             */
/*   Updated: 2021/11/16 17:36:45 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "tests.hpp"
#include "../utils.hpp"

bool	maydo(std::string testname, std::string selection);

template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, ft::pair<T1, T2> &x ) 
{
	out << "[" << x.first << ", " << x.second << "]";
	return out;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> &x ) 
{
	out << "[" << x.first << ", " << x.second << "]";
	return out;
}

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
int	exectest(int (*test_fct_a)(container_a &a),
		int (*test_fct_b)(container_b &b),
		container_a &a, container_b &b)
{
	int	ret_a;
	int	ret_b;

	ret_a = test_fct_a(a);
	ret_b = test_fct_b(b);

	if (ret_a != 0)
		return (-1 * ret_a);
	if (ret_b != 0)
		return (ret_b);
	return (!isequal(a.begin(), a.end(), b.begin(), b.end()) * 1000);
}

template< class container_a, class container_b >
bool	test(int (*test_fct_a)(container_a &a),
		int (*test_fct_b)(container_b &b),
		std::string testname, std::string selection)
{
	if (maydo(testname, selection))
	{
		int			ret;
		container_a	a;
		container_b	b;

		std::cout << testname << ": ";
		if ((ret = exectest(test_fct_a, test_fct_b, a, b)) == 0)
		{
			std::cout << "OK - ";
			dump(b.begin(), b.end());
		}	
		else
		{
			std::cout << "KO (return " << ret << ")" << std::endl;
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

template< class container >
void	stack_dump(container &stack)
{
	size_t	limit	= DUMP_LIMIT;

	std::cout << "[";
	if (!stack.size())
		std::cout << "]" << std::endl;
	else
	{
		while (stack.size() && --limit)
		{
			std::cout << stack.top();
			stack.pop();
			if (stack.size())
				std::cout << ", ";
			else
				std::cout << "]" << std::endl;
		}
		if (!limit && stack.size())
			std::cout << "...]" << std::endl;
	}
}

template< class container_a, class container_b >
bool	stack_isequal(container_a a, container_b b)
{
	if (a.size() != b.size())
		return (false);
	while (a.size())
	{
		if (a.top() != b.top())
			return (false);
		a.pop();
		b.pop();
	}
	return (true);
}

template< class container_a, class container_b >
int	stack_exectest(int (*test_fct_a)(container_a &a),
		int (*test_fct_b)(container_b &b),
		container_a &a, container_b &b)
{
	int	ret_a;
	int	ret_b;

	ret_a = test_fct_a(a);
	ret_b = test_fct_b(b);

	if (ret_a != 0)
		return (-1 * ret_a);
	if (ret_b != 0)
		return (ret_b);
	return (!stack_isequal(a, b) * 1000);
}
template< class container_a, class container_b >
bool	stack_test(int (*test_fct_a)(container_a &a),
		int (*test_fct_b)(container_b &b),
		std::string testname, std::string selection)
{
	if (maydo(testname, selection))
	{
		int			ret;
		container_a	a;
		container_b	b;

		std::cout << testname << ": ";
		if ((ret = stack_exectest(test_fct_a, test_fct_b, a, b)) == 0)
		{
			std::cout << "OK - ";
			stack_dump(a);
		}	
		else
		{
			std::cout << "KO (return " << ret << ")" << std::endl;
			std::cout << ">>>>>>>>" << std::endl;
			stack_dump(a);
			std::cout << "--------" << std::endl;
			stack_dump(b);
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
