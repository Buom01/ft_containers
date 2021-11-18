/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultrabasic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/11/18 13:32:32 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_UB_HPP
# define TESTS_MAP_UB_HPP

template <class container>
int	map_ub_insert(container &map)
{
	typename container::value_type	basic_pair(std::string("test"), 1);

	map.insert(basic_pair);

	return (0);
}

template <class container>
int	map_ub_std_insert1(container &map)
{ 
	map.insert(std::make_pair(std::string("test"), 1));

	return (0);
}

template <class container>
int	map_ub_ft_insert1(container &map)
{
	map.insert(ft::make_pair(std::string("test"), 1));

	return (0);
}

#endif