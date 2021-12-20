/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:49:40 by badam             #+#    #+#             */
/*   Updated: 2021/12/20 16:50:14 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <stdexcept>
# include <cmath>
# include <iostream>  // remove me
# include "utils.hpp"
# include "core.hpp"
# include "rbt_iterator.hpp"

namespace ft
{

template <class Key, class T, class Item, class Alloc>
struct rbt_node
{
	public:
		Item		*data;
		bool		red;
		rbt_node	*parent;
		rbt_node	*left_child;
		rbt_node	*right_child;

		rbt_node(const Item &val, Alloc *alloc, const void *tip = NULL): data(NULL), red(true), parent(NULL), left_child(NULL), right_child(NULL)
		{
			data = alloc->allocate(1, tip);
			alloc->construct(data, val);
		};

	protected:
		Key		_key(Key *data)
		{
			return (*data);
		}

		Key		_key(pair<const Key, T> *data)
		{
			return (data->first);
		}

		T		_value(T *data)
		{
			return (*data);
		}

		T		_value(pair<const Key, T> *data)
		{
			return (data->second);
		}

	public:
		Key	key(void)
		{
			return (_key(this->data));
		}

		T	value(void)
		{
			return (_value(this->data));
		}
};

template< class Key, class T, class Item, class PublicItem, class Compare = less<Key>, class Alloc = std::allocator<Item> >
class rbt: public ft::core< Item, Alloc, rbt_node<Key, T, Item, Alloc>, rbt_iterator< PublicItem, rbt_node<Key, T, Item, Alloc> >, rbt_iterator< const PublicItem, rbt_node<Key, T, Item, Alloc> > >
{
	typedef rbt		_self;
	typedef	ft::core< Item, Alloc, rbt_node<Key, T, Item, Alloc>, rbt_iterator< PublicItem, rbt_node<Key, T, Item, Alloc> >, rbt_iterator< const PublicItem, rbt_node<Key, T, Item, Alloc> > >	_parent;


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
		typedef rbt_node<Key, T, Item, Alloc>		node;

		key_compare	*_key_compare;
		node		*_content;

		static const Key	&_getKey(const Key &item)
		{
			return (item);
		}

		static const Key	&_getKey(const pair<const Key, T> &item)
		{
			return (item.first);
		}

		static const T		&_getValue(const T &item)
		{
			return (item);
		}

		static const T		&_getValue(const pair<const Key, T> &item)
		{
			return (item.second);
		}

		// Key				_newItem(const Key key)
		// {
		// 	return (key);
		// }

		// pair<const Key, T>	_newItem(const Key key)
		// {
		// 	return (ft::make_pair(key, T()));
		// }

		void		_autoupdate(void)
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
			}
			else
				_parent::_update(NULL, NULL);
		}

		void		_init(const key_compare &comp, const allocator_type &alloc)
		{
			_key_compare	= &(const_cast<key_compare &>(comp));
			_content		= NULL;
			_parent::_init(alloc);
		}

		bool	_dump(node *n, size_t indent = 0)
		{
			size_t	i	= 0;

			if (indent > 20)
			{
				std::cout << "[....]" << std::endl;
				return (false);
			}
			
			while (i++ < indent)
				std::cout << "  ";
			
			if (n)
			{
				std::cout << "- " << n->key() << " (=" << n->value() << ") - " << (_is_red(n) ? "Red" : "Black");
				if (n->parent)
					std::cout << " - parent is [" << n->parent->key() << "]";
				std::cout << std::endl;
			
				if (!_dump(n->left_child, indent + 1) || !_dump(n->right_child, indent + 1))
					return (false);
			}
			else
				std::cout << "- (nil node) - Black" << std::endl;
			return (true);
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
			if (_is_red(_content))
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

			if (_is_red(n))
			{
				
				if (_is_red(n->left_child) && (got_error = true))
					std::cout << "=== DOUBLE RED FOR [" << n->key() << "] WITH LEFT CHILD ===" << std::endl;
				if (_is_red(n->right_child) && (got_error = true))
					std::cout << "=== DOUBLE RED FOR [" << n->key() << "] WITH RIGHT CHILD ===" << std::endl;
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
				std::cout << "=== WRONG PARENT FOR [" << n->left_child->key() << "] THAT MAY BE [" << n->key() << "] ===" << std::endl;
			if (n->right_child && n->right_child->parent != n && (got_error = true))
				std::cout << "=== WRONG PARENT FOR [" << n->right_child->key() << "] THAT MAY BE [" << n->key() << "] ===" << std::endl;

			if (got_error)
				return (got_error);

			got_error |= _check_parenting(n->left_child);
			got_error |= _check_parenting(n->right_child);

			return (got_error);
		}

		bool	_check_black_depth(node *n, int count = 0, int *depth = NULL)
		{
			int	shared_depth	= 0;

			if (!depth)
				depth = &shared_depth;

			if (_is_black(n))
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

		bool	_check_order(void)
		{
			iterator	i	= _parent::begin();
			iterator	p;

			while (i != _parent::end())
			{
				p = i++;
				if (i != _parent::end())
				{
					if (key_comp()(i.getElem()->key(), p.getElem()->key()))
					{
						std::cout << "=== ELEMENTS ARE NOT IN ORDER AT :" << p.getElem()->key() << " ===" << std::endl;
						_dump(_content);
						return (true);
					}
				}
			}
			return (false);
		}

		void	_assert_rbt_rules(void)
		{
			bool	got_error	= false;

			got_error |= _check_root_color();
			got_error |= _check_red_child_color(_content);
			got_error |= _check_parenting(_content);
			got_error |= _check_black_depth(_content);
			got_error |= _check_order();

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
			if (!n || !(n->parent))
				return (NULL);
			else if (n->parent->left_child == n)
				return (n->parent->right_child);
			else
				return (n->parent->left_child);
		}

		node	**_get_parent_link(node *n)
		{
			if (n->parent)
			{
				if (_is_leftchild(n))
					return (&(n->parent->left_child));
				else
					return (&(n->parent->right_child));
			}
			else
				return (&_content);
		}

		bool	_is_black(node *n)
		{
			return (!n || !n->red);
		}

		bool	_is_red(node *n)
		{
			return (n && n->red);
		}

		bool	_is_leftchild(node *n)
		{
			return (!n->parent || n->parent->left_child == n);
		}

		bool	_is_rightchild(node *n)
		{
			return (n->parent->right_child == n);
		}

		void	_set_black(node *n, bool black = true)
		{
			if (n)
				n->red = !black;
		}

		void	_set_red(node *n, bool red = true)
		{
			if (n)
				n->red = red;
		}

		bool	_is_doubleblack(node *n)
		{
			bool	double_black	= false;

			if (_is_black(n) && _is_black(n->parent))
				double_black = true;
			else if (!(n->right_child) && n->left_child && _is_black(n->left_child))
				double_black = true;
			else if (!(n->left_child) && n->right_child && _is_black(n->right_child))
				double_black = true;

			return (double_black);
		}

		node	*_get_node_predecessor(node *n)
		{
			iterator	it	= _parent::_get_iterator(n);

			--it;

			return (it.getElem());
		}

		void	_node_swap(node *a, node *b)
		{
			_parent::_swap_pointer(_get_parent_link(a), _get_parent_link(b));
			_parent::_swap_pointer(&(a->parent), &(b->parent));
			_parent::_swap_pointer(&(a->left_child), &(b->left_child));
			_parent::_swap_pointer(&(a->right_child), &(b->right_child));
			_parent::_swap_pointer(&(a->red), &(b->red));

			if (a->parent == a)
				a->parent = b;
			if (b->parent == b)
				b->parent = a;
			if (a->left_child == a)
				a->left_child = b;
			if (b->left_child == b)
				b->left_child = a;
			if (a->right_child == a)
				a->right_child = b;
			if (b->right_child == b)
				b->right_child = a;

			if (a->right_child)
				a->right_child->parent = a;
			if (b->right_child)
				b->right_child->parent = b;
			if (a->left_child)
				a->left_child->parent = a;
			if (b->left_child)
				b->left_child->parent = b;

			_check_parenting(_content);
		}

		void	_insert_rotate(node *n)
		{
			_check_parenting(_content);

			node	*parent			= n->parent;
			node	*gparent		= parent->parent;
			node	*ggparent		= gparent->parent;
			node	**ggparent_child;
			node	*tmp;

			if (!ggparent)
				ggparent_child	= &_content;
			else if (ggparent->left_child == gparent)  // should use specialized functions
				ggparent_child = &(ggparent->left_child);
			else
				ggparent_child = &(ggparent->right_child);

			*ggparent_child = parent;
			parent->parent = ggparent;
			gparent->parent = parent;
		
			if (gparent->left_child == parent)  // should use specialized functions
			{
				tmp = parent->right_child;
				parent->right_child = gparent;
				gparent->left_child = tmp;
			}
			else
			{
				tmp = parent->left_child;
				parent->left_child = gparent;
				gparent->right_child = tmp;
			}
			if (tmp)
				tmp->parent = gparent;
			
			_set_black(parent);
			_set_red(gparent);
		}

		void	_insert_unrotate(node *n)
		{
			_check_parenting(_content);

			node	*parent			= n->parent;
			node	*gparent		= parent->parent;
			node	**gparent_child;
			node 	*tmp;

			if (!gparent)
				gparent_child = &_content;
			else if (_is_leftchild(parent))
				gparent_child = &(gparent->left_child);
			else
				gparent_child = &(gparent->right_child);
			

			if (_is_rightchild(n))
			{
				tmp = n->left_child;
				n->left_child = parent;
				parent->right_child = tmp;
			}
			else
			{
				tmp = n->right_child;
				n->right_child = parent;
				parent->left_child = tmp;
			}
			if (tmp)
				tmp->parent = parent;
			parent->parent = n;

			n->parent = gparent;
			*gparent_child = n;

			_check_parenting(_content);
		}

		void	_insert_autorotate(node *n)
		{
			if ((_is_rightchild(n) && _is_rightchild(n->parent)) || (_is_leftchild(n) && _is_leftchild(n->parent)))
				_insert_rotate(n);
			else
			{
				node	*parent	= n->parent;
				_insert_unrotate(n);
				_insert_rotate(parent);
			}
		}

		void	_insert_rebalance(node *n)
		{
			_check_parenting(_content);


			if (_is_root(n))
				_set_black(n);
			else
			{
				node	*parent		= n->parent;
				node	*gparent	= parent->parent;

				_set_red(n);
				if (_is_red(parent))
				{
					node	*sibling = _get_sibling(parent);

					if (_is_black(sibling))
						_insert_autorotate(n);
					else
					{
						_set_black(parent);
						_set_black(sibling);
						_set_red(gparent);
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

			if (!parent)
				_content = child;
			else
			{
				if (_is_leftchild(n))
					parent->left_child = child;
				else
					parent->right_child = child;
			}
			if (child)
				child->parent = parent;

			_raw_delete(n);
			
			return (child);
		}

		void	_repair_double_black(node *parent, node *sibling)
		{
			if (!parent)
				return ;
			
			_check_parenting(_content);
			
			if (!sibling)
				return ;

			if	(_is_black(sibling))
			{
				if ((_is_red(sibling->left_child) ) || (_is_red(sibling->right_child) ))
				{
					node	*gparent			= parent->parent;
					node	**gparent_child;
					node	**sibling_red_child;
					node	**sibling_other_child;

					if (parent->right_child == sibling && !_is_red(sibling->right_child))
					{
						node	*new_sibling		= sibling->left_child;
						node	*new_red_child	= sibling;

						parent->right_child = new_sibling;
						new_sibling->parent = parent;

						new_red_child->left_child = new_sibling->right_child;
						if (new_red_child->right_child)
							new_red_child->left_child->parent = new_red_child;

						new_sibling->right_child = new_red_child;
						new_red_child->parent = new_sibling;
						
						sibling = new_sibling;
					}
					else if (parent->left_child == sibling && !_is_red(sibling->left_child))
					{
						node	*new_sibling		= sibling->right_child;
						node	*new_red_child	= sibling;

						parent->left_child = new_sibling;
						new_sibling->parent = parent;

						new_red_child->right_child = new_sibling->left_child;
						if (new_red_child->right_child)
							new_red_child->right_child->parent = new_red_child;

						new_sibling->left_child = new_red_child;
						new_red_child->parent = new_sibling;

						sibling = new_sibling;
					}

					_check_parenting(_content);

					if (parent->left_child == sibling)
					{
						sibling_red_child = &(sibling->left_child);
						sibling_other_child = &(sibling->right_child);
					}
					else
					{
						sibling_red_child = &(sibling->right_child);
						sibling_other_child = &(sibling->left_child);
					}
					
					if (gparent)
					{
						if (_is_leftchild(parent))
							gparent_child = &(gparent->left_child);
						else
							gparent_child = &(gparent->right_child);
					}
					else
						gparent_child	= &_content;

					_set_red(sibling, _is_red(parent));
					_set_black(parent);
					_set_black(*sibling_red_child);

					if (parent->left_child == sibling)
					{
						parent->left_child = *sibling_other_child;
						*sibling_other_child = parent;
						if (parent->left_child)
							parent->left_child->parent = parent;
						_set_black(parent->right_child);
					}
					else
					{
						parent->right_child = *sibling_other_child;
						*sibling_other_child = parent;
						if (parent->right_child)
							parent->right_child->parent = parent;
						_set_black(parent->left_child);
					}
					*gparent_child = sibling;
					parent->parent = sibling;
					sibling->parent = gparent;
				}
				else
				{
					_set_red(sibling);
					if (_is_red(parent))
						_set_black(parent);
					else
						_repair_double_black(parent->parent, _get_sibling(parent));
				}
			}
			else
			{
				node	*new_sibling;

				if (_is_rightchild(sibling))
					new_sibling = sibling->left_child;
				else
					new_sibling = sibling->right_child;

				_insert_unrotate(sibling);
				_set_black(sibling);
				_set_red(parent);
				
				_repair_double_black(parent, new_sibling);
			}
		}

		void	_delete(node *elem)
		{
			_check_parenting(_content);

			if (_count_children(elem) <= 1)
			{
				node	*parent			= elem->parent;
				node	*sibling		= _get_sibling(elem);
				bool	black			= _is_black(elem);
				node	*removed_place	= _remove(elem);
				bool	double_black	= black && (_is_black(parent) || _is_black(removed_place));

				if (_is_red(removed_place))
					_set_black(removed_place);
				else if (parent && double_black)
					_repair_double_black(parent, sibling);
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
		rbt()
		{
			_init(key_compare(), allocator_type());
		}

		explicit rbt(const key_compare &comp, const allocator_type &alloc = allocator_type())
		{
			_init(comp, alloc);
		};

		template <class InputIterator>
		rbt(InputIterator first, InputIterator last,
     				const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		{
			_init(comp, alloc);
			insert(first, last);
		};

		rbt(const rbt &x): _parent(x)
		{
			_init(x.key_comp(), x.get_allocator());
			*this = x;
		};

		virtual	~rbt(void)
		{
			_assert_rbt_rules();
			clear();
		};

		_self	&operator=(const rbt &ref)
		{
			iterator	it;

			if (this == &ref)
				return (*this);

			clear();
			insert(ref.begin(), ref.end());

			return (*this);
		};

		class value_compare: public binary_function<value_type, value_type, bool>
		{
			protected:
				key_compare	comp;

				value_compare( key_compare c )
				{
					comp = c;
				}

			public:
				value_compare( void )
				{}
				
				bool operator()( const value_type& lhs, const value_type& rhs ) const
				{
					return comp(_getKey(lhs), _getKey(rhs));
				}
		};

		size_type	max_size(void) const
		{
			return (_parent::_max_size(std::numeric_limits<difference_type>::max() / (sizeof(node))));
		}

		pair<iterator, bool>	insert(const value_type &val)
		{
			iterator	it	= find(this->_getKey(val));

			if (it != _parent::end())
				return (ft::make_pair(it, false));
			else
			{
				node					*new_node;
				node					**insert_point	= &_content;
				node					*parent			= NULL;
				
				new_node = new node(val, _parent::_alloc, _content);
				++_parent::_size;

				while (*insert_point)
				{
					parent = *insert_point;
					if (key_comp()(_getKey(val), (*insert_point)->key()))
						insert_point = &((*insert_point)->left_child);
					else
						insert_point = &((*insert_point)->right_child);
				}
				*insert_point = new_node;
				new_node->parent = parent;

				_insert_rebalance(new_node);
				_autoupdate();

				_assert_rbt_rules();
				
				return ft::make_pair(_parent::_get_iterator(new_node), true);
			}
		}

		iterator 				insert(iterator hint, const value_type& value)
		{
			static_cast<void>(hint);
			
			return (insert(value).first);
		}

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last/*, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0*/)
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
			_autoupdate();
			_assert_rbt_rules();
		}

		void	erase(iterator first, iterator last)
		{
			iterator	current	= first;
			iterator	next;
			if (first == last)
				return ;

			while (current != last)
			{
				next = current;
				++next;
				erase(current);
				current = next;
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
			_parent::_update(NULL, NULL);
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
				if (key_comp()(key, cursor->key()))
					cursor = cursor->left_child;
				else if (key_comp()(cursor->key(), key))
					cursor = cursor->right_child;
				else
					break;
			}

			if (cursor)
				return (_parent::_get_iterator(cursor));
			return (_parent::end());
		}
		
		const_iterator		find(const key_type& key) const
		{
			node	*cursor = _content;

			while (cursor)
			{
				if (key_comp()(key, cursor->key()))
					cursor = cursor->left_child;
				else if (key_comp()(cursor->key(), key))
					cursor = cursor->right_child;
				else
					break;
			}

			if (cursor)
				return (_parent::_get_const_iterator(cursor));
			return (_parent::end());
		}

		size_type			count(const key_type& key) const
		{
			const_iterator	it	= find(key);

			if(it == _parent::end())
				return (0);
			else
				return (1);
		}

		iterator		lower_bound(const Key &key)
		{
			iterator	it	= _parent::begin();

			while (it != _parent::end() && key_comp()(_getKey(*it), key))
				++it;
			
			return (it);
		}

		const_iterator	lower_bound(const Key &key) const
		{
			const_iterator	it	= _parent::begin();

			while (it != _parent::end() && key_comp()(_getKey(*it), key))
				++it;
			
			return (it);
		}

		iterator		upper_bound(const Key &key)
		{
			iterator	it	= _parent::begin();

			while (it != _parent::end() && !key_comp()(key, _getKey(*it)))
				++it;
			
			return (it);
		}

		const_iterator	upper_bound(const Key &key) const
		{
			const_iterator	it	= _parent::begin();

			while (it != _parent::end() && !key_comp()(key, _getKey(*it)))
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

		allocator_type	get_allocator(void) const
		{
			return (_parent::_get_allocator());
		}
};

template< class Key, class T, class Item, class Compare, class Alloc >
void swap( ft::rbt<Key, T, Item, Compare, Alloc>& lhs, ft::rbt<Key, T, Item, Compare, Alloc>& rhs )
{
	lhs.swap(rhs);
}

}

#endif
