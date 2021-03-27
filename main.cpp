/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:27 by badam             #+#    #+#             */
/*   Updated: 2021/03/28 00:51:04 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

int	main(void)
{
	List<int>	myList;
	List<int>	mySecList;

	myList.push_front(10);
	mySecList.push_front(1);
	mySecList.push_front(10);
}

