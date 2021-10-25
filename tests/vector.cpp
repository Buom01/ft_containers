/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:03:56 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 13:49:53 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_CPP
# define TESTS_VECTOR_CPP

#include "tests.hpp"
#include "vector/members.hpp"
#include "vector/access.hpp"
#include "vector/iterator.hpp"
#include "vector/capacity.hpp"
#include "vector/modifiers.hpp"
#include "vector/nonmember.hpp"

void	vector_members(std::string selection)
{
	test(
		vector_memberstypes_1< std::vector<E> >,
		vector_memberstypes_1< ft::vector<E> >,
		"vector_memberstypes_1",
		selection
	);

	test(
		vector_memberstypes_2< std::vector<E> >,
		vector_memberstypes_2< ft::vector<E> >,
		"vector_memberstypes_2",
		selection
	);

	test(
		vector_contructors< std::vector<E> >,
		vector_contructors< ft::vector<E> >,
		"vector_contructors",
		selection
	);

	test(
		vector_equal< std::vector<E> >,
		vector_equal< ft::vector<E> >,
		"vector_equal",
		selection
	);
	
	test(
		vector_assign_1< std::vector<E> >,
		vector_assign_1< ft::vector<E> >,
		"vector_assign_1",
		selection
	);
	
	test(
		vector_assign_2< std::vector<E> >,
		vector_assign_2< ft::vector<E> >,
		"vector_assign_2",
		selection
	);
	
	test(
		vector_assign_3< std::vector<E> >,
		vector_assign_3< ft::vector<E> >,
		"vector_assign_3",
		selection
	);
	
	test(
		vector_assign_4< std::vector<E> >,
		vector_assign_4< ft::vector<E> >,
		"vector_assign_4",
		selection
	);
	
	test(
		vector_assign_5< std::vector<E> >,
		vector_assign_5< ft::vector<E> >,
		"vector_assign_5",
		selection
	);
	
	test(
		vector_assign_6< std::vector<E> >,
		vector_assign_6< ft::vector<E> >,
		"vector_assign_6",
		selection
	);
}
void	vector_access(std::string selection)
{
	test(
		vector_access_1< std::vector<E> >,
		vector_access_1< ft::vector<E> >,
		"vector_access_1",
		selection
	);

	test(
		vector_access_2< std::vector<E> >,
		vector_access_2< ft::vector<E> >,
		"vector_access_2",
		selection
	);

	test(
		vector_access_3< std::vector<E> >,
		vector_access_3< ft::vector<E> >,
		"vector_access_3",
		selection
	);

	test(
		vector_access_4< std::vector<E> >,
		vector_access_4< ft::vector<E> >,
		"vector_access_4",
		selection
	);

	test(
		vector_access_5< std::vector<E> >,
		vector_access_5< ft::vector<E> >,
		"vector_access_5",
		selection
	);
}

