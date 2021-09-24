/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:12:54 by badam             #+#    #+#             */
/*   Updated: 2021/09/24 21:24:00 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "core_iterator.hpp"
# include "reverse_iterator.hpp"
# include "vector.hpp"


namespace ft
{

template< class T, class RT = T>
class	vector_iterator: public ft::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>
// class	vector_iterator: public ft::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, RT*, RT&>
{
	typedef vector_iterator																_self;
	typedef ft::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>	_parent;
	// typedef ft::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, RT*, RT&>	_parent;
	typedef	vector_iterator< T, T >														_forced_vector_iterator;
	typedef	vector_iterator< T, const T >												_forced_const_vector_iterator;

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

		vector_iterator(const vector_iterator &src): _parent(src)
		{};

		vector_iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem): _parent(front, back, elem)
		{};


		reference	operator*(void) const
		{
			return (*_parent::_elem);
		};

		pointer 	operator->(void) const
		{
			return (_parent::_elem);
		};


		_self	&operator=(const _forced_vector_iterator &ref)  // Should patch theses
		{
			if (this != (static_cast<const void *>(&ref)))
			{
				_parent::_front = ref.getFront();
				_parent::_back = ref.getBack();
				_parent::_elem = ref.getElem();
			}

			return (*this);
		};

		_self	&operator=(const _forced_const_vector_iterator &ref)  // Should patch theses
		{
			if (this != (static_cast<const void *>(&ref)))
			{
				_parent::_front = ref.getFront();
				_parent::_back = ref.getBack();
				_parent::_elem = ref.getElem();
			}

			return (*this);
		};

		_self		&operator++(void)
		{
			if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_front;
			else if (_parent::_elem == *_parent::_back)
				_parent::_elem = NULL;
			else
				++_parent::_elem;

			return (*this);
		};

		_self		operator++(int)
		{
			_self	tmp(*this);

			++(*this);
			return (tmp);
		};

		_self		&operator--(void)
		{
			if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_back;
			else if (_parent::_elem == *_parent::_front)
				_parent::_elem = NULL;
			else
				--_parent::_elem;

			return (*this);
		};

		_self		operator--(int)
		{
			_self	tmp(*this);

			--(*this);
			return (tmp);
		};

		_self		&operator+=(difference_type n)
		{
			if (n < 0)
				(*this) -= -n;
			else if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_front + (n - 1);
			else if ((_parent::_elem += n) > *_parent::_back)
				_parent::_elem = NULL;

			return (*this);
		};

		_self		&operator-=(difference_type n)
		{
			if (n < 0)
				(*this) += -n;
			else if (_parent::_elem == NULL)
				_parent::_elem = *_parent::_back - (n - 1);
			else if ((_parent::_elem -= n) < *_parent::_front)
				_parent::_elem = NULL;

			return (*this);
		};

		_self		operator+(difference_type n) const
		{
			_self	tmp(*this);

			tmp += n;

			return (tmp);
		};

		_self		operator-(difference_type n) const
		{
			_self	tmp(*this);

			tmp -= n;

			return (tmp);
		};

		difference_type operator-(_self it) const
		{
			return (_parent::_elem - it.getElem());
		}

		bool	operator<=(const _self &ref) const
		{
			return (ref.getElem() <= _parent::_elem);
		};

		bool	operator<(const _self &ref) const
		{
			return (ref.getElem() < _parent::_elem);
		};

		bool	operator>=(const _self &ref) const
		{
			return (ref.getElem() >= _parent::_elem);
		};

		bool	operator>(const _self &ref) const
		{
			return (ref.getElem() > _parent::_elem);
		};

		reference	operator[](difference_type n) const
		{
			return (*(*this + n));
		}

		_size_type	getIndex(void) const
		{
			return (_parent::_elem - *_parent::_begin);
		}
};

}

#endif

