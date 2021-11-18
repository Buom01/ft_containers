/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/11/18 13:31:57 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_CPP
# define TESTS_MAP_CPP

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

#include "tests.hpp"
#include "map/ultrabasic.hpp"
#include "map/members.hpp"
#include "map/access.hpp"
#include "map/iterator.hpp"
#include "map/capacity.hpp"
#include "map/modifiers.hpp"
#include "map/nonmember.hpp"


void	map_members(std::string selection)
{
	test(
		map_memberstypes_1< std::map<std::string, E> >,
		map_memberstypes_1< ft::map<std::string, E> >,
		"map_memberstypes_1",
		selection
	);

	test(
		map_contructors_1< std::map<std::string, E>, std::pair<std::string, E> >,
		map_contructors_1< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_contructors_1",
		selection
	);

	test(
		map_contructors_2< std::map<std::string, E, cmpByStringLength>, std::pair<std::string, E> >,
		map_contructors_2< ft::map<std::string, E, cmpByStringLength>, ft::pair<std::string, E> >,
		"map_contructors_2",
		selection
	);

	test(
		map_equal< std::map<std::string, E>, std::pair<std::string, E> >,
		map_equal< ft::map<std::string, E>, ft::pair<std::string, E> >,
		"map_equal",
		selection
	);
}

void	map_access(std::string selection)
{
	test(
		map_access_1< std::map<std::string, E> >,
		map_access_1< ft::map<std::string, E> >,
		"map_access_1",
		selection
	);

	test(
		map_access_2< std::map<std::string, E> >,
		map_access_2< ft::map<std::string, E> >,
		"map_access_2",
		selection
	);

// 	test(
// 		map_access_3< std::map<std::string, E>, std::pair<std::string, E> >,
// 		map_access_3< ft::map<std::string, E>, ft::pair<std::string, E> >,
// 		"map_access_3",
// 		selection
// 	);

// 	test(
// 		map_access_4< std::map<std::string, E>, std::pair<std::string, E> >,
// 		map_access_4< ft::map<std::string, E>, ft::pair<std::string, E> >,
// 		"map_access_4",
// 		selection
// 	);

// 	test(
// 		map_access_5< std::map<std::string, E>, std::pair<std::string, E> >,
// 		map_access_5< ft::map<std::string, E>, ft::pair<std::string, E> >,
// 		"map_access_5",
// 		selection
// 	);
}

// void	map_iterator(std::string selection)
// {
// 	test(
// 		map_iterator_1< std::map<E>, std::map<E>::iterator >,
// 		map_iterator_1< ft::map<E>, ft::map<E>::iterator >,
// 		"map_iterator_1",
// 		selection
// 	);

// 	test(
// 		map_iterator_1< std::map<E>, std::map<E>::const_iterator >,
// 		map_iterator_1< ft::map<E>, ft::map<E>::const_iterator >,
// 		"map_iterator_1_const",
// 		selection
// 	);

// 	test(
// 		map_iterator_2< std::map<E>, std::map<E>::iterator >,
// 		map_iterator_2< ft::map<E>, ft::map<E>::iterator >,
// 		"map_iterator_2",
// 		selection
// 	);

// 	test(
// 		map_iterator_2< std::map<E>, std::map<E>::const_iterator >,
// 		map_iterator_2< ft::map<E>, ft::map<E>::const_iterator >,
// 		"map_iterator_2_const",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_1< std::map<E>, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_1< ft::map<E>, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_1",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_1< std::map<E>, std::map<E>::const_reverse_iterator >,
// 		map_reverse_iterator_1< ft::map<E>, ft::map<E>::const_reverse_iterator >,
// 		"map_reverse_iterator_1",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_2< std::map<E>, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_2< ft::map<E>, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_2",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_2< std::map<E>, std::map<E>::const_reverse_iterator >,
// 		map_reverse_iterator_2< ft::map<E>, ft::map<E>::const_reverse_iterator >,
// 		"map_reverse_iterator_2",
// 		selection
// 	);

// 	test(
// 		map_iterator_contructor_eq_deref< std::map<E>, std::map<E>::iterator , std::map<E>::iterator , std::map<E>::const_iterator >,
// 		map_iterator_contructor_eq_deref< ft::map<E>, ft::map<E>::iterator , ft::map<E>::iterator , ft::map<E>::const_iterator >,
// 		"map_iterator_contructor_eq_deref",
// 		selection
// 	);

