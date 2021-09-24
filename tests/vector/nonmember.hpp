/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonmember.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/09/24 14:04:01 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_NONMEMBER_HPP
# define TESTS_VECTOR_NONMEMBER_HPP

template <class container>
int	vector_nm_equal(container &vector)
{
	container	vector1;

	if (!(vector == vector1))
		return (1);

	vector.push_back(1);

	if (vector == vector1)
		return (2);

	vector1.push_back(1);

	if (!(vector == vector1))
		return (3);

	vector1.push_back(2);

	if (vector == vector1)
		return (4);

	vector.push_back(2);

	if (!(vector == vector1))
		return (5);



	vector1.push_back(3);

	if (vector == vector1)
		return (6);

	vector.push_back(3);

	if (!(vector == vector1))
		return (7);

	vector.push_back(4);

	if (vector == vector1)
		return (8);

	vector1.push_back(4);

	if (!(vector == vector1))
		return (9);

	
	vector.clear();
	vector1.clear();

	if (!(vector == vector1))
		return (10);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector1.push_back(0);
	vector1.push_back(2);
	vector1.push_back(3);

	if (vector == vector1)
		return (11);

	vector.clear();
	vector1.clear();

	if (!(vector == vector1))
		return (12);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(4);

	if (vector == vector1)
		return (13);

	vector.clear();
	vector1.clear();

	if (!(vector == vector1))
		return (14);


	return (0);
}


// other non-memeber to do

#endif