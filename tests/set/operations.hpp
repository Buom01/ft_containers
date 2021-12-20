/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:26:33 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 18:24:05 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_OPERATIONS_HPP
# define TESTS_SET_OPERATIONS_HPP


template <class container>
int	set_find(container &set)
{
    container   set2;
    
    set2.insert("p");
	set2.insert("s");
	set2.insert("x");
	set2.insert("o");
	set2.insert("u");
	set2.insert("b");
	set2.insert("w");
	set2.insert("e");
	set2.insert("q");
	set2.insert("r");
	set2.insert("y");
	set2.insert("i");
	set2.insert("z");
	set2.insert("n");
	set2.insert("m");
	set2.insert("t");
	set2.insert("d");
	set2.insert("k");
	set2.insert("a");
	set2.insert("h");
	set2.insert("l");
	set2.insert("v");
	set2.insert("g");
	set2.insert("f");
	set2.insert("j");
	set2.insert("c");


    set.insert(*set2.find("a"));
    set.insert(*set2.find("b"));
    set.insert(*set2.find("c"));
    set.insert(*set2.find("d"));
    set.insert(*set2.find("e"));
    set.insert(*set2.find("f"));
    set.insert(*set2.find("g"));
    set.insert(*set2.find("h"));
    set.insert(*set2.find("i"));
    set.insert(*set2.find("j"));
    set.insert(*set2.find("k"));
    set.insert(*set2.find("l"));
    set.insert(*set2.find("m"));
    set.insert(*set2.find("n"));
    set.insert(*set2.find("o"));
    set.insert(*set2.find("p"));
    set.insert(*set2.find("q"));
    set.insert(*set2.find("r"));

    set.insert(*set2.find("z"));
    set.insert(*set2.find("y"));
    set.insert(*set2.find("x"));

	return (0);
}

template <class container>
int	set_count(container &set)
{
    container   set2;
    
    set2.insert("b");
    set2.insert("b");
    set2.insert("b");
    set2.insert("b");
    set2.insert("c");
    set2.insert("d");
    set2.insert("e");
    set2.insert("e");


    set.insert(set_concat_pair("a", set2.count("a")));
    set.insert(set_concat_pair("b", set2.count("b")));
    set.insert(set_concat_pair("c", set2.count("c")));
    set.insert(set_concat_pair("d", set2.count("d")));
    set.insert(set_concat_pair("e", set2.count("e")));
    set.insert(set_concat_pair("f", set2.count("f")));

	return (0);
}


template <class container>
static void    set_insert_lowerbound(std::string key, container &set, container &set2)
{
    typename container::iterator  it  = set2.lower_bound(key);
    
    if (it != set2.end())
        set.insert(set_concat_pair(key, *it));
    else
        set.insert(set_concat_pair(key, "end"));
}

template <class container>
int	set_lowerbound(container &set)
{
    container   set2;
    
    set2.insert("p");
	set2.insert("s");
	set2.insert("x");
	set2.insert("o");
	set2.insert("u");
	set2.insert("b");
	set2.insert("w");
	set2.insert("e");
	set2.insert("q");


    set_insert_lowerbound<container>("a", set, set2);
    set_insert_lowerbound<container>("b", set, set2);
    set_insert_lowerbound<container>("c", set, set2);
    set_insert_lowerbound<container>("d", set, set2);
    set_insert_lowerbound<container>("e", set, set2);
    set_insert_lowerbound<container>("f", set, set2);
    set_insert_lowerbound<container>("g", set, set2);
    set_insert_lowerbound<container>("h", set, set2);
    set_insert_lowerbound<container>("i", set, set2);
    set_insert_lowerbound<container>("j", set, set2);
    set_insert_lowerbound<container>("k", set, set2);
    set_insert_lowerbound<container>("l", set, set2);
    set_insert_lowerbound<container>("m", set, set2);
    set_insert_lowerbound<container>("n", set, set2);
    set_insert_lowerbound<container>("o", set, set2);
    set_insert_lowerbound<container>("p", set, set2);
    set_insert_lowerbound<container>("q", set, set2);
    set_insert_lowerbound<container>("r", set, set2);
    set_insert_lowerbound<container>("s", set, set2);
    set_insert_lowerbound<container>("t", set, set2);
    set_insert_lowerbound<container>("u", set, set2);
    set_insert_lowerbound<container>("v", set, set2);
    set_insert_lowerbound<container>("w", set, set2);
    set_insert_lowerbound<container>("x", set, set2);
    set_insert_lowerbound<container>("y", set, set2);
    set_insert_lowerbound<container>("z", set, set2);

	return (0);
}


