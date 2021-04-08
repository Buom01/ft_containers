/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:27 by badam             #+#    #+#             */
/*   Updated: 2021/04/08 03:52:26 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "List.hpp"

int	main(void)
{
	{
		list<int>	myList;
		myList.push_front(10);
	}

	{
		list<int>	mySecList;

		mySecList.push_front(0);
		mySecList.push_front(22021);
		mySecList.push_back(3466);

		list<int>::iterator it	= mySecList.begin();
		while (it != mySecList.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}

