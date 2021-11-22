/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:33:50 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/22 18:11:13 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename T, typename Container = vector<T> >
	class stack
	{
		template <typename V, typename C>
		friend bool operator==(const stack<V, C> &lhs,
		                       const stack<V, C> &rhs);
		template <typename V, typename C>
		friend bool operator!=(const stack<V, C> &lhs,
		                       const stack<V, C> &rhs);
		template <typename V, typename C>
		friend bool operator>(const stack<V, C> &lhs,
		                      const stack<V, C> &rhs);
		template <typename V, typename C>
		friend bool operator<(const stack<V, C> &lhs,
		                      const stack<V, C> &rhs);
		template <typename V, typename C>
		friend bool operator>=(const stack<V, C> &lhs,
		                       const stack<V, C> &rhs);
		template <typename V, typename C>
		friend bool operator<=(const stack<V, C> &lhs,
		                       const stack<V, C> &rhs);

	public:
		typedef typename Container::value_type value_type;
		typedef Container container_type;
		typedef typename Container::size_type size_type;

	protected:
		container_type c;

	public:
		bool empty(void) const;
		size_type size(void) const;
		value_type &top(void);
		value_type &top(void) const;
		void push(const value_type &val);
		void pop(void);
	};
	template <typename T, typename Container>
	bool stack<T, Container>::empty(void) const
	{
		return (c.empty());
	}
	template <typename T, typename Container>
	typename stack<T, Container>::size_type stack<T, Container>::size(
	    void) const
	{
		return (c.size());
	}
	template <typename T, typename Container>
	typename stack<T, Container>::value_type &stack<T, Container>::top(void)
	{
		return (c.back());
	}
	template <typename T, typename Container>
	typename stack<T, Container>::value_type &stack<T, Container>::top(
	    void) const
	{
		return (c.back());
	}
	template <typename T, typename Container>
	void stack<T, Container>::push(const value_type &val)
	{
		c.push_back(val);
	}
	template <typename T, typename Container>
	void stack<T, Container>::pop(void)
	{
		c.pop_back();
	}
	template <typename T, typename Container>
	bool operator==(const stack<T, Container> &lhs,
	                const stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <typename T, typename Container>
	bool operator!=(const stack<T, Container> &lhs,
	                const stack<T, Container> &rhs)
	{
		return (!(lhs.c == rhs.c));
	}
	template <typename T, typename Container>
	bool operator<(const stack<T, Container> &lhs,
	               const stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <typename T, typename Container>
	bool operator>(const stack<T, Container> &lhs,
	               const stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <typename T, typename Container>
	bool operator<=(const stack<T, Container> &lhs,
	                const stack<T, Container> &rhs)
	{
		return (!(lhs.c > rhs.c));
	}
	template <typename T, typename Container>
	bool operator>=(const stack<T, Container> &lhs,
	                const stack<T, Container> &rhs)
	{
		return (!(lhs.c < rhs.c));
	}
}  // namespace ft
#endif /* ifndef STACK_HPP */