template <class container>
static void    set_insert_upperbound(std::string key, container &set, container &set2)
{
    typename container::iterator  it  = set2.upper_bound(key);
    
    if (it != set2.end())
        set.insert(set_concat_pair(key, *it));
    else
        set.insert(set_concat_pair(key, "end"));
}

template <class container>
int	set_upperbound(container &set)
{
    container   set2;
    
    set2.insert("p");
	set2.insert("s");
	set2.insert("x");
	set2.insert("o");
	set2.insert("u");
	set2.insert("b");
	set2.insert("w");
	set2.insert("e");
	set2.insert("q");


    set_insert_upperbound<container>("a", set, set2);
    set_insert_upperbound<container>("b", set, set2);
    set_insert_upperbound<container>("c", set, set2);
    set_insert_upperbound<container>("d", set, set2);
    set_insert_upperbound<container>("e", set, set2);
    set_insert_upperbound<container>("f", set, set2);
    set_insert_upperbound<container>("g", set, set2);
    set_insert_upperbound<container>("h", set, set2);
    set_insert_upperbound<container>("i", set, set2);
    set_insert_upperbound<container>("j", set, set2);
    set_insert_upperbound<container>("k", set, set2);
    set_insert_upperbound<container>("l", set, set2);
    set_insert_upperbound<container>("m", set, set2);
    set_insert_upperbound<container>("n", set, set2);
    set_insert_upperbound<container>("o", set, set2);
    set_insert_upperbound<container>("p", set, set2);
    set_insert_upperbound<container>("q", set, set2);
    set_insert_upperbound<container>("r", set, set2);
    set_insert_upperbound<container>("s", set, set2);
    set_insert_upperbound<container>("t", set, set2);
    set_insert_upperbound<container>("u", set, set2);
    set_insert_upperbound<container>("v", set, set2);
    set_insert_upperbound<container>("w", set, set2);
    set_insert_upperbound<container>("x", set, set2);
    set_insert_upperbound<container>("y", set, set2);
    set_insert_upperbound<container>("z", set, set2);

	return (0);
}


template <class container>
static void    set_insert_equalrange(std::string key, container &set, container &set2)
{
    if (set2.equal_range(key).first != set2.end())
        set.insert(set_concat_pair(key + "_low", *(set2.equal_range(key).first)));
    else
        set.insert(set_concat_pair(key + "_low", "end"));

    if (set2.equal_range(key).second != set2.end())
        set.insert(set_concat_pair(key + "_upp", *(set2.equal_range(key).second)));
    else
        set.insert(set_concat_pair(key + "_upp", "end"));
}

template <class container>
int	set_equalrange(container &set)
{
    container   set2;
    
    set2.insert("p");
	set2.insert("s");
	set2.insert("x");
	set2.insert("o");
	set2.insert("u");
	set2.insert("b");
	set2.insert("w");
	set2.insert("e");
	set2.insert("q");


    set_insert_equalrange<container>("a", set, set2);
    set_insert_equalrange<container>("b", set, set2);
    set_insert_equalrange<container>("c", set, set2);
    set_insert_equalrange<container>("d", set, set2);
    set_insert_equalrange<container>("e", set, set2);
    set_insert_equalrange<container>("f", set, set2);
    set_insert_equalrange<container>("g", set, set2);
    set_insert_equalrange<container>("h", set, set2);
    set_insert_equalrange<container>("i", set, set2);
    set_insert_equalrange<container>("j", set, set2);
    set_insert_equalrange<container>("k", set, set2);
    set_insert_equalrange<container>("l", set, set2);
    set_insert_equalrange<container>("m", set, set2);
    set_insert_equalrange<container>("n", set, set2);
    set_insert_equalrange<container>("o", set, set2);
    set_insert_equalrange<container>("p", set, set2);
    set_insert_equalrange<container>("q", set, set2);
    set_insert_equalrange<container>("r", set, set2);
    set_insert_equalrange<container>("s", set, set2);
    set_insert_equalrange<container>("t", set, set2);
    set_insert_equalrange<container>("u", set, set2);
    set_insert_equalrange<container>("v", set, set2);
    set_insert_equalrange<container>("w", set, set2);
    set_insert_equalrange<container>("x", set, set2);
    set_insert_equalrange<container>("y", set, set2);
    set_insert_equalrange<container>("z", set, set2);

	return (0);
}

#endif