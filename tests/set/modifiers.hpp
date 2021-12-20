/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:39 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 18:14:20 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_MODIFIERS_HPP
# define TESTS_SET_MODIFIERS_HPP

# include <sstream>

template <class container>
int	set_tricky_insert_1(container &set)
{
	set.insert(set_concat_pair("c", 0));
	set.insert(set_concat_pair("b", 1));
	set.insert(set_concat_pair("a", 2));

	return (0);
}

template <class container>
int	set_tricky_insert_2(container &set)
{
	set.insert(set_concat_pair("a", 0));
	set.insert(set_concat_pair("b", 0));
	set.insert(set_concat_pair("c", 0));
	set.insert(set_concat_pair("d", 0));
	set.insert(set_concat_pair("e", 1));
	set.insert(set_concat_pair("f", 2));
	set.insert(set_concat_pair("g", 2));
	set.insert(set_concat_pair("h", 2));
	set.insert(set_concat_pair("i", 2));
	set.insert(set_concat_pair("j", 2));
	set.insert(set_concat_pair("k", 2));
	set.insert(set_concat_pair("l", 2));
	set.insert(set_concat_pair("m", 2));
	set.insert(set_concat_pair("n", 2));
	set.insert(set_concat_pair("o", 2));
	set.insert(set_concat_pair("p", 2));
	set.insert(set_concat_pair("q", 2));
	set.insert(set_concat_pair("r", 2));
	set.insert(set_concat_pair("s", 2));
	set.insert(set_concat_pair("t", 2));
	set.insert(set_concat_pair("u", 2));
	set.insert(set_concat_pair("v", 2));
	set.insert(set_concat_pair("w", 2));
	set.insert(set_concat_pair("x", 2));
	set.insert(set_concat_pair("y", 2));
	set.insert(set_concat_pair("z", 2));

	return (0);
}

template <class container>
int	set_tricky_insert_3(container &set)
{
	set.insert(set_concat_pair("f", 0));
	set.insert(set_concat_pair("e", 0));
	set.insert(set_concat_pair("d", 0));
	set.insert(set_concat_pair("c", 0));
	set.insert(set_concat_pair("b", 1));
	set.insert(set_concat_pair("a", 2));
	set.insert(set_concat_pair("g", 2));
	set.insert(set_concat_pair("h", 2));
	set.insert(set_concat_pair("i", 2));
	set.insert(set_concat_pair("j", 2));
	set.insert(set_concat_pair("k", 2));
	set.insert(set_concat_pair("m", 2));
	set.insert(set_concat_pair("l", 2));

	return (0);
}

template <class container>
int	set_tricky_insert_4(container &set)
{
	set.insert(set_concat_pair("r", 2));
	set.insert(set_concat_pair("f", 2));
	set.insert(set_concat_pair("o", 2));
	set.insert(set_concat_pair("d", 0));
	set.insert(set_concat_pair("x", 2));
	set.insert(set_concat_pair("s", 2));
	set.insert(set_concat_pair("w", 2));
	set.insert(set_concat_pair("u", 2));
	set.insert(set_concat_pair("i", 2));
	set.insert(set_concat_pair("e", 1));
	set.insert(set_concat_pair("t", 2));
	set.insert(set_concat_pair("n", 2));
	set.insert(set_concat_pair("j", 2));
	set.insert(set_concat_pair("z", 2));
	set.insert(set_concat_pair("k", 2));
	set.insert(set_concat_pair("b", 0));
	set.insert(set_concat_pair("l", 2));
	set.insert(set_concat_pair("h", 2));
	set.insert(set_concat_pair("c", 0));
	set.insert(set_concat_pair("y", 2));
	set.insert(set_concat_pair("m", 2));
	set.insert(set_concat_pair("a", 0));
	set.insert(set_concat_pair("q", 2));
	set.insert(set_concat_pair("p", 2));
	set.insert(set_concat_pair("v", 2));
	set.insert(set_concat_pair("g", 2));

	return (0);
}

