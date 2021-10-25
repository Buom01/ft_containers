/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:47:07 by badam             #+#    #+#             */
/*   Updated: 2021/10/25 14:35:18 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

template< class Iter >
class reverse_iterator
{
	typedef reverse_iterator<Iter>	_self;

	protected:
		typedef typename Iter::_item_ptr	_item_ptr;
		typedef typename Iter::_core		_core;

	public:
		Iter	*current;

		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	
	public:
		reverse_iterator(void)
		{
			current = new Iter();
		};

		reverse_iterator(const Iter &src)
		{
			current = new Iter(src);
			++(*this);
		};

		template < class Other >
		reverse_iterator(const reverse_iterator<Other> &src)
		{
			current = new Iter(*(src.current));
		};

		reverse_iterator(const _self &src)
		{
			current = new Iter(*(src.current));
		};

		reverse_iterator(_item_ptr front, _item_ptr back, _item_ptr elem)
		{
			current = new Iter(front, back, elem);
		};

		_self		&operator=(const _self &ref)
		{
			if (this != &ref)
			{
				if (current)
					delete current;
				current = new Iter(*(ref.current));
			}

			return (*this);
		};

		virtual	~reverse_iterator(void)
		{
			delete current;
		};


		Iter		base(void) const
		{
			return (*current + 1);
		}

		reference	operator*(void) const
		{
			return (*(*current));
		};

		pointer 	operator->(void) const
		{
			return ((*current).operator->());
		};

		reference	operator[](difference_type n) const
		{
			Iter	copy(current->getFront(), current->getBack(), current->getBack());

			copy -= n;
			return (*copy);
		}

		_self		&operator++(void)
		{
			--(*current);
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
			++(*current);
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
			*current -= n;
			
			return (*this);
		};

		_self		&operator-=(difference_type n)
		{
			*current += n;

			return (*this);
		};

		_self		operator+(difference_type n) const
		{
			_self	tmp(*this);

			return (tmp += n);
		};

		_self		operator-(difference_type n) const
		{
			_self	tmp(*this);

			return (tmp -= n);
		};

		_item_ptr	getElem(void) const
		{
			return (current->getElem());
		};

		_item_ptr	getFront(void) const
		{
			return (current->getFront());
		};

		_item_ptr	getBack(void) const
		{
			return (current->getBack());
		};
};

template< class L_I, class R_I >
bool	operator==(const reverse_iterator< L_I > &lhs, const reverse_iterator< R_I > &rhs)
{
	return (lhs.getElem() == rhs.getElem());
};

template< class L_I, class R_I >
bool	operator!=(const reverse_iterator< L_I > &lhs, const reverse_iterator< R_I > &rhs)
{
	return (lhs.getElem() != rhs.getElem());
};

template< class L_I, class R_I >
bool	operator<=(const reverse_iterator< L_I > &lhs, const reverse_iterator< R_I > &rhs)
{
	if (lhs.getElem() == rhs.getElem())
		return (true);
	return (lhs < rhs);
};

template< class L_I, class R_I >
bool	operator<(const reverse_iterator< L_I > &lhs, const reverse_iterator< R_I > &rhs)
{
	if (!lhs.getElem())
		return (false);
	if (!rhs.getElem())
		return (true);
	return (*(lhs.current) > *(rhs.current));
};

template< class L_I, class R_I >
bool	operator>=(const reverse_iterator< L_I > &lhs, const reverse_iterator< R_I > &rhs)
{
	return (!(lhs < rhs));
};

template< class L_I, class R_I >
bool	operator>(const reverse_iterator< L_I > &lhs, const reverse_iterator< R_I > &rhs)
{
	return (!(lhs <= rhs));
};

template< class I >
reverse_iterator< I >		operator+(const int nb, const reverse_iterator< I > &ref)
{
	return (ref + nb);
};

template< class L_I, class R_I >
typename reverse_iterator< L_I >::difference_type	operator-(const reverse_iterator< L_I > &lit, const reverse_iterator< R_I > &rit)
{
	if (rit.getElem() == lit.getElem())
		return (0);


	if (!rit.getElem())
		return lit.getFront() - 1 - lit.getElem();
	if (!lit.getElem())
		return rit.getElem() - rit.getFront() + 1;

	return rit.getElem() - lit.getElem();
}

}

#endif

