/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/11/18 19:55:05 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include <cmath>
# include <iostream>  // remove me
# include "utils.hpp"
# include "core.hpp"
# include "map_iterator.hpp"

namespace ft
{

template <class Key, class T>
class map_node
{
	public:
		class map_node			*parent;
		bool					red;
		class map_node			*left_child;
		class map_node			*right_child;
		pair<const Key, T>		*data;

	map_node(void): parent(NULL), red(true), left_child(NULL), right_child(NULL), data(NULL)
	{}
};

template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >  // should use ft::pair and ft::less
class map: public ft::core< pair<const Key, T>, Alloc, map_node<Key, T>, map_iterator< pair<const Key, T>, map_node<Key, T> >, map_iterator< const pair<const Key, T>, map_node<Key, T> > >
{
	typedef map																_self;
	typedef	ft::core< pair<const Key, T>, Alloc, map_node<Key, T>, map_iterator< pair<const Key, T>, map_node<Key, T> >, map_iterator< const pair<const Key, T>, map_node<Key, T> > >	_parent;


	using typename _parent::_item;
	using typename _parent::_item_ptr;

	public:
		typedef Key		key_type;
		typedef T		mapped_type;
		typedef	Compare key_compare;

		using typename _parent::value_type;
		using typename _parent::difference_type;
		using typename _parent::size_type;
		using typename _parent::allocator_type;
		using typename _parent::reference;
		using typename _parent::const_reference;
		using typename _parent::pointer;
		using typename _parent::const_pointer;
		using typename _parent::iterator;
		using typename _parent::const_iterator;
		using typename _parent::reverse_iterator;
		using typename _parent::const_reverse_iterator;

	protected:
		typedef map_node<key_type, mapped_type>		node;

		key_compare	*_key_compare;
		node		*_content;

		pair<node*, node*>		_autoupdate(void)
		{
			node	*first	= _content;
			node	*last	= _content;

			if (_content)
			{
				while (first->left_child)
					first = first->left_child;
				while (last->right_child)
					last = last->right_child;
				_parent::_update(first, last);
				
				return ft::make_pair(first, last);
			}
			else
				_parent::_update(NULL, NULL);

			return ft::make_pair<node*, node*>(NULL, NULL);
		}

		void		_init(const key_compare &comp, const allocator_type &alloc)
		{
			_key_compare	= &(const_cast<key_compare &>(comp));
			_content		= NULL;
			_parent::_init(alloc);
		}

		void	_dump(node *n, size_t indent = 0)
		{
			size_t	i	= 0;
			
			while (i++ < indent)
				std::cout << "  ";
			
			if (n)
			{
				std::cout << "- " << n->data->first << " (=" << n->data->second << ") - " << (n->red ? "Red" : "Black") << std::endl;
			
				_dump(n->left_child, indent + 1);
				_dump(n->right_child, indent + 1);
			}
			else
				std::cout << "- (nil node) - Black" << std::endl;
		}

		value_type	*_create_node_value(const value_type &val, const void *tip)
		{
			value_type	*node_value;
			
			node_value = _parent::_alloc->allocate(1, tip);
			_parent::_alloc->construct(node_value, value_type(val));

			return (node_value);
		}

		bool	_is_root(node *n)
		{
			return (n == _content);
		}

		bool	_check_root_color(void)
		{
			if (_content && _content->red)
			{
				std::cout << "=== ROOT IS NOT BLACK ===" << std::endl;
				return (true);
			}
			else
				return (false);
		}

		bool	_check_red_child_color(node *n)
		{
			bool	got_error	= false;

			if (!n)
				return (false);

			if (n->red)
			{
				
				if (n->left_child && n->left_child->red && (got_error = true))
					std::cout << "=== DOUBLE RED FOR [" << n->data->first << "] WITH LEFT CHILD ===" << std::endl;
				if (n->right_child && n->right_child->red && (got_error = true))
					std::cout << "=== DOUBLE RED FOR [" << n->data->first << "] WITH RIGHT CHILD ===" << std::endl;
			}

			got_error |= _check_red_child_color(n->left_child);
			got_error |= _check_red_child_color(n->right_child);

			return (got_error);
		}

