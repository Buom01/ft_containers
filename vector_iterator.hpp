/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:12:54 by badam             #+#    #+#             */
/*   Updated: 2021/09/21 13:33:31 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "core_iterator.hpp"
# include "vector.hpp"


namespace ft
{

template< class T >
class	vector_iterator: public ft::iterator<std::random_access_iterator_tag, T>
{
	typedef ft::vector_iterator<T>								_self;
	typedef ft::iterator<std::random_access_iterator_tag, T>	_parent;

	protected: 
		using typename _parent::_size_type;
		using typename _parent::_item;
		using typename _parent::_item_ptr;

	public:
		using typename _parent::iterator_category;
		using typename _parent::value_type;
		using typename _parent::difference_type;
		using typename _parent::pointer;
		using typename _parent::reference;


		vector_iterator(void): _parent()
		{};

		// vector_iterator(const vector_iterator &src): _parent(src)
		// {};

		vector_iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem): _parent(front, back, elem)
		{};


		_self	&operator++(void)
		{
			if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_front;
			else if (_parent::_elem == *_parent::_back)
				_parent::_elem = NULL;
			else
				++_parent::_elem;

			return (*this);
		};

		_self	operator++(int)
		{
			_self	tmp(*this);

			++(*this);
			return (tmp);
		};

		_self	&operator--(void)
		{
			if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_back;
			else if (_parent::_elem == *_parent::_front)
				_parent::_elem = NULL;
			else
				--_parent::_elem;

			return (*this);
		};

		_self	operator--(int)
		{
			_self	tmp(*this);

			--(*this);
			return (tmp);
		};

		T			operator*(void)
		{
			return (*_parent::_elem);
		};

		const T		operator*(void) const
		{
			return (*_parent::_elem);
		};

		T			&operator->(void)
		{
			return (*_parent::_elem);
		};

		const T		&operator->(void) const
		{
			return (*_parent::_elem);
		};

		_self	&operator+=(difference_type n)
		{
			if (n < 0)
				(*this) -= -n;
			else if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_front + (n - 1);
			else if ((_parent::_elem += n) > *_parent::_back)
				_parent::_elem = NULL;

			return (*this);
		};

		_self	&operator-=(difference_type n)
		{
			if (n < 0)
				(*this) += -n;
			else if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_back - (n - 1);
			else if ((_parent::_elem -= n) < *_parent::_front)
				_parent::_elem = NULL;

			return (*this);
		};

		_self	operator+(difference_type n)
		{
			_self	tmp(*this);

			tmp += n;

			return (tmp);
		};

		_self	operator-(difference_type n)
		{
			_self	tmp(*this);

			tmp -= n;

			return (tmp);
		};

		bool	operator<=(const _self &ref)
		{
			return (ref.getElem() <= _parent::_elem);
		};

		bool	operator<(const _self &ref)
		{
			return (ref.getElem() < _parent::_elem);
		};

		bool	operator>=(const _self &ref)
		{
			return (ref.getElem() >= _parent::_elem);
		};

		bool	operator>(const _self &ref)
		{
			return (ref.getElem() > _parent::_elem);
		};

		T		&operator[](difference_type n)
		{
			return (*(*this + n));
		}

		_size_type	getIndex(void)
		{
			return (_parent::_elem - *_parent::_begin);
		}
};

}

#endif

