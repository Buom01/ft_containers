/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultrabasic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 17:28:42 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_UB_HPP
# define TESTS_SET_UB_HPP

template <class container>
int	set_ub_insert(container &set)
{
	set.insert("test");

	return (0);
}

#endif