		bool	_check_parenting(node *n)
		{
			bool	got_error	= false;

			if (!n)
				return (false);

			if (n->left_child && n->left_child->parent != n && (got_error = true))
				std::cout << "=== WRONG PARENT FOR [" << n->left_child->data->first << "] THAT MAY BE [" << n->data->first << "] ===" << std::endl;
			if (n->right_child && n->right_child->parent != n && (got_error = true))
				std::cout << "=== WRONG PARENT FOR [" << n->right_child->data->first << "] THAT MAY BE [" << n->data->first << "] ===" << std::endl;

			got_error |= _check_parenting(n->left_child);
			got_error |= _check_parenting(n->right_child);

			return (got_error);
		}

		bool	_check_black_depth(node *n, int count = 0, int *depth = NULL)
		{
			int	shared_depth	= 0;

			if (!depth)
				depth = &shared_depth;

			if (!n || !n->red)
				++count;
			if (!n)
			{
				if (*depth > 0)
				{
					if (*depth != count)
					{
						std::cout << "=== BLACK DEPTH NOT EQUAL; GOT " << count << " AGAINST " << *depth << std::endl;
						return (true);
					}
					else
						return (false);
				}
				else
					*depth = count;
				return (false);
			}
			else
			{
				bool	got_error	= false;

				got_error |= _check_black_depth(n->left_child, count, depth);
				got_error |= _check_black_depth(n->right_child, count, depth);

				return (got_error);
			}
		}

		void	_assert_rbt_rules(void)
		{
			bool	got_error	= false;

			got_error |= _check_root_color();
			got_error |= _check_red_child_color(_content);
			got_error |= _check_parenting(_content);
			got_error |= _check_black_depth(_content);

			if (got_error)
			{
				std::cout << "While tree looks like:" << std::endl;
				_dump(_content);
			}
		}

		char	_count_children(node *n)
		{
			return (!!(n->right_child) + !!(n->left_child));
		}

		node	*_get_sibling(node *n)
		{
			if (!(n->parent))
				return (NULL);
			else if (n->parent->left_child == n)
				return (n->parent->right_child);
			else
				return (n->parent->left_child);
		}

		bool	_is_doubleblack(node *n)
		{
			bool	double_black	= false;

			if (!(n->red) && !(n->parent->red))
				double_black = true;
			else if (!(n->right_child) && n->left_child && !(n->left_child->red))
				double_black = true;
			else if (!(n->left_child) && n->right_child && !(n->right_child->red))
				double_black = true;

			return (double_black);
		}


		node	*_get_node_predecessor(node *n)
		{
			node	*predecessor	= n->left_child;

			while (predecessor->right_child)
				predecessor = predecessor->right_child;
			
			return (predecessor);
		}

		void	_node_swap(node *a, node *b)
		{
			_parent::_swap_pointer(&(a->parent), &(b->parent));
			_parent::_swap_pointer(&(a->left_child), &(b->left_child));
			_parent::_swap_pointer(&(a->right_child), &(b->right_child));
		}

		void	_insert_autorotate(node *n)
		{
			node *parent	= n->parent;
			node *gparent	= parent->parent;
			n->red = true;
			parent->red = false;
			gparent->red = true;

			if (parent->left_child == n)
			{
				parent = gparent->parent;
				gparent->left_child = parent->right_child;
				gparent->parent = parent;
			}
			else
			{
				parent = gparent->parent;
				gparent->right_child = parent->left_child;
				gparent->parent = parent;
			}
		}

		void	_insert_rebalance(node *n)
		{
			if (_is_root(n))
				n->red = false;
			else
			{
				node	*parent		= n->parent;
				node	*gparent	= parent->parent;

				n->red = true;
				if (parent->red)
				{
					node	*sibling = _get_sibling(parent);

					if (!sibling)
						return ;
					if (!sibling->red)
						_insert_autorotate(n);
					else
					{
						parent->red = false;
						sibling->red = false;
						gparent->red = true;
						_insert_rebalance(gparent);
					}
				}
			}
		}