template <class container>
int	set_tricky_insert_5(container &set)
{
	set.insert(set_concat_pair("b", 0));
	set.insert(set_concat_pair("q", 2));
	set.insert(set_concat_pair("m", 2));
	set.insert(set_concat_pair("o", 2));
	set.insert(set_concat_pair("p", 2));
	set.insert(set_concat_pair("j", 2));
	set.insert(set_concat_pair("k", 2));
	set.insert(set_concat_pair("s", 2));
	set.insert(set_concat_pair("l", 2));
	set.insert(set_concat_pair("n", 2));
	set.insert(set_concat_pair("r", 2));
	set.insert(set_concat_pair("c", 0));
	set.insert(set_concat_pair("t", 2));
	set.insert(set_concat_pair("g", 2));
	set.insert(set_concat_pair("u", 2));
	set.insert(set_concat_pair("z", 2));
	set.insert(set_concat_pair("e", 1));
	set.insert(set_concat_pair("d", 0));
	set.insert(set_concat_pair("w", 2));
	set.insert(set_concat_pair("v", 2));
	set.insert(set_concat_pair("a", 0));
	set.insert(set_concat_pair("f", 2));
	set.insert(set_concat_pair("i", 2));
	set.insert(set_concat_pair("y", 2));
	set.insert(set_concat_pair("h", 2));
	set.insert(set_concat_pair("x", 2));

	return (0);
}

template <class container>
int	set_tricky_insert_6(container &set)
{
	set.insert(set_concat_pair("h", 2));
	set.insert(set_concat_pair("p", 2));
	set.insert(set_concat_pair("v", 2));
	set.insert(set_concat_pair("c", 0));
	set.insert(set_concat_pair("s", 2));
	set.insert(set_concat_pair("m", 2));
	set.insert(set_concat_pair("f", 2));
	set.insert(set_concat_pair("z", 2));
	set.insert(set_concat_pair("o", 2));
	set.insert(set_concat_pair("g", 2));
	set.insert(set_concat_pair("n", 2));
	set.insert(set_concat_pair("w", 2));
	set.insert(set_concat_pair("i", 2));
	set.insert(set_concat_pair("r", 2));
	set.insert(set_concat_pair("y", 2));
	set.insert(set_concat_pair("t", 2));
	set.insert(set_concat_pair("b", 0));
	set.insert(set_concat_pair("k", 2));
	set.insert(set_concat_pair("d", 0));
	set.insert(set_concat_pair("x", 2));
	set.insert(set_concat_pair("l", 2));
	set.insert(set_concat_pair("j", 2));
	set.insert(set_concat_pair("q", 2));
	set.insert(set_concat_pair("e", 1));
	set.insert(set_concat_pair("u", 2));
	set.insert(set_concat_pair("a", 0));

	return (0);
}

template <class container>
int	set_epic_insert_1(container &set)
{
	int	i	= 0;
	std::stringstream	key;

	while (i < 100)
	{
		key << i;
		set.insert(set_concat_pair(key.str(), i));
		key.str(std::string());
		++i;
	}

	return (0);
}

template <class container>
int	set_clear(container &set)
{
	set.clear();

	if (set.size() != 0 || !set.empty())
		return (1);

	set.insert(set_concat_pair("h", 2));
	set.insert(set_concat_pair("p", 2));


	if (set.size() != 2 || set.empty())
		return (2);

	set.clear();

	if (set.size() != 0 || !set.empty())
		return (3);

	set.insert(set_concat_pair("v", 2));
	set.insert(set_concat_pair("v", 2));

	if (set.size() != 1 || set.empty())
		return (4);

	set.clear();
	set.clear();

	if (set.size() != 0 || !set.empty())
		return (5);
	
	return (0);
}

template <class container>
int	set_swap(container &set)
{
	container						set2;
	container						set3;
	typename container::iterator	first;
	typename container::iterator	second;
	typename container::iterator	third;

	set.insert(set_concat_pair("a", 0));
	set.insert(set_concat_pair("b", 1));
	set.insert(set_concat_pair("c", 2));
	set.insert(set_concat_pair("d", 3));

	set2.insert(set_concat_pair("e", 4));
	set2.insert(set_concat_pair("f", 5));
	set2.insert(set_concat_pair("g", 6));

	set3.insert(set_concat_pair("h", 7));
	set3.insert(set_concat_pair("i", 8));
	set3.insert(set_concat_pair("j", 9));

	first = set3.begin();
	second = first;
	++second;
	third = second;
	++third;

	set3.swap(set2);
	set.swap(set2);

	if (set.size() != 3 || set.empty())
		return (1);
	
	return (0);
}

