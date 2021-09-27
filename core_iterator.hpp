/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:23:55 by badam             #+#    #+#             */
/*   Updated: 2021/09/27 13:32:34 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ITERATOR_HPP
# define CORE_ITERATOR_HPP


namespace ft
{

template< class Category, class T>
class	iterator
{
	public:
		typedef	Category		iterator_category;
		typedef	T				value_type;
		typedef	std::ptrdiff_t	difference_type;
		typedef	T*				pointer;
		typedef	T&				reference;

	protected:
		typedef	typename remove_const<T>::type		_nonconst;
		typedef iterator							_self;
		typedef ft::iterator<Category, _nonconst>	_core;
		typedef	_nonconst							_item;
		typedef	_nonconst*							_item_ptr;
		typedef	std::size_t							_size_type;

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

		iterator(const _core &src)
		{
			*this = src;
		};

		iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem)
		{
			_front = front;
			_back = back;
			_elem = elem;
		};

		_self	&operator=(const _core &ref)
		{
			if (this != static_cast<const void *>(&ref))
			{
				_front = ref.getFront();
				_back = ref.getBack();
				_elem = ref.getElem();
			}

			return (*this);
		};

		virtual	~iterator(void)
		{};


		_item_ptr	getElem(void) const
		{
			return (_elem);
		};

		_item_ptr	*getFront(void) const
		{
			return (_front);
		};

		_item_ptr	*getBack(void) const
		{
			return (_back);
		};
};

template< class L_Category, class L_T, class R_Category, class R_T >
bool	operator==(const iterator<L_Category, L_T> &lhs, const iterator<R_Category, R_T> &rhs)
{
	return (lhs.getElem() == rhs.getElem());
};

template< class L_Category, class L_T, class R_Category, class R_T >
bool	operator!=(const iterator<L_Category, L_T> &lhs, const iterator<R_Category, R_T> &rhs)
{
	return (lhs.getElem() != rhs.getElem());
};

}

#endif
