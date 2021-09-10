/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/09/10 17:12:04 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MODIFIERS_HPP
# define VECTOR_MODIFIERS_HPP

template <class container>
int	vector_push_back(container &vector)
{
	vector.push_back(1);
	vector.push_back(2);

	if (vector.size() != 2)
		return (1);
	
	return (0);
}

template <class container>
int	vector_pop_back(container &vector)
{
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	vector.pop_back();
	vector.pop_back();
	vector.pop_back();

	vector.push_back(7);
	vector.push_back(8);
	vector.push_back(9);

	vector.pop_back();

	if (vector.size() != 2)
		return (1);
	
	return (0);
}

template <class container>
int	vector_clear(container &vector)
{
	vector.clear();

	if (vector.size() != 0)
		return (1);

	vector.push_back(3);
	vector.push_back(4);


	if (vector.size() != 2)
		return (2);

	vector.clear();

	if (vector.size() != 0)
		return (3);

	vector.push_back(1);

	if (vector.size() != 1)
		return (4);

	vector.clear();
	vector.clear();

	if (vector.size() != 0)
		return (5);
	
	return (0);
}

template <class container>
int	vector_swap(container &vector)
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

	vector3.swap(vector2);
	vector.swap(vector2);

	if (vector.size() != 3)
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
int	vector_erase(container &vector)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);

	ret = vector.erase(vector.begin(), vector.end());
	if (ret != vector.end())
		return (1);
	if (vector.size() != 0)
		return (2);

	vector.push_back(5);
	vector.push_back(6);

	ret = vector.erase(vector.begin());
	if (ret != vector.begin() || vector.size() != 1)
		return (3);
	ret = vector.erase(vector.begin());
	if (ret != vector.begin() || vector.size() != 0)
		return (4);

	vector.push_back(7);
	vector.push_back(8);

	pos = vector.end();
	--pos;

	ret = vector.erase(pos);
	if (ret != vector.end() || vector.size() != 1)
		return (5);
	ret = vector.erase(vector.begin());
	if (ret != vector.begin() || !vector.empty())
		return (6);

	vector.push_back(9);
	vector.push_back(10);
	vector.push_back(11);
	vector.push_back(12);

	pos = vector.end();
	--pos;

	ret = vector.erase(pos);
	if (ret != vector.end() || vector.size() != 3)
		return (7);
	ret = vector.erase(vector.begin());
	if (ret != vector.begin() || vector.size() != 2)
		return (8);

	return (0);
}

template <class container>
int	vector_insert_1(container &vector)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	ret = vector.insert(vector.begin(), 2);
	if (ret != vector.begin() || vector.size() != 1)
		return (1);

	ret = vector.insert(vector.end(), 4);
	std::advance(pos = vector.end(), -1);
	if (ret != pos || vector.size() != 2)
		return (2);
		
	ret = vector.insert(pos, 3);
	std::advance(pos = vector.begin(), 1);
	if (ret != pos || vector.size() != 3)
		return (3);


	ret = vector.insert(vector.end(), 7);
	std::advance(pos = vector.end(), -1);
	if (ret != pos || vector.size() != 4)
		return (4);

	ret = vector.insert(pos, 6);
	std::advance(pos = vector.end(), -2);
	if (ret != pos || vector.size() != 5)
		return (5);

	ret = vector.insert(pos, 5);
	std::advance(pos = vector.end(), -3);
	if (ret != pos || vector.size() != 6)
		return (6);


	ret = vector.insert(vector.begin(), 0);
	if (ret != vector.begin() || vector.size() != 7)
		return (7);

	std::advance(pos = vector.begin(), 1);
	ret = vector.insert(pos, 1);
	std::advance(pos = vector.begin(), 1);
	if (ret != pos || vector.size() != 8)
		return (8);
		
	ret = vector.insert(vector.end(), 8);
	std::advance(pos = vector.end(), -1);
	if (ret != pos || vector.size() != 9)
		return (9);

	return (0);
}

template <class container>
int		vector_insert_2(container &vector)
{
	typename container::iterator	pos;
	typename container::iterator	ret;

	vector.insert(vector.end(), 0u, 0);
	if (vector.size() != 0)
		return (1);

	vector.insert(vector.begin(), 0u, 0);
	if (vector.size() != 0)
		return (2);

	vector.insert(vector.end(), 1u, 1);
	if (vector.size() != 1)
		return (3);

	vector.insert(vector.end(), 2u, 3);
	if (vector.size() != 3)
		return (4);

	vector.insert(vector.begin(), 3u, 0);
	if (vector.size() != 6)
		return (5);

	std::advance(pos = vector.end(), -2);
	vector.insert(pos, 4u, 2);
	if (vector.size() != 10)
		return (6);

	return (0);
}

template <class container>
int		vector_insert_3(container &vector)
{
	typename container::iterator	pos;
	container						vector1;
	container						vector2;
	container						vector3;

	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector2.push_back(4);
	vector2.push_back(5);
	vector2.push_back(6);
	vector3.push_back(7);
	vector3.push_back(8);
	vector3.push_back(9);

	vector.insert(vector.end(), vector3.begin(), vector3.end());
	if (vector.size() != 3)
		return (1);

	vector.insert(vector.begin(), vector1.begin(), vector1.end());
	if (vector.size() != 6)
		return (2);

	std::advance(pos = vector.begin(), 3);
	vector.insert(pos, vector2.begin(), vector2.end());
	if (vector.size() != 9)
		return (3);

	return (0);
}

template <class container>
int		vector_resize_1(container &vector)
{
	vector.resize(0);
	if (vector.size() != 0)
		return (1);
	
	return (0);
}

template <class container>
int		vector_resize_2(container &vector)
{
	vector.push_back(1);
	vector.resize(7);
	vector.push_back(2);

	if (vector.size() != 8)
		return (1);
	
	return (0);
}

template <class container>
int		vector_resize_3(container &vector)
{
	vector.resize(1);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	vector.resize(10, 4);
	vector.resize(5);
	vector.resize(7, 5);
	vector.resize(6);
	vector.resize(7, 6);
	vector.resize(7, 10);

	vector.push_back(7);

	if (vector.size() != 8)
		return (1);
	
	return (0);
}

template <class container>
int		vector_resize_4(container &vector)
{
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	vector.resize(0);

	if (vector.size() != 0)
		return (1);
	
	return (0);
}

template <class container>
int		vector_resize_5(container &vector)
{
	vector.resize(0);
	vector.resize(1);
	vector.resize(100);
	vector.resize(1000);
	vector.resize(0);

	if (vector.size() != 0)
		return (1);
	
	return (0);
}

template <class container>
int		vector_assign_1(container &vector)
{
	vector.assign(0u, 0);
	if (vector.size() != 0)
		return (1);

	vector.assign(10u, 0);

	return (0);
}

template <class container>
int		vector_assign_2(container &vector)
{
	vector.push_back(2);

	vector.assign(10u, 1);

	if (vector.size() != 10)
		return (1);

	return (0);
}

template <class container>
int		vector_assign_3(container &vector)
{
	vector.push_back(2);

	vector.assign(10u, 1);
	if (vector.size() != 10)
		return (1);

	vector.assign(5u, 2);

	if (vector.size() != 5)
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
	if (vector.size() != 5)
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
	if (vector.size() != 0)
		return (1);

	return (0);
}

template <class container>
int		vector_assign_6(container &vector)
{
	container	vector2;

	vector.push_back(9);
	
	vector.assign(vector2.begin(), vector2.end());
	if (vector.size() != 0)
		return (1);

	return (0);
}

#endif

