/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonmember.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 13:48:16 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_NONMEMBER_HPP
# define TESTS_VECTOR_NONMEMBER_HPP

template <class container>
int	_vector_nm_swap(container &vector, void (*swap)(container &lhs, container &rhs))
{
	container						vector2;
	container						vector3;
	typename container::iterator	first;
	typename container::iterator	second;
	typename container::iterator	third;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	vector2.push_back(4);
	vector2.push_back(5);
	vector2.push_back(6);

	vector3.push_back(7);
	vector3.push_back(8);
	vector3.push_back(9);

	first = vector3.begin();
	second = first;
	++second;
	third = second;
	++third;

	swap(vector3, vector2);
	swap(vector, vector2);

	if (vector.size() != 3 || vector.empty())
		return (1);
	if (*first == 4)
		return (2);
	if (*second == 5)
		return (3);
	if (*third == 6)
		return (4);
	
	return (0);
}

template <class container>
int	vector_nm_std_swap(container &vector)
{
	return (_vector_nm_swap(vector, std::swap));
}

template <class container>
int	vector_nm_ft_swap(container &vector)
{
	return (_vector_nm_swap(vector, ft::swap));
}


template <class container>
int	vector_nm_equal_not_equal(container &vector)
{
	container	vector1;

	if (!(vector == vector1))
		return (1);
	if (vector != vector1)
		return (2);

	vector.push_back(1);

	if (vector == vector1)
		return (3);
	if (!(vector != vector1))
		return (4);

	vector1.push_back(1);

	if (!(vector == vector1))
		return (5);
	if (vector != vector1)
		return (6);

	vector1.push_back(2);

	if (vector == vector1)
		return (7);
	if (!(vector != vector1))
		return (8);

	vector.push_back(2);

	if (!(vector == vector1))
		return (9);
	if (vector != vector1)
		return (10);



	vector1.push_back(3);

	if (vector == vector1)
		return (11);
	if (!(vector != vector1))
		return (12);

	vector.push_back(3);

	if (!(vector == vector1))
		return (13);
	if (vector != vector1)
		return (14);

	vector.push_back(4);

	if (vector == vector1)
		return (15);
	if (!(vector != vector1))
		return (16);

	vector1.push_back(4);

	if (!(vector == vector1))
		return (17);
	if (vector != vector1)
		return (18);

	
	vector.clear();
	vector1.clear();

	if (!(vector == vector1))
		return (19);
	if (vector != vector1)
		return (20);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector1.push_back(0);
	vector1.push_back(2);
	vector1.push_back(3);

	if (vector == vector1)
		return (21);
	if (!(vector != vector1))
		return (22);

	vector.clear();
	vector1.clear();

	if (!(vector == vector1))
		return (23);
	if (vector != vector1)
		return (24);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(4);

	if (vector == vector1)
		return (25);
	if (!(vector != vector1))
		return (26);

	vector.clear();
	vector1.clear();

	if (!(vector == vector1))
		return (27);
	if (vector != vector1)
		return (28);


	return (0);
}

template <class container>
void	_vector_nm_dump_compare(container &out, container first, container second)
{
	out.push_back(first == second);
	out.push_back(first >= second);
	out.push_back(first <= second);
	out.push_back(first != second);
	out.push_back(first > second);
	out.push_back(first < second);
	out.push_back(2);
}

template <class container>
int	vector_nm_compare(container &vector)
{
	{
		container first;
		container second;
		
		_vector_nm_dump_compare(vector, first, second);

		first.push_back(1);
		_vector_nm_dump_compare(vector, first, second);
		
		second.push_back(2);
		_vector_nm_dump_compare(vector, first, second);
		
		first.push_back(3);
		_vector_nm_dump_compare(vector, first, second);
		
		second.push_back(4);
		_vector_nm_dump_compare(vector, first, second);
		
		second.push_back(5);
		_vector_nm_dump_compare(vector, first, second);
	}

	{
		container first;
		container second;
		
		_vector_nm_dump_compare(vector, second, first);

		first.push_back(1);
		_vector_nm_dump_compare(vector, second, first);
		
		second.push_back(2);
		_vector_nm_dump_compare(vector, second, first);
		
		first.push_back(3);
		_vector_nm_dump_compare(vector, second, first);
		
		second.push_back(4);
		_vector_nm_dump_compare(vector, second, first);
		
		second.push_back(5);
		_vector_nm_dump_compare(vector, second, first);
	}

	return (0);
}

#endif