// 	test(
// 		map_iterator_contructor_eq_deref_reverse< std::map<E>, std::map<E>::reverse_iterator , std::map<E>::reverse_iterator , std::map<E>::const_reverse_iterator >,
// 		map_iterator_contructor_eq_deref_reverse< ft::map<E>, ft::map<E>::reverse_iterator , ft::map<E>::reverse_iterator , ft::map<E>::const_reverse_iterator >,
// 		"map_iterator_contructor_eq_deref_reverse",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_diff_1< std::map<E>, std::map<E>::iterator, std::map<E>::iterator >,
// 		map_iterator_operator_diff_1< ft::map<E>, ft::map<E>::iterator, ft::map<E>::iterator >,
// 		"map_iterator_operator_diff_1",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_diff_1< std::map<E>, std::map<E>::const_iterator, std::map<E>::const_iterator >,
// 		map_iterator_operator_diff_1< ft::map<E>, ft::map<E>::const_iterator, ft::map<E>::const_iterator >,
// 		"map_iterator_operator_diff_1_const",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_diff_1< std::map<E>, std::map<E>::const_iterator, std::map<E>::iterator >,
// 		map_iterator_operator_diff_1< ft::map<E>, ft::map<E>::const_iterator, ft::map<E>::iterator >,
// 		"map_iterator_operator_diff_1_mixed_1",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_diff_1< std::map<E>, std::map<E>::iterator, std::map<E>::const_iterator >,
// 		map_iterator_operator_diff_1< ft::map<E>, ft::map<E>::iterator, ft::map<E>::const_iterator >,
// 		"map_iterator_operator_diff_1_mixed_2",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_diff_reverse_1< std::map<E>, std::map<E>::reverse_iterator, std::map<E>::reverse_iterator >,
// 		map_iterator_operator_diff_reverse_1< ft::map<E>, ft::map<E>::reverse_iterator, ft::map<E>::reverse_iterator >,
// 		"map_iterator_operator_diff_reverse_1",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_diff_reverse_1< std::map<E>, std::map<E>::const_reverse_iterator, std::map<E>::const_reverse_iterator >,
// 		map_iterator_operator_diff_reverse_1< ft::map<E>, ft::map<E>::const_reverse_iterator, ft::map<E>::const_reverse_iterator >,
// 		"map_iterator_operator_diff_reverse_1_const",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_diff_reverse_1< std::map<E>, std::map<E>::const_reverse_iterator, std::map<E>::reverse_iterator >,
// 		map_iterator_operator_diff_reverse_1< ft::map<E>, ft::map<E>::const_reverse_iterator, ft::map<E>::reverse_iterator >,
// 		"map_iterator_operator_diff_reverse_1_mixed_1",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_diff_reverse_1< std::map<E>, std::map<E>::reverse_iterator, std::map<E>::const_reverse_iterator >,
// 		map_iterator_operator_diff_reverse_1< ft::map<E>, ft::map<E>::reverse_iterator, ft::map<E>::const_reverse_iterator >,
// 		"map_iterator_operator_diff_reverse_1_mixed_2",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_sum_diff_1< std::map<E>, std::map<E>::iterator >,
// 		map_iterator_operator_sum_diff_1< ft::map<E>, ft::map<E>::iterator >,
// 		"map_iterator_operator_sum_diff_1",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_sum_diff_1< std::map<E>, std::map<E>::const_iterator >,
// 		map_iterator_operator_sum_diff_1< ft::map<E>, ft::map<E>::const_iterator >,
// 		"map_iterator_operator_sum_diff_1_const",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_sum_diff_1< std::map<E>, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_operator_sum_diff_1< ft::map<E>, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_operator_sum_diff_1",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_sum_diff_1< std::map<E>, std::map<E>::const_reverse_iterator >,
// 		map_reverse_iterator_operator_sum_diff_1< ft::map<E>, ft::map<E>::const_reverse_iterator >,
// 		"map_reverse_iterator_operator_sum_diff_1_const",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_compare_1< std::map<E>, std::map<E>::iterator, std::map<E>::iterator >,
// 		map_iterator_operator_compare_1< ft::map<E>, ft::map<E>::iterator, ft::map<E>::iterator >,
// 		"map_iterator_operator_compare_1",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_compare_1< std::map<E>, std::map<E>::const_iterator, std::map<E>::const_iterator >,
// 		map_iterator_operator_compare_1< ft::map<E>, ft::map<E>::const_iterator, ft::map<E>::const_iterator >,
// 		"map_iterator_operator_compare_1_const",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_compare_1< std::map<E>, std::map<E>::const_iterator, std::map<E>::iterator >,
// 		map_iterator_operator_compare_1< ft::map<E>, ft::map<E>::const_iterator, ft::map<E>::iterator >,
// 		"map_iterator_operator_compare_1_mixed",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_compare_1< std::map<E>, std::map<E>::reverse_iterator, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_operator_compare_1< ft::map<E>, ft::map<E>::reverse_iterator, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_operator_compare_1",
// 		selection
// 	);
	
