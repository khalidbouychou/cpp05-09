/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:16:46 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/20 10:19:02 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        RPN();
        RPN(RPN const &src);
        ~RPN();
        RPN &operator=(RPN const &rhs);
    public :
        static void calculate(std::string str);
};