		void	_raw_delete(node *n)
		{
			_parent::_alloc->destroy(n->data);
			_parent::_alloc->deallocate(n->data, 1);
			delete n;
		}

		node	*_remove(node *n)
		{
			node	*parent			= n->parent;
			node	*child			= n->right_child ? n->right_child : n->left_child;

			_raw_delete(n);

			if (parent->left_child == n)
				return (parent->left_child = child);
			else
				return (parent->right_child = child);
		}

		void	_repair_double_black(node *n)
		{
			node	*sibling	= _get_sibling(n);
			node	*parent		= n->parent;

			if	(!(sibling->red))
			{
				if (sibling->left_child->red || sibling->right_child->red)
				{
					node	*red_sibling_child	= sibling->left_child->red ? sibling->left_child : sibling->right_child;

					sibling->red = parent->red;
					parent->red = false;
					red_sibling_child->red = false;

					_parent::_swap_pointer(&(parent->parent), &(sibling->parent));
					if (parent->parent == parent->left_child)
						_parent::_swap_pointer(&(parent->left_child), &(sibling->right_child));
					else
						_parent::_swap_pointer(&(parent->right_child), &(sibling->left_child));
				}
				else
				{
					sibling->red = true;
					if (parent->red)
						parent->red = false;
					else if (_is_root(parent))
						_repair_double_black(parent);
				}
			}
			else
			{
				_parent::_swap_pointer(&(parent->parent), &(sibling->parent));
				if (parent->parent == parent->left_child)
					_parent::_swap_pointer(&(parent->left_child), &(sibling->right_child));
				else
					_parent::_swap_pointer(&(parent->right_child), &(sibling->left_child));
				
				sibling->red = false;
				parent->red  = true;
				_repair_double_black(n);
			}
		}

		void	_delete(node *elem)
		{
			if (_count_children(elem) <= 1)
			{
				bool	double_black	=	_is_doubleblack(elem);
				node	*removed_place	=	_remove(elem);

				if (removed_place->red)
					removed_place->red = false;
				else if (!_is_root(removed_place) && double_black)
					_repair_double_black(removed_place);
			}
			else
			{
				node	*predecessor	=	_get_node_predecessor(elem);

				_node_swap(elem, predecessor);
				_delete(elem);
			}
		}

		void	_cleanup(node *n)
		{
			if (n->left_child)
				_cleanup(n->left_child);
			if (n->right_child)
				_cleanup(n->right_child);
			
			_raw_delete(n);
		}

	public:
		map()
		{
			_init(key_compare(), allocator_type());
		}

		explicit map(const key_compare &comp, const allocator_type &alloc = allocator_type())
		{
			_init(comp, alloc);
		};

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
     				const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		{
			_init(comp, alloc);
			insert(first, last);
		};

		map(const map &x): _parent(x)
		{
			_init(x.key_comp(), x.get_allocator());
			*this = x;
		};

		virtual	~map(void)
		{
			_assert_rbt_rules();
			clear();
		};

		_self	&operator=(const map &ref)
		{
			iterator	it;

			if (this == &ref)
				return (*this);

			clear();
			insert(ref.begin(), ref.end());

			return (*this);
		};

		class value_compare: public std::binary_function<value_type, value_type, bool>  // should be implanted in ft ?
		{
			protected:
				key_compare	comp;

				value_compare( key_compare c )
				{
					comp = c;
				}

			public:
				bool operator()( const value_type& lhs, const value_type& rhs ) const
				{
					return comp(lhs.first, rhs.first);
				}
		};

		size_type	max_size(void) const
		{
			return (_parent::_max_size());
		}

		pair<iterator, bool>	insert(const value_type &val)
		{
			iterator	it	= find(val.first);

			if (it != _parent::end())
				return (ft::make_pair(it, false));
			else
			{
				node					*new_node;
				node					**insert_point	= &_content;
				node					*parent			= NULL;
				pair<node*, node*>	extremities;
				
				new_node = new node();
				new_node->data = _create_node_value(val, _content);
				++_parent::_size;

				while (*insert_point)
				{
					parent = *insert_point;
					if ((*insert_point)->data->first > val.first)
						insert_point = &((*insert_point)->left_child);
					else
						insert_point = &((*insert_point)->right_child);
				}
				*insert_point = new_node;
				new_node->parent = parent;

				_insert_rebalance(new_node);
				extremities = _autoupdate();

				_assert_rbt_rules();
				
				return ft::make_pair(iterator(extremities.first, extremities.second, _content), true);
			}
		}

