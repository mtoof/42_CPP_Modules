/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:41:04 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/20 16:03:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack()
{

}

template <class T>
MutantStack<T>::~MutantStack()
{
	while (this->size() > 0)
		this->pop();
}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &rhs): std::stack<T>(rhs)
{
}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	if (this != &rhs)
	{
		while (this->size() != 0)
			this->c.pop();
		std::stack<T>::operator=(rhs);
	}
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}
