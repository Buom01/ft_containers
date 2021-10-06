/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:12:54 by badam             #+#    #+#             */
/*   Updated: 2021/10/05 16:36:32 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "core_iterator.hpp"
# include "reverse_iterator.hpp"
# include "vector.hpp"


namespace ft
{

template< class T >
class	vector_iterator: public ft::iterator< std::random_access_iterator_tag, T >
{
	typedef vector_iterator< T >								_self;
	typedef ft::iterator<std::random_access_iterator_tag, T >	_parent;

	protected: 
		using typename _parent::_core;
		using typename _parent::_item;
		using typename _parent::_item_ptr;
		using typename _parent::_size_type;

	public:
		using typename _parent::iterator_category;
		using typename _parent::value_type;
		using typename _parent::difference_type;
		using typename _parent::pointer;
		using typename _parent::reference;


		vector_iterator(void): _parent()
		{};

		vector_iterator(const _core &src): _parent(src)
		{};

		vector_iterator(_item_ptr *front, _item_ptr *back, _item_ptr elem): _parent(front, back, elem)
		{};

		virtual	~vector_iterator(void)
		{};


		reference	operator*(void) const
		{
			return (*_parent::_elem);
		};

		pointer 	operator->(void) const
		{
			return (_parent::_elem);
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
			n = _parent::_modulo(n);

			if (n < 0)
				(*this) -= -n;
			else if (_parent::_elem == NULL && n)
				_parent::_elem = *_parent::_front + (n - 1);
			else
			{
				_parent::_elem += n;
				if (_parent::_elem == *_parent::_back + 1)
					_parent::_elem = NULL;
			}

			return (*this);
		};

		_self		&operator-=(difference_type n)
		{
			n = -_parent::_modulo(-n);
			
			if (n < 0)
				(*this) += -n;
			else if (_parent::_elem == NULL && n)
				_parent::_elem = *_parent::_back - (n - 1);
			else
			{
				_parent::_elem -= n;
				if (_parent::_elem == *_parent::_front - 1)
					_parent::_elem = NULL;
			}

			return (*this);
		};

		reference	operator[](difference_type n) const
		{
			return (*(*_parent::_front + n));
		}
};


template< class L_T, class R_T >
bool	operator<=(const vector_iterator<L_T> &lhs, const vector_iterator<R_T> &rhs)
{
	if (lhs.getElem() == rhs.getElem())
		return (true);
	return (lhs < rhs);
};

template< class L_T, class R_T >
bool	operator<(const vector_iterator<L_T> &lhs, const vector_iterator<R_T> &rhs)
{
	if (!lhs.getElem())
		return (false);
	if (!rhs.getElem())
		return (true);
	return (lhs.getElem() < rhs.getElem());
};

template< class L_T, class R_T >
bool	operator>=(const vector_iterator<L_T> &lhs, const vector_iterator<R_T> &rhs)
{
	return (!(lhs < rhs));
};

template< class L_T, class R_T >
bool	operator>(const vector_iterator<L_T> &lhs, const vector_iterator<R_T> &rhs)
{
	return (!(lhs <= rhs));
};


template< class T>
vector_iterator<T>		operator+(const vector_iterator<T> &ref, const int nb)
{
	vector_iterator<T>	tmp(ref);
	
	return (tmp += nb);
};

template< class T>
vector_iterator<T>		operator-(const vector_iterator<T> &ref, const int nb)
{
	vector_iterator<T>	tmp(ref);

	return (tmp -= nb);
};

template< class T>
vector_iterator<T>		operator+(const int nb, const vector_iterator<T> &ref)
{
	return (ref + nb);
};

template< class L_T, class R_T >
typename vector_iterator<L_T>::difference_type	operator-(const vector_iterator<L_T> &lit, const vector_iterator<R_T> &rit)
{
	if (rit.getElem() == lit.getElem())
		return (0);
	
	if (!rit.getElem())
		return lit.getElem() - *(rit.getBack()) - 1;

	if (!lit.getElem())
		return *(lit.getBack()) + 1 - rit.getElem();
		
	return lit.getElem() - rit.getElem();
}

template< class L_T, class R_T >
bool	operator<=(const reverse_iterator< vector_iterator<L_T> > &lhs, const reverse_iterator< vector_iterator<R_T> > &rhs)
{
	if (lhs.getElem() == rhs.getElem())
		return (true);
	return (lhs < rhs);
};

template< class L_T, class R_T >
bool	operator<(const reverse_iterator< vector_iterator<L_T> > &lhs, const reverse_iterator< vector_iterator<R_T> > &rhs)
{
	if (!lhs.getElem())
		return (false);
	if (!rhs.getElem())
		return (true);
	return (static_cast< vector_iterator<L_T> >(lhs) > static_cast< vector_iterator<R_T> >(rhs));
};

template< class L_T, class R_T >
bool	operator>=(const reverse_iterator< vector_iterator<L_T> > &lhs, const reverse_iterator< vector_iterator<R_T> > &rhs)
{
	return (!(lhs < rhs));
};

template< class L_T, class R_T >
bool	operator>(const reverse_iterator< vector_iterator<L_T> > &lhs, const reverse_iterator< vector_iterator<R_T> > &rhs)
{
	return (!(lhs <= rhs));
};

template< class T>
reverse_iterator< vector_iterator<T> >		operator+(const reverse_iterator< vector_iterator<T> > &ref, const int nb)
{
	reverse_iterator< vector_iterator<T> >	tmp(ref);
	
	return (tmp += nb);
};

template< class T>
reverse_iterator< vector_iterator<T> >		operator-(const reverse_iterator< vector_iterator<T> > &ref, const int nb)
{
	reverse_iterator< vector_iterator<T> >	tmp(ref);
	
	return (tmp -= nb);
};

template< class T>
reverse_iterator< vector_iterator<T> >		operator+(const int nb, const reverse_iterator< vector_iterator<T> > &ref)
{
	return (ref + nb);
};

template< class L_T, class R_T >
typename reverse_iterator< vector_iterator<L_T> >::difference_type
		operator-(const reverse_iterator< vector_iterator<L_T> > &lit, const reverse_iterator< vector_iterator<R_T> > &rit)
{
	if (rit.getElem() == lit.getElem())
		return (0);
	
	if (!rit.getElem())
		return *(rit.getFront()) - 1 - lit.getElem();

	if (!lit.getElem())
		return rit.getElem() - *(lit.getFront()) + 1;
		
	return rit.getElem() - lit.getElem();
}

}

#endif

