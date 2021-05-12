/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:24:18 by user              #+#    #+#             */
/*   Updated: 2021/05/12 15:24:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
namespace tests
{


template <class container>
bool	list_push_frontback(container &list)
{
	list.push_front(2);
	list.push_front(1);
	list.push_back(3);
	list.push_back(4);

	return (true);
}

template <class container>
bool	list_pushpop_frontback(container &list)
{
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_back(3);
	list.push_back(4);
	list.push_back(4);

	list.pop_front();
	list.pop_back();

	return (true);
}

template <class container>
bool	list_clear(container &list)
{
	list.clear();

	list.push_back(3);
	list.push_back(4);

	list.clear();

	list.push_front(1);

	list.clear();

	return (true);
}

}
}