void	vector_iterator(std::string selection)
{
	test(
		vector_iterator_1< std::vector<E>, std::vector<E>::iterator >,
		vector_iterator_1< ft::vector<E>, ft::vector<E>::iterator >,
		"vector_iterator_1",
		selection
	);

	test(
		vector_iterator_1< std::vector<E>, std::vector<E>::const_iterator >,
		vector_iterator_1< ft::vector<E>, ft::vector<E>::const_iterator >,
		"vector_iterator_1_const",
		selection
	);

	test(
		vector_iterator_2< std::vector<E>, std::vector<E>::iterator >,
		vector_iterator_2< ft::vector<E>, ft::vector<E>::iterator >,
		"vector_iterator_2",
		selection
	);

	test(
		vector_iterator_2< std::vector<E>, std::vector<E>::const_iterator >,
		vector_iterator_2< ft::vector<E>, ft::vector<E>::const_iterator >,
		"vector_iterator_2_const",
		selection
	);

	test(
		vector_reverse_iterator_1< std::vector<E>, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_1< ft::vector<E>, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_1",
		selection
	);

	test(
		vector_reverse_iterator_1< std::vector<E>, std::vector<E>::const_reverse_iterator >,
		vector_reverse_iterator_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator >,
		"vector_reverse_iterator_1",
		selection
	);

	test(
		vector_reverse_iterator_2< std::vector<E>, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_2< ft::vector<E>, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_2",
		selection
	);

	test(
		vector_reverse_iterator_2< std::vector<E>, std::vector<E>::const_reverse_iterator >,
		vector_reverse_iterator_2< ft::vector<E>, ft::vector<E>::const_reverse_iterator >,
		"vector_reverse_iterator_2",
		selection
	);

	test(
		vector_iterator_contructor_eq_deref< std::vector<E>, std::vector<E>::iterator , std::vector<E>::iterator , std::vector<E>::const_iterator >,
		vector_iterator_contructor_eq_deref< ft::vector<E>, ft::vector<E>::iterator , ft::vector<E>::iterator , ft::vector<E>::const_iterator >,
		"vector_iterator_contructor_eq_deref",
		selection
	);

	test(
		vector_iterator_contructor_eq_deref_reverse< std::vector<E>, std::vector<E>::reverse_iterator , std::vector<E>::reverse_iterator , std::vector<E>::const_reverse_iterator >,
		vector_iterator_contructor_eq_deref_reverse< ft::vector<E>, ft::vector<E>::reverse_iterator , ft::vector<E>::reverse_iterator , ft::vector<E>::const_reverse_iterator >,
		"vector_iterator_contructor_eq_deref_reverse",
		selection
	);

	test(
		vector_iterator_operator_diff_1< std::vector<E>, std::vector<E>::iterator, std::vector<E>::iterator >,
		vector_iterator_operator_diff_1< ft::vector<E>, ft::vector<E>::iterator, ft::vector<E>::iterator >,
		"vector_iterator_operator_diff_1",
		selection
	);
	
	test(
		vector_iterator_operator_diff_1< std::vector<E>, std::vector<E>::const_iterator, std::vector<E>::const_iterator >,
		vector_iterator_operator_diff_1< ft::vector<E>, ft::vector<E>::const_iterator, ft::vector<E>::const_iterator >,
		"vector_iterator_operator_diff_1_const",
		selection
	);
	
	test(
		vector_iterator_operator_diff_1< std::vector<E>, std::vector<E>::const_iterator, std::vector<E>::iterator >,
		vector_iterator_operator_diff_1< ft::vector<E>, ft::vector<E>::const_iterator, ft::vector<E>::iterator >,
		"vector_iterator_operator_diff_1_mixed_1",
		selection
	);
	
	test(
		vector_iterator_operator_diff_1< std::vector<E>, std::vector<E>::iterator, std::vector<E>::const_iterator >,
		vector_iterator_operator_diff_1< ft::vector<E>, ft::vector<E>::iterator, ft::vector<E>::const_iterator >,
		"vector_iterator_operator_diff_1_mixed_2",
		selection
	);

	test(
		vector_iterator_operator_diff_reverse_1< std::vector<E>, std::vector<E>::reverse_iterator, std::vector<E>::reverse_iterator >,
		vector_iterator_operator_diff_reverse_1< ft::vector<E>, ft::vector<E>::reverse_iterator, ft::vector<E>::reverse_iterator >,
		"vector_iterator_operator_diff_reverse_1",
		selection
	);
	
	test(
		vector_iterator_operator_diff_reverse_1< std::vector<E>, std::vector<E>::const_reverse_iterator, std::vector<E>::const_reverse_iterator >,
		vector_iterator_operator_diff_reverse_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator, ft::vector<E>::const_reverse_iterator >,
		"vector_iterator_operator_diff_reverse_1_const",
		selection
	);
	
	test(
		vector_iterator_operator_diff_reverse_1< std::vector<E>, std::vector<E>::const_reverse_iterator, std::vector<E>::reverse_iterator >,
		vector_iterator_operator_diff_reverse_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator, ft::vector<E>::reverse_iterator >,
		"vector_iterator_operator_diff_reverse_1_mixed_1",
		selection
	);
	
	test(
		vector_iterator_operator_diff_reverse_1< std::vector<E>, std::vector<E>::reverse_iterator, std::vector<E>::const_reverse_iterator >,
		vector_iterator_operator_diff_reverse_1< ft::vector<E>, ft::vector<E>::reverse_iterator, ft::vector<E>::const_reverse_iterator >,
		"vector_iterator_operator_diff_reverse_1_mixed_2",
		selection
	);

	test(
		vector_iterator_operator_sum_diff_1< std::vector<E>, std::vector<E>::iterator >,
		vector_iterator_operator_sum_diff_1< ft::vector<E>, ft::vector<E>::iterator >,
		"vector_iterator_operator_sum_diff_1",
		selection
	);

	test(
		vector_iterator_operator_sum_diff_1< std::vector<E>, std::vector<E>::const_iterator >,
		vector_iterator_operator_sum_diff_1< ft::vector<E>, ft::vector<E>::const_iterator >,
		"vector_iterator_operator_sum_diff_1_const",
		selection
	);

	test(
		vector_reverse_iterator_operator_sum_diff_1< std::vector<E>, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_operator_sum_diff_1< ft::vector<E>, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_operator_sum_diff_1",
		selection
	);

	test(
		vector_reverse_iterator_operator_sum_diff_1< std::vector<E>, std::vector<E>::const_reverse_iterator >,
		vector_reverse_iterator_operator_sum_diff_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator >,
		"vector_reverse_iterator_operator_sum_diff_1_const",
		selection
	);

	test(
		vector_iterator_operator_compare_1< std::vector<E>, std::vector<E>::iterator, std::vector<E>::iterator >,
		vector_iterator_operator_compare_1< ft::vector<E>, ft::vector<E>::iterator, ft::vector<E>::iterator >,
		"vector_iterator_operator_compare_1",
		selection
	);
	
	test(
		vector_iterator_operator_compare_1< std::vector<E>, std::vector<E>::const_iterator, std::vector<E>::const_iterator >,
		vector_iterator_operator_compare_1< ft::vector<E>, ft::vector<E>::const_iterator, ft::vector<E>::const_iterator >,
		"vector_iterator_operator_compare_1_const",
		selection
	);
	
	test(
		vector_iterator_operator_compare_1< std::vector<E>, std::vector<E>::const_iterator, std::vector<E>::iterator >,
		vector_iterator_operator_compare_1< ft::vector<E>, ft::vector<E>::const_iterator, ft::vector<E>::iterator >,
		"vector_iterator_operator_compare_1_mixed",
		selection
	);

	test(
		vector_reverse_iterator_operator_compare_1< std::vector<E>, std::vector<E>::reverse_iterator, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_operator_compare_1< ft::vector<E>, ft::vector<E>::reverse_iterator, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_operator_compare_1",
		selection
	);
	
	test(
		vector_reverse_iterator_operator_compare_1< std::vector<E>, std::vector<E>::const_reverse_iterator, std::vector<E>::const_reverse_iterator >,
		vector_reverse_iterator_operator_compare_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator, ft::vector<E>::const_reverse_iterator >,
		"vector_reverse_iterator_operator_compare_1_const",
		selection
	);
	
	test(
		vector_reverse_iterator_operator_compare_1< std::vector<E>, std::vector<E>::const_reverse_iterator, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_operator_compare_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_operator_compare_1_mixed",
		selection
	);

	test(
		vector_iterator_operator_equal_add_del_1< std::vector<E>, std::vector<E>::iterator >,
		vector_iterator_operator_equal_add_del_1< ft::vector<E>, ft::vector<E>::iterator >,
		"vector_iterator_operator_equal_add_del_1",
		selection
	);

	test(
		vector_iterator_operator_equal_add_del_1< std::vector<E>, std::vector<E>::const_iterator >,
		vector_iterator_operator_equal_add_del_1< ft::vector<E>, ft::vector<E>::const_iterator >,
		"vector_iterator_operator_equal_add_del_1_const",
		selection
	);

	test(
		vector_reverse_iterator_operator_equal_add_del_1< std::vector<E>, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_operator_equal_add_del_1< ft::vector<E>, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_operator_equal_add_del_1",
		selection
	);

	test(
		vector_reverse_iterator_operator_equal_add_del_1< std::vector<E>, std::vector<E>::const_reverse_iterator >,
		vector_reverse_iterator_operator_equal_add_del_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator >,
		"vector_reverse_iterator_operator_equal_add_del_1_const",
		selection
	);

	test(
		vector_reverse_iterator_operator_equal_with_iterator< std::vector<E>, std::vector<E>::reverse_iterator, std::vector<E>::iterator >,
		vector_reverse_iterator_operator_equal_with_iterator< ft::vector<E>, ft::vector<E>::reverse_iterator, ft::vector<E>::iterator >,
		"vector_reverse_iterator_operator_equal_with_iterator",
		selection
	);

	test(
		vector_iterator_operator_brackets_1< std::vector<E>, std::vector<E>::iterator >,
		vector_iterator_operator_brackets_1< ft::vector<E>, ft::vector<E>::iterator >,
		"vector_iterator_operator_brackets_1",
		selection
	);
	
	test(
		vector_iterator_operator_brackets_1< std::vector<E>, std::vector<E>::const_iterator >,
		vector_iterator_operator_brackets_1< ft::vector<E>, ft::vector<E>::const_iterator >,
		"vector_iterator_operator_brackets_1_const",
		selection
	);

	test(
		vector_reverse_iterator_operator_brackets_1< std::vector<E>, std::vector<E>::reverse_iterator >,
		vector_reverse_iterator_operator_brackets_1< ft::vector<E>, ft::vector<E>::reverse_iterator >,
		"vector_reverse_iterator_operator_brackets_1",
		selection
	);
	
	test(
		vector_reverse_iterator_operator_brackets_1< std::vector<E>, std::vector<E>::const_reverse_iterator >,
		vector_reverse_iterator_operator_brackets_1< ft::vector<E>, ft::vector<E>::const_reverse_iterator >,
		"vector_reverse_iterator_operator_brackets_1_const",
		selection
	);
}

