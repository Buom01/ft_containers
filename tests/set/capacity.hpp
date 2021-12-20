/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 18:10:05 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_CAPACITY_HPP
# define TESTS_SET_CAPACITY_HPP

# include <sstream>

template <class container>
int	set_capacity(container &set)
{
	typename container::size_type	maxsize1	= set.max_size();
	int								i			= 0;
	std::stringstream				key;

	set.insert(set_concat_pair("empty1", set.empty()));

	while (i < 10)
	{
		key << i;
		set.insert(set_concat_pair(key.str(), i));
		key.str(std::string());
		++i;
	}

	if (set.max_size() != maxsize1)
		return (1);

	if (maxsize1 < 128)
		return (2);
	
	set.insert(set_concat_pair("empty2", set.empty()));
	set.insert(set_concat_pair("size", set.size()));

	return (0);
}

#endif

