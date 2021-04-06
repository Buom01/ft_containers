/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:27 by badam             #+#    #+#             */
/*   Updated: 2021/03/31 02:19:39 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "List.hpp"

int	main(void)
{
	{
		List<int>	myList;
		myList.push_front(10);
	}

	{
		List<int>	mySecList;

		mySecList.push_front(0);
		mySecList.push_front(22021);
		mySecList.push_back(3466);

		List<int>::iterator it	= mySecList.begin();
		while (it != mySecList.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}