/*
** empty() and size() members are both
** tested along other tests
*/
void	vector_capacity(std::string selection)
{
	test(
		vector_capacity_maxsize< std::vector<E> >,
		vector_capacity_maxsize< ft::vector<E> >,
		"vector_capacity_maxsize",
		selection
	);

	test(
		vector_capacity_reservecapacity< std::vector<E> >,
		vector_capacity_reservecapacity< ft::vector<E> >,
		"vector_capacity_reservecapacity",
		selection
	);
}

void	vector_modifiers(std::string selection)
{
	test(
		vector_push_back< std::vector<E> >,
		vector_push_back< ft::vector<E> >,
		"vector_push_back",
		selection
	);
	
	test(
		vector_pop_back< std::vector<E> >,
		vector_pop_back< ft::vector<E> >,
		"vector_pop_back",
		selection
	);
	
	test(
		vector_clear< std::vector<E> >,
		vector_clear< ft::vector<E> >,
		"vector_clear",
		selection
	);
	
	test(
		vector_swap< std::vector<E> >,
		vector_swap< ft::vector<E> >,
		"vector_swap",
		selection
	);
	
	test(
		vector_erase< std::vector<E> >,
		vector_erase< ft::vector<E> >,
		"vector_erase",
		selection
	);
	
	test(
		vector_insert_1< std::vector<E> >,
		vector_insert_1< ft::vector<E> >,
		"vector_insert_1",
		selection
	);
	
	test(
		vector_insert_2< std::vector<E> >,
		vector_insert_2< ft::vector<E> >,
		"vector_insert_2",
		selection
	);
	
	test(
		vector_insert_3< std::vector<E> >,
		vector_insert_3< ft::vector<E> >,
		"vector_insert_3",
		selection
	);
	
	test(
		vector_resize_1< std::vector<E> >,
		vector_resize_1< ft::vector<E> >,
		"vector_resize_1",
		selection
	);
	
	test(
		vector_resize_2< std::vector<E> >,
		vector_resize_2< ft::vector<E> >,
		"vector_resize_2",
		selection
	);
	
	test(
		vector_resize_3< std::vector<E> >,
		vector_resize_3< ft::vector<E> >,
		"vector_resize_3",
		selection
	);
	
	test(
		vector_resize_4< std::vector<E> >,
		vector_resize_4< ft::vector<E> >,
		"vector_resize_4",
		selection
	);
	
	test(
		vector_resize_5< std::vector<E> >,
		vector_resize_5< ft::vector<E> >,
		"vector_resize_5",
		selection
	);
}

void	vector_nonmemeber(std::string selection)
{
	test(
		vector_nm_std_swap< std::vector<E> >,
		vector_nm_ft_swap< ft::vector<E> >,
		"vector_nm_swap",
		selection
	);

	test(
		vector_nm_equal_not_equal< std::vector<E> >,
		vector_nm_equal_not_equal< ft::vector<E> >,
		"vector_nm_equal_not_equal",
		selection
	);

	test(
		vector_nm_compare< std::vector<E> >,
		vector_nm_compare< ft::vector<E> >,
		"vector_nm_compare",
		selection
	);

	// should do supplementary test with string
}

void	vector_tests(std::string selection)
{
	// SHOULD TEST TIME !

	vector_members(selection);
	vector_access(selection); 
	vector_iterator(selection);
	vector_capacity(selection);
	vector_modifiers(selection);
	vector_nonmemeber(selection);
}

#endif
