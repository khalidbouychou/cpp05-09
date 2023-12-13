/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:21:36 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/13 02:41:27 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0){}

Span::Span(unsigned int n) : _n(n){}

Span::Span(Span const &src){*this = src;}

Span::~Span(){}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_v = rhs._v;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->_v.size() < this->_n)
        this->_v.push_back(n);
    else
        throw std::exception();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_v.size() + std::distance(begin, end) <= this->_n)
        this->_v.insert(this->_v.end(), begin, end);
    else
        throw std::exception();
}

int Span::shortestSpan()
{
    if (this->_v.size() < 2)
        throw Span::NoSpanException();
    std::sort(this->_v.begin(), this->_v.end());
    int min = this->_v[1] - this->_v[0];
    for (unsigned int i = 2; i < this->_v.size(); i++)
        if (this->_v[i] - this->_v[i - 1] < min)
            min = this->_v[i] - this->_v[i - 1];
    return (min);
}

int Span::longestSpan()
{
    if (this->_v.size() < 1)
        throw Span::NoSpanException();
    std::sort(this->_v.begin(), this->_v.end());
    return (this->_v[this->_v.size() - 1] - this->_v[0]);
}

Span::NoSpanException::NoSpanException(){}

Span::NoSpanException::NoSpanException(NoSpanException const &src){*this = src;}

Span::NoSpanException::~NoSpanException() throw(){}

Span::NoSpanException &Span::NoSpanException::operator=(NoSpanException const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

const char *Span::NoSpanException::what() const throw()
{
    return ("No span to find");
}

// std::ostream &operator<<(std::ostream &o, Span const &rhs)
// {
//     for (unsigned int i = 0; i < rhs._v.size(); i++)
//         o << rhs._v[i] << " ";
//     return (o);
// }

