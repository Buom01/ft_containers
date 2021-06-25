/* ************************************************************************** */
/*                                                                            */
/*                                                        .:      ....   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:43:45 by badam             #+#    #+#             */
/*   Updated: 2021/06/25 15:26:10 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
namespace tests
{

template <class container>
bool	list_remove(container &list)
{
	list.remove(0);
	if (list.size() != 0)
		return (false);

	list.push_back(0);
	list.push_back(1);
	list.push_back(0);

	list.remove(0);
	if (list.size() != 1)
		return (false);
	list.remove(1);
	if (list.size() != 0)
		return (false);

	list.push_back(1);
	list.push_back(0);

	list.remove(0);
	if (list.size() != 1)
		return (false);
	list.remove(1);
	if (list.size() != 0)
		return (false);

	list.push_back(0);
	list.push_back(1);

	list.remove(0);
	if (list.size() != 1)
		return (false);
	list.remove(1);
	if (list.size() != 0)
		return (false);

	return (true);
}

template <class container>
bool	list_remove_if(container &list)
{
	s_pred_const<E>	always_true;
	s_pred_const<E>	always_false;
	s_pred_val<E>	custom_value;

	always_true.set_ret(true);
	always_false.set_ret(false);

	list.remove_if(always_false);
	if (list.size() != 0)
		return (false);
	list.remove_if(always_true);
	if (list.size() != 0)
		return (false);

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.remove_if(always_false);
	if (list.size() != 4)
		return (false);
	list.remove_if(always_true);
	if (list.size() != 0)
		return (false);

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(2);
	list.push_back(3);

	custom_value.set_refval(4);
	list.remove_if(custom_value);
	if (list.size() != 5)
		return (false);

	custom_value.set_refval(2);
	list.remove_if(custom_value);
	if (list.size() != 3)
		return (false);

	custom_value.set_refval(1);
	list.remove_if(custom_value);
	if (list.size() != 2)
		return (false);

	custom_value.set_refval(0);
	list.remove_if(custom_value);
	if (list.size() != 1)
		return (false);

	custom_value.set_refval(3);
	list.remove_if(custom_value);
	if (list.size() != 0)
		return (false);

	return (true);
}

template <class container>
bool	list_reverse(container &list)
{
	list.reverse();
	list.push_back(5);
	list.reverse();
	list.push_back(6);
	list.reverse();
	list.push_back(4);
	list.reverse();
	list.push_back(7);
	list.reverse();
	list.push_back(3);
	list.reverse();
	list.push_back(8);
	list.reverse();
	list.push_back(2);
	list.reverse();
	list.push_back(9);
	list.reverse();
	list.push_back(1);
	list.reverse();
	list.push_back(10);
	list.reverse();
	list.push_back(0);
	list.reverse();

	return (true);
}

template <class container>
bool	list_unique_1(container &list)
{
	s_pred_unique_two<E>	blurred;

	list.unique(blurred);

	list.push_back(0);
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(3);
	list.push_back(4);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(8);
	list.push_back(9);
	list.push_back(9);
	list.push_back(10);

	list.unique(blurred);
	if (list.size() != 6)
		return (false);

	list.push_back(10);

	list.unique(blurred);
	if (list.size() != 6)
		return (false);

	return (true);
}

template <class container>
bool	list_unique(container &list)
{
	list.unique();

	list.push_back(0);
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(3);
	list.push_back(4);
	list.push_back(4);
	list.push_back(5);
	list.push_back(5);

	list.unique();
	if (list.size() != 6)
		return (false);

	list.push_back(5);

	list.unique();
	if (list.size() != 6)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_3_1(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, ++list2.begin(), --list2.end());

	return (true);
}

template <class container>
bool	list_splice_3_2(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, ++list2.begin(), list2.end());

	return (true);
}

template <class container>
bool	list_splice_3_3(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, list2.begin(), --list2.end());

	return (true);
}

template <class container>
bool	list_splice_3_4(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, list2.begin(), ++list2.begin());

	return (true);
}

template <class container>
bool	list_splice_3_5(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, ++list2.begin(), ++(++list2.begin()));

	return (true);
}

template <class container>
bool	list_splice_3_6(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, list2.begin(), ++(++list2.begin()));

	return (true);
}

template <class container>
bool	list_splice_3_7(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, --(--list2.end()), list2.end());

	return (true);
}

template <class container>
bool	list_splice_3_8(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, --list2.begin(), --(list2.begin()));

	return (true);
}

template <class container>
bool	list_splice_2_1(container &list)
{
	container	list2;

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, ++(++(list2.begin())));

	if (list2.size() != 4 || list.size() != 1)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_2_2(container &list)
{
	container	list2;

	list.push_back(1);

	list2.push_back(0);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.begin(), list2, list2.begin());

	if (list2.size() != 3 || list.size() != 2)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_2_3(container &list)
{
	container	list2;

	list.push_back(0);

	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.splice(list.end(), list2, list2.begin());

	if (list2.size() != 3 || list.size() != 2)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_1(container &list)
{
	container	list2;
	container	list3;

	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	list.push_back(0);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(14);

	list3.push_back(9);
	list3.push_back(10);
	list3.push_back(11);
	list3.push_back(12);
	list3.push_back(13);

	list.splice(++(list.begin()), list2);

	if (list2.size() != 0)
		return (false);

	list3.splice(++(list3.begin()), list2);

	if (list2.size() != 0)
		return (false);
	if (list3.size() != 5)
		return (false);

	list2.splice(++(list2.begin()), list3);

	if (list2.size() != 5)
		return (false);
	if (list3.size() != 0)
		return (false);

	list.splice(--(list.end()), list2);
	
	if (list.size() != 15)
		return (false);
	if (list2.size() != 0)
		return (false);
	if (list3.size() != 0)
		return (false);

	list2.splice(list2.begin(), list);
	list.splice(--(list.end()), list2);

	return (true);
}

template <class container>
bool	list_splice_2_undefined_1(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	list.splice(list.end(), list, list.begin());

	if (list.size() != 5)
		return (false);
	if (*(list.begin()) != 1)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_2_undefined_2(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	list.splice(list.begin(), list, list.begin());

	if (list.size() != 5)
		return (false);
	if (*(list.begin()) != 0)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_2_undefined_3(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	list.splice(list.end(), list, ++list.begin());

	if (list.size() != 5)
		return (false);
	if (*(list.begin()) != 0)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_2_undefined_4(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	list.splice(list.begin(), list, ++list.begin());

	if (list.size() != 5)
		return (false);
	if (*(list.begin()) != 1)
		return (false);

	return (true);
}

template <class container>
bool	list_splice_2_undefined_5(container &list)
{
	typename container::iterator	it	= list.begin();
	--it;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	list.splice(list.begin(), list, ++list.begin());
	list.splice(list.begin(), list, ++(++list.begin()));

	if (list.size() != 5)
		return (false);
	if (*(list.begin()) != 2)
		return (false);
	if (*(++it) != 2)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_1(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	list.sort();
	if (list.size() != 8)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_2(container &list)
{
	list.push_back(7);
	list.push_back(6);
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(0);

	list.sort();
	if (list.size() != 8)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_3(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);

	list.sort();
	if (list.size() != 10)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_4(container &list)
{
	list.push_back(9);
	list.push_back(8);
	list.push_back(7);
	list.push_back(6);
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(0);

	list.sort();
	if (list.size() != 10)
		return (false);

	return (true);
}


template <class container>
bool	list_sort_5(container &list)
{
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);

	list.sort();
	if (list.size() != 9)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_6(container &list)
{
	list.push_back(8);
	list.push_back(7);
	list.push_back(6);
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(0);

	list.sort();
	if (list.size() != 9)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_7(container &list)
{
	list.push_back(4);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(1);
	list.push_back(0);
	list.push_back(0);

	list.sort();
	if (list.size() != 8)
		return (false);

	return (true);
}

template <class T>
bool	compare_reverted(const T &first, const T &second)
{
	return (first > second);
}

template <class container>
bool	list_sort_8(container &list)
{
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(0);

	list.sort(compare_reverted<int>);
	if (list.size() != 5)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_9(container &list)
{
	list.push_back(4);
	list.push_back(2);
	list.push_back(3);
	list.push_back(1);
	list.push_back(0);

	list.sort(compare_reverted<int>);
	if (list.size() != 5)
		return (false);

	return (true);
}

template <class container>
bool	list_sort_10(container &list)
{
	list.push_back(4);
	list.push_back(2);
	list.push_back(3);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);
	list.push_back(4);
	list.push_back(2);
	list.push_back(3);
	list.push_back(1);
	list.push_back(5);
	list.push_back(259);
	list.push_back(6);
	list.push_back(262);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);
	list.push_back(10);
	list.push_back(11);
	list.push_back(12);
	list.push_back(2);
	list.push_back(3);
	list.push_back(10);
	list.push_back(0);
	list.push_back(258);
	list.push_back(0);
	list.push_back(4);
	list.push_back(11);
	list.push_back(3);
	list.push_back(1);
	list.push_back(0);
	list.push_back(4);
	list.push_back(2);
	list.push_back(4);
	list.push_back(2);
	list.push_back(1);
	list.push_back(0);

	list.sort(compare_reverted<unsigned char>);
	if (list.size() != 39)
		return (false);

	return (true);
}


}
}