template <class container>
int	set_erase_1(container &set)
{
	typename container::iterator	pos;

	set.insert(set_concat_pair("a", 0));
	set.insert(set_concat_pair("b", 1));
	set.insert(set_concat_pair("c", 2));
	set.insert(set_concat_pair("d", 3));
	set.insert(set_concat_pair("e", 4));

	set.erase(set.begin(), set.end());
	if (set.size() != 0 || !set.empty() || set.begin() != set.end())
		return (2);

	set.insert(set_concat_pair("f", 5));
	set.insert(set_concat_pair("g", 6));

	set.erase(set.begin());
	if (set.size() != 1 || set.empty())
		return (3);
	set.erase(set.begin());
	if (set.size() != 0 || !set.empty() || set.begin() != set.end())
		return (4);

	set.insert(set_concat_pair("h", 7));
	set.insert(set_concat_pair("i", 8));

	pos = set.end();
	--pos;

	set.erase(pos);
	if (set.size() != 1 || set.empty())
		return (5);
	set.erase(set.begin());
	if (!set.empty()|| set.begin() != set.end())
		return (6);

	set.insert(set_concat_pair("j", 7));
	set.insert(set_concat_pair("k", 8));
	set.insert(set_concat_pair("l", 9));
	set.insert(set_concat_pair("m", 10));

	pos = set.end();
	--pos;

	set.erase(pos);
	if (set.size() != 3 || set.empty())
		return (7);
	set.erase(set.begin());
	if (set.size() != 2 || set.empty())
		return (8);

	return (0);
}

template <class container>
int	set_erase_2(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("a"));
	set.erase(set.find("b"));
	set.erase(set.find("c"));
	set.erase(set.find("d"));
	set.erase(set.find("e"));
	set.erase(set.find("f"));
	set.erase(set.find("g"));
	set.erase(set.find("h"));
	set.erase(set.find("i"));
	set.erase(set.find("j"));
	set.erase(set.find("k"));
	set.erase(set.find("l"));
	set.erase(set.find("m"));
	set.erase(set.find("n"));
	set.erase(set.find("o"));
	set.erase(set.find("p"));
	set.erase(set.find("q"));
	set.erase(set.find("r"));
	set.erase(set.find("s"));
	set.erase(set.find("t"));
	set.erase(set.find("u"));
	set.erase(set.find("v"));
	set.erase(set.find("w"));
	set.erase(set.find("x"));
	set.erase(set.find("y"));
	set.erase(set.find("z"));

	return (0);
}

template <class container>
int	set_erase_3(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("z"));
	set.erase(set.find("y"));
	set.erase(set.find("x"));
	set.erase(set.find("w"));
	set.erase(set.find("v"));
	set.erase(set.find("u"));
	set.erase(set.find("t"));
	set.erase(set.find("s"));
	set.erase(set.find("r"));
	set.erase(set.find("q"));
	set.erase(set.find("p"));
	set.erase(set.find("o"));
	set.erase(set.find("n"));
	set.erase(set.find("m"));
	set.erase(set.find("l"));
	set.erase(set.find("k"));
	set.erase(set.find("j"));
	set.erase(set.find("i"));
	set.erase(set.find("h"));
	set.erase(set.find("g"));
	set.erase(set.find("f"));
	set.erase(set.find("e"));
	set.erase(set.find("d"));
	set.erase(set.find("c"));
	set.erase(set.find("b"));
	set.erase(set.find("a"));

	return (0);
}

template <class container>
int	set_erase_4(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("n"));
	set.erase(set.find("x"));
	set.erase(set.find("u"));
	set.erase(set.find("s"));
	set.erase(set.find("l"));
	set.erase(set.find("o"));
	set.erase(set.find("m"));
	set.erase(set.find("d"));
	set.erase(set.find("b"));
	set.erase(set.find("v"));
	set.erase(set.find("c"));
	set.erase(set.find("g"));
	set.erase(set.find("h"));
	set.erase(set.find("j"));
	set.erase(set.find("r"));
	set.erase(set.find("z"));
	set.erase(set.find("t"));
	set.erase(set.find("f"));
	set.erase(set.find("p"));
	set.erase(set.find("k"));
	set.erase(set.find("q"));

	return (0);
}