		iterator insert(iterator hint, const value_type& value)
		{
			static_cast<void>(hint);
			
			return (insert(value).first);
		}

		template <class InputIterator>
		void		insert(InputIterator first, InputIterator last/*, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0*/)
		{
			InputIterator	it	= first;
			while (it != last)
			{
				insert(*it);
				++it;
			}
		}

		void	erase(iterator position)
		{
			_delete(position.getElem());
			--_parent::_size;
			_assert_rbt_rules();
		}

		void	erase(iterator first, iterator last)
		{
			iterator	current	= first;
			iterator	next	= ++first;

			while (current != last)
			{
				erase(current);
				current = next;
				++next;
			}
		}

		size_type	erase(const key_type& key)
		{
			iterator	it	= find(key);

			if (it == _parent::end())
				return (0);

			erase(it);
			return (1);
		}

		void		swap(_self &x)
		{
			_parent::_swap_pointer(&_key_compare, &x._key_compare);
			_parent::_swap_pointer(&_content, &x._content);
			_parent::_swap(x);
		}

		void		clear(void)
		{
			if (_content)
				_cleanup(_content);
			_parent::_size = 0;
			_content = NULL;
		}

		Compare	key_comp() const
		{
			return (*_key_compare);
		}

		value_compare value_comp() const
		{
			value_compare	def;

			return (def);
		}
		
		iterator		find(const key_type& key)
		{
			node	*cursor = _content;

			while (cursor)
			{
				if (key_comp()(key, cursor->data->first))
					cursor = cursor->left_child;
				else if (key_comp()(cursor->data->first, key))
					cursor = cursor->right_child;
				else
					break;
			}

			if (cursor)
				return (iterator(_parent::_front, _parent::_back, cursor));
			return (_parent::end());
		}
		
		const_iterator		find(const key_type& key) const
		{
			node	*cursor = _content;

			while (cursor)
			{
				if (key_comp()(key, cursor->data->first))
					cursor = cursor->left_child;
				else if (key_comp()(cursor->data->first, key))
					cursor = cursor->right_child;
				else
					break;
			}

			if (cursor)
				return (const_iterator(_parent::_front, _parent::_back, cursor));
			return (_parent::end());
		}

		size_type			count(const key_type& key) const
		{
			iterator	it	= find(key);

			if(it == _parent::end())
				return (0);
			else
				return (1);
		}

		iterator		lower_bound(const Key &key)
		{
			return (find(key));
		}

		const_iterator	lower_bound(const Key &key) const
		{
			return (find(key));
		}

		iterator		upper_bound(const Key &key)
		{
			iterator	it	= find(key);

			if (it != _parent::end())
				++it;
			
			return (it);
		}

		const_iterator	upper_bound(const Key &key) const
		{
			const_iterator	it	= find(key);

			if (it != _parent::end())
				++it;
			
			return (it);
		}
		
		pair<iterator,iterator>	equal_range(const Key &key)
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		pair<const_iterator, const_iterator>	equal_range(const Key &key) const
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		mapped_type			&operator[](const key_type& key)
		{
			return (insert(ft::make_pair(key, T())).first->second);
		}

		mapped_type			&at(const Key& key)
		{
			iterator	it	= find(key);

			if (it == _parent::end())
				throw std::out_of_range("key");

			return (it->second);
		} 

		const mapped_type	&at(const Key& key) const
		{
			const_iterator	it	= find(key);

			if (it == _parent::end())
				throw std::out_of_range("key");

			return (it->second);
		} 
		
		allocator_type	get_allocator(void) const
		{
			return (_parent::_get_allocator());
		}
};

template< class T, class Alloc >
void swap( ft::map<T,Alloc>& lhs, ft::map<T,Alloc>& rhs )
{
	lhs.swap(rhs);
}

}

#endif
