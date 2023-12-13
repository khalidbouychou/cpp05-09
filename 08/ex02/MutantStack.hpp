/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.HPP                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:44:56 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/13 02:47:17 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const &src);
        ~MutantStack();
        MutantStack &operator=(MutantStack const &rhs);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs)
{
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template <typename T>

typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}
