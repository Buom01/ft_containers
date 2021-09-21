/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:23:55 by badam             #+#    #+#             */
/*   Updated: 2021/09/21 13:32:52 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ITERATOR_HPP
# define CORE_ITERATOR_HPP


namespace ft
{

template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
class	iterator
{
	public:
		typedef	Category		iterator_category;
		typedef	T				value_type;
		typedef	Distance		difference_type;
		typedef	Pointer			pointer;
		typedef	Reference		reference;

	protected:
		typedef	T				_value_type;
		typedef	T				_item;
		typedef	pointer			_item_ptr;
		typedef	std::size_t		_size_type;

		_item_ptr	*_front;
		_item_ptr	*_back;
		_item_ptr	_elem;

	public:
		iterator(void)
		{
			_front = NULL;
			_back = NULL;
			_elem = NULL;
		};

		iterator(const iterator &src)
		{
			*this = src;
		};

		iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem)
		{
			_front = front;
			_back = back;
			_elem = elem;
		};

		virtual	~iterator(void)
		{
		};


		iterator	&operator=(const iterator &ref)
		{
			if (this != &ref)
			{
				_front = ref.getFront();
				_back = ref.getBack();
				_elem = ref.getElem();
			}

			return (*this);
		};

		bool		operator==(const iterator &ref)
		{
			return (ref.getElem() == _elem);
		};

		bool		operator!=(const iterator &ref)
		{
			return (ref.getElem() != _elem);
		};

		_item	*getElem(void) const
		{
			return (_elem);
		};

		_item	**getElemPtr(void)
		{
			return (&_elem);
		};

		_item	**getFront(void) const
		{
			return (_front);
		};

		_item	**getBack(void) const
		{
			return (_back);
		};
};

}

#endif
