/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:12:54 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 19:23:17 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "core_iterator.hpp"
# include "reverse_iterator.hpp"
# include "rbt.hpp"


namespace ft
{

template< class T, class Item >
class	rbt_iterator: public ft::iterator< std::random_access_iterator_tag, T, Item >
{
	typedef rbt_iterator< T, Item >									_self;
	typedef ft::iterator<std::random_access_iterator_tag, T, Item >	_parent;

	protected: 
		using typename _parent::_item;
		using typename _parent::_size_type;


	public:
		using typename _parent::_core;
		using typename _parent::_item_ptr;
		
		using typename _parent::iterator_category;
		using typename _parent::value_type;
		using typename _parent::difference_type;
		using typename _parent::pointer;
		using typename _parent::reference;


		rbt_iterator(void): _parent()
		{};

		rbt_iterator(const _core &src): _parent(src)
		{};

		rbt_iterator(_item_ptr front, _item_ptr back, _item_ptr elem): _parent(front, back, elem)
		{};

		virtual	~rbt_iterator(void)
		{};

	private:
		bool	_is_rightchild(Item *n)
		{
			if (!n->parent)
				return (false);
			
			return (n->parent->right_child == n);
		}
		bool	_is_leftchild(Item *n)
		{
			if (!n->parent)
				return (false);
			
			return (n->parent->left_child == n);
		}

		Item	*_get_leftmost(Item *n)
		{
			while (n->left_child)
				n = n->left_child;
			
			return (n);
		}

		Item	*_get_rightmost(Item *n)
		{
			while (n->right_child)
				n = n->right_child;
			
			return (n);
		}

	public:

		reference	operator*(void) const
		{
			return *(_parent::_elem->data);
		};

		pointer 	operator->(void) const
		{
			return (_parent::_elem->data);
		};

		_self		&operator++(void)
		{
			if (_parent::_elem == NULL)
				_parent::_elem = _parent::_front;
			else if (_parent::_elem == _parent::_back)
				_parent::_elem = NULL;
			else
			{
				if (_parent::_elem->right_child)
					_parent::_elem = _get_leftmost(_parent::_elem->right_child);
				else if (_is_rightchild(_parent::_elem))
				{
					while (_is_rightchild(_parent::_elem))
						_parent::_elem = _parent::_elem->parent;
					_parent::_elem = _parent::_elem->parent;
				}
				else
					_parent::_elem = _parent::_elem->parent;
			}

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
				_parent::_elem = _parent::_back;
			else if (_parent::_elem == _parent::_front)
				_parent::_elem = NULL;
			else
			{
				if (_parent::_elem->left_child)
					_parent::_elem = _get_rightmost(_parent::_elem->left_child);
				else if (_is_leftchild(_parent::_elem))
				{
					while (_is_leftchild(_parent::_elem))
						_parent::_elem = _parent::_elem->parent;
					_parent::_elem = _parent::_elem->parent;
				}
				else
					_parent::_elem = _parent::_elem->parent;
			}

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
			else
			{
				while (n--)
					++(*this);
			}

			return (*this);
		};

		_self		&operator-=(difference_type n)
		{
			if (n < 0)
				(*this) += -n;
			else
			{
				while (n--)
					--(*this);
			}

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

		reference	operator[](difference_type n) const
		{
			return (*(_parent::_front + n));
		}
};


template< class L_T, class L_I, class R_T, class R_I >
bool	operator<=(const rbt_iterator<L_T, L_I> &lhs, const rbt_iterator<R_T, R_I> &rhs)
{
	if (lhs.getElem() == rhs.getElem())
		return (true);
	return (lhs < rhs);
};

template< class L_T, class L_I, class R_T, class R_I >
bool	operator<(const rbt_iterator<L_T, L_I> &lhs, const rbt_iterator<R_T, R_I> &rhs)
{
	if (!lhs.getElem())
		return (false);
	if (!rhs.getElem())
		return (true);
	return (lhs.getElem() < rhs.getElem());
};

template< class L_T, class L_I, class R_T, class R_I >
bool	operator>=(const rbt_iterator<L_T, L_I> &lhs, const rbt_iterator<R_T, R_I> &rhs)
{
	return (!(lhs < rhs));
};

template< class L_T, class L_I, class R_T, class R_I >
bool	operator>(const rbt_iterator<L_T, L_I> &lhs, const rbt_iterator<R_T, R_I> &rhs)
{
	return (!(lhs <= rhs));
};


template< class T, class I >
rbt_iterator<T, I>		operator+(const int nb, const rbt_iterator<T, I> &ref)
{
	return (ref + nb);
};

template< class L_T, class L_I, class R_T, class R_I >
typename rbt_iterator<L_T, L_I>::difference_type	operator-(const rbt_iterator<L_T, L_I> &lit, const rbt_iterator<R_T, R_I> &rit)
{
	if (rit.getElem() == lit.getElem())
		return (0);
	
	if (!rit.getElem())
		return lit.getElem() - lit.getBack() - 1;

	if (!lit.getElem())
		return rit.getBack() + 1 - rit.getElem();
		
	return lit.getElem() - rit.getElem();
}

}

#endif

