/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:46:00 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/13 16:49:42 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<char> mstack;
    mstack.push('a');
    mstack.push('b');
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << "top " << mstack.top() << std::endl;
    // std::cout << "before pop :size stack "<< mstack.size() << std::endl;
    // mstack.pop();
    // std::cout << "after pop : size stack "<< mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // mstack.push(0);
    MutantStack<char>::iterator it = mstack.begin();
    MutantStack<char>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // std::stack<int> s(mstack);
    return 0;
}