template <class container>
int	set_erase_5(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("r"));
	set.erase(set.find("l"));
	set.erase(set.find("m"));
	set.erase(set.find("a"));
	set.erase(set.find("h"));
	set.erase(set.find("q"));
	set.erase(set.find("b"));
	set.erase(set.find("o"));
	set.erase(set.find("k"));
	set.erase(set.find("y"));
	set.erase(set.find("w"));
	set.erase(set.find("c"));
	set.erase(set.find("u"));
	set.erase(set.find("x"));
	set.erase(set.find("n"));
	set.erase(set.find("v"));
	set.erase(set.find("p"));
	set.erase(set.find("j"));
	set.erase(set.find("f"));
	set.erase(set.find("g"));
	set.erase(set.find("e"));

	return (0);
}

template <class container>
int	set_erase_6(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("p"));
	set.erase(set.find("l"));
	set.erase(set.find("e"));
	set.erase(set.find("d"));
	set.erase(set.find("k"));
	set.erase(set.find("a"));
	set.erase(set.find("w"));
	set.erase(set.find("v"));
	set.erase(set.find("t"));
	set.erase(set.find("g"));
	set.erase(set.find("i"));
	set.erase(set.find("m"));
	set.erase(set.find("c"));
	set.erase(set.find("z"));
	set.erase(set.find("s"));
	set.erase(set.find("o"));
	set.erase(set.find("u"));
	set.erase(set.find("r"));
	set.erase(set.find("y"));
	set.erase(set.find("f"));
	set.erase(set.find("n"));

	return (0);
}

template <class container>
int	set_erase_7(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("m"));
	set.erase(set.find("n"));
	set.erase(set.find("v"));
	set.erase(set.find("l"));
	set.erase(set.find("u"));
	set.erase(set.find("i"));
	set.erase(set.find("q"));
	set.erase(set.find("r"));
	set.erase(set.find("o"));
	set.erase(set.find("z"));
	set.erase(set.find("f"));

	return (0);
}

template <class container>
int	set_erase_8(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("m"));
	set.erase(set.find("n"));
	set.erase(set.find("v"));
	set.erase(set.find("l"));
	set.erase(set.find("u"));
	set.erase(set.find("i"));
	set.erase(set.find("q"));
	set.erase(set.find("r"));

	return (0);
}

template <class container>
int	set_erase_9(container &set)
{
	set.insert("a");
	set.insert("b");
	set.insert("c");
	set.insert("d");
	set.insert("e");
	set.insert("f");
	set.insert("g");
	set.insert("h");
	set.insert("i");
	set.insert("j");
	set.insert("k");
	set.insert("l");
	set.insert("m");
	set.insert("n");
	set.insert("o");
	set.insert("p");
	set.insert("q");
	set.insert("r");
	set.insert("s");
	set.insert("t");
	set.insert("u");
	set.insert("v");
	set.insert("w");
	set.insert("x");
	set.insert("y");
	set.insert("z");

	set.erase(set.find("y"));
	set.erase(set.find("x"));
	set.erase(set.find("w"));
	set.erase(set.find("v"));
	set.erase(set.find("u"));
	set.erase(set.find("t"));
	set.erase(set.find("s"));
	set.erase(set.find("r"));
	set.erase(set.find("q"));
	set.erase(set.find("p"));
	set.erase(set.find("o"));
	set.erase(set.find("n"));
	set.erase(set.find("m"));
	set.erase(set.find("l"));
	set.erase(set.find("k"));
	set.erase(set.find("j"));
	set.erase(set.find("i"));
	set.erase(set.find("h"));
	set.erase(set.find("g"));
	set.erase(set.find("f"));
	set.erase(set.find("e"));
	set.erase(set.find("d"));
	set.erase(set.find("c"));
	set.erase(set.find("b"));

	return (0);
}

#endif