// 	test(
// 		map_reverse_iterator_operator_compare_1< std::map<E>, std::map<E>::const_reverse_iterator, std::map<E>::const_reverse_iterator >,
// 		map_reverse_iterator_operator_compare_1< ft::map<E>, ft::map<E>::const_reverse_iterator, ft::map<E>::const_reverse_iterator >,
// 		"map_reverse_iterator_operator_compare_1_const",
// 		selection
// 	);
	
// 	test(
// 		map_reverse_iterator_operator_compare_1< std::map<E>, std::map<E>::const_reverse_iterator, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_operator_compare_1< ft::map<E>, ft::map<E>::const_reverse_iterator, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_operator_compare_1_mixed",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_equal_add_del_1< std::map<E>, std::map<E>::iterator >,
// 		map_iterator_operator_equal_add_del_1< ft::map<E>, ft::map<E>::iterator >,
// 		"map_iterator_operator_equal_add_del_1",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_equal_add_del_1< std::map<E>, std::map<E>::const_iterator >,
// 		map_iterator_operator_equal_add_del_1< ft::map<E>, ft::map<E>::const_iterator >,
// 		"map_iterator_operator_equal_add_del_1_const",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_equal_add_del_1< std::map<E>, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_operator_equal_add_del_1< ft::map<E>, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_operator_equal_add_del_1",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_equal_add_del_1< std::map<E>, std::map<E>::const_reverse_iterator >,
// 		map_reverse_iterator_operator_equal_add_del_1< ft::map<E>, ft::map<E>::const_reverse_iterator >,
// 		"map_reverse_iterator_operator_equal_add_del_1_const",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_equal_with_iterator< std::map<E>, std::map<E>::reverse_iterator, std::map<E>::iterator >,
// 		map_reverse_iterator_operator_equal_with_iterator< ft::map<E>, ft::map<E>::reverse_iterator, ft::map<E>::iterator >,
// 		"map_reverse_iterator_operator_equal_with_iterator",
// 		selection
// 	);

// 	test(
// 		map_iterator_operator_brackets_1< std::map<E>, std::map<E>::iterator >,
// 		map_iterator_operator_brackets_1< ft::map<E>, ft::map<E>::iterator >,
// 		"map_iterator_operator_brackets_1",
// 		selection
// 	);
	
// 	test(
// 		map_iterator_operator_brackets_1< std::map<E>, std::map<E>::const_iterator >,
// 		map_iterator_operator_brackets_1< ft::map<E>, ft::map<E>::const_iterator >,
// 		"map_iterator_operator_brackets_1_const",
// 		selection
// 	);

// 	test(
// 		map_reverse_iterator_operator_brackets_1< std::map<E>, std::map<E>::reverse_iterator >,
// 		map_reverse_iterator_operator_brackets_1< ft::map<E>, ft::map<E>::reverse_iterator >,
// 		"map_reverse_iterator_operator_brackets_1",
// 		selection
// 	);
	
// 	test(
// 		map_reverse_iterator_operator_brackets_1< std::map<E>, std::map<E>::const_reverse_iterator >,
// 		map_reverse_iterator_operator_brackets_1< ft::map<E>, ft::map<E>::const_reverse_iterator >,
// 		"map_reverse_iterator_operator_brackets_1_const",
// 		selection
// 	);
// }

