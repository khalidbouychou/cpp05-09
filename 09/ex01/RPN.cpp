/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:15:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/20 11:42:52 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const &src){*this = src;}
RPN::~RPN(){}
RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

static int check_format(std::string args)
{
    int i = 0;
    if (!args[i])
        return 0;
    while (args[i])
    {
        if (args[i] != ' ' && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/' && (args[i] < '0' || args[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}
static int parse_format(std::string args)
{
    int i = 0;
    while (args[i])
    {
        if ((isdigit(args[i]) && isdigit(args[i + 1])))
            return 0;
        i++;
    }
    return 1;
}

static void process_operator(std::string op, int xs, int ys, std::stack<int> &sdata)
{
    if (op == "/")
    {
        if (xs == 0)
        {
            std::cout << "Error " << std::endl;
            exit(0);
        }
        else
            sdata.push(ys / xs);
    }
    else if (op == "-")
        sdata.push(ys - xs);
    else if (op == "*")
        sdata.push(ys * xs);
    else if (op == "+")
        sdata.push(ys + xs);
}
static void handle_operator(std::string operators, std::stack<int> &sdata)
{
    int xstack = 0;
    int ystack = 0;
    if (sdata.size() < 2)
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    xstack = sdata.top();
    sdata.pop();
    ystack = sdata.top();
    sdata.pop();
    process_operator(operators, xstack, ystack, sdata);
}
void RPN::calculate (std::string args)
{
    if (!check_format(args) || !parse_format(args))
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    std::stack<int> sdata;
    std::stringstream read_input(args);
    std::string operators;

    while (read_input >> operators)
    {
        if (operators == "-" || operators == "/" || operators == "*" || operators == "+")
            handle_operator(operators, sdata);
        else
            sdata.push(std::atoi(operators.c_str()));
    }
    if (sdata.size() != 1)
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    std::cout << sdata.top() << std::endl;
}