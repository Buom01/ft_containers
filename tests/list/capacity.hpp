/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:47:24 by badam             #+#    #+#             */
/*   Updated: 2021/05/20 08:36:32 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class container>
bool	list_capacity(container &list)
{
	if (list.size() != 0 || !list.empty())
		return (false);
	if (list.max_size() < 200*1024*1024 / sizeof(E))
		return (false);

	list.push_back(0);
	if (list.size() != 1 || list.empty())
		return (false);

	list.clear();
	if (list.size() != 0 || !list.empty())
		return (false);

	list.push_back(0);
	list.push_back(0);
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	if (list.size() != 6 || list.empty())
		return (false);

	return (true);
}