/*
** empty() and size() members are both
** tested along other tests
*/
// void	map_capacity(std::string selection)
// {
// 	test(
// 		map_capacity_maxsize< std::map<E> >,
// 		map_capacity_maxsize< ft::map<E> >,
// 		"map_capacity_maxsize",
// 		selection
// 	);

// 	test(
// 		map_capacity_reservecapacity< std::map<E> >,
// 		map_capacity_reservecapacity< ft::map<E> >,
// 		"map_capacity_reservecapacity",
// 		selection
// 	);
// }

// void	map_modifiers(std::string selection)
// {
// 	test(
// 		map_push_back< std::map<E> >,
// 		map_push_back< ft::map<E> >,
// 		"map_push_back",
// 		selection
// 	);
	
// 	test(
// 		map_pop_back< std::map<E> >,
// 		map_pop_back< ft::map<E> >,
// 		"map_pop_back",
// 		selection
// 	);
	
// 	test(
// 		map_clear< std::map<E> >,
// 		map_clear< ft::map<E> >,
// 		"map_clear",
// 		selection
// 	);
	
// 	test(
// 		map_swap< std::map<E> >,
// 		map_swap< ft::map<E> >,
// 		"map_swap",
// 		selection
// 	);
	
// 	test(
// 		map_erase< std::map<E> >,
// 		map_erase< ft::map<E> >,
// 		"map_erase",
// 		selection
// 	);
	
// 	test(
// 		map_insert_1< std::map<E> >,
// 		map_insert_1< ft::map<E> >,
// 		"map_insert_1",
// 		selection
// 	);
	
// 	test(
// 		map_insert_2< std::map<E> >,
// 		map_insert_2< ft::map<E> >,
// 		"map_insert_2",
// 		selection
// 	);
	
// 	test(
// 		map_insert_3< std::map<E> >,
// 		map_insert_3< ft::map<E> >,
// 		"map_insert_3",
// 		selection
// 	);
	
// 	test(
// 		map_resize_1< std::map<E> >,
// 		map_resize_1< ft::map<E> >,
// 		"map_resize_1",
// 		selection
// 	);
	
// 	test(
// 		map_resize_2< std::map<E> >,
// 		map_resize_2< ft::map<E> >,
// 		"map_resize_2",
// 		selection
// 	);
	
// 	test(
// 		map_resize_3< std::map<E> >,
// 		map_resize_3< ft::map<E> >,
// 		"map_resize_3",
// 		selection
// 	);
	
// 	test(
// 		map_resize_4< std::map<E> >,
// 		map_resize_4< ft::map<E> >,
// 		"map_resize_4",
// 		selection
// 	);
	
// 	test(
// 		map_resize_5< std::map<E> >,
// 		map_resize_5< ft::map<E> >,
// 		"map_resize_5",
// 		selection
// 	);
// }

// void	map_nonmemeber(std::string selection)
// {
// 	test(
// 		map_nm_std_swap< std::map<E> >,
// 		map_nm_ft_swap< ft::map<E> >,
// 		"map_nm_swap",
// 		selection
// 	);

// 	test(
// 		map_nm_equal_not_equal< std::map<E> >,
// 		map_nm_equal_not_equal< ft::map<E> >,
// 		"map_nm_equal_not_equal",
// 		selection
// 	);

// 	test(
// 		map_nm_compare< std::map<E> >,
// 		map_nm_compare< ft::map<E> >,
// 		"map_nm_compare",
// 		selection
// 	);

// 	// should do supplementary test with string
// }

void	map_ultrabasic(std::string selection)
{
	test(
		map_ub_insert< std::map<std::string, E> >,
		map_ub_insert< ft::map<std::string, E> >,
		"map_ub_insert",
		selection
	);

	test(
		map_ub_std_insert1< std::map<std::string, E> >,
		map_ub_ft_insert1< ft::map<std::string, E> >,
		"map_ub_insert1",
		selection
	);
}

void	map_tests(std::string selection)
{
	// SHOULD TEST TIME !

	map_ultrabasic(selection);

	map_members(selection);
	map_access(selection); 
	// map_iterator(selection);
	// map_capacity(selection);
	// map_modifiers(selection);
	// map_nonmemeber(selection);
}

